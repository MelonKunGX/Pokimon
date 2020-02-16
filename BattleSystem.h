#ifndef BattleStstem_h
#define BattleStstem_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Player.h"

//ƒGƒ“ƒJƒEƒ“ƒg‚·‚é‚Ü‚Å‚ÌŠî€•à”
#define STEPS 10

/* ƒvƒƒgƒ^ƒCƒvéŒ¾ */
int BattleAttack(int);
int BattleEscape(void);
int BattleFadeOut(int);
int BattleFadeIn(void);
int BattleInit(void);
int BattleItemSelect(void);
int BattleTop(void);
int BattlePokimonSelect(void);
int ctoi(char);
int Encount(void);
int ToDisplay(int);
/* ƒvƒƒgƒ^ƒCƒvéŒ¾ */

char ui[25][101], display[25][101];
struct parts{

  char menu[7][17];
  char message[76];
  char center[17][76];

}part;

struct enemy{

  int id;
  char name[20];
  int type;
  int atk;
  int def;
  int max_hp;
  int hp;
  int sp;

}status;

int BattleAttack(int my_id){

  int i, turn, damage;
  float com;

  if(player.pokimon[my_id].sp > status.sp){

    turn = 0;

  }else if(player.pokimon[my_id].sp < status.sp){

    turn = 1;

  }else{

    srand((unsigned) time(NULL));
    turn = rand() % 2;

  }

  for(i = 0; i < 2; i++){

    if(turn == 0){

      sprintf(part.message, "%20s‚Ì‚±‚¤‚°‚«I yEnterz                                 ", player.pokimon[my_id].name);
      ToDisplay(-1);
      printf("\n\t\t\ty%sz%d/%d\t\t\ty%sz%d/%d", player.pokimon[my_id].name, player.pokimon[my_id].hp, player.pokimon[my_id].max_hp, status.name, status.hp, status.max_hp);

      while(getch() != 13);

      damage = (player.pokimon[my_id].atk / status.def) * 10;

      if(defpokimon[player.pokimon[my_id].id].type == 0){

        if(status.type == 1)
          damage /= 2;

        if(status.type == 2)
          damage *= 2;

      }

      if(defpokimon[player.pokimon[my_id].id].type == 1){

        if(status.type == 0)
          damage *= 2;

        if(status.type == 2)
          damage /= 2;

      }

      if(defpokimon[player.pokimon[my_id].id].type == 2){

        if(status.type == 0)
          damage /= 2;

        if(status.type == 1)
          damage *= 2;

      }

      if(damage < 1)
        damage += 1;

      status.hp -= damage;

      if(status.hp <= 0){

        status.hp = 0;
        sprintf(part.message, "%20s‚ð‚½‚¨‚µ‚½I yEnterz                                 ", status.name);
        ToDisplay(-1);
        printf("\n\t\t\ty%sz%d/%d\t\t\ty%sz%d/%d", player.pokimon[my_id].name, player.pokimon[my_id].hp, player.pokimon[my_id].max_hp, status.name, status.hp, status.max_hp);

        while(getch() != 13);

        return 1;

      }

      turn = 1;
      continue;

    }

    if(turn == 1){

      sprintf(part.message, "%20s‚Ì‚±‚¤‚°‚«I yEnterz                                 ", status.name);
      ToDisplay(-1);
      printf("\n\t\t\ty%sz%d/%d\t\t\ty%sz%d/%d", player.pokimon[my_id].name, player.pokimon[my_id].hp, player.pokimon[my_id].max_hp, status.name, status.hp, status.max_hp);

      while(getch() != 13);

      damage = (status.atk / player.pokimon[my_id].def) * 10;

      if(status.type == 0){

        if(defpokimon[player.pokimon[my_id].id].type == 1)
          damage /= 2;

        if(defpokimon[player.pokimon[my_id].id].type == 2)
          damage *= 2;

      }

      if(status.type == 1){

        if(defpokimon[player.pokimon[my_id].id].type == 0)
          damage *= 2;

        if(defpokimon[player.pokimon[my_id].id].type == 2)
          damage /= 2;

      }

      if(status.type == 2){

        if(defpokimon[player.pokimon[my_id].id].type == 0)
          damage /= 2;

        if(defpokimon[player.pokimon[my_id].id].type == 1)
          damage *= 2;

      }

      if(damage < 1)
        damage += 1;

      player.pokimon[my_id].hp -= damage;

      if(player.pokimon[my_id].hp <= 0){

        player.pokimon[my_id].hp = 0;
        sprintf(part.message, "%20s‚Í—Ís‚«‚Ä‚µ‚Ü‚Á‚½I yEnterz                         ", player.pokimon[my_id].name);
        ToDisplay(-1);
        printf("\n\t\t\ty%sz%d/%d\t\t\ty%sz%d/%d", player.pokimon[my_id].name, player.pokimon[my_id].hp, player.pokimon[my_id].max_hp, status.name, status.hp, status.max_hp);

        while(getch() != 13);

        return 1;

      }

      turn = 0;
      continue;

    }
  }

  return 0;

}

