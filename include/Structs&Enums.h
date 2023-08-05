enum color {Red = 1, Green, Yellow, Blue, Purple, Lightblue, No};
// مقدار آخر تنها در رنگ بازیکن سوم ممکن است قرار بگیرد و نشاندهنده عدم وجود بازیکن سوم است
typedef struct 
{
    char player1_name[16];
    char player2_name[16];
    char player3_name[16];
    enum color player1_color;
    enum color player2_color;
    enum color player3_color;
    int trow; // تعداد ردیف انتخابی برای بازی
    int tcolumn; // تعداد ستون انتخابی برای بازی
    int target; //تعداد انتخابی از مهره های همرنگ هم جوار برای بُرد 
    FILE* write; // فایل برای ثبت آخرین بازی انجام شده
    FILE* read; // فایل در صورت دلخواه که دستورات بازی از آن گرفته شود 
}information;
