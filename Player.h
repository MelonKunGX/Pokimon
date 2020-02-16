#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pokimon.h"

static int IsLoaded = 0;

static struct pokimons{
  int id;
  char name[20];
  int atk;
  int def;
  int max_hp;
  int hp;
  int sp;
};

static struct items{
  int id;
  char name[20];
  int count;
};

static struct players{
  int id;
  char name[20];
  int x;
  int y;
  char map[20];
  struct pokimons pokimon[6];
  struct items item[2];
}player;

/* プロトタイプ宣言 */
int CreatePlayerData(char*);
int GetItemCount(int);
int GetPlayerId(void);
char *GetPlayerName(void);
int GetPlayerX(void);
int GetPlayerY(void);
char *GetPlayerInMap(void);
int GetPokimonId(int);
char *GetPokimonName(int);
int GetPokimonAtk(int);
int GetPokimonDef(int);
int GetPokimonMaxHp(int);
int GetPokimonHp(int);
int GetPokimonSp(int);
int LoadPlayerData(int);
int PrintPlayerData(void);
int SavePlayerData(int);
int SetItemCount(int, int);
int SetPlayerId(int);
int SetPlayerName(char*);
int SetPlayerX(int);
int SetPlayerY(int);
int SetPlayerInMap(char*);
int SetPokimonId(int, int);
int SetPokimonName(int, char*);
int SetPokimonAtk(int, int);
int SetPokimonDef(int, int);
int SetPokimonMaxHp(int, int);
int SetPokimonHp(int, int);
int SetPokimonSp(int, int);
/* プロトタイプ宣言 */

int AddPokimon(int id, char *name){

  int i;

  if(id > PokimonCount)
    return -1;

  for(i = 0; i < 6, strcmp(player.pokimon[i].name, "null") != 0; i++);

  player.pokimon[i].id = id;
  strcpy(player.pokimon[i].name, name);
  player.pokimon[i].atk = defpokimon[id].atk;
  player.pokimon[i].def = defpokimon[id].def;
  player.pokimon[i].max_hp = defpokimon[id].hp;
  player.pokimon[i].hp = defpokimon[id].hp;
  player.pokimon[i].sp = defpokimon[id].sp;

  return 0;

}

int CreatePlayerData(char *name){

  int result, i = 0;
  char find_name[20];
  FILE *fp;

  if((fp = fopen("Data/players.txt", "r")) == NULL)
    return -1;

  while(1){

    fseek(fp, i * 367L, SEEK_SET);

    if(fscanf(fp, "%*5d%20s", find_name) == EOF)
			break;

    if(strcmp(name, find_name) == 0)
    	return -1;

    i++;

  }

  fclose(fp);

  player.id = i;
  strcpy(player.name, name);
  player.x = 1;
  player.y = 1;
  strcpy(player.map, "map1");

  for(i = 0; i < 6; i ++){

    player.pokimon[i].id = -1;
    strcpy(player.pokimon[i].name, "null");
    player.pokimon[i].atk = -1;
    player.pokimon[i].def = -1;
    player.pokimon[i].max_hp = -1;
    player.pokimon[i].hp = -1;
    player.pokimon[i].sp = -1;

  }

  player.item[0].id = 0;
  strcpy(player.item[0].name, "きずぐすり");
  player.item[0].count = 0;
  player.item[1].id = 1;
  strcpy(player.item[1].name, "ポキモンボール");
  player.item[1].count = 0;

  IsLoaded = 1;

  if(SavePlayerData(0) == -1)
    return -1;

  return 0;

}

int GetItemCount(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 2)
      return player.item[index].count;

  return -1;

}

int GetPlayerId(void){

  if(IsLoaded)
    return player.id;

  return -1;

}

char *GetPlayerName(void){

  if(IsLoaded)
    return player.name;

  return "-1";

}

int GetPlayerX(void){

  if(IsLoaded)
    return player.x;

  return -1;

}

int GetPlayerY(void){

  if(IsLoaded)
    return player.y;

  return -1;

}

char *GetPlayerInMap(void){

  if(IsLoaded)
    return player.map;

  return "-1";

}

int GetPokimonId(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].id;

  return -1;

}

char *GetPokimonName(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].name;

  return "-1";

}

int GetPokimonAtk(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].atk;

  return -1;

}

int GetPokimonDef(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].def;

  return -1;

}

int GetPokimonMaxHp(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].max_hp;

  return -1;

}

int GetPokimonHp(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].hp;

  return -1;

}

int GetPokimonSp(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].sp;

  return -1;

}

int LoadPlayerData(int id){

  FILE *fp;

  if((fp = fopen("Data/players.txt", "r")) == NULL)
    return -1;

  fseek(fp, id * 367L, SEEK_SET);

  if(fscanf(fp, "%5d%20s%5d%5d%20s%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%5d",
    &player.id, player.name, &player.x, &player.y, player.map,
    &player.pokimon[0].id, player.pokimon[0].name, &player.pokimon[0].atk, &player.pokimon[0].def, &player.pokimon[0].max_hp, &player.pokimon[0].hp, &player.pokimon[0].sp,
    &player.pokimon[1].id, player.pokimon[1].name, &player.pokimon[1].atk, &player.pokimon[1].def, &player.pokimon[1].max_hp, &player.pokimon[1].hp, &player.pokimon[1].sp,
    &player.pokimon[2].id, player.pokimon[2].name, &player.pokimon[2].atk, &player.pokimon[2].def, &player.pokimon[2].max_hp, &player.pokimon[2].hp, &player.pokimon[2].sp,
    &player.pokimon[3].id, player.pokimon[3].name, &player.pokimon[3].atk, &player.pokimon[3].def, &player.pokimon[3].max_hp, &player.pokimon[3].hp, &player.pokimon[3].sp,
    &player.pokimon[0].id, player.pokimon[4].name, &player.pokimon[4].atk, &player.pokimon[4].def, &player.pokimon[4].max_hp, &player.pokimon[4].hp, &player.pokimon[4].sp,
    &player.pokimon[0].id, player.pokimon[5].name, &player.pokimon[5].atk, &player.pokimon[5].def, &player.pokimon[5].max_hp, &player.pokimon[5].hp, &player.pokimon[5].sp,
    &player.item[0].count, &player.item[1].count
  ) != EOF){

    player.item[0].id = 0;
    strcpy(player.item[0].name, "きずぐすり");
    player.item[1].id = 1;
    strcpy(player.item[1].name, "ポキモンボール");

    IsLoaded = 1;
    fclose(fp);
    return 0;

  }

  fclose(fp);
  return -1;

}

