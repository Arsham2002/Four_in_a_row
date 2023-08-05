void rule(int x ,enum color txtcolor)
{
    if(x == 0)
    {// برای زیبایی عملکرد و پاک کردن ترمینال در شرایط خاص
        system("cls");
    }
    else if(x == 1)
    {// اعلام زمان از اجرا تا به این لحظه
        double time = (double)clock()/1000;
        if(time < 60)
        {
            printf("You was %.0f seconds in my program.\n", time);
        }
        else
        {
            printf("You was %.0f minutes and %.0f seconds in my program.\n", time/60, fmod(time, 60));
        }
    }
    else if(x == 2)
    {// تغییر رنگ متن بعدی و بولد کردن آن
        switch(txtcolor)
        {
            case Red:
            printf("\033[1;31m");
        //    fprintf(game->write, "\033[1;31m");
            break;
            case Green:
            printf("\033[1;32m");
        //    fprintf(game->write, "\033[1;32m");
            break;
            case Yellow:
            printf("\033[1;33m");
        //    fprintf(game->write, "\033[1;33m");
            break;
            case Blue:
            printf("\033[1;34m");
        //    fprintf(game->write, "\033[1;34m");
            break;
            case Purple:
            printf("\033[1;35m");
        //    fprintf(game->write, "\033[1;35m");
            break;
            case Lightblue:
            printf("\033[1;36m");
            break;
            default:
            break;
        }

    }
}
information* Submit_Information()
{
    information* game = (information*)malloc(sizeof(information));
    char code_color1, code_color2, code_color3, move;
    printf("Enter the name of player1: ");
    scanf("%15s", game->player1_name);
    getchar();
    do
    {
        printf("\033[0;31m1:Red \033[0;32m2:Green ");
        printf("\033[0;33m3:Yellow \033[0;34m4:Blue ");
        printf("\033[0;35m5:Purple \033[0;36m6:Light Blue\n");
        printf("\033[0;37mEnter the color of player1: ");
        code_color1 = getchar();
        if(code_color1 != '\n')
        {
            getchar();
        }
        if(code_color1 == '!')
        {
            free(game);
            exit(0);
        }
        if(code_color1 == '?')
        {
            rule(1 , 1);
            continue;
        }
        if(code_color1 <= '6' && '1' <= code_color1)
        {
            game->player1_color = code_color1 - '0';
            break;
        }
        printf("Wrong command for select the color!(your command was: %c)\n", code_color1);
    }while(1);
    printf("Enter the name of player2: ");
    scanf("%15s", game->player2_name);
    getchar();
    do
    {
        printf("\033[0;31m1:Red \033[0;32m2:Green ");
        printf("\033[0;33m3:Yellow \033[0;34m4:Blue ");
        printf("\033[0;35m5:Purple \033[0;36m6:Light Blue\n");
        printf("\033[0;37mEnter the color of player2: ");
        code_color2 = getchar();
        if(code_color2 != '\n')
        {
            getchar();
        }
        if(code_color2 == '!')
        {
            free(game);
            exit(0);
        }
        if(code_color2 == '?')
        {
           rule(1 , 1);
           continue;
        }
        if(code_color2 <= '6' && '1' <= code_color2)
        {
            if(code_color1 != code_color2)
            {
                game->player2_color = code_color2 - '0';
                break;
            }
            printf("you Can't select the same color!\n");
            continue;
        }
        printf("Wrong command for select the color!(your command was: %c)\n", code_color2);
    }while(1);
    do
    {
        printf("Wait you can also play this game with three players.\n");
        printf("Do you want? Y/N: ");
        // درخواست از کاربر برای تنظیم بازی به صورت دو نفره یا سه نفره
        move = getchar();
        if(move != '\n')
        {
            getchar();
        }
        if(move == '!')
        {
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
            printf("Enter the name of player3: ");
            scanf("%15s", game->player3_name);
            getchar();
            game->player3_color = Red;
            break;
        }
        if(toupper(move) == 'N')
        {
            game->player3_color = No;
            break;
        }
        printf("Your command was wrong!(your command was: %c)\n", move);

    } while(1);
    while(game->player3_color != No)
    {
        printf("\033[0;31m1:Red \033[0;32m2:Green ");
        printf("\033[0;33m3:Yellow \033[0;34m4:Blue ");
        printf("\033[0;35m5:Purple \033[0;36m6:Light Blue\n");
        printf("\033[0;37mEnter the color of player3: ");
        code_color3 = getchar();
        if(code_color3 != '\n')
        {
            getchar();
        }
        if(code_color3 == '!')
        {
            free(game);
            exit(0);
        }
        if(code_color3 == '?')
        {
           rule(1 , 1);
           continue;
        }
        if(code_color3 <= '6' && '1' <= code_color3)
        {
            if(code_color1 != code_color3 && code_color2 != code_color3)
            {
                game->player3_color = code_color3 - '0';
                break;
            }
            printf("you Can't select the same color!\n");
            continue;
        }
        printf("Wrong command for select the color!(your command was: %c)\n", code_color3);
    }
    do
    {
        printf("Enter Row then Column of the table and target for win(Sug: 8 8 4): ");
        scanf("%d %d %d", &(game->trow), &(game->tcolumn), &(game->target));
        getchar();
        if(game->trow == '!' || game->tcolumn == '!' || game->target == '!')
        {
            free(game);
            exit(0);
        }
        if(game->trow == '?' || game->tcolumn == '?' || game->target == '?')
        {
            rule(1 , 1);
            continue;
        }
        if(game->trow < 11 && (game->tcolumn) < 11 && game->target < 6 && game->target > 2 && game->trow > 4 && game->tcolumn > 4)
        // این اگر، شرط استاندارد بودن بازی با توجه به تعداد ردیف، ستون و تارگت را چک میکند
        {
            break;
        }
        printf("you can't select Row or Column bigger than 10 or smaller than 5\n");
        printf("also can't select target bigger than 5 or smaller than 3\n");
    } while (1);
    game->write = fopen("The_Last_Game.txt","w");
    if(game->write == NULL)
    {
        printf("Can't open the file\n");
        return NULL;
    }
    do
    {
        printf("Wanna Auto play from New_Game.txt? Y/N: ");
        // در صورتی که کاربر فایل اماده ای به این شکل دارد و میخواهد بازی اتومات انجام شود
        move = getchar();
        if(move != '\n')
        {
            getchar();
        }
        if(move == '!')
        {
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
            game->read = fopen("New_Game.txt", "r");
            if(game->read == NULL)
            {
                printf("Can't open the file!!");
                return NULL;
            }
            break;
        }
        else if(toupper(move) == 'N')
        {
            game->read = NULL; // اگر کاربر بازی اتومات را رد کرد
            break;
        }
        printf("Your command was wrong!(your command was: %c)\n", move);
    } while(1);

    return game;
}