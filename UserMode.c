#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "..\loginfeatuer\login.h"
#include "..\adminmode\Admin.h"

// App Code
void App(void)
{
  int pwd[3];
  char uName[50];
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  /* Save current attributes */
  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  saved_attributes = consoleInfo.wAttributes;

  SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
  printf(__DATE__ "\t***");
  printf("\t"__TIME__
         "\n");

  /* Restore original attributes */
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
  _uint8 Mode;
  char *Esc;
  _uint8 Id;
  char ch;
  int sel;
  do
  {

    do
    {
      printf("1->User\n");
      printf("2->Admin\n");
      scanf("%u", &Mode);

      switch (Mode)
      {
      case 1:
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

        printf(__DATE__ "*****USER MODE*****"__TIME__
                        "\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("\nSelect Following  Featuer\n1.View patientrecord:\n2. View today's reservations\n");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
          printPatientRecordWithId();

          break;
        case 2:
          printPatientReservedToday();
          break;
        default:
          break;
        }
        break;
      case 2:

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);

        printf(__DATE__ "*****ADMIN MODE*****"__TIME__
                        "\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("Username: ");
        fflush(stdin);
        gets(uName);

        for (int i = 0; i < 3; ++i)
        {
          printf("Password[%d] : ", i);
          fflush(stdin);
          scanf("%d", &pwd[i]);
        }
        if (1234 == pwd[0] && pwd[0] == pwd[1] && pwd[0] == pwd[2])
        {
          adminFeatuers();
        }
        else
        {
          printf("\nWrong in password or Username\ncheck and Try again\n");
          exit(0);
        }
        break;
      default:
        break;
      }

      printf("Change Mode (Y/N)\nPress Any Key To Out\n");
      fflush(stdin);
      scanf("%c", &ch);

    } while ((ch == 'Y' || ch == 'y'||ch == 'N' || ch == 'n'));
    printf("Write Exit to escape from the Program\n");
    scanf("%s", &Esc);

  } while (Esc == "Exit" || Esc == "exit");
  system("exit");
  system("cls");


}
