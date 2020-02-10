#include<stdio.h>
#include "Player.h"

void main(void){

	char name[20];

	printf("–¼‘O=>");
	scanf("%s", name);

	CreatePlayerData(name);
	PrintPlayerData();

}