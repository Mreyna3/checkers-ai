#include "def.h"

void PrintIndex()
{
	for(int i=0;i<64;i++)
	{
		if(i%8==0)
			printf("\n");
		printf("%d ",sq64to100[i]);
	}
	printf("\n");
}

void SelfPlay()
{
	printf("\n\n--------------The Bot Will Now Play itself to Some Randomized Depth-------------\n\n");
	printf("Press Any Key To See The Next Move\n");
	BOARD board[1];
	SetStart(board);
	getchar();
	while(1)
	{
		MOVE list[1];
		GenMoves(board,list);
		if(list->Count==0)
		{
			printf("%c LOST THE GAME\n\n",PceSideChar[board->Side]);
			break;
		}
		int Depth=5+rand()%4;
		vector<int>BestMove=SearchPos(board,Depth);
		PrintBoard(board);
		MakeMove(board,BestMove);
		getchar();
		getchar();
	}
	StartGame();
}


void PlayBot()
{
	printf("\n\nAt Any Time In The Game If You Want To See The Grid Indexing Press 0 and then Enter\n\n");
	printf("To See The Posible Moves Press 1 and then Enter\n\n");
	BOARD board[1];
	SetStart(board);
	printf("The Starting Board\n\n");
	PrintBoard(board);
	char Inp[200];
	int Side;
	printf("\nChoose Your Side...\n\n0. For Black\n1. For White\n");
	scanf("%d",&Side);
	if(Side==0)
	{
		MOVE list1[1];
		GenMoves(board,list1);
		vector<int>BestMove1=SearchPos(board,8);
		MakeMove(board,BestMove1);
		PrintBoard(board);
	}
	while(1)
	{
		printf("\nEnter Your Move\n");
		getchar();
		scanf("%[^\n]",&Inp);
		if(Inp[0]=='0')
		{
			//Prints the current board
			PrintIndex();
			continue;
		}
		else if(Inp[0]=='1')
		{
			//Prints the Possible move list 
			printf("\nYour Possible MoveList is\n");
			MOVE YourMoveList[1];
			GenMoves(board,YourMoveList);
			PrintMoveList(YourMoveList);
		}
		vector<int>Move=ParseMove(Inp);
		if(MoveExists(board,Move))
			MakeMove(board,Move);
		else
		{
			MOVE User[1];
			GenMoves(board,User);
			if(User->Count==0)
			{
				printf("Sorry You Lost\n\n");
				break;
			}
			else
				printf("Invalid Move...Enter Again\n\n");
			continue;
		}
		PrintBoard(board);
		printf("-----------------------------------Bot's Turn----------------------------------\n");
		MOVE Bot[1];
		GenMoves(board,Bot);
		if(Bot->Count==0)
		{
			printf("--------------------------Congratulations You Win--------------------------\n");
			break;
		}
		vector<int>BestMove=SearchPos(board,8);
		MakeMove(board,BestMove);
		PrintBoard(board);
	}
	StartGame();
}
