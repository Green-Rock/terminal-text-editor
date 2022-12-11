#ifndef _TEXT_H_
#define _TEXT_H_

//void prokrutka_teksta();
void scroll_text();
//void vydelenie_teksta(int i, int j);
void text_selection(int i, int j);
//void vstavit();
void insert_line();
//void otkrytie_fajla();
void open_file();
//void sohranenie_fajla();
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