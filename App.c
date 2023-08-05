#include "include/Headers.h" // تمام اینکلود های لازم در این فایل قرار گرفته اند
int main()
{
    rule(0 , 1);
    char command = '1';
    printf("Welcome to my program.\tHope to enjoy!\n");
    do
    {
        printf("1: Start a new game\n");
        printf("2: Game guide\n");
        printf("3: Exit the program\n");
        printf("?: How long were you in the program?\n");
        printf("!: Emergency Exit!\n");
        printf("(You can enter ? and ! command whenever you want)\n");
        printf("Enter the number to select the command: ");
        command = getchar();
        if(command == '!')
        // با این شرط بیشتر مواجه خواهید شد، برای اعمال خروج در هر لحظه ار برنامه است
        {
            exit(0);
        }
        if(command != '\n')
        /* 
        با این شرط بیشتر مواجه خواهید شد برای 
        گرفتن اینتر اضافه بعد از وارد کردن دستورات است
        مگر کاربر خوده اینتر را به تنهایی و به اشتباه وارد کرده باشد
        */
        {
            getchar();
        }
        rule(0 , 1);
        switch(command)
        {
            case '1':
            Play();
            break;
            case '2':
            Guide_game();
            break;
            case '3':
            rule(1 , 1);
            printf("Thank you for playing.\tGOOD BYE!");
            break;
            case '?':
            rule(1 , 1);
            printf("Tap Enter to continue: ");
            if(getchar() == '!')
            {
                exit(0);
            }
            rule(0 , 1);
            break;
            default:
            printf("The command was invalid!!(your command was: %c)\n", command);
            break;
        }
    }while(command != '3');
    
    return 0;
}