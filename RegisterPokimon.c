#include <stdio.h>
#include <string.h>
#include "Pokimon.h"

int main(void){

	char name[20];
	int id, type, atk, def, hp, sp;

	printf("- �|�L�����o�^ -\n");

	while(1){

		printf("ID����͂��Ă��������B\n(�I���� -1 �����)\n");
		printf(">");
		scanf("%d", &id);

		if(id == -1)
			break;

		printf("�o�^����|�L�����̖��O����͂��Ă��������B\n");
		printf(">");
		scanf("%s", name);

		do{

			printf("�^�C�v����͂��Ă��������B\n(�ق̂��F0�E�݂��F1�E�����F2)\n");
			printf(">");
			scanf("%d", &type);

		}while(type < 0 || type > 2);

		printf("�U���͂���͂��Ă�������\n");
		printf(">");
		scanf("%d", &atk);
		printf("�h��͂���͂��Ă�������\n");
		printf(">");
		scanf("%d", &def);
		printf("�̗͂���͂��Ă�������\n");
		printf(">");
		scanf("%d", &hp);
		printf("���΂₳����͂��Ă�������\n");
		printf(">");
		scanf("%d", &sp);

		if(CreatePokimon(id, name, type, atk, def, hp, sp) == -1){

			printf("�y�G���[�F�|�L�����̓o�^�Ɏ��s���܂����B�z");
			exit(-1);

		}

		printf("\n-------------------\n");

	}

	return 0;

}
