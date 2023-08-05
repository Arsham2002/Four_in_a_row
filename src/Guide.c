void Guide_game()
{
    information* game = (information*)malloc(sizeof(information));
    game->trow = game->tcolumn = 8;
    game->target = 4;
    game->write = game->read = NULL;
    game->player1_color = Red;
    game->player2_color = Blue;
    char table[8][8];
    for(int i = 0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            table[i][j] = ' ';
        }
    }
    // تا به اینجا اطلاعات یک بازی فرضی را در یک استراکت تولید کرده ایم
    rule(0 , 1);
    DrawTable(game, table);
    printf("This is a competitive and turn-based game\n");
    printf("That you play with your friend in a table like the one above\n");
    printf("To drop a piece in each column, you need to enter its column icon:\n");
    printf("Like A or B or C ...\n");
    printf("Whoever can reach one of the following situations\n");
    printf("with his pieces first is the winner of the game\n");
    printf("Tap Enter to view situations: ");
    char ch;
    ch = getchar();
    rule(0 , 1);
    if(ch == '!')
    {
        free(game);
        exit(0);
    }
    // از اینجا به بعد چهار حالت بُرد افقی، عمودی، قطر اصلی و قطر فرعی را بوجود آورده
    for(int j = 0; j<4; j++)
    {
        table[0][j] = '1';
    }
    DrawTable(game , table);
    if(ch  == '?')
    {
        rule(1 , 1);
        getchar();
    }
    printf("Tap Enter to view next situations: ");
    ch = getchar();
    rule(0 , 1);
    if(ch == '!')
    {
        free(game);
        exit(0);
    }
    for(int i = 0; i<4; i++)
    {
        table[0][i] = ' ';
        table[i][0] = '1';
    }
    DrawTable(game, table);
    if(ch  == '?')
    {
        rule(1 , 1);
        getchar();
    }
    printf("Tap Enter to view next situations: ");
    ch = getchar();
    rule(0 , 1);
    if(ch == '!')
    {
        free(game);
        exit(0);
    }
    for(int i = 0; i<4; i++)
    {
        table[i][0] = ' ';
        table[i][i] = '1';
    }
    DrawTable(game, table);
    if(ch  == '?')
    {
        rule(1 , 1);
        getchar();
    }
    printf("Tap Enter to view next situations: ");
    ch = getchar();
    rule(0 , 1);
    if(ch == '!')
    {
        free(game);
        exit(0);
    }
    for(int i = 0, j = 3; i<4 ;i++,j--)
    {
        table[i][i] = ' ';
        table[i][j] = '1';
    }
    DrawTable(game, table);
    if(ch  == '?')
    {
        rule(1 , 1);
        getchar();
    }
    printf("Tap Enter to continue: ");
    ch = getchar();
    rule(0 , 1);
    if(ch  == '?')
    {
        rule(1 , 1);
        getchar();
        printf("Tap Enter: ");
        getchar();
    }
    if(ch == '!')
    {
        free(game);
        exit(0);
    }
    free(game);
}