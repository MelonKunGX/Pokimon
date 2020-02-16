#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//エンカウントするまでの基準歩数
#define STEPS 10

/* プロトタイプ宣言 */
int Encount(void);
int BattleFadeOut(int);
int BattleFadeIn(void);
int BattleInit(void);
int BattleTop(int, char*);
int BattleEscape(void);
int ToDisplay(int);
int ctoi(char);
/* プロトタイプ宣言 */

char ui[25][101], display[25][101];
struct parts{

  char menu[7][17];
  char message[75];
  char center[17][76];

}part;

int Encount(void){

  int prob;
  FILE *fp;

  srand((unsigned) time(NULL));
  // 確率 = 0～99の乱数生成 ÷ (基準歩数 + エンカウントレベル)
  prob = (rand() % 100) / STEPS;
  prob = 0;

  if(prob == 0)
    return 1;

  else
    return 0;

}

int BattleFadeIn(void){

  int i, j;
  char effect[25][101];

  for(i = 0; i < 25; i++)
    strcpy(effect[i], ui[i]);

  for(i = 0; i < 25; i++)
    for(j = 0; j < 99; j++)
      display[i][j] = ' ';

  for(i = 0; i < 13; i++){

    strcpy(display[12 - i], effect[12 - i]);

    if(i != 13)
    	strcpy(display[13 + i], effect[13 + i]);

    system("cls");

    for(j = 0; j < 25; j++)
      printf("%s", display[j]);

    Sleep(10);

  }

  return 0;

}

int BattleFadeOut(int mode){

  int i, j, k;
  FILE *fp;

  if(mode == 0){

    if((fp = fopen("UI/Bikkuri.txt", "r")) == NULL)
      return -1;

    for(i = 0; i < 25; i++)
      fgets(display[i], 101, fp);

    system("cls");

    for(i = 0; i < 25; i++)
      printf("%s", display[i]);

  }

  Sleep(1000);

  for(i = 0; i < 25; i++){

    for(j = 0; j < 99; j++){

      display[i][j] = ' ';
      display[24 - i][j] = ' ';

    }

    system("cls");

    for(k = 0; k < 25; k++)
      printf("%s", display[k]);

    Sleep(10);

  }

  return 0;

}

int BattleInit(void){

  int i;
  FILE *fp;

  if((fp = fopen("UI/BattleUI.txt", "r")) == NULL)
    return -1;

  for(i = 0; i < 25; i++)
    fgets(ui[i], 101, fp);

  fclose(fp);
  return 0;

}

int BattleTop(int id, char *name){

  int i, in, update = 1, mode = 0;
  char file_name[20];
  FILE *fp;

  strcpy(part.menu[0], " たたかう        ");
  strcpy(part.menu[1], " もちもの        ");
  strcpy(part.menu[2], " にげる          ");

  for(i = 3; i < 7; i++)
    strcpy(part.menu[i], "                 ");

  sprintf(file_name, "AA/%d.txt", id);
  sprintf(part.message, "やせいの%20sがとびだしてきた！                             ", name);

  if((fp = fopen(file_name, "r")) == NULL)
    return -1;

  for(i = 0; i < 17; i++)
    fgets(part.center[i], 80, fp);

  fclose(fp);

  while(1){

    if(update == 1){

      ToDisplay(mode);
      update = 0;

    }

    in = getch();

    if(in == 13){

      if(mode == 1){

        //strcpy()
      }

      if(mode == 2){

        BattleEscape();
        break;

      }
    }

    if(in != 0)
      continue;

    in = getch();

    if(in == 72 && mode > 0){

      mode--;
      update = 1;

    }

    if(in == 80 && mode < 2){

      mode++;
      update = 1;

    }
  }

  return 0;

}

int BattleEscape(void){

  strcpy(part.message, "うまくにげることができた！                                                 ");
  ToDisplay(2);
  getch();

  return 0;

}

int BattleItemSelect(void){

  int i, j, k, num, update;

  for(i = 0; i < 25; i++)
    strcpy(display[i], ui[i]);

  while(1){

    if(update){

      for(i = 0; i < 25; i++){

        for(j = 0; j < 101; j++){

          if(display[i][j] == '%'){

            num = ctoi(display[i][j + 2]);

            switch(ctoi(display[i][j + 1])){

              case 0:

                for(k = 0; k < 17; k++)
                  display[i][j + k] = part.menu[num][k];

                break;
            }
          }
        }
      }
    }
  }
}

int RandomPokimon(void){

  int c, id = 0;
  FILE *fp;

  if((fp = fopen("Data/Pokimons.txt", "r")) == NULL)
    return -1;

  while(1){

  	c = fgetc(fp);

  	if(c == EOF)
  		break;

  	if(c == '\n')
  		id++;

  }

  if(id == 0)
    return -1;

  srand((unsigned) time(NULL));

  return rand() % id;

}

int ToDisplay(int mode){

  int i, j, k, num;

  for(i = 0; i < 25; i++)
    strcpy(display[i], ui[i]);

  for(i = 0; i < 25; i++){

    for(j = 0; j < 99; j++){

      if(display[i][j] == '%'){

        num = ctoi(display[i][j + 2]);

        switch(ctoi(display[i][j + 1])){

          case 0:

            for(k = 0; k < 17; k++)
              display[i][j + k] = part.menu[num][k];

            break;

          case 1:

            for(k = 0; k < 75; k++)
              display[i][j + k] = part.message[k];

            break;

          case 2:

            for(k = 0; k < 75, part.center[num][k] != '\n'; k++)
              display[i][j + k] = part.center[num][k];

            break;

          case 3:

            for(k = 0; k < 75, part.center[10 + num][k] != '\n'; k++)
              display[i][j + k] = part.center[10 + num][k];

            break;

        }
      }
    }
  }

  for(i = 0; i < 7; i++){

    if(i == mode)
      display[2 + i * 3][2] = '>';

    else
      display[2 + i * 3][2] = ' ';

  }

  system("cls");

  for(i = 0; i < 25; i++)
    printf("%s", display[i]);

  return 0;

}

int ctoi(char c){

  switch(c){

    case '0':
      return 0;

    case '1':
      return 1;

    case '2':
      return 2;

    case '3':
      return 3;

    case '4':
      return 4;

    case '5':
      return 5;

    case '6':
      return 6;

    case '7':
      return 7;

    case '8':
      return 8;

    case '9':
      return 9;

    default:
      return -1;

  }
}
