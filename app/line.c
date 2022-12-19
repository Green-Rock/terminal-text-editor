#include <coniow.h>
#include "line.h"
#include "window.h"
#include "text.h"

void delete_character()
{
    for (int i = cursor_x - 1; i <= text[cursor_y].size; i++)
    {
        text[kursor_y].s[i] = text[kursor_y].s[i + 1];
    }

    text[cursor_y].size--;
    cursor_x--;
}

void shift_row_up()
{
    for (int i = cursor_y + 2; i <= quantity_rows + 1; i++)
   {
        text[i - 1] = text[i];

        for (int j = 1; j <= text[i].size; j++)
        {
            text[i].s[j] = ' ';
        }
   }
}

void shift_row_down()
{
    for (int i = quantity_rows + 1; i > cursor_y; i--)
   {
      text[i + 1] = text[i];

      for (int j = 1; j <= text[i].size; j++)
      {
         text[i].s[j] = ' ';
      }
   }
}

void enter_character(int code)
{
    for (int i = text[cursor_y].size; i >= cursor_x; i--)
    {
        text[cursor_y].s[i + 1] = text[cursor_y].s[i];
    }

    text[cursor_y].size++;
    text[cursor_y].s[cursor_x] = kod;
    cursor_x++;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copy_line()
{
    if (!selection_mode)
    {
        return;
    }

    if (copy_y >= cursor_y)
    {
        swap(&copy_y, &cursor_y);
        swap(&copy_x, &cursor_x);
    }

    for (int i = 0; i < SIZEH; i++)
    {
        copy_text[i].size = 0;
    }

    copy_size = 0;

    for (int i = copy_y; i <= cursor_y; i++)
    {
        for (int j = copy_x; j <= text[i].size; j++)
        {
            if (i == cursor_y && j == cursor_x)
            {
                break;
            }

            copy_text[copy_size].s[copy_text[copy_size].size] = text[i].s[j];
            copy_text[copy_size].size++;
        }

        copy_x = 1;
        copy_size++;
    }

    selection_mode = 0;
}

void enter_file_name()
{
    if (enter_name)
    {
        enter_name = 0;
        cursor_x = 1;
        cursor_y = 2;
        interface_x = 0;
    }
    else
    {
        enter_name = 1;
        cursor_y = 1;
        cursor_x = text[cursor_y].size + 1;;
        interface_x = -5;
    }

    interface_y = 0;
}