#include<stdio.h>
#include "Player.h"

void main(void){

	char name[20];

	LoadPokimons();

	printf("�v���C���[=>");
	scanf("%s", name);
	CreatePlayerData(name);

	printf("�|�L����=>");
	scanf("%s", name);
	AddPokimon(0, name);

	SavePlayerData(1);
	PrintPlayerData();

}