int PrintPlayerData(void){

  int i;

  if(!IsLoaded)
    return -1;

  printf("ID: %d\n", player.id);
  printf("名前: %s\n", player.name);
  printf("X座標: %d\n", player.x);
  printf("Y座標: %d\n", player.y);
  printf("マップ: %s\n", player.map);

  for(i = 0; i < 6; i ++){

    printf("ポキモン%d:\n", i + 1);
    printf("\tID: %d\n", player.pokimon[i].id);
    printf("\t名前: %s\n", player.pokimon[i].name);
    printf("\t攻撃力: %d\n", player.pokimon[i].atk);
    printf("\t防御力: %d\n", player.pokimon[i].def);
    printf("\t最大体力: %d\n", player.pokimon[i].max_hp);
    printf("\t体力: %d\n", player.pokimon[i].hp);
    printf("\tすばやさ: %d\n", player.pokimon[i].sp);

  }

  for(i = 0; i < 2; i++){

    printf("アイテム%d:\n", i + 1);
    printf("\tID: %d\n", player.item[i].id);
    printf("\t名前: %s\n", player.item[i].name);
    printf("\t個数: %d\n", player.item[i].count);

  }

  return 0;

}

int SavePlayerData(int mode){

  FILE *fp;

  if(!IsLoaded)
    return -1;

  if(mode == 0){

    if((fp = fopen("Data/players.txt", "a")) == NULL)
      return -1;

    fseek(fp, player.id * 367L, SEEK_END);

  }


  if(mode == 1){

    if((fp = fopen("Data/players.txt", "r+")) == NULL)
      return -1;

    fseek(fp, player.id * 367L, SEEK_SET);

  }

  fprintf(fp, "%5d%20s%5d%5d%20s%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%5d\n",
    player.id, player.name, player.x, player.y, player.map,
    player.pokimon[0].id, player.pokimon[0].name, player.pokimon[0].atk, player.pokimon[0].def, player.pokimon[0].max_hp, player.pokimon[0].hp, player.pokimon[0].sp,
    player.pokimon[1].id, player.pokimon[1].name, player.pokimon[1].atk, player.pokimon[1].def, player.pokimon[1].max_hp, player.pokimon[1].hp, player.pokimon[1].sp,
    player.pokimon[2].id, player.pokimon[2].name, player.pokimon[2].atk, player.pokimon[2].def, player.pokimon[2].max_hp, player.pokimon[2].hp, player.pokimon[2].sp,
    player.pokimon[3].id, player.pokimon[3].name, player.pokimon[3].atk, player.pokimon[3].def, player.pokimon[3].max_hp, player.pokimon[3].hp, player.pokimon[3].sp,
    player.pokimon[0].id, player.pokimon[4].name, player.pokimon[4].atk, player.pokimon[4].def, player.pokimon[4].max_hp, player.pokimon[4].hp, player.pokimon[4].sp,
    player.pokimon[0].id, player.pokimon[5].name, player.pokimon[5].atk, player.pokimon[5].def, player.pokimon[5].max_hp, player.pokimon[5].hp, player.pokimon[5].sp,
    player.item[0].count, player.item[1].count
  );
  fclose(fp);
  return 0;

}

int SetItemCount(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 2){

      player.item[index].count = value;
      return 0;

    }
  }

  return -1;

}

int SetPlayerId(int value){

  if(IsLoaded){

    player.id = value;
    return 0;

  }

  return -1;

}

int SetPlayerName(char *value){

  if(IsLoaded){

    strcpy(player.name, value);
    return 0;

  }

  return -1;

}

int SetPlayerX(int value){

  if(IsLoaded){

    player.x = value;
    return 0;

  }

  return -1;

}

int SetPlayerY(int value){

  if(IsLoaded){

    player.y = value;
    return 0;

  }

  return -1;

}

int SetPlayerInMap(char *value){

  if(IsLoaded){

    strcpy(player.map, value);
    return 0;

  }

  return -1;

}

int SetPokimonId(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].id = value;
      return 0;

    }
  }

  return -1;

}

int SetPokimonName(int index, char *value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      strcpy(player.pokimon[index].name, value);
      return 0;

    }
  }

  return -1;

}

int SetPokimonAtk(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].atk = value;
      return 0;

    }
  }

  return -1;

}

int SetPokimonDef(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].def = value;
      return 0;

    }
  }

  return -1;

}

int SetPokimonMaxHp(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].max_hp = value;
      return 0;

    }
  }

  return -1;

}

int SetPokimonHp(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].hp = value;
      return 0;

    }
  }

  return -1;

}

int SetPokimonSp(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].sp = value;
      return 0;

    }
  }

  return -1;

}

#endif
