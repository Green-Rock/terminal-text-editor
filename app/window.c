#include <coniow.h>
#include "window.h"
#include "text.h"

// void obnovlenie_okna();
void update_window()
{
    if (enter_name)
    {
        scroll_text();

        for (int i = 0; i < HEIGHT - 2; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                window[i][j].letter = text[i + 2 + interf_y].s[j + 1 + interf_x];
                window[i][j].attr = BLUE * 16 + WHITE;

                if (selection_mode)
                {
                    text_selection(int i, int j);
                    if (letter_highlighted)
                    {
                        window[i][j].attr = DARKGRAY * 16 + WHITE;
                    }
                }
                else
                {
                    copy_x = cursor_x;
                    copy_y = cursor_y;
                }
            }
        }

        puttext(1, 2, WIDTH, HEIGHT - 1, &window);
    }

    for (int i = 0; i < WIDTH; i++)
    {
      file_info[i].letter = text[1].s[i + 1];
      file_info[i].attr = BLACK * 16 + WHITE;
    }

    puttext(6, 1, WIDTH, 1, &file_info);
}


// void interfejs();
void interface()
{
    textbackground(BLACK);

    for (int i = 0; i < SIZEH; i++)
    {
        text[1].s[i] = ' ';
    }

    gotoxy(1, 1);
    clreol();
    cputs(information_for_user[0]);
    gotoxy(1, HEIGHT);
    clreol();

    for (int i = 1; i < 7; i++)
    {
        cputs(information_for_user[i]);
        gotoxy(wherex() + 7, HEIGHT);
    }

    gotoxy(cursor_x, cursor_y);
}

// void ochistka_okna();
void window_cleaning()
{
    for (int i = 2; i < SIZE; i++)
    {
        for (int j = 0; j < SIZEH; j++)
        {
            text[i].s[j] = ' ';
        }
    }

    for (int i = 2; i < SIZE; i++)
    {
        text[i].size = 0;
    }

    count_row = 1;
    cursor_x = 1;
    cursor_y = 2;
}