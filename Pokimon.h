#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct status{

  int id;
  char name[20];
  int type;
  int atk;
  int def;
  int hp;
  int sp;

}pokimon;

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

    fseek(fp, i * 50L, SEEK_SET);

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

/*
* 返り値
* -1: ファイルがーオープンできない。
* -2: 指定したIDが見つからない。
*/
int LoadPokimon(int id){

  int i = 0, find_id;
  FILE *fp;

  if((fp = fopen("Data/Pokimons.txt", "r")) == NULL)
    return -1;

  while(1){

    fseek(fp, i * 50L, SEEK_SET);

    if(fscanf(fp, "%5d", &find_id) == EOF)
      return -2;

    if(find_id == id){

      fscanf(fp, "%5d%20s%5d%5d%5d%5d%5d",
        &pokimon.id, pokimon.name, &pokimon.type, &pokimon.atk, &pokimon.def, &pokimon.hp, &pokimon.sp
      );
      fclose(fp);

      return 0;

    }
  }
}
