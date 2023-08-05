void Play()
{
    information* game = Submit_Information();
    if(game == NULL) // اگر یکی از فایل های خواندن یا نوشتن باز نشود
    {
        free(game);
        return;
    }
    char table[game->trow][game->tcolumn];// جدول بازی
    for(int i = 0; i < (game->trow); i++)
    {
        for(int j = 0; j < (game->tcolumn); j++)
        {
            table[i][j] = ' ';
        }
    }
    char move;
    bool result = false; // نتیجه بازی معلوم شده است یا خیر
    for(int i = 0; !result && i < (game->trow)*(game->tcolumn) ;i++)
    // در صورت معلوم شدن برنده یا پر شدن جدول از حلقه خارج میشود
    {
        rule(0 , 1);
        DrawTable(game, table);
        if((i%2 == 0 && game->player3_color == No) || (i%3 == 0 && game->player3_color != No)) 
        {// نوبت بازیکن اول
            rule(2, game->player1_color);
            printf("Player1 \033[0;37m%s is your turn: ", game->player1_name);
            fprintf(game->write, "Player1 %s is your turn: ", game->player1_name);
            move = Submit_Move(game, table ,'1');
        }
        else if((i%2 == 1 && game->player3_color == No) || (i%3 == 1 && game->player3_color != No))
        {// نوبت بازیکن دوم
            rule(2, game->player2_color);
            printf("Player2 \033[0;37m%s is your turn: ", game->player2_name);
            fprintf(game->write, "Player2 %s is your turn: ", game->player2_name);
            move = Submit_Move(game, table ,'2');
        }
        else // در صورت وجود بازیکن سوم و نوبتش وارد این در غیر اینصورت میشویم
        {
            rule(2, game->player3_color);
            printf("Player3 \033[0;37m%s is your turn: ", game->player3_name);
            fprintf(game->write, "Player3 %s is your turn: ", game->player3_name);
            move = Submit_Move(game, table ,'3');
        }
        if((i+1 >= 3*(game->target)-2 || (i+1 >= 2*(game->target)-1 && game->player3_color == No)) && (result = Check_Result(game, move, table)))
        /*
        در صورتی که اولا حداقل یکی از بازیکنان حداقل به اندازه تارگت انداخته باشد
        و دوما برنده بازی مشخص شده باشد وارد این شرط میشویم
        */
        {
            rule(0 , 1);
            printf("***");
            fprintf(game->write, "***");
            if((i%2 == 0 && game->player3_color == No) || (i%3 == 0 && game->player3_color != No))
            {
                rule(2, game->player1_color);
                printf("Plater1\033[0;37m(%s)", game->player1_name);
                fprintf(game->write, "Player1(%s)", game->player1_name);
            }
            else if((i%2 == 1 && game->player3_color == No) || (i%3 == 1 && game->player3_color != No))
            {
                rule(2, game->player2_color);
                printf("Player2\033[0;37m(%s)", game->player2_name);
                fprintf(game->write, "Player2(%s)", game->player2_name);
            }
            else
            {
                rule(2, game->player3_color);
                printf("Player3\033[0;37m(%s)", game->player3_name);
                fprintf(game->write, "Player3(%s)", game->player3_name);
            }
            printf("Won!***\n");
            fprintf(game->write, "Won!***\n");
        }
    }
    if(!result)
    // در صورت مساوی و معلوم نشدن برنده
    {
        rule(0 , 1);
        printf("!Equal!\n");
        fprintf(game->write, "!Equal!\n");
    }
    do
    {
        printf("Wanna See Last Table? Y/N: ");
        // درخواست از کاربر برای نمایش آخرین صحنه از جدول این دور از بازی
        move = getchar();
        if(move != '\n')
        {
            getchar();
        }
        if(move == '!')
        {
            if(game->read != NULL)
            {
                fclose(game->read);
            }
            fclose(game->write);
            free(game);
            exit(0);
        }
        if(move == '?')
        {
            rule(1 , 1);
            continue;
        }
        if(toupper(move) == 'Y')
        {
            DrawTable(game, table);
            break;
        }
        if(toupper(move) == 'N')
        {
            break;
        }
        printf("Your command was wrong!(your command was: %c)\n", move);

    } while(1);
    fprintf(game->write, "*********************************\n");
    
    fclose(game->write);
    if(game->read != NULL)
    {
        fclose(game->read);
    }
    free(game);
}