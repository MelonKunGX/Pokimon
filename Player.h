#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 0
#define FAILED -1

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

static struct players{
  int id;
  char name[20];
  int x;
  int y;
  char map[20];
  struct pokimons pokimon[6];
}player;

/* プロトタイプ宣言 */
int CreatePlayerData(char*);
int GetPlayerId(void);
char *GetPlayerName(void);
int GetPlayerX(void);
int GetPlayerY(void);
char *GetPlayerInMap(void);
int GetPokimonId(int);
char GetPokimonName(int);
int GetPokimonAtk(int);
int GetPokimonDef(int);
int GetPokimonMaxHp(int);
int GetPokimonHp(int);
int GetPokimonSp(int);
int LoadPlayerData(int);
int PrintPlayerData(void);
int SavePlayerData(void);
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

int CreatePlayerData(char *name){

  int result, i = 0;
  char find_name[20], dummy[1];
  FILE *fp;

  if((fp = fopen("Data/players.txt", "r")) == NULL)
    return FAILED;

  while(1){

    fseek(fp, i * 320L, SEEK_SET);

    if(fscanf(fp, "%*5d%20s%*331c", find_name) == EOF)
			break;

    if(strcmp(name, find_name) == 0)
    	return FAILED;

  }

  while(fgets(dummy, 1, fp) != NULL)
    i++;

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

  IsLoaded = 1;

  if(SavePlayerData() == FAILED)
    return FAILED;

  return SUCCESS;

}

int GetPlayerId(void){

  if(IsLoaded)
    return player.id;

  return FAILED;

}

char *GetPlayerName(void){

  if(IsLoaded)
    return player.name;

  return "FAILED";

}

int GetPlayerX(void){

  if(IsLoaded)
    return player.x;

  return FAILED;

}

int GetPlayerY(void){

  if(IsLoaded)
    return player.y;

  return FAILED;

}

char *GetPlayerInMap(void){

  if(IsLoaded)
    return player.map;

  return "FAILED";

}

int GetPokimonId(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].id;

  return FAILED;

}

char GetPokimonName(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return *player.pokimon[index].name;

  return FAILED;

}

int GetPokimonAtk(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].atk;

  return FAILED;

}

int GetPokimonDef(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].def;

  return FAILED;

}

int GetPokimonMaxHp(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].max_hp;

  return FAILED;

}

int GetPokimonHp(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].hp;

  return FAILED;

}

int GetPokimonSp(int index){

  if(IsLoaded)
    if(index >= 0 && index <= 5)
      return player.pokimon[index].sp;

  return FAILED;

}

int LoadPlayerData(int id){

  FILE *fp;

  if((fp = fopen("Data/players.txt", "r")) == NULL)
    return FAILED;

  fseek(fp, id * 320L, SEEK_SET);

  if(fscanf(fp, "%5d%20s%5d%5d%20s%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d",
    &player.id, player.name, &player.x, &player.y, player.map,
    &player.pokimon[0].id, player.pokimon[0].name, &player.pokimon[0].atk, &player.pokimon[0].def, &player.pokimon[0].max_hp, &player.pokimon[0].hp, &player.pokimon[0].sp,
    &player.pokimon[1].id, player.pokimon[1].name, &player.pokimon[1].atk, &player.pokimon[1].def, &player.pokimon[1].max_hp, &player.pokimon[1].hp, &player.pokimon[1].sp,
    &player.pokimon[2].id, player.pokimon[2].name, &player.pokimon[2].atk, &player.pokimon[2].def, &player.pokimon[2].max_hp, &player.pokimon[2].hp, &player.pokimon[2].sp,
    &player.pokimon[3].id, player.pokimon[3].name, &player.pokimon[3].atk, &player.pokimon[3].def, &player.pokimon[3].max_hp, &player.pokimon[3].hp, &player.pokimon[3].sp,
    &player.pokimon[0].id, player.pokimon[4].name, &player.pokimon[4].atk, &player.pokimon[4].def, &player.pokimon[4].max_hp, &player.pokimon[4].hp, &player.pokimon[4].sp,
    &player.pokimon[0].id, player.pokimon[5].name, &player.pokimon[5].atk, &player.pokimon[5].def, &player.pokimon[5].max_hp, &player.pokimon[5].hp, &player.pokimon[5].sp
  ) != EOF){

    IsLoaded = 1;
    fclose(fp);
    return SUCCESS;

  }

  fclose(fp);
  return FAILED;

}

