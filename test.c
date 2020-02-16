#include<stdio.h>
#include "Player.h"

void main(void){

	char name[20];

	LoadPokimons();

	printf("プレイヤー=>");
	scanf("%s", name);
	CreatePlayerData(name);

	printf("ポキモン=>");
	scanf("%s", name);
	AddPokimon(0, name);

	SavePlayerData(1);
	PrintPlayerData();

}
