void DrawTable(information* game, char[][game->tcolumn]);
// جدول بازی را در ترمینال رسم میکند
char Submit_Move(information* game, char[][game->tcolumn], char);
// حرکت بازیکنان را در جدول اعمال میکند و حرکت موردقبول اعمال شده را برمیگرداند
bool Check_Result(information* game, char, char[][game->tcolumn]);
// چک میکند آیا برنده بازی مشخص شده است یا خیر
void Guide_game();
// بازی را به کاربر آموزش میدهد
information* Submit_Information();
/*
این تابع یک فضا برای استراکت مرتبط با اطلاعات بازی در نظر میگیرد
اطلاعات را در آن قرار میدهد و آدرسش را برمیگرداند
*/
void rule(int ,enum color);
/* 
این تابع سه کار ساده را انجام میدهد؛ با گرفتن 0 صفحه ترمینال را پاک 
با گرفتن 1 زمان گذشته از اجرا برنامه تا فراخوانی این تابع را به کاربر اعلام میکند
با گرفتن 2 با توجه به داده شمارشی که دریافت کرده رنگ متن بعدی را تغییر میدهد و بولد میکند
*/
void Play();
// روند کلی بازی در آن اجرا میشود