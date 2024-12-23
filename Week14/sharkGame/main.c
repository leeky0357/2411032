//
//  main.c
//  sharkGame
//

#include <stdio.h>
// ----- EX. 1 : Preparation------------
#include <stdlib.h>
#include <time.h>
// ----- EX. 1 : Preparation------------
#include "board.h"

// ----- EX. 4 : player ------------
#define N_PLAYER            3
// ----- EX. 4 : player ------------

#define MAX_CHARNAME        200

// ----- EX. 3 : board ------------
#define MAX_DIE             6

// ----- EX. 4 : player ------------
#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER]; //0 - live, 1 - die, 2 - end
char player_statusString[3][MAX_CHARNAME] = {"LIVE", "DIE", "END"};
// ----- EX. 4 : player ------------

// ----- EX. 3 : board ------------
int rolldie(void)
{
    return rand()%MAX_DIE+1;
}
// ----- EX. 3 : board ------------

// ----- EX. 1 : Preparation------------
void opening(void)
{
    printf("==============================================================\n");
    printf("==============================================================\n");
    printf("==========                SHARK GAME!!!                =======\n");
    printf("==============================================================\n");
    printf("==============================================================\n");
}
// ----- EX. 1 : Preparation------------

// ----- EX. 6 : game end ------------
int game_end(void)
{
    int i;
    int flag_end = 1;
    
    //if all the players are died?
    for (i=0;i<N_PLAYER;i++)
    {
        if (player_status[i] == PLAYERSTATUS_LIVE)
        {
            flag_end = 0;
            break;
        }
    }
    
    return flag_end;
}
// ----- EX. 6 : game end ------------

// ----- EX. 4 : player ------------
void printPlayerPosition(int player)
{
    int i;
    
    for (i=0;i<N_BOARD;i++)
    {
        printf("|");
        if (player_position[player] == i)
            printf("%c", player_name[player][0]);
        else
        {
            if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
                printf("X");
            else
                printf(" ");
        }
    }
    printf("|\n");
}

void printPlayerStatus(void)
{
    int i;
    printf("player status ---\n");
    for (i=0;i<N_PLAYER;i++)
    {
        printf("%s : pos %i, coin %i, status %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i);
    }
    printf("-----------------\n");
}
// ----- EX. 4 : player ------------

// ----- EX. 5 : shark ------------
void checkDie(void)
{
    int i;
    for (i=0;i<N_PLAYER;i++)
    {
        if (board_getBoardStatus(player_position[i]) == BOARDSTATUS_NOK)
        {
            printf("%s in pos %i has died!! (coin %i)\n", player_name[i], player_position[i], player_coin[i]);
            player_status[i] = PLAYERSTATUS_DIE;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int i;
    int turn=0;

// ----- EX. 1 : Preparation------------
    srand(time(NULL));
    opening();
// ----- EX. 1 : Preparation------------

// ----- EX. 2 : structuring ------------
    //step1 : initialization
    //step1-1 : board initialization
    board_initBoard();

// ----- EX. 4 : player ------------
    //step1-2 : initialize player
    for (i=0;i<N_PLAYER;i++)
    {
        player_position[i] = 0;
        player_coin[i] = 0;
        player_status[i] = PLAYERSTATUS_LIVE;
        printf("Player %i's name: ", i);
        scanf("%s", player_name[i]);
    }
// ----- EX. 4 : player ------------
    
    //step 2. : game start, turn loop
    do {
        int dieResult;
        int coinResult;
        int dum;

// ----- EX. 4 : player ------------
        if (player_status[turn] != PLAYERSTATUS_LIVE)
        {
            turn = (turn + 1)%N_PLAYER;
            continue;
        }
// ----- EX. 4 : player ------------
        
        //step 2-1. status printing
// ----- EX. 3 : board ------------
        board_printBoardStatus();
// ----- EX. 3 : board ------------
// ----- EX. 4 : player ------------
        printPlayerStatus();
// ----- EX. 4 : player ------------

        //step 2-2. rolling die
        
// ----- EX. 4 : player ------------
        printf("%s turn!! ", player_name[turn]);
        printf("Press any key to roll a die!\n");
        scanf("%d", &dum);
        fflush(stdin);
        
// ----- EX. 4 : player ------------
        dieResult = rolldie();
        printf("%s rolled %d\n", player_name[turn], dieResult);
        
        //step 2-3. moving
   		player_position[turn] += dieResult; //the present pos+ dieResult
   		if (player_position[turn] >= N_BOARD)
   		{
   			player_position[turn] %= N_BOARD;
		   }
		printf("%s moved to position %d.\n", player_name[turn], player_position[turn]);
		
        //step 2-4. coin
    	coinResult = board_getBoardCoin(player_position[turn]); 	//collect coin (on board)
        player_coin[turn] += coinResult; //add coin-player
        if (coinResult > 0)
        {
        	printf("%s collected %d coins!\n", player_name[turn], coinResult);
		}
		
        //step 2-5. end process
    	if (player_position[turn] == N_BOARD - 1) 	//end?
    	{
    		player_status[turn] = PLAYERSTATUS_END;
    		printf("%s reached the end of the board!\n", player_name[turn]);
		}
		
		printf("***Shark is moving***\n");
		board_stepShark;
		checkDie();
		
		turn = (turn + 1) % N_PLAYER;	//next player
		
		// ----- EX. 5 : shark ------------
	if (turn == 0) // one round
	{
		int shark_pos = board_stepShark(); //shark moving
		printf("Shark moved to %i\n", shark_pos); 
		checkDie(); //check die
	}

// ----- EX. 6 : game end ------------
    } while(game_end() == 0);
    

// ----- EX. 6 : game end ------------
int getAlivePlayer(void)
{
	int i;
	int cnt=0;
	for (i=0;i<N_PLAYER;i++)
	{
		if(player_status[i] == PLAYERSTATUS_LIVE)
			cnt++;			//count AlivePlayer
	}
	
	return cnt;
}
	
int getWinner(void)
{
	int i;
	int winner = 0;
	int max_coin = -1;
		
	for (i=0;i<N_PLAYER;i++)
	{
		if (player_status[i] == PLAYERSTATUS_LIVE && player_coin[i] > max_coin)
		{				max_coin = player_coin[i];		//check winner(max_coin)
			winner = i;
		}
	}
		
	return winner;
}
    //step 3. game end process
    printf("GAME END!!\n");
   	int winner = getWinner();
   	
   	if (getAlivePlayer() ==0)
    {
			printf("No winner! All players were died.\n");
    }
	else if (winner != -1)
       	printf("%i players are alive! The winner is %s (%d coins)!\n", getAlivePlayer(), player_name[winner], player_coin[winner]);
        	
// ----- EX. 6 : game end ------------
int game_end(void)
{
	int i;
	int flag_end = 1;
	
	//if all the players are died?
	for (i=0;i<N_PLAYER;i++)
	{
		if(player_status[i] == PLAYERSTATUS_LIVE)
		{
			flag_end = 0;
			break;
		}
	}
	
	return flag_end;
}


// ----- EX. 2 : structuring ------------

    return 0;
}
