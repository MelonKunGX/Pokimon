#include<stdio.h>
#include "Player.h"

void main(void){

	char name[20];

	printf("���O=>");
	scanf("%s", name);

	CreatePlayerData(name);
	PrintPlayerData();

}