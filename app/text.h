#ifndef _TEXT_H_
#define _TEXT_H_

void scroll_text();
void text_selection(int i, int j);
void insert_line();
void open_file();
void save_file();

extern int selection_mode = 0;
extern int letter_highlighted = 0;
extern int quantity_rows = 1;
extern int copy_x;
extern int copy_y;
extern int copy_size = 0;
extern int interface_x = 0;
extern int interface_y = 0;

#endif