int BattleEscape(void){

  strcpy(part.message, "‚¤‚Ü‚­‚É‚°‚«‚ê‚½I                                                         ");
  ToDisplay(2);

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

int BattleItemSelect(void){

  int in, mode = 0;
  char menu[17];

  strcpy(part.menu[0], " ‚«‚¸‚®‚·‚è      ");
  strcpy(part.menu[1], " ƒ|ƒLƒ‚ƒ“ƒ{[ƒ‹  ");
  strcpy(part.menu[2], "                 ");

  while(1){

    if(mode == 0)
      sprintf(part.message, "Žg—p‚µ‚Ä‚¢‚éƒ|ƒLƒ‚ƒ“‚ÌHP‚ð30‰ñ•œ‚·‚éB ŠŽ”: %d                           ", GetItemCount(0));

    if(mode == 1)
      sprintf(part.message, "–ì¶ƒ|ƒLƒ‚ƒ“‚ð•ß‚Ü‚¦‚éB ŠŽ”: %d                                         ", GetItemCount(1));

    ToDisplay(mode);

    in = getch();

    if(in == 27)
      break;

    if(in != 0)
      continue;

    in = getch();

    if(in == 72)
      if(mode == 1)
        mode  = 0;

    if(in == 80)
      if(mode == 0)
        mode = 1;

  }

  return 0;

}

int BattleTop(void){

  int i, in, my_id, update = 1, mode = 0;
  char file_name[20];
  FILE *fp;

  sprintf(file_name, "AA/%d.txt", status.id);

  if((fp = fopen(file_name, "r")) == NULL)
    return -1;

  for(i = 0; i < 17; i++)
    fgets(part.center[i], 80, fp);

  fclose(fp);

  for(i = 0; i < 7; i++)
    strcpy(part.menu[i], "                 ");

  sprintf(part.message, "‚â‚¹‚¢‚Ì%20s‚ª‚Æ‚Ñ‚¾‚µ‚Ä‚«‚½I yEnterz                   ", status.name);
  ToDisplay(-1);
  while(getch() != 13);

  my_id = BattlePokimonSelect();

  if(my_id == -1)
    return 0;

  while(1){

    strcpy(part.menu[0], " ‚½‚½‚©‚¤        ");
    strcpy(part.menu[1], " ‚à‚¿‚à‚Ì        ");
    strcpy(part.menu[2], " ‚É‚°‚é          ");

    for(i = 3; i < 7; i++)
      strcpy(part.menu[i], "                 ");

    strcpy(part.message, "‚Ç‚¤‚·‚éH                                                                 ");

    if(update == 1){

      ToDisplay(mode);
      printf("\n\t\t\ty%sz%d/%d\t\t\ty%sz%d/%d", player.pokimon[my_id].name, player.pokimon[my_id].hp, player.pokimon[my_id].max_hp, status.name, status.hp, status.max_hp);
      update = 0;

    }

    in = getch();

    if(in == 13){

      if(mode == 0){

        if(BattleAttack(my_id) == 0)
          update = 1;

        else
          break;

      }

      if(mode == 1){

        BattleItemSelect();
        update = 1;

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

int BattlePokimonSelect(void){

  int i, in, count = -1, mode = 0, find = 0;
  char name[20];

  for(i = 0; i < 6, strcmp(player.pokimon[i].name, "null") != 0, player.pokimon[i].hp != 0; i++)
    find = 1;

  if(!find){

    sprintf(part.message, "%20s‚Íí‚¦‚éƒ|ƒLƒ‚ƒ“‚ðŽ‚Á‚Ä‚¢‚È‚¢... yEnterz            ", player.name);
    ToDisplay(-1);
    while(getch() != 13);
    return -1;

  }

  for(i = 0; i < 6; i++){

    if(strcmp(GetPokimonName(i), "null") != 0){

      sprintf(part.menu[i], " %16s", GetPokimonName(i));
      count++;

    }else{

      strcpy(part.menu[i], "                 ");

    }
  }

  while(1){

    strcpy(part.message, "‚Ç‚Ìƒ|ƒLƒ‚ƒ“‚Å‚±‚¤‚°‚«‚·‚éH                                               ");
    ToDisplay(mode);

    in = getch();

    if(in == 13){

      if(player.pokimon[mode].hp == 0){

        strcpy(part.message, "‚»‚Ìƒ|ƒLƒ‚ƒ“‚Í‚·‚Å‚É—Ís‚«‚Ä‚¢‚é... yEnterz                              ");
        ToDisplay(mode);
        while(getch() != 13);
        continue;

      }

      return mode;

    }

    if(in != 0)
      continue;

    in = getch();

    if(in == 72 && mode > 0)
      mode--;

    if(in == 80 && mode < count)
      mode++;

  }
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

int Encount(void){

  int prob;
  FILE *fp;

  srand((unsigned) time(NULL));
  // Šm—¦ = 0`99‚Ì—”¶¬ € (Šî€•à” + ƒGƒ“ƒJƒEƒ“ƒgƒŒƒxƒ‹)
  prob = (rand() % 100) / STEPS;
  prob = 0;

  if(prob == 0)
    return 1;

  else
    return 0;

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

  id = rand() % id;

  status.id = id;
  strcpy(status.name, defpokimon[id].name);
  status.type = defpokimon[id].type;
  status.atk = defpokimon[id].atk;
  status.def = defpokimon[id].def;
  status.max_hp = defpokimon[id].hp;
  status.hp = defpokimon[id].hp;
  status.sp = defpokimon[id].sp;

  return 0;

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

#endif
