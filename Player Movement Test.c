/*
	Description: This program is a board game called Ups and Downs.
	Author: Marvin Ivan C. Mangubat - S21A
	Acknowledgments: (references and sites/sources)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int nDiceRoll(void){
	int nResult;
	int nMinimum = 0; 
	int nMaximum = 6;
	
	nResult = (rand() % (nMaximum - nMinimum + 1)) + nMinimum; // rand() % 7 (0-6)
	return nResult;
}

void vDiceFeature(int nCurrentPlayer){
	
	int nDiceRollResult, nPlayer1RollTemp, nPlayer2RollTemp;
    char cContinueInput;
    
    	printf("\nPress the Enter key to roll the die. ");
		scanf("%c", &cContinueInput);
		
		nDiceRollResult = nDiceRoll();
		printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
		
		if (nCurrentPlayer == 1){
			if(nDiceRollResult == 1 && nPlayer1RollTemp == 1){
				printf("Player 1, you rolled '1' twice in a row and get another turn! Press the Enter key to roll the die.");
				scanf("%c", &cContinueInput);
				nDiceRollResult = nDiceRoll();
				printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
				nPlayer1RollTemp = 0;
			}
		}
		
		if (nCurrentPlayer == 2){
			if(nDiceRollResult == 1 && nPlayer2RollTemp == 1){
				printf("Player 2, you rolled '1' twice in a row and get another turn! Press the Enter key to roll the die.");
				scanf("%c", &cContinueInput);
				nDiceRollResult = nDiceRoll();
				printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
				nPlayer2RollTemp = 0;
			}
		}
		
		if(nCurrentPlayer == 1){
			nPlayer1RollTemp = nDiceRollResult;
		} else {
			nPlayer2RollTemp = nDiceRollResult;
		}
}

void vPrintGameBoard(int nPlayer1Position, int nPlayer2Position){
    int nBoardSize = 10;  // Determines the size of the board.
    int nTiles = 99;
    int nDirection = 1;  // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	int nRow, nColumn, nPlayerMovement;
	
    for (nRow = nBoardSize - 1; nRow >= 0; nRow--) {
        for (nColumn = 0; nColumn < nBoardSize; nColumn++) {
            if (nDirection == 1) {
                printf("%2d ", nTiles - nColumn); // "%c , 219" or "%2d ", nTiles - nColumn
                if (nPlayer1Position == nTiles - nColumn && nPlayer1Position == nRow){
                	printf("P1 ");
				}
				else if (nPlayer2Position == nTiles - nColumn && nPlayer2Position == nRow){
					printf("P2 ");
				}
            } else {
                printf("%2d ", nTiles - nBoardSize + nColumn + 1); // "%c , 219" or "%2d ", nTiles - nBoardSize + nColumn + 1
                if (nPlayer1Position == nTiles - nColumn && nPlayer1Position == nRow){
                	printf("P1 ");
				}
				else if (nPlayer2Position == nTiles - nColumn && nPlayer2Position == nRow){
					printf("P2 ");
				}
            }
        }
        nDirection *= -1;  // Toggle direction after each row.
        nTiles -= nBoardSize;
        printf("\n\n");
    }
    
}

int nPlayerMovement(void){ // This function determines the number of movements the player will make.
	int nMovementCount;
	nMovementCount = 0;
	
	nMovementCount = nDiceRoll();
	
	return nMovementCount;
}

int nCurrentPlayerPlacement(int nCurrentPosition){ // This function adds the number of movements to the current position.
	int nMovementCount;
	nMovementCount = nPlayerMovement();
	nCurrentPosition += nMovementCount;
	
	return nCurrentPosition;
}

void vCreateGameBoard(int *nPlayer1Position, int *nPlayer2Position, int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End){
	int nBoardSize, nTiles;
	int nDirection;
	int i, nCounter, nColumn;
	
	nBoardSize = 10; // Determines the size of the board.
	nTiles = 99;
	nDirection = 1; // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	nCounter = 0;
	nColumn = 0;
	
    // GAMEBOARD
	for (i = nTiles; i >= 0; i--){
    	
    	if (nDirection == 1){
    		if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == i) && (*nPlayer2Position == i)){
    			printf(" @ ");
			}
			
	    	else if (*nPlayer1Position == i){
	    		printf("P1 ");
			}
			else if (*nPlayer2Position == i){
				printf("P2 ");
			}
			
			else if (*nUpTile1Start == i){
				printf("A ");
			}
			else if (*nUpTile1End == i){
				printf("A ");
			}
			else if (*nUpTile2Start == i){
				printf("B ");
			}
			else if (*nUpTile2End == i){
				printf("B ");
			}
			else if (*nUpTile3Start == i){
				printf("C ");
			}
			else if (*nUpTile3End == i){
				printf("C ");
			}
			
			else if (*nDownTile1Start == i){
				printf("a ");
			}
			else if (*nDownTile1End == i){
				printf("a ");
			}
			else if (*nDownTile2Start == i){
				printf("b ");
			}
			else if (*nDownTile2End == i){
				printf("b ");
			}
			else if (*nDownTile3Start == i){
				printf("c ");
			}
			else if (*nDownTile3End == i){
				printf("c ");
			}
			else {
				printf("%2d ", i); // "%c " , 219 or "%2d ", i
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){
	    		nCounter = 0;
	    		nTiles -= 10;
	    		printf("\n\n");
			}
		} 
		
		else {
			if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1) && (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1)){
    			printf(" @ ");
    			nColumn++;
			}
			
			
	    	else if (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1){
	    		printf("P1 ");
	    		nColumn++;
			}
			else if (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1){
				printf("P2 ");
				nColumn++;
			}
			
			
			else if (*nUpTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("A ");
				nColumn++;
			}
			else if (*nUpTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("A ");
				nColumn++;
			}
			else if (*nUpTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("B ");
				nColumn++;
			}
			else if (*nUpTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("B ");
				nColumn++;
			}
			else if (*nUpTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("C ");
				nColumn++;
			}
			else if (*nUpTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("C ");
				nColumn++;
			}
			
			else if (*nDownTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("a ");
				nColumn++;
			}
			else if (*nDownTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("a ");
				nColumn++;
			}
			else if (*nDownTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("b ");
				nColumn++;
			}
			else if (*nDownTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("b ");
				nColumn++;
			}
			else if (*nDownTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("c ");
				nColumn++;
			}
			else if (*nDownTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("c ");
				nColumn++;
			}
			
			else {
				printf("%2d ", nTiles - nBoardSize + nColumn + 1); // "%c " , 219 or "%2d ", nTiles - nBoardSize + nColumn + 1
				nColumn++;
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){
	    		nCounter = 0;
	    		nColumn = 0;
	    		nTiles -= 10;
	    		printf("\n\n");
			}
		} 
    	
    	if (i % 10 == 0)
    	nDirection *= -1; // Toggle direction after each row.
	}
}

void vUpdateGameBoard(int nCurrentPlayer, int *nPlayer1Position, int *nPlayer2Position, int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End) {
	
	int nBoardSize, nTiles;
	int nDirection;
	int i, nCounter, nColumn;
	
	int nDiceRollResult, nPlayer1RollTemp, nPlayer2RollTemp;
    char cContinueInput;
	
	nBoardSize = 10; // Determines the size of the board.
	nTiles = 99;
	nDirection = 1; // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	nCounter = 0;
	nColumn = 0;
	nDiceRollResult = 0;
    
    
    // GAMEBOARD
	for (i = nTiles; i >= 0; i--){
    	
    	if (nDirection == 1){
    		if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == i) && (*nPlayer2Position == i)){
    			printf(" @ ");
			}
			
	    	else if (*nPlayer1Position == i){
	    		printf("P1 ");
			}
			else if (*nPlayer2Position == i){
				printf("P2 ");
			}
			
			else if (*nUpTile1Start == i){
				printf("A ");
			}
			else if (*nUpTile1End == i){
				printf("A ");
			}
			else if (*nUpTile2Start == i){
				printf("B ");
			}
			else if (*nUpTile2End == i){
				printf("B ");
			}
			else if (*nUpTile3Start == i){
				printf("C ");
			}
			else if (*nUpTile3End == i){
				printf("C ");
			}
			
			else if (*nDownTile1Start == i){
				printf("a ");
			}
			else if (*nDownTile1End == i){
				printf("a ");
			}
			else if (*nDownTile2Start == i){
				printf("b ");
			}
			else if (*nDownTile2End == i){
				printf("b ");
			}
			else if (*nDownTile3Start == i){
				printf("c ");
			}
			else if (*nDownTile3End == i){
				printf("c ");
			}
			else {
				printf("%2d ", i); // "%c " , 219 or "%2d ", i
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){
	    		nCounter = 0;
	    		nTiles -= 10;
	    		printf("\n\n");
			}
		} 
		
		else {
			if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1) && (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1)){
    			printf(" @ ");
    			nColumn++;
			}
			
			
	    	else if (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1){
	    		printf("P1 ");
	    		nColumn++;
			}
			else if (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1){
				printf("P2 ");
				nColumn++;
			}
			
			
			else if (*nUpTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("A ");
				nColumn++;
			}
			else if (*nUpTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("A ");
				nColumn++;
			}
			else if (*nUpTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("B ");
				nColumn++;
			}
			else if (*nUpTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("B ");
				nColumn++;
			}
			else if (*nUpTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("C ");
				nColumn++;
			}
			else if (*nUpTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("C ");
				nColumn++;
			}
			
			else if (*nDownTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("a ");
				nColumn++;
			}
			else if (*nDownTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("a ");
				nColumn++;
			}
			else if (*nDownTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("b ");
				nColumn++;
			}
			else if (*nDownTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("b ");
				nColumn++;
			}
			else if (*nDownTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("c ");
				nColumn++;
			}
			else if (*nDownTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("c ");
				nColumn++;
			}
			
			else {
				printf("%2d ", nTiles - nBoardSize + nColumn + 1); // "%c " , 219 or "%2d ", nTiles - nBoardSize + nColumn + 1
				nColumn++;
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){
	    		nCounter = 0;
	    		nColumn = 0;
	    		nTiles -= 10;
	    		printf("\n\n");
			}
		} 
    	
    	if (i % 10 == 0)
    	nDirection *= -1; // Toggle direction after each row.
	}
	
	// DICE ROLL
	    
    	printf("\nPress the Enter key to roll the die. ");
		scanf("%c", &cContinueInput);
		
		nDiceRollResult = nDiceRoll();
		if (nCurrentPlayer == 1){
			*nPlayer1Position += nDiceRollResult;
		}
		else if (nCurrentPlayer == 2){
			*nPlayer2Position += nDiceRollResult;
		}
		printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
		
		if (nCurrentPlayer == 1){
			if(nDiceRollResult == 1 && nPlayer1RollTemp == 1){
				vCreateGameBoard(nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
				printf("Player 1, you rolled '1' twice in a row and get another turn! Press the Enter key to roll the die.");
				scanf("%c", &cContinueInput);
				nDiceRollResult = nDiceRoll();
				*nPlayer1Position += nDiceRollResult;
				printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
				nPlayer1RollTemp = 0;
			}
		}
		
		else if (nCurrentPlayer == 2){
			if(nDiceRollResult == 1 && nPlayer2RollTemp == 1){
				vCreateGameBoard(nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
				printf("Player 2, you rolled '1' twice in a row and get another turn! Press the Enter key to roll the die.");
				scanf("%c", &cContinueInput);
				nDiceRollResult = nDiceRoll();
				*nPlayer2Position += nDiceRollResult;
				printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
				nPlayer2RollTemp = 0;
			}
		}
		
		if(nCurrentPlayer == 1){
			nPlayer1RollTemp = nDiceRollResult;
		} else {
			nPlayer2RollTemp = nDiceRollResult;
		}
		
		// PLAYER MOVEMENT
		if (*nPlayer1Position >= 99){
			*nPlayer1Position = 99;
			vCreateGameBoard(nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
		}
		else if (*nPlayer2Position >= 99){
			*nPlayer2Position = 99;
			vCreateGameBoard(nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
		}
		
		
		if (*nPlayer1Position == *nUpTile1Start){
			*nPlayer1Position = *nUpTile1End;
			printf("Player %d has stepped on an UP TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nUpTile1Start){
			*nPlayer2Position = *nUpTile1End;
			printf("Player %d has stepped on an UP TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
		if (*nPlayer1Position == *nUpTile2Start){
			*nPlayer1Position = *nUpTile2End;
			printf("Player %d has stepped on an UP TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nUpTile2Start){
			*nPlayer2Position = *nUpTile2End;
			printf("Player %d has stepped on an UP TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
		if (*nPlayer1Position == *nUpTile3Start){
			*nPlayer1Position = *nUpTile3End;
			printf("Player %d has stepped on an UP TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nUpTile3Start){
			*nPlayer2Position = *nUpTile3End;
			printf("Player %d has stepped on an UP TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
		
		if (*nPlayer1Position == *nDownTile1Start){
			*nPlayer1Position = *nDownTile1End;
			printf("Player %d has stepped on a DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nDownTile1Start){
			*nPlayer2Position = *nDownTile1End;
			printf("Player %d has stepped on a DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
		if (*nPlayer1Position == *nDownTile2Start){
			*nPlayer1Position = *nDownTile2End;
			printf("Player %d has stepped on a DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nDownTile2Start){
			*nPlayer2Position = *nDownTile2End;
			printf("Player %d has stepped on a DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
		if (*nPlayer1Position == *nDownTile3Start){
			*nPlayer1Position = *nDownTile3End;
			printf("Player %d has stepped on a DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nDownTile3Start){
			*nPlayer2Position = *nDownTile3End;
			printf("Player %d has stepped on a DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
}

void vGameInstance(void){
    // Initializing of variables at the beginning of the game.
    int nCurrentPlayer = 1;  // The game starts with Player 1.
    int nGameOver = 0;      // The game is not over initially.
	int nInitialPlayer1Position, nInitialPlayer2Position;
	int nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End;
	
	nInitialPlayer1Position = 0; nInitialPlayer2Position = 0; // Player 1 and Player 2 start at the 0 position.
	
	nUpTile1Start = 4; nUpTile1End = 93;
	nUpTile2Start = 15; nUpTile2End = 88;
	nUpTile3Start = 23; nUpTile3End = 74;
	
	nDownTile1Start = 97; nDownTile1End = 8;
	nDownTile2Start = 85; nDownTile2End = 19;
	nDownTile3Start = 79; nDownTile3End = 27;
	
    while (!nGameOver) { // While the game is not over.
    	 
    	vUpdateGameBoard(nCurrentPlayer, &nInitialPlayer1Position, &nInitialPlayer2Position, &nUpTile1Start, &nUpTile1End, &nUpTile2Start, &nUpTile2End, &nUpTile3Start, &nUpTile3End, &nDownTile1Start, &nDownTile1End, &nDownTile2Start, &nDownTile2End, &nDownTile3Start, &nDownTile3End);
		
		// * PUT FUNCTION FOR DICE ROLL AND UPDATED GAME BOARD HERE.
        if (nCurrentPlayer == 1) { // Switch turns
            nCurrentPlayer = 2;
        } else {
            nCurrentPlayer = 1;
        }
        
        // * GAME OVER
        if (nInitialPlayer1Position >= 99){
        	printf("Congratulations! Player 1 is the winner.");
        	nGameOver = 1;
		}
		else if (nInitialPlayer2Position >= 99){
			printf("Congratulations! Player 2 is the winner.");
			nGameOver = 1;
		}
    }
	
}

int main(){
	srand(time(NULL));
	vGameInstance();	
	return 0;
}