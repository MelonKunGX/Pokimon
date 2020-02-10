#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Player.h"
#include "BattleSystem.h"
#include "Pokimon.h"

int x, y; //プレイヤー座標
char map[25][101];
FILE *map1;

int key(void);
int playerMove(int, int);

int main(void){

  int i, j, chr, result = 0; //システムに関する変数
  char before[1] = {' '};

  if((map1 = fopen("Maps/Map1.txt", "r")) == NULL){

    printf("【エラー: マップファイルが読み込めませんでした。】");
    return -1;

  }

  x = 1;
  y = 1;

  for(i = 0; i < 25; i ++)
    fgets(map[i], 102, map1);

  while(result != 1){

    system("cls");

    for(i = 0; i < 25; i ++)
      for(j = 0; j < 100; j ++)
        if(map[i][j] == 'O')
          map[i][j] = before[0];

    for(i = 0; i < 25; i ++){

      for(j = 0; j < 100; j ++){

        if(i == y && j == x){

          before[0] = map[i][j];
          map[i][j] = 'O';

        }
      }
    }

    for(i = 0; i < 25; i ++)
      printf("%s", map[i]);

    printf("\n\n\n\t\t\t\tO:プレイヤー w:草むら 文：ポキセン ESC:終了\n");

    do{

      result = key();

    }while(result == 2);
  }

  fclose(map1);
  SavePlayerData();

  return 0;

}

int key(void){

  int in, result;

  in = getch();

  if(in == 27)
    return 1;

  if(in != 0)
    return 2;

  in = getch();

  switch(in){

    case 72:

      result = playerMove(0, -1);

      break;

    case 80:

      result = playerMove(0, 1);

      break;

    case 77:

      result = playerMove(1, 0);

      break;

    case 75:

      result = playerMove(-1, 0);

      break;

    default:

      result = 1;

  }

  if(result == 1)
    return 2;

  return 0;

}

int playerMove(int changeX, int changeY){

  switch(map[y + changeY][x + changeX]){

    case '=':
    case '|':

      return 1;

    case 'w':

      if(Encount() == 1){

        BattleFadeOut(0);
        BattleFadeIn(0);
        BattleTop();

      }

      break;

  }

  x += changeX;
  y += changeY;

  SetPlayerX(x);
  SetPlayerY(y);

  return 0;

}
