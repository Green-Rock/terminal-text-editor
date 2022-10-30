#include <stdio.h>
#include <coniow.h>
#define WIDTH 120
#define HEIGHT 30
#define SIZE 1000
#define SIZEH 500
void specialnye_klavishi(int kod);
void obnovlenie_okna();
void strelka_vpravo();
void strelka_vlevo();
void backspace();
void enter();
void swap(int *a, int *b);
void strelka_vverh();
void strelka_vniz();
void udalenie_simvolov();
void sdvig_strok_vniz();
void sdvig_strok_vverh();
void interfejs();
void prokrutka_teksta();
void otkrytie_fajla();
void vvod_simvolov();
void kopirovat();
void vvod_imeni_fajla();
void ochistka_okna();
void sohranenie_fajla();
void vydelenie_teksta(int i, int j);
void vstavit();
void vvod_simvolov(int kod);

struct Line {
   char s[SIZEH];
   int size;
} text[SIZE], copy_text[SIZE]; //���� ����� � ������������� �����
FILE *file;
char_info okno[HEIGHT - 2][WIDTH]; //�����, ������� ������������ � ����
char_info file_info[SIZEH]; //���������� � �����, ������� ������������ �� ������
int kolichestvo_strok = 1; //���������� �����
int vvod_imeni = 0; //����, ������� ���������, ��� ���� ������� ����� ���� � �����
int copy_size = 0; //���������� ������������� �����
int rezhim_vydeleniya = 0; //����, ������� ���������, ��� ���� ������� ��������� ������
int copy_x, copy_y; //��������� ������� ������������� �������
int interf_x= 0, interf_y = 0; //��������� ������� ���� �� x � y
int kursor_x = 1, kursor_y = 2; //������� ������� �� x � y
int vydelit = 0; //����, ������� ���������, ��� ����� ������ ���� ��������
char imya_fajla[SIZE]; //������ � ������ �����

