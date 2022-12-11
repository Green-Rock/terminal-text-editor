#include <stdio.h>
#include <coniow.h>
#include "window.h"
#include "text.h"
#include "keys.h"
#include "line.h"

int main(int argc, char *argv[])
{
    window(1, 1, WIDTH, HEIGHT);
    _setcursortype(_NORMALCURSOR);
    textcolor(WHITE);
    textbackground(BLUE);
    clrscr();

    window_cleaning();
    interface();

    int character;

    while(1)
    {
        character = getch();

        if (character == 0)
        {
            character = getch();

            if (character == KEY_F6)
            {
                clrscr();
                break;
            }

            special_keys(character);
        }
        else if (character == KEY_ENTER)
        {
            if (enter_name)
            {
                enter_file_name();
                open_file();
            }
            else
            {
                enter();
            }
        }
        else if (character == KEY_BACKSPACE)
        {
            backspace();
        }
        else if (!selection_mode)
        {
            enter_character(character);
        }

        update_window();
        gotoxy(cursor_x - interface_x, cursor_y - interface_y);
    }

    return 0;
}