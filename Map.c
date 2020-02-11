#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Player.h"
#include "BattleSystem.h"
#include "Pokimon.h"

char map[25][101];
FILE *map1;

int Key(void);
int PlayerMove(int, int);
int MapFadeIn(char*);
int MapFadeOut(void);

int main(void){

  int i, j, chr, result = 0; //システムに関する変数
  char before[1] = {' '}, file_name[20];

  LoadPlayerData(0);

  sprintf(file_name, "Maps/%s.txt", GetPlayerInMap());

  if((map1 = fopen(file_name, "r")) == NULL){

    printf("【エラー: マップファイルが読み込めませんでした。】");
    return -1;

  }

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

        if(i == GetPlayerY() && j == GetPlayerX()){

          before[0] = map[i][j];
          map[i][j] = 'O';

        }
      }
    }

    for(i = 0; i < 25; i ++)
      printf("%s", map[i]);

    printf("\n\n\n\t\t\t\tO:プレイヤー w:草むら 文：ポキセン ESC:終了\n");

    do{

      result = Key();

    }while(result == 2);
  }

  fclose(map1);
  SavePlayerData();

  return 0;

}

int Key(void){

  int in, result;

  in = getch();

  if(in == 27)
    return 1;

  if(in != 0)
    return 2;

  in = getch();

  switch(in){

    case 72:

      result = PlayerMove(0, -1);

      break;

    case 80:

      result = PlayerMove(0, 1);

      break;

    case 77:

      result = PlayerMove(1, 0);

      break;

    case 75:

      result = PlayerMove(-1, 0);

      break;

    default:

      result = 1;

  }

  if(result == 1)
    return 2;

  return 0;

}

int PlayerMove(int changeX, int changeY){

  switch(map[GetPlayerY() + changeY][GetPlayerX() + changeX]){

    case '=':
    case '|':

      return -1;

    case 'w':

      if(Encount() == 1){

        BattleFadeOut(0);
        BattleFadeIn();
        BattleTop();
        BattleFadeOut(1);
        MapFadeIn(GetPlayerInMap());

      }

      break;

    case 'P':

      MapFadeOut();
      MapFadeIn("pokisen");
      SetPlayerInMap("pokisen");
      SetPlayerX(48);
      SetPlayerY(14);

      return 0;

    case 'E':

      MapFadeOut();
      MapFadeIn("map1");
      SetPlayerInMap("map1");
      SetPlayerX(63);
      SetPlayerY(10);

      return 0;

  }

  SetPlayerX(GetPlayerX() + changeX);
  SetPlayerY(GetPlayerY() + changeY);

  return 0;

}

int MapFadeIn(char *name){

  int i, j;
  char file_name[20], effect[25][101];
  FILE *fp;

  sprintf(file_name, "Maps/%s.txt", name);

  if((fp = fopen(file_name, "r")) == NULL)
    return -1;

  for(i = 0; i < 25; i++)
    fgets(effect[i], 101, fp);

  for(i = 0; i < 25; i++)
    for(j = 0; j < 101; j++)
      map[i][j] = ' ';

  for(i = 0; i < 25; i++){

    strcpy(map[12 - i], effect[12 - i]);
    strcpy(map[13 + i], effect[13 + i]);
    system("cls");

    for(j = 0; j < 25; j++)
      printf("%s", map[j]);

    Sleep(10);

  }

  return 0;

}

int MapFadeOut(void){

  int i, j;

  for(i = 0; i < 25; i++){

    system("cls");

    for(j = 0; j < 99; j++){

      map[i][j] = ' ';
      map[24 - i][j] = ' ';

    }

    for(j = 0; j < 25; j++)
      printf("%s", map[j]);

    Sleep(10);

  }

  return 0;

}
