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
int BattleTop(int, char*);
int BattleEscape(int);
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

  int i, j, k;
  char effect[25][101];
  FILE *fp;

  if((fp = fopen("UI/BattleUI.txt", "r")) == NULL)
    return -1;

  for(i = 0; i < 25; i++)
    fgets(effect[i], 101, fp);

  for(i = 0; i < 25; i++)
    for(j = 0; j < 101; j++)
      display[i][j] = ' ';

  for(i = 0; i < 13; i++){

    strcpy(display[12 - i], effect[12 - i]);

    if(i != 13)
    	strcpy(display[13 + i], effect[13 + i]);

    system("cls");

    for(k = 0; k < 25; k++)
      printf("%s", display[k]);

    Sleep(10);

  }

  for(i = 0; i < 25; i++)
    strcpy(ui[i], display[i]);

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

    system("cls");

    for(j = 0; j < 99; j++){

      display[i][j] = ' ';
      display[24 - i][j] = ' ';

    }

    for(k = 0; k < 25; k++)
      printf("%s", display[k]);

    Sleep(10);

  }

  return 0;

}

int BattleTop(int id, char *name){

  int i, j, k, in, num, update = 1, mode = 0;
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

  while(1){

    if(update == 1){

      for(i = 0; i < 25; i++){

        for(j = 0; j < 101; j++){

          if(display[i][j] == '%'){

          	if(ctoi(display[i][j + 1]) == 0){

          		num = ctoi(display[i][j + 2]);

          		for(k = 0; k < 17; k++)
          			display[i][j + k] = part.menu[num][k];

          	}

          	if(ctoi(display[i][j + 1]) == 1){

          		for(k = 0; k < 75; k++)
          			display[i][j + k] = part.message[k];

          	}

          	if(ctoi(display[i][j + 1]) == 2){

          		num = ctoi(display[i][j + 2]);

          		for(k = 0; k < 75, part.center[num][k] != '\n'; k++)
          			display[i][j + k] = part.center[num][k];

          	}

          	if(ctoi(display[i][j + 1]) == 3){

          		num = ctoi(display[i][j + 2]);

          		for(k = 0; k < 75, part.center[10 + num][k] != '\n'; k++)
          			display[i][j + k] = part.center[10 + num][k];

          	}
          }
        }
      }

      display[2][2] = ' ';
      display[5][2] = ' ';
      display[8][2] = ' ';

      switch(mode){

        case 0:
          display[2][2] = '>';
          break;

        case 1:
          display[5][2] = '>';
          break;

        case 2:
          display[8][2] = '>';
          break;

      }

      system("cls");

      for(i = 0; i < 25; i++)
        printf("%s", display[i]);

      update = 0;

    }

    in = getch();

    if(in == 13){

      if(mode == 1){

        //strcpy()
      }

      if(mode == 2){

        BattleEscape(id);
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

int BattleEscape(int id){

  int i, j, k, in, num;
  char menu[7][17] = {
    " たたかう        ",
    " もちもの        ",
    " にげる          ",
    "                 ",
    "                 ",
    "                 ",
    "                 "
  }, message[75] = "うまくにげきることができた！                                               ",
  center[17][76], file_name[20];
  FILE *fp;

  sprintf(file_name, "AA/%d.txt", id);

  if((fp = fopen(file_name, "r")) == NULL)
    return -1;

  for(i = 0; i < 17; i++)
    fgets(center[i], 80, fp);

  for(i = 0; i < 25; i++)
    strcpy(display[i], ui[i]);

  system("cls");

  for(i = 0; i < 25; i++){

    for(j = 0; j < 101; j++){

      if(display[i][j] == '%'){

        if(ctoi(display[i][j + 1]) == 0){

          num = ctoi(display[i][j + 2]);

          for(k = 0; k < 17; k++){

            display[i][j + k] = menu[num][k];

          }
        }

        if(ctoi(display[i][j + 1]) == 1){

          for(k = 0; k < 75; k++)
            display[i][j + k] = message[k];

        }

        if(ctoi(display[i][j + 1]) == 2){

          num = ctoi(display[i][j + 2]);

          for(k = 0; k < 75, center[num][k] != '\n'; k++)
              display[i][j + k] = center[num][k];

        }

        if(ctoi(display[i][j + 1]) == 3){

          num = ctoi(display[i][j + 2]);

          for(k = 0; k < 75, center[10 + num][k] != '\n'; k++)
              display[i][j + k] = center[10 + num][k];

        }
      }
    }
  }

  for(i = 0; i < 25; i++)
    printf("%s", display[i]);

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
