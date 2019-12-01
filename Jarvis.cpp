#include"def.h"

int main()
{
	time_t t;
	srand(time(&t));
	Init();
	printf("-------------------------------Checker Game Bot---------------------------------\n\n");
	printf("Id - : %s\n\n",NAME);
	printf("Author - : Michaud Reyna & Adrian\n\n");
	StartGame();
	return 0;
}