int PrintPlayerData(void){

  int i;

  if(!IsLoaded)
    return FAILED;

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

  return SUCCESS;

}

int SavePlayerData(void){

  FILE *fp;

  if(!IsLoaded)
    return FAILED;

  if((fp = fopen("Data/players.txt", "r+")) == NULL)
    return FAILED;

  fseek(fp, player.id * 320L, SEEK_SET);

  fprintf(fp, "%5d%20s%5d%5d%20s%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d%5d%20s%5d%5d%5d%5d%5d",
    player.id, player.name, player.x, player.y, player.map,
    player.pokimon[0].id, player.pokimon[0].name, player.pokimon[0].atk, player.pokimon[0].def, player.pokimon[0].max_hp, player.pokimon[0].hp, player.pokimon[0].sp,
    player.pokimon[1].id, player.pokimon[1].name, player.pokimon[1].atk, player.pokimon[1].def, player.pokimon[1].max_hp, player.pokimon[1].hp, player.pokimon[1].sp,
    player.pokimon[2].id, player.pokimon[2].name, player.pokimon[2].atk, player.pokimon[2].def, player.pokimon[2].max_hp, player.pokimon[2].hp, player.pokimon[2].sp,
    player.pokimon[3].id, player.pokimon[3].name, player.pokimon[3].atk, player.pokimon[3].def, player.pokimon[3].max_hp, player.pokimon[3].hp, player.pokimon[3].sp,
    player.pokimon[0].id, player.pokimon[4].name, player.pokimon[4].atk, player.pokimon[4].def, player.pokimon[4].max_hp, player.pokimon[4].hp, player.pokimon[4].sp,
    player.pokimon[0].id, player.pokimon[5].name, player.pokimon[5].atk, player.pokimon[5].def, player.pokimon[5].max_hp, player.pokimon[5].hp, player.pokimon[5].sp
  );
  fclose(fp);
  return SUCCESS;

}

int SetPlayerId(int value){

  if(IsLoaded){

    player.id = value;
    return SUCCESS;

  }

  return FAILED;

}

int SetPlayerName(char *value){

  if(IsLoaded){

    strcpy(player.name, value);
    return SUCCESS;

  }

  return FAILED;

}

int SetPlayerX(int value){

  if(IsLoaded){

    player.x = value;
    return SUCCESS;

  }

  return FAILED;

}

int SetPlayerY(int value){

  if(IsLoaded){

    player.y = value;
    return SUCCESS;

  }

  return FAILED;

}

int SetPlayerInMap(char *value){

  if(IsLoaded){

    strcpy(player.map, value);
    return SUCCESS;

  }

  return FAILED;

}

int SetPokimonId(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].id = value;
      return SUCCESS;

    }
  }

  return FAILED;

}

int SetPokimonName(int index, char *value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      strcpy(player.pokimon[index].name, value);
      return SUCCESS;

    }
  }

  return FAILED;

}

int SetPokimonAtk(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].atk = value;
      return SUCCESS;

    }
  }

  return FAILED;

}

int SetPokimonDef(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].def = value;
      return SUCCESS;

    }
  }

  return FAILED;

}

int SetPokimonMaxHp(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].max_hp = value;
      return SUCCESS;

    }
  }

  return FAILED;

}

int SetPokimonHp(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].hp = value;
      return SUCCESS;

    }
  }

  return FAILED;

}

int SetPokimonSp(int index, int value){

  if(IsLoaded){

    if(index >= 0 && index <= 5){

      player.pokimon[index].sp = value;
      return SUCCESS;

    }
  }

  return FAILED;

}
