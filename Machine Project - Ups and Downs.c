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
	
	nResult = (rand() % (nMaximum - nMinimum + 1)) + nMinimum;
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

void vPrintGameBoard() {
    int nBoardSize = 10;  // Determines the size of the board.
    int nTiles = 99;
    int nDirection = 1;  // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	int nRow, nColumn;
	
    for (nRow = nBoardSize - 1; nRow >= 0; nRow--) {
        for (nColumn = 0; nColumn < nBoardSize; nColumn++) {
            if (nDirection == 1) {
                printf("%2d ", nTiles - nColumn); // "%c , 219" or "%2d ", nTiles - nColumn
            } else {
                printf("%2d ", nTiles - nBoardSize + nColumn + 1); // "%c , 219" or "%2d ", nTiles - nBoardSize + nColumn + 1
            }
        }
        nDirection *= -1;  // Toggle direction after each row.
        nTiles -= nBoardSize;
        printf("\n\n");
    }
}

void vGameInstance(void){
    // Initializing of variables at the beginning of the game.
    int nCurrentPlayer = 1;  // The game starts with Player 1.
    int nGameOver = 0;      // The game is not over initially.
    int nDiceRollResult, nPlayer1RollTemp, nPlayer2RollTemp;
    char cContinueInput;

    while (!nGameOver) { // While the game is not over.
		vPrintGameBoard();
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