//
//  board.c
//  sharkGame
//

#include "board.h"
#include <stdlib.h>
#include <time.h>
// ----- EX. 3 : board ------------
#define N_COINPOS       12
#define MAX_COIN        4
// ----- EX. 3 : board ------------
// ----- EX. 5 : shark ------------
#define MAX_SHARKSTEP   6
#define SHARK_INITPOS   -4
// ----- EX. 5 : shark ------------
// ----- EX. 3 : board ------------
static int board_coin[N_BOARD];
static int board_status[N_BOARD]; //0 - OK, 1 - destroyed
// ----- EX. 3 : board ------------


static int shark_position;

// ----- EX. 3 : board ------------
void board_printBoardStatus(void)
{
    int i;
    
    printf("----------------------- BOARD STATUS -----------------------\n");
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (board_status[i] == BOARDSTATUS_NOK)
            printf("X");
        else
            printf("O");
    }
    printf("|\n");
    printf("------------------------------------------------------------\n");
}

int board_initBoard(void)
{
    int i, coin_pos;
    
    //variable initialization
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }

// ----- EX. 5 : shark ------------
    shark_position = SHARK_INITPOS;
// ----- EX. 5 : shark ------------

    //coin allocation
    for (i=0;i<N_COINPOS;i++)
    {
    	do
    	{
    		coin_pos = rand() % N_BOARD;
		} while (board_coin[coin_pos] != 0);
    	
    	//[i] coin
    	board_coin[coin_pos] = (rand() % MAX_COIN) + 1;
	}   
	
    return N_COINPOS;
}
// ----- EX. 3 : board ------------


// ----- EX. 5 : shark ------------
int board_stepShark(void)
{
	int step = (rand() % MAX_SHARKSTEP) + 1; //random shark's step
	int start_position = shark_position;
	shark_position = (shark_position + step) % N_BOARD;
	
	printf("Shark moved %d steps from %d to %d.\n", step, start_position, shark_position);
	
	for (int i = start_position; i != shark_position; i = (i+1) %N_BOARD)
	{
		board_status[i] = BOARDSTATUS_NOK;
	}
	board_status[shark_position] = BOARDSTATUS_NOK;
	
	return shark_position;
}
// ----- EX. 5 : shark ------------

// ----- EX. 3 : board ------------
int board_getBoardStatus(int pos)
{
    return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin;
}
// ----- EX. 3 : board ------------
