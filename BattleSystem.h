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
int BattleTop(void);
int BattleEscape(void);
int ctoi(char);
/* プロトタイプ宣言 */

float enc_lv = 0.0;
char ui[25][101], display[25][101];

int Encount(void){

  int prob;

  srand((unsigned) time(NULL));
  // 確率 = 0~99の乱数生成 ÷ (基準歩数 + エンカウントレベル)
  prob = (rand() % 100) / STEPS;
  prob = 0;

  if(prob == 0){

    //enc_lv = 0;
    return 1;

  }else{

    //enc_lv += 0.5;
    return 0;

  }
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

int BattleTop(void){

  int i, j, k, in, num, update = 1, mode = 0;
  char menu[7][17] = {
			" たたかう        ",
   		" もちもの        ",
    	" にげる          ",
    	"                 ",
			"                 ",
			"                 ",
			"                 "
  	},
  	message[75] = "やせいのポキモンがとびだしてきた！                                         ",
  	center[16][75] = {
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           ",
  		"                                                                           "
  	};

  while(1){

    if(update == 1){

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

          		for(k = 0; k < 75; k++)
          			display[i][j + k] = center[num][k];

          	}

          	if(ctoi(display[i][j + 1]) == 3){

          		num = ctoi(display[i][j + 2]);

          		for(k = 0; k < 75; k++)
          			display[i][j + k] = center[num][k];

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

  int i, j, k, in, num;
  char menu[7][17] = {
    " たたかう        ",
    " もちもの        ",
    " にげる          ",
    "                 ",
    "                 ",
    "                 ",
    "                 "
  }, message[75] = "うまくにげきることができた！                                               ";

  system("cls");

  for(i = 0; i < 25; i++){

    for(j = 0; j < 101; j++){

      if(ui[i][j] == '%'){

        switch(ctoi(ui[i][j + 1])){

          case 0:

            for(k = 0; k < 17; k++)
              display[i][j + k] = menu[ctoi(ui[i][j + 2])][k];

            break;

          case 1:

            for(k = 0; k < 75; k++)
              display[i][j + k] = message[k];

            break;

          case 2:
          case 3:

            for(k = 0; k < 3; k++)
              display[i][j + k] = '   ';

            break;

        }
      }
    }
  }

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
