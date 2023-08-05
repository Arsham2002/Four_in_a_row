#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> // برای تخصیص حافظه، اندازه گیری زمان اجرا, پاک کردن ترمینال
#include <ctype.h> // بیشتر برای از بین بردن حساسیت بین حروف بزرگ و کوچک در واقع استفاده از توآپر
#include <math.h> //  تنها برای باقیمانده تقسیم دو متغیر اعشاری در تابع تایم

#include "Structs&Enums.h"
#include "Prototypes.h"

#include "../src/Guide.c" // تابع برای آموزش دادن بازی در آن قرار گفته است
#include "../src/Game_Func.c" // توابع مورد نیاز برای اجرای بازی در آن است
#include "../src/Information_Func.c"// تابع برای ثبت اطلاعات در استراکت و یک تابع با کاربردهای عمومی
#include "../src/Play.c" // اجرای بازی در اصل در این فایل صورت میگیرد