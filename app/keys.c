#include <coniow.h>
#include "keys.h"
#include "window.h"
#include "text.h"
#include "line.h"


// void specialnye_klavishi(int kod);
void special_keys(int code) {
    switch(code)
   {
      case KEY_F1:
         enter_file_name();
         break;
      case KEY_F2:
         save_file();
         break;
      case KEY_F3:
         copy_line();
         break;
      case KEY_F4:
         selection_mode = 1 - selection_mode;
         break;
      case KEY_F5:
         insert_line();
         break;
      case 72:
         up_key();
         break;
      case 75:
         left_key();
         break;
      case 77:
         right_key();
         break;
      case 80:
         down_key();
         break;
   }
}

// void backspace();
void backspace()
{
   if ((cursor_x == 1 && (cursor_y == 2 || enter_name)) || selection_mode)
   {
      return ;
   }
   
   if (cursor_x == 1)
   {
      int length = text[cursor_y].size - cursor_x + 1;

      for (int i = 1; i <= dlina; i++)
      {
         text[cursor_y - 1].s[text[cursor_y - 1].size + i] = text[cursor_y].s[i];
         text[cursor_y].s[i] = ' ';
      }

      text[cursor_y].size = 0;
      cursor_x = text[--cursor_y].size + 1;
      text[cursor_y].size += length;

      if (cursor_y - 1 != quantity_rows)
      {
         shift_row_up();
      }
      
      quantity_rows--;
   }
   else
   {
      delete_character();
   }
}

// void enter();
void enter()
{
   if (selection_mode)
   {
      return;
   }

   int length = text[cursor_y].size - cursor_x + 1;

   if (cursor_y - 1 != quantity_rows)
   {
      shift_row_down();
   }

   for (int i = 0; i < length; i++)
   {
      text[cursor_y + 1].s[i + 1] = text[cursor_y].s[cursor_x + i];
      text[cursor_y].s[cursor_x + i] = ' ';
   }

   quantity_rows++;
   text[cursor_y].size -= length;
   text[++cursor_y].size = 0;
   text[cursor_y].size += length;
   cursor_x = 1;
}

// void strelka_vverh();
void up_key()
{
   if (cursor_y != 2 && !enter_name)
   {
      if (cursor_x > text[cursor_y - 1].size)
      {
         cursor_x = text[cursor_y - 1].size + 1;
      }

      cursor_y--;
   }
}

// void strelka_vniz();
void down_key()
{
   if (cursor_y - 1 != quantity_rows && !enter_name)
   {
      if (cursor_x > text[cursor_y + 1].size)
      {
         cursor_x = text[cursor_y +1].size + 1;
      }

      cursor_y++;
   }
}

// void strelka_vlevo();
void left_key()
{
   if (cursor_x == 1)
   {
      if (cursor_y == 2 || enter_name)
      {
         return;
      }

      cursor_y--;
      cursor_x = text[cursor_y].size + 1;
   }
   else
   {
      cursor_x--;
   }
}

// void strelka_vpravo();
void right_key()
{
   if (cursor_x == text[cursor_y].size + 1)
   {
      if (cursor_y - 1 != quantity_rows && !enter_name)
      {
         cursor_y++;
         cursor_x = 1;
      }
      else
      {
         return;
      }
   }
   else
   {
      cursor_x++;
   }
}