int main()
{
   window(1, 1, WIDTH, HEIGHT);
   _setcursortype(_NORMALCURSOR);
   textcolor(WHITE);
   textbackground(BLUE);
   clrscr();
   ochistka_okna();
   interfejs();
   int ch;
   while(1)
   {
      ch = getch();
      if (ch == 0) //����������� �������
      {
         ch = getch();
         if (ch == KEY_F6)
         {
            clrscr();
            break;
         }
         specialnye_klavishi(ch);
      }
      else if (ch == KEY_ENTER)
      {
         if (vvod_imeni)
         {
            vvod_imeni_fajla();
            otkrytie_fajla();
         }
         else
            enter();
      }
      else if (ch == KEY_BACKSPACE)
         backspace();
      else if (!rezhim_vydeleniya)
         vvod_simvolov(ch);
      obnovlenie_okna();
      gotoxy(kursor_x - interf_x, kursor_y - interf_y);
   }
}
//��������� ����������� ������
void specialnye_klavishi(int kod)
{
   switch(kod)
   {
      case KEY_F1:
         vvod_imeni_fajla();
         break;
      case KEY_F2:
         sohranenie_fajla();
         break;
      case KEY_F3:
         kopirovat();
         break;
      case KEY_F4:
         if (rezhim_vydeleniya)
            rezhim_vydeleniya = 0;
         else
            rezhim_vydeleniya = 1;
         break;
      case KEY_F5:
         vstavit();
         break;
      case 72:
         strelka_vverh();
         break;
      case 75:
         strelka_vlevo();
         break;
      case 77:
         strelka_vpravo();
         break;
      case 80:
         strelka_vniz();
         break;
   }
}
//������� ��������� ���� � �������� ��������� � ��������� ���������
void ochistka_okna() {
   for (int i = 2; i < SIZE; i++)
   {
      for (int j = 0; j < SIZEH; j++)
      {
         text[i].s[j] = ' '; //��� ������ ������
      }
   }
   for (int i = 2; i < SIZE; i++)
      text[i].size = 0;
   kolichestvo_strok = 1;
   kursor_x = 1;
   kursor_y = 2;
}
//��������� ��� ���������� ��������� ����� ���� � �����
void vvod_imeni_fajla()
{
   if (vvod_imeni)
   {
      vvod_imeni = 0; //������� ����� ���� � ����� �����������
      kursor_x = 1; //��������� ��������� �������
      kursor_y = 2;
      interf_x = 0;
   }
   else
   {
      vvod_imeni = 1; //������� ����� ���� � ����� ����������
      kursor_y = 1;
      kursor_x = text[kursor_y].size + 1;
      interf_x = -5;
   }
   interf_y = 0;
}
//��������� ����
void sohranenie_fajla()
{
   file = fopen(imya_fajla, "w");
   for (int i = 2; i <= kolichestvo_strok + 1; i++)
   {
      for (int j = 1; j <= text[i].size; j++)
         fprintf(file, "%c", text[i].s[j]);
      if (i != kolichestvo_strok + 1)
         fprintf(file, "\n");
   }
   fclose(file);
}
//��������� ����
void otkrytie_fajla()
{
   unsigned char ch;
   ochistka_okna();
   for (int i = 1; i <= text[1].size; i++)
      imya_fajla[i - 1] = text[1].s[i];
   imya_fajla[text[1].size] = 0; //������ ����� ������
   file = fopen(imya_fajla, "r");
   while (fscanf(file, "%c", &ch) == 1)
   {
      if (ch == '\n')
      {
         kursor_y++; //����� ������
         kursor_x = 1; //������� �� ������ ������
         kolichestvo_strok++;
      }
      else
      {
         text[kursor_y].s[kursor_x] = ch;
         text[kursor_y].size++; //���������� ���������� �������� � ������
         kursor_x++;
      }
   }
   kursor_x = 1;
   kursor_y = 2;
   fclose(file);
}
//�������� ��������� ������ � ����
void prokrutka_teksta()
{
   if (kursor_x > WIDTH)
      interf_x = kursor_x - WIDTH;
   else
      interf_x = 0;
   if (kursor_y == interf_y + HEIGHT)
      interf_y++;
   else if (kursor_y == interf_y + 1 && !vvod_imeni)
      interf_y--;
}
//��������� ������
void vstavit()
{
   for (int i = 0; i < copy_size; i++)
   {
      for (int j = 0; j < copy_text[i].size; j++)
      {
         vvod_simvolov(copy_text[i].s[j]);
      }
      if (i != copy_size - 1) enter();
      prokrutka_teksta();
   }
}
//������ ������� a � b
void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}
//�������� ������
void kopirovat()
{
   if (rezhim_vydeleniya)
   {
      if (copy_y >= kursor_y)
      {
         swap(&copy_y, &kursor_y);
         swap(&copy_x, &kursor_x);
      }
      for (int i = 0; i < SIZEH; i++) copy_text[i].size = 0;
      copy_size = 0;
      for (int i = copy_y; i <= kursor_y; i++)
      {
         for (int j = copy_x; j <= text[i].size; j++)
         {
            if (i == kursor_y && j == kursor_x) break;
            copy_text[copy_size].s[copy_text[copy_size].size] = text[i].s[j]; //����������� ����� �������
            copy_text[copy_size].size++; //����������� ���������� ��������
         }
         copy_x = 1;
         copy_size++;
      }
      rezhim_vydeleniya = 0;
   }
}
//��������� ������� ��������� ������
void vydelenie_teksta(int i, int j)
{
   if (copy_x == kursor_x && copy_y == kursor_y)
      vydelit = 0;
   else if (kursor_x == j + 1 + interf_x && kursor_y == i + 2 + interf_y)
   {
      if (vydelit) vydelit = 0;
      else vydelit = 1;
   }
   else if (copy_x == j + 1 + interf_x && copy_y == i + 2 + interf_y)
   {
      if (vydelit) vydelit = 0;
      else vydelit = 1;
   }
}
//������ ��������� ���������
void interfejs()
{
   const char *podskazki[7] = {
   "FILE:",
   "F1 - ������� ����",
   "F2 - ���������",
   "F3 - ����������",
   "F4 - ��������",
   "F5 - �������� ",
   "F6 - �����"
   };
   textbackground(BLACK);
   for (int i = 0; i < SIZEH; i++) 
      text[1].s[i] = ' '; //������, ��� ����������� � ��������� � �����                                          
   gotoxy(1, 1);
   clreol();
   cputs(podskazki[0]);
   gotoxy(1, HEIGHT);
   clreol();
   for (int i = 1; i < 7; i++)
   {
      cputs(podskazki[i]);
      gotoxy(wherex() + 7, HEIGHT);
   }
   gotoxy(kursor_x, kursor_y);
}
//���������� ������ ����
void strelka_vniz()
{
   if (kursor_y - 1 != kolichestvo_strok && !vvod_imeni)
   {
      if (kursor_x > text[kursor_y + 1].size)
         kursor_x = text[kursor_y +1].size + 1; //����������� ������� �� ����� ��������� ������
      kursor_y++;
   }
}
//���������� ������ �����
void strelka_vverh()
{
   if (kursor_y != 2 && !vvod_imeni)
   {
      if (kursor_x > text[kursor_y - 1].size)
         kursor_x = text[kursor_y - 1].size + 1; //����������� ������� �� ����� ���������� ������
      kursor_y--;
   }
}
//���������� ������ �����
void strelka_vlevo()
{
   if (kursor_x == 1)
   {
      if (kursor_y == 2 || vvod_imeni)
         return ;
      kursor_y--;
      kursor_x = text[kursor_y].size + 1; //����������� ������� �� ����� ���������� ������
   }
   else
      kursor_x--; //����������� ������� �����
}
//���������� ������ ������
void strelka_vpravo()
{
   if (kursor_x == text[kursor_y].size + 1)
   {
      if (kursor_y - 1 != kolichestvo_strok && !vvod_imeni)
      {
         kursor_y++; //����������� ������� �� ������ ��������� ������
         kursor_x = 1;
      }
      else
         return ;
   }
   else
      kursor_x++; //����������� ������� ������
}
//��������� ��� ������, ����������� ���� �������, �� ���� ������ �����
void sdvig_strok_vverh()
{
   for (int i = kursor_y + 2; i <= kolichestvo_strok + 1; i++)
   {
      text[i - 1] = text[i];
      for (int j = 1; j <= text[i].size; j++)
      {
         text[i].s[j] = ' ';
      }
   }
}
//�������� ��� ������, ����������� ���� �������, �� ���� ������ ����
void sdvig_strok_vniz()
{
   for (int i = kolichestvo_strok + 1; i > kursor_y; i--)
   {
      text[i + 1] = text[i];
      for (int j = 1; j <= text[i].size; j++)
      {
         text[i].s[j] = ' ';
      }
   }
}
//�������������� ��������� ����
void obnovlenie_okna()
{
   if (!vvod_imeni)
   {
      prokrutka_teksta();
      for (int i = 0; i < HEIGHT - 2; i++)
      {
         for (int j = 0; j < WIDTH; j++)
         {
            okno[i][j].letter = text[i + 2 + interf_y].s[j + 1 + interf_x]; //���������� ������� �������
            okno[i][j].attr = BLUE*16 + WHITE;
            if (rezhim_vydeleniya)
            {
               vydelenie_teksta(i, j); 
               if (vydelit)
                  okno[i][j].attr = DARKGRAY*16 + WHITE; //��������� ������
            }
            else
            {
               copy_x = kursor_x;
               copy_y = kursor_y;
            }
         }
      }
      puttext(1, 2, WIDTH, HEIGHT - 1, &okno); //����� ������� ������
   }
   for (int i = 0; i < WIDTH; i++)
   {
      file_info[i].letter = text[1].s[i + 1]; //���������� ������� � ����������� � �����
      file_info[i].attr = BLACK*16 + WHITE;
   }
   puttext(6, 1, WIDTH, 1, &file_info); //����� ������� � ����������� � �����
}
//�������� ������ ����� � ������� ������
void udalenie_simvolov()
{
   for (int i = kursor_x - 1; i <= text[kursor_y].size; i++)
      text[kursor_y].s[i] = text[kursor_y].s[i + 1];
   text[kursor_y].size--;
   kursor_x--;
}
//�������� ������ ������ � ��������� ������
void vvod_simvolov(int kod)
{
   for (int i = text[kursor_y].size; i >= kursor_x; i--)
      text[kursor_y].s[i + 1] = text[kursor_y].s[i];
   text[kursor_y].size++;
   text[kursor_y].s[kursor_x] = kod;
   kursor_x++;
}
//�������� ��� ������� ������� backspace
void backspace()
{
   if ((kursor_x == 1 && (kursor_y == 2 || vvod_imeni)) || rezhim_vydeleniya)
      return ;
   if (kursor_x == 1) //������ � ������ ������
   {
      int dlina = text[kursor_y].size - kursor_x + 1;
      for (int i = 1; i <= dlina; i++) //���������� ������� �� ���������� ������
      {
         text[kursor_y - 1].s[text[kursor_y - 1].size + i] = text[kursor_y].s[i];
         text[kursor_y].s[i] = ' ';
      }
      text[kursor_y].size = 0;
      kursor_x = text[--kursor_y].size + 1; //������ �� ����� ���������� ������
      text[kursor_y].size += dlina; //����������� ����� ���������� ������
      if (kursor_y - 1 != kolichestvo_strok)
         sdvig_strok_vverh();
      kolichestvo_strok--;
   }
   else 
      udalenie_simvolov();
}
//������� ������
void enter()
{
   if (rezhim_vydeleniya)
      return ;
   int dlina = text[kursor_y].size - kursor_x + 1;
   if (kursor_y - 1 != kolichestvo_strok)
      sdvig_strok_vniz();
   for (int i = 0; i < dlina; i++) //���������� ������� �� ��������� ������
   {
      text[kursor_y + 1].s[i + 1] = text[kursor_y].s[kursor_x + i];
      text[kursor_y].s[kursor_x + i] = ' ';
   }
   kolichestvo_strok++;
   text[kursor_y].size -= dlina;
   text[++kursor_y].size = 0;
   text[kursor_y].size += dlina; //����������� ����� ���������� ������
   kursor_x = 1; //������� ������� �� ������ ������
}