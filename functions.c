#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////      DZ MODYL 2      ////////////////////////////////// 

char* NumOne(char* str)
{
   int lenght = strlen(str);

   char* temp = malloc((lenght + 1) * sizeof(char));

   int first = 0;
   int last = 0;
   int flag = 0;

   for (int i = 0; i < strlen(str); i++)
   {
      if (flag == 0 && str[i] == ' ')
      {
         first = i;
         flag = 1;
      }
      if (str[i] == ' ')
         last = i;
   }

   int final = 0;
   for (int i = last + 1; i < strlen(str); i++) {
      temp[final] = str[i];
      final++;
   }

   temp[final] = ' ';
   final++;

   for (int i = first + 1; i < last; i++)
   {
      temp[final] = str[i];
      final++;
   }

   temp[final] = ' ';
   final++;

   for (int i = 0; i < first; i++)
   {
      temp[final] = str[i];
      final++;
   }
   temp[final] = '\0';
   str = temp;

   return str;
}

struct People {
   char Surname[99];
   char Name[99];
   char Patronymic[99];
   char Sex[99];
   char job[99];
   int date;
};

void NumTwo()
{
   int count = 0;

   scanf_s("%d", &count);

   struct People* Arr = (struct Human*)malloc(count * sizeof(struct People));

   for (int i = 0; i < count; i++)
   {
      printf("Enter surname:");
      scanf_s("%s", Arr[i].Surname, 100);

      printf("Enter name:");
      scanf_s("%s", Arr[i].Name, 100);

      printf("Enter Patronymic:");
      scanf_s("%s", Arr[i].Patronymic, 100);

      printf("Enter sex:");
      scanf_s("%s", Arr[i].Sex, 100);

      printf("Enter job:");
      scanf_s("%s", Arr[i].job, 100);

      printf("Enter birthday:");
      scanf_s("%d", &Arr[i].date);

      printf("\n");
   }

   for (int i = 0; i < count; i++)
   {
      if (strcmp(Arr[i].job, "engineer") == 0)
      {
         if (strcmp(Arr[i].Sex, "male") == 0)
         {
            if (Arr[i].date <= 1956)
            {
               printf("Full name: %s %s %s\nsex: %s\njob: %s\nDate of Birth: %d", Arr[i].Surname, Arr[i].Name, Arr[i].Patronymic, Arr[i].Sex, Arr[i].job, Arr[i].date);
            }
         }
         else
         {
            if (Arr[i].date <= 1961)
            {
               printf("Full name: %s %s %s\nsex: %s\njob: %s\nDate of Birth: %d", Arr[i].Surname, Arr[i].Name, Arr[i].Patronymic, Arr[i].Sex, Arr[i].job, Arr[i].date);
            }
         }
      }
   }
}

void NumThree()
{
   FILE* f = NULL;
   FILE* g = NULL;

   errno_t err1 = fopen_s(&f, "f.txt", "r");
   errno_t err2 = fopen_s(&g, "g.txt", "w");
   if (err1)
   {
      perror("file F not opening");
      return;
   }
   if (err2)
   {
      perror("file G not opening");
      return;
   }

   int c = 0;

   for (char tmp = 0; fscanf_s(&f, "%d", &tmp) != EOF;)
   {
      if (tmp == 'Ï' || tmp == 'ï' || c % 4 == 0)
      {
         c++;
         while (tmp != ' ')
            fscanf_s(f, "%c", &tmp);
      }
      else
      {
         fprintf_s(g, "%c", tmp);
      }
   }
   fclose(f);
   fclose(g);
}