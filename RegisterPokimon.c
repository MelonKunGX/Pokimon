#include <stdio.h>
#include <string.h>
#include "Pokimon.h"

int main(void){

	char name[20];
	int id, type, atk, def, hp, sp;

	printf("- ポキモン登録 -\n");

	while(1){

		printf("IDを入力してください。\n(終了は -1 を入力)\n");
		printf(">");
		scanf("%d", &id);

		if(id == -1)
			break;

		printf("登録するポキモンの名前を入力してください。\n");
		printf(">");
		scanf("%s", name);

		do{

			printf("タイプを入力してください。\n(ほのお：0・みず：1・くさ：2)\n");
			printf(">");
			scanf("%d", &type);

		}while(type < 0 || type > 2);

		printf("攻撃力を入力してください\n");
		printf(">");
		scanf("%d", &atk);
		printf("防御力を入力してください\n");
		printf(">");
		scanf("%d", &def);
		printf("体力を入力してください\n");
		printf(">");
		scanf("%d", &hp);
		printf("すばやさを入力してください\n");
		printf(">");
		scanf("%d", &sp);

		if(CreatePokimon(id, name, type, atk, def, hp, sp) == -1){

			printf("【エラー：ポキモンの登録に失敗しました。】");
			exit(-1);

		}

		printf("\n-------------------\n");

	}

	return 0;

}
