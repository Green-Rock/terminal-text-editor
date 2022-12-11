#include <coniow.h>
#include <stdio.h>
#include "text.h"
#include "window.h"
#include "line.h"
#include "keys.h"

//void prokrutka_teksta();
void scroll_text()
{
    if (cursor_x > WIDTH)
    {
        interface_x = cursor_x - WIDTH;
    }
    else
    {
        interface_x = 0;
    }

    if (cursor_y == interface_y + HEIGHT)
    {
        interface_y++;
    }
    else if (cursor_y == interface_y + 1 && !enter_name)
    {
        interface_y--;
    }
}

//void vydelenie_teksta(int i, int j);
void text_selection(int i, int j)
{
    if (copy_x == cursor_x && copy_y == cursor_y)
    {
        letter_highlighted = 0;
    }
    else if (cursor_x == j + 1 + interface_x && cursor_y == i + 2 + interface_y ||
             copy_x == j + 1 + interface_x && copy_y == i + 2 + interface_y)
    {
        letter_highlighted = 1 - letter_highlighted;
    }
}

//void vstavit();
void insert_line()
{
    for (int i = 0; i < copy_size; i++)
    {
        for (int j = 0; j < copy_text[i].size; j++)
        {
            enter_character(copy_text[i].s[j]);
        }

        if (i != copy_size - 1)
        {
            enter();
        }

        scroll_text();
    }
}

//void otkrytie_fajla();
void open_file()
{
    unsigned char character;
    window_cleaning();

    for (int i = 1; i <= text[1].size; i++)
    {
        file_name[i - 1] = text[1].s[i];
    }

    file_name[text[1].size] = 0;

    FILE *file = fopen(imya_fajla, "r");
    while (fscanf(file, "%c", &character) == 1)
    {
        if (character == '\n')
        {
            cursor_y++;
            cursor_x = 1;
            quantity_rows++;
        }
        else
        {
            text[cursor_y].s[cursor_x] = character;
            text[cursor_y].size++; //увеличение количества символов в строке
            cursor_x++;
        }
    }

    cursor_x = 1;
    cursor_y = 2;
    fclose(file);
}

//void sohranenie_fajla();
void save_file()
{
    FILE *file = fopen(file_name, "w");

    for (int i = 2; i <= quantity_rows + 1; i++)
    {
        for (int j = 1; j <= text[i].size; j++)
        {
            fprintf(file, "%c", text[i].s[j]);
        }

        if (i != quantity_rows + 1)
        {
            fprintf(file, "\n");
        }
    }

    fclose(file);
}