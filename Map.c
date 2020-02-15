#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "Player.h"
#include "BattleSystem.h"
#include "Pokimon.h"

char map[25][101];

int Key(void);
int PlayerMove(int, int);
int MapFadeIn(char*);
int MapFadeOut(void);

int main(void){

  int i, j, chr, result;
  char before[1] = {' '}, file_name[20];
  FILE *fp;

	system("mode 100,30");
  LoadPlayerData(0);

  if(LoadPokimons() == -1){

    printf("【エラー: ポキモンが読み込めませんでした。】\n");
    return -1;

  }

  if(strstr(GetPlayerInMap(), "pokisen") != NULL)
    strcpy(file_name, "Maps/pokisen.txt");

  else
    sprintf(file_name, "Maps/%s.txt", GetPlayerInMap());

  if((fp = fopen(file_name, "r")) == NULL){

    printf("【エラー: マップファイルが読み込めませんでした。】\n");
    return -1;

  }

  for(i = 0; i < 25; i ++)
    fgets(map[i], 102, fp);

  fclose(fp);

  while(1){

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

    if(strcmp(GetPlayerInMap(), "pokisen") == 0){

      printf("\n\n\t\t\t\t【操作】↑→↓←:移動 ESC:メニュー");
      printf("\n\t\t【マップの記号】O:プレイヤー C:カウンター E:出口 ESC:メニュー");

    }else{

      printf("\n\n\t\t\t【操作】↑→↓←:移動 ESC:メニュー");
      printf("\n   【マップの記号】O:プレイヤー w:草むら P：ポキセン <:前のマップへ >:次のマップへ ESC:メニュー\n");

    }

    do{

      result = Key();

    }while(result == 2);

    if(result == 1)
      break;

  }

  SavePlayerData(1);
  system("cls");
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

      return 2;

  }

  if(result == -1)
    return 2;

  return 0;

}

int PlayerMove(int changeX, int changeY){

  int i, in, mode, id;
  static char before_map[20], pokisen_num[20];

  switch(map[GetPlayerY() + changeY][GetPlayerX() + changeX]){

    case '=':
    case '|':

      return -1;

    case '>':

      MapFadeOut();

      if(strcmp(GetPlayerInMap(), "map1") == 0){

        MapFadeIn("map2");
        SetPlayerInMap("map2");
        SetPlayerX(5);
        SetPlayerY(2);
        return 0;

      }

      if(strcmp(GetPlayerInMap(), "map2") == 0){

        MapFadeIn("map3");
        SetPlayerInMap("map3");
        SetPlayerX(5);
        SetPlayerY(23);
        return 0;

      }

    case '<':

      MapFadeOut();

      if(strcmp(GetPlayerInMap(), "map2") == 0){

        MapFadeIn("map1");
        SetPlayerInMap("map1");
        SetPlayerX(95);
        SetPlayerY(23);
        return 0;

      }

      if(strcmp(GetPlayerInMap(), "map3") == 0){

        MapFadeIn("map2");
        SetPlayerInMap("map2");
        SetPlayerX(95);
        SetPlayerY(22);
        return 0;

      }

    case 'w':

      if(Encount() == 1){

        id = RandomPokimon();

        BattleFadeOut(0);
        BattleFadeIn();
        BattleTop(id, GetDefaultPokimonName(id));
        BattleFadeOut(1);
        MapFadeIn(GetPlayerInMap());

      }

      break;

    case 'P':

      strcpy(before_map, GetPlayerInMap());
      MapFadeOut();
      MapFadeIn("pokisen");
      sprintf(pokisen_num, "pokisen%c", GetPlayerInMap()[3]);
      SetPlayerInMap(pokisen_num);
      SetPlayerX(48);
      SetPlayerY(14);

      return 0;

    case 'E':

      MapFadeOut();
      sprintf(pokisen_num, "map%c", GetPlayerInMap()[7]);
      MapFadeIn(pokisen_num);
      SetPlayerInMap(pokisen_num);

      switch(GetPlayerInMap()[7]){

        case '1':
          SetPlayerX(63);
          SetPlayerY(10);
          break;

        case '2':
          SetPlayerX(80);
          SetPlayerY(5);
          break;

        case '3':
          SetPlayerX(57);
          SetPlayerY(9);
          break;

      }

      return 0;

    case 'C':

      mode = 0;

      while(1){

        system("cls");

        for(i = 0; i < 25; i++)
          printf("%s", map[i]);

        printf("\n\n\t\t\t\t手持ちのポキモンを回復させますか？\n");

        if(mode == 0)
          printf("\t\t\t\t\t>はい\t\t いいえ");

        if(mode == 1)
          printf("\t\t\t\t\t はい\t\t>いいえ");

        in = getch();

        if(in == 13){

          if(mode == 0){

            for(i = 0; i < 6; i++){

              if(GetPokimonId(i) != -1)
                SetPokimonHp(i, GetPokimonMaxHp(i));

              MapFadeOut();
              MapFadeIn("pokisen");
              printf("\n\n\n\t\t\t\tポキモンたちが元気になりました！ 【Enter】");
              while(getch() != 13);
              return 0;

            }
          }

          if(mode == 1)
            return 0;
        }

        if(in != 0)
          continue;

        in = getch();

        if(in == 77)
          if(mode < 1)
            mode++;

        if(in == 75)
          if(mode > 0)
            mode--;

      }
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

  for(i = 0; i < 13; i++){

    strcpy(map[12 - i], effect[12 - i]);

    if(i != 12)
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
