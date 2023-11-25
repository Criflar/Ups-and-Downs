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
	srand(time(NULL));
	
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

void vUpdateGameBoard(int nPlayer1Position, int nPlayer2Position) {
    int nBoardSize = 10;  // Determines the size of the board.
    int nTiles = 99;
    int nDirection = 1;  // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	int i, nCounter, nColumn;
	nCounter = 0;
	nColumn = 0;
    
	for (i = nTiles; i >= 0; i--){
    	
    	if (nDirection == 1){
    		if ((nPlayer1Position == nPlayer2Position) && (nPlayer1Position == i) && (nPlayer2Position == i)){
    			printf(" @ ");
			}
	    	else if (nPlayer1Position == i){
	    		printf("P1 ");
			}
			else if (nPlayer2Position == i){
				printf("P2 ");
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
			if ((nPlayer1Position == nPlayer2Position) && (nPlayer1Position == nTiles - nBoardSize + nColumn + 1) && (nPlayer2Position == nTiles - nBoardSize + nColumn + 1)){
    			printf(" @ ");
    			nColumn++;
			}
	    	else if (nPlayer1Position == nTiles - nBoardSize + nColumn + 1){
	    		printf("P1 ");
	    		nColumn++;
			}
			else if (nPlayer2Position == nTiles - nBoardSize + nColumn + 1){
				printf("P2 ");
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

void vGameInstance(void){
    // Initializing of variables at the beginning of the game.
    int nCurrentPlayer = 1;  // The game starts with Player 1.
    int nGameOver = 0;      // The game is not over initially.
	int nPlayer1Position, nPlayer2Position;
	nPlayer1Position = 0; nPlayer2Position = 0; // Player 1 and Player 2 start at the 0 position.
	
    while (!nGameOver) { // While the game is not over.
    	vUpdateGameBoard(nPlayer1Position, nPlayer2Position);
		vDiceFeature(nCurrentPlayer);
		
		// * PUT FUNCTION FOR DICE ROLL AND UPDATED GAME BOARD HERE.
        if (nCurrentPlayer == 1) { // Switch turns
            nCurrentPlayer = 2;
        } else {
            nCurrentPlayer = 1;
        }
    }
	// * GAME OVER
}

int main(){
	vGameInstance();	
	return 0;
}