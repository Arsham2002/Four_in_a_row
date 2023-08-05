void DrawTable(information* game, char table[][game->tcolumn])
{
    char Separator[(game->tcolumn)*4 + 2];
    /*
    این استرینگ درواقع همان +----+است که برای جدا ساری هر ردیف جدول از آن استفاده کردم
    تعداد کرکتر هایش بستگی به تعداد ستون انتخابی آن دست از بازی دارد و در ادامه
    کرکتر های + در ابتدا و انتها و - در بین آن قرار داده میشود
    */
    Separator[0] = Separator[(game->tcolumn)*4] = '+';
    Separator[(game->tcolumn)*4 + 1] = '\0';
    for(int i = 1; i < (game->tcolumn)*4; i++)
    {
        Separator[i] = '-';
    }
    for(int i = 0; i<(game->tcolumn) ;i++)
    // این حلقه ردیف انتخاب حرکت را در بالای جدول برای بازیکن چاپ میکند
    {
        printf("  %c ", 'A'+i);
        fprintf(game->write, "  %c ", 'A'+i);
    }
    printf("\n");
    fprintf(game->write, "\n");
    for(int i = game->trow-1; i>=0; i--)
    /*
    کاری که تمام این حلقه انجام میدهد این است که
    با توجه به رنگ های انتخابی بازیکنان جدول بازی رارسم میکند
    */
    {
        for(int j = 0; j<(game->tcolumn); j++)
        {
            if(table[i][j] == ' ')
            {
                printf("|   ");
                fprintf(game->write, "|   ");
            }
            else if(table[i][j] == '1')
            {
                printf("| ");
                fprintf(game->write, "| ");
                rule(2 , game->player1_color);
                printf("%c ", table[i][j]);
                fprintf(game->write, "%c ", table[i][j]);
            }
            else if(table[i][j] == '2')
            {
                printf("| ");
                fprintf(game->write, "| ");
                rule(2 , game->player2_color);
                printf("%c ", table[i][j]);
                fprintf(game->write, "%c ", table[i][j]);
            }
            else if(table[i][j] == '3')
            {
                printf("| ");
                fprintf(game->write, "| ");
                rule(2 , game->player3_color);
                printf("%c ", table[i][j]);
                fprintf(game->write, "%c ", table[i][j]);
            }
            printf("\033[0;37m");
        }
        printf("|\n");
        printf("%s\n", Separator);
        fprintf(game->write, "|\n");
        fprintf(game->write, "%s\n", Separator);
    }
}
char Submit_Move(information* game, char table[][game->tcolumn], char player)
{
    char movech;
    do
    {
        game->read != NULL && !feof(game->read)? fscanf(game->read, "%c", &movech): scanf("%c", &movech);
        // در صورتی که کاربر بازی اتومات را انخاب کرده باشد و فایل انتخابی تمام نشده باشد
        if(movech != '\n' && game->read == NULL)
        {
            getchar();
        }
        if(movech == '!')
        {
            fclose(game->write);
            if(game->read != NULL)
            {
                fclose(game->read);
            }
            free(game);
            exit(0);
        }
        if(movech == '?')
        {
            rule(1 , 1);
            printf("Enter move: ");
            continue;
        }
        else if(game->read != NULL)
        {
            fgetc(game->read);
        }
        if(toupper(movech) >= 'A' && toupper(movech) < 'A'+(game->tcolumn))
        {
            break;
        }
        printf("Wrong move Enter again.(your move was: %c): ", movech);
    }while(1);
    int column = toupper(movech) - 'A';
    int row;
    for(row = 0; row < game->trow; row++)
    // این حلقه ردیفی که مهره ورودی باید در آن قرار بگیرد را پیدا میکند
    {
        if(table[row][column] == ' ')
        {
            break;
        }
    }
    if(row == game->trow)
    {
        printf("This column is full(%c). select another player%c: ", movech, player);
        return Submit_Move(game, table, player);
        // اگر وارد این شرط شویم بازیکن باید حرکتش را عوض کند و این تابع حرکت جدید را برگرداند
    }
    fprintf(game->write, "%c\n*********************************\n", toupper(movech));
    table[row][column] = player;
    return movech;
}
bool Check_Result(information* game, char move, char table[][game->tcolumn])
{
    int column = toupper(move) - 'A';
    int row;
    for(row = game->trow-1; row >= 0; row--)
    {
        if(table[row][column] != ' ')
        {
            break;
        }
    }
    // تا به اینجا تابع ردیف و ستونی که آخرین حرکت در آن اعمال شده را میابد
    char player = table[row][column];
    int sum = 0;
    for(int j = 0; j<(game->tcolumn) ;j++)
    /*
    این حلقه در راستای ردیف چک میکند
    که آیا به اندازه تارگت مهره های بازیکن در جوار هم قرار گرفته اند؟
    */
    {
        if(table[row][j] == player)
        {
            sum++;
            if(sum == game->target)
            {
                return true;
            }
        }
        if(table[row][j] != player)
        {
            sum = 0;
        }
    }
    sum = 0;
    for(int i = 0; i<game->trow ;i++)
    // این حلقه هم در راستای ردیف چک میکند
    {
        if(table[i][column] == player)
        {
            sum++;
            if(sum == game->target)
            {
                return true;
            }
        }
        if(table[i][column] != player)
        {
            sum = 0;
        }
    }
    sum = 0;
    int i, j;
    if(row >= column)
    {
        j = 0;
        i = row - column;
    }
    else
    {
        j = column - row;
        i = 0;
    }
    /*
    بعد از گذر ازین شرط و درغیراینصورت در آی و جی 
    مختصاتی قرار گرفته که در پایین ترین نقطه قطر اصلی است
    که شامل مختصات آخرین حرکت  بازیکن است 
    */
    for(; !(j == (game->tcolumn) || i == game->trow)  ; j++, i++)
    // چک به صورت قطر اصلی
    {
        if(table[i][j] == player)
        {
            sum++;
            if(sum == game->target)
            {
                return true;
            }
        }
        if(table[i][j] != player)
        {
            sum = 0;
        }
    }
    sum = 0;
    if(row <= (game->tcolumn) - 1 - column)
    {
        j = column + row;
        i = 0;
    }
    else
    {
        j = (game->tcolumn) - 1;
        i = row - ((game->tcolumn) - 1 - column);
    }
    // همان شرایط قبلی اما درمورد قطر فرعی
    for(;!(j == -1 || i == game->trow)  ; j--, i++)
    {
        if(table[i][j] == player)
        {
            sum++;
            if(sum == game->target)
            {
                return true;
            }
        }
        if(table[i][j] != player)
        {
            sum = 0;
        }
    }
    return false; // در صورتی که تا این لحظه از تابع خارج نشده ایم یعنی برنده مشخص نشده

}