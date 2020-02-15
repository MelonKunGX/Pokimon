#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PokimonCount 3

char *GetDefaultPokimonName(int);

struct status{

  int id;
  char name[20];
  int type;
  int atk;
  int def;
  int hp;
  int sp;

}pokimon[PokimonCount];

int Pokimon_IsLoaded = 0;

/*
* 返り値
* -1: ファイルがーオープンできない。
* -2: 既存のポキモンと名前が重複している。
*/
int CreatePokimon(int id, char *name, int type, int atk, int def, int hp, int sp){

  int i = 0, result;
  char find_name[20];
  FILE *fp;

  if((fp = fopen("Data/Pokimons.txt", "r+")) == NULL)
    return -1;

  while(1){

    fseek(fp, i * 52L, SEEK_SET);

    if(fscanf(fp, "%*5d%20s", find_name) == EOF)
      break;

    if(strcmp(find_name, name) == 0)
      return -2;

    i++;

  }

  fprintf(fp, "%5d%20s%5d%5d%5d%5d%5d\n", id, name, type, atk, def, hp, sp);
  fclose(fp);
  return 0;

}

char *GetDefaultPokimonName(int id){

  return pokimon[id].name;

}

int LoadPokimons(void){

  int i;
  FILE *fp;

  if((fp = fopen("Data/Pokimons.txt", "r")) == NULL)
    return -1;

  for(i = 0; i < PokimonCount; i++){

    fseek(fp, i * 52L, SEEK_SET);
    fscanf(fp, "%5d%20s%5d%5d%5d%5d%5d",
      &pokimon[i].id, pokimon[i].name, &pokimon[i].type, &pokimon[i].atk, &pokimon[i].def, &pokimon[i].hp, &pokimon[i].sp
    );

  }

  fclose(fp);
  return 0;

}
