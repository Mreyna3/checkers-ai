#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<time.h>

#define NAME "Jarvis"

using namespace std;

#define DEBUG
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n)\
if(!(n)){\
printf("%s - FAILED\n",#n);\
printf("ON - %s\n",__DATE__);\
printf("AT - %s\n",__TIME__);\
printf("In File - %s\n",__FILE__);\
printf("At line - %d\n",__LINE__);\
exit(1);}
#endif

#define ULL unsigned long long int
#define MAXMOVES 2048


#define Convert(r,c) (r*10 +c) //Asscoiated Type
#define SetBit(b,sq) (b|=(1ULL<<sq))  // Look into bitwise members, allows quick manipulation of matrix like objects. bitboards
#define ClearBit(b,sq) (b&=(~(1ULL<<sq)))  //Look into bitwise members, basically allows quick manipulation of matrixx like objects
#define pii pair<int,int> //Associtaed Type
#define mp(a,b) make_pair(a,b) //Associtaed Type

enum {BLACK,WHITE,RED};
enum {FALSE,TRUE};
enum {EMPTY,wP,wK,bP,bK,OFF=9};

//this is a move structure to create a movelist just create
//a vector of this MOVE structure to get the moves in form of a list
typedef struct{
	vector<vector<int> >Move;
	int Count;
}MOVE;

//all the necessary components needed to uniquely reset a state of the board
typedef struct{
	int Side;
	int PceVal[5];
	int PceNum[5];
	int Pieces[100];
}UNDO;

//our checkers board structure
typedef struct{
	int Pieces[100];
	int HisPly,Ply;
	int Side;
	int PceVal[2];
	int PceNum[5];
	UNDO History[MAXMOVES];
}BOARD;

/*-----------------------------------------------------arrays or valuse----------------------------------------------------------*/

//Init.cpp
extern int sq100to64[100];
extern int sq64to100[64];
extern char PceChar[5];
extern int PceVal[5];
extern int PceCol[5];
extern char PceSideChar[2];

/*-----------------------------------------------------functions----------------------------------------------------------*/

//Init.cpp
extern void Init();
extern void StartGame();


//Board.cpp
extern void SetStart(BOARD *board);
extern void ResetBoard(BOARD *board);
extern void PrintBoard(BOARD *board);


//Movegenerator.cpp
extern void GenMoves(BOARD *board,MOVE *MoveList);
extern void PrintMoveList(MOVE *MoveList);


//Makemove.cpp
extern void MakeMove(BOARD *board,vector<int> Move);//to make the actual move on he board
extern void TakeMove(BOARD *board);//to take back the last move
extern int MoveExists(BOARD *board,vector<int> Move);//to check wheather a move entered by the use is valid or not
extern vector<int>ParseMove(char *Inp);//to parse a move from the user

//Search.cpp
extern vector<int> SearchPos(BOARD *board,int Depth);

//Playgame.cpp
extern void SelfPlay();
extern void PlayBot();
