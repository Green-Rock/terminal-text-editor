#ifndef _WINDOW_H_
#define _WINDOW_H_

#define WIDTH 120
#define HEIGHT 30
#define SIZE 1000
#define SIZEH 500

#include <coniow.h>

extern char_info window[HEIGHT - 2][WIDTH];
extern char_info file_info[SIZEH];

extern int enter_name = 0;
extern int interf_y = 0;
extern int interf_x = 0;
extern int cursor_x = 1;
extern int cursor_y = 2;
extern int count_row = 0;

extern struct Line {
   char s[SIZEH];
   int size;
} text[SIZE], copy_text[SIZE];

extern char file_name[SIZE];

const char *information_for_user[7] = {
   "FILE:",
   "F1 - Открыть файл",
   "F2 - Сохранить",
   "F3 - Копировать",
   "F4 - Выделить",
   "F5 - Вставить ",
   "F6 - Выход"
};

void update_window();
void interface();
void window_cleaning();

#endif