/*
	Description: This program is a board game akin to Snakes and Ladders called "Ups and Downs" featuring Up and Down Special Tiles.
	Author: Marvin Ivan C. Mangubat - S21A
	Acknowledgments: https://pubs.opengroup.org/onlinepubs/009696799/functions/sleep.html - unistd.h library and sleep function
					
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


/* 
	Description: This function returns a random value between 0-6.
	Precondition: There are no parameters.
	@param: N/A
	@return: A random integer from 0-6.

*/

int nDiceRoll(void){
	int nResult;
	int nMinimum; 
	int nMaximum;
	
	nMinimum = 0; // Minimum value of die is 0.
	nMaximum = 6; // Maximum value of die is 6.
	
	nResult = (rand() % (nMaximum - nMinimum + 1)) + nMinimum; // Also equivalent to rand() % 7. (0-6)
	return nResult;
}


/*
	Description: This function returns a random number between 1-98.
	Precondition: There are no parameters.
	@param: N/A
	@return: A random integer from 1-98.

*/

int nPlacementGenerator(void){
	int nResult;
	int nMinimum; 
	int nMaximum;
	
	nMinimum = 1; // because special tiles cannot be placed at the start.
	nMaximum = 98; // because special tiles cannot be placed at the end.
	
	nResult = (rand() % (nMaximum - nMinimum + 1)) + nMinimum;
	return nResult;
}


/*
	Description: This function returns the value of the parameter with the highest value.
	Precondition: The parameters should already be generated.

	@param: *nTile1Start - a pointer parameter for the start of the first special tile.
	@param: *nTile1End - a pointer parameter for the end of the first special tile.
	
	@param: *nTile2Start - a pointer parameter for the start of the second special tile.
	
	@param: *nTile2End - a pointer parameter for the end of the second special tile.
	
	@param: *nTile3Start - a pointer parameter for the start of the third special tile.
	@param: *nTile3End - a pointer parameter for the end of the third special tile.
	
	@return: The highest value among the special tile parameters.

*/

int nGetHighestTile (int *nTile1Start, int *nTile1End, int *nTile2Start, int *nTile2End, int *nTile3Start, int *nTile3End){
	int nHighestTile;
	nHighestTile = *nTile1Start; // Assume the first parameter is initially the highest tile.
	
	// Check the remaining parameters and update nHighestTile if a larger value is found.
	
	if (*nTile1End > nHighestTile){ // If over else if because it will stop the entire process once nHighestTile gets updated.
		nHighestTile = *nTile1End;
	}
	
	if (*nTile2Start > nHighestTile){
	nHighestTile = *nTile2Start;
	}
	
	if (*nTile2End > nHighestTile){
	nHighestTile = *nTile2End;
	}
	
	if (*nTile3Start > nHighestTile){
	nHighestTile = *nTile3Start;
	}
	
	if (*nTile3End > nHighestTile){
	nHighestTile = *nTile3End;
	}
	
	return nHighestTile; // Returns the highest value among the tiles.
}


/*
	Description: The parameters in this function will undergo conditions that determine if they are valid.
	Precondition: The parameters should already be generated and the player input parameters should already be inputted.
	
	@param: *nPlayer1DownTileStart - a pointer parameter for the start of the down tile inputted by Player 1.
	@param: *nPlayer1DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 1.
	
	@param: *nPlayer2DownTileStart - a pointer parameter for the start of the down tile inputted by Player 2.
	@param: *nPlayer2DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 2.
	
	@param: *nUpTile1Start - a pointer parameter for the start of the first randomly-generated up tile.
	@param: *nUpTile1End - a pointer parameter for the end of the first randomly-generated up tile.
	
	@param: *nUpTile2Start - a pointer parameter for the start of the second randomly-generated up tile.
	@param: *nUpTile2End - a pointer parameter for the end of the second randomly-generated up tile.
	
	@param: *nUpTile3Start - a pointer parameter for the start of the third randomly-generated up tile.
	@param: *nUpTile3End - a pointer parameter for the end of the third randomly-generated up tile.
	
	@param: *nDownTile1Start - a pointer parameter for the start of the first randomly-generated down tile.
	@param: *nDownTile1End - a pointer parameter for the end of the first randomly-generated down tile.
	
	@param: *nDownTile2Start - a pointer parameter for the start of the second randomly-generated down tile.
	@param: *nDownTile2End - a pointer parameter for the end of the second randomly-generated down tile.
	
	@param: *nDownTile3Start - a pointer parameter for the start of the third randomly-generated down tile.
	@param: *nDownTile3End - a pointer parameter for the end of the third randomly-generated down tile.
	
	@return: returns 1 if all the conditions are met.

*/

int nValidation(int *nPlayer1DownTileStart, int *nPlayer1DownTileEnd, int *nPlayer2DownTileStart, int *nPlayer2DownTileEnd, int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End){
	int nPlayer1DownStartRow, nPlayer1DownEndRow, nPlayer2DownStartRow, nPlayer2DownEndRow, nUpStart1Row, nUpEnd1Row, nUpStart2Row, nUpEnd2Row, nUpStart3Row, nUpEnd3Row, nDownStart1Row, nDownEnd1Row, nDownStart2Row, nDownEnd2Row, nDownStart3Row, nDownEnd3Row;
	int nHighestUpTile, nHighestDownTile;
	int nValidated;
	
	nValidated = 1; // Assume that the special tiles' placements are initially valid.
	
	nUpStart1Row = *nUpTile1Start / 10; // Dividing each position by 10 will get the tens position - rows.
	nUpEnd1Row = *nUpTile1End / 10;
	nUpStart2Row = *nUpTile2Start / 10;
	nUpEnd2Row = *nUpTile2End / 10;
	nUpStart3Row = *nUpTile3Start / 10;
	nUpEnd3Row = *nUpTile3End / 10;
	
	nPlayer1DownStartRow = *nPlayer1DownTileStart / 10;
	nPlayer1DownEndRow = *nPlayer1DownTileEnd / 10;
	nPlayer2DownStartRow = *nPlayer2DownTileStart / 10;
	nPlayer2DownEndRow = *nPlayer2DownTileEnd / 10;
	
	nDownStart1Row = *nDownTile1Start / 10;
	nDownEnd1Row = *nDownTile1End / 10;
	nDownStart2Row = *nDownTile2Start / 10;
	nDownEnd2Row = *nDownTile2End / 10;
	nDownStart3Row = *nDownTile3Start / 10;
	nDownEnd3Row = *nDownTile3End / 10;
	
	nHighestUpTile = nGetHighestTile(nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End); // Calling this function will get the highest value from the Up Tiles.
	nHighestDownTile = nGetHighestTile(nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End); // Calling this function will get the highest value from the Down Tiles.
	
	if (nHighestUpTile > nHighestDownTile){
		nValidated = 0; // Invalid because the last special tile would then be an up tile.
	}
	
	else if (*nUpTile1Start > *nUpTile1End || *nUpTile2Start > *nUpTile2End || *nUpTile3Start > *nUpTile3End){
		nValidated = 0; // Invalid because up tiles should go from Down to Up.
	}
	
	else if (*nDownTile1Start < *nDownTile1End || *nDownTile2Start < *nDownTile2End || *nDownTile3Start < *nDownTile3End){
		nValidated = 0; // Invalid because down tiles should go from Up to Down.
	}
	
	else if (*nUpTile1Start == *nDownTile1Start || *nUpTile1Start == *nDownTile1End || *nUpTile1Start == *nDownTile2Start || *nUpTile1Start == *nDownTile2End || *nUpTile1Start == *nDownTile3Start || *nUpTile1Start == *nDownTile3End || *nUpTile1Start == *nPlayer1DownTileStart || *nUpTile1Start == *nPlayer1DownTileEnd || *nUpTile1Start == *nPlayer2DownTileStart || *nUpTile1Start == *nPlayer2DownTileEnd || *nUpTile1End == *nDownTile1Start || *nUpTile1End == *nDownTile1End || *nUpTile1End == *nDownTile2Start || *nUpTile1End == *nDownTile2End || *nUpTile1End == *nDownTile3Start || *nUpTile1End == *nDownTile3End || *nUpTile1End == *nPlayer1DownTileStart || *nUpTile1End == *nPlayer1DownTileEnd || *nUpTile1End == *nPlayer2DownTileStart || *nUpTile1End == *nPlayer2DownTileEnd || *nUpTile2Start == *nDownTile1Start || *nUpTile2Start == *nDownTile1End || *nUpTile2Start == *nDownTile2Start || *nUpTile2Start == *nDownTile2End || *nUpTile2Start == *nDownTile3Start || *nUpTile2Start == *nDownTile3End || *nUpTile2Start == *nPlayer1DownTileStart || *nUpTile2Start == *nPlayer1DownTileEnd || *nUpTile2Start == *nPlayer2DownTileStart || *nUpTile2Start == *nPlayer2DownTileEnd || *nUpTile2End == *nDownTile1Start || *nUpTile2End == *nDownTile1End || *nUpTile2End == *nDownTile2Start || *nUpTile2End == *nDownTile2End || *nUpTile2End == *nDownTile3Start || *nUpTile2End == *nDownTile3End || *nUpTile2End == *nPlayer1DownTileStart || *nUpTile2End == *nPlayer1DownTileEnd || *nUpTile2End == *nPlayer2DownTileStart || *nUpTile2End == *nPlayer2DownTileEnd || *nUpTile3Start == *nDownTile1Start || *nUpTile3Start == *nDownTile1End || *nUpTile3Start == *nDownTile2Start || *nUpTile3Start == *nDownTile2End || *nUpTile3Start == *nDownTile3Start || *nUpTile3Start == *nDownTile3End || *nUpTile3Start == *nPlayer1DownTileStart || *nUpTile3Start == *nPlayer1DownTileEnd || *nUpTile3Start == *nPlayer2DownTileStart || *nUpTile3Start == *nPlayer2DownTileEnd || *nUpTile3End == *nDownTile1Start || *nUpTile3End == *nDownTile1End || *nUpTile3End == *nDownTile2Start || *nUpTile3End == *nDownTile2End || *nUpTile3End == *nDownTile3Start || *nUpTile3End == *nDownTile3End || *nUpTile3End == *nPlayer1DownTileStart || *nUpTile3End == *nPlayer1DownTileEnd || *nUpTile3End == *nPlayer2DownTileStart || *nUpTile3End == *nPlayer2DownTileEnd){
		nValidated = 0; // Invalid because the placements of the Up Tiles and Down Tiles should never be equal.
	}
	
	else if (nUpStart1Row == nUpEnd1Row || nUpStart1Row == nUpStart2Row || nUpStart1Row == nUpEnd2Row || nUpStart1Row == nUpStart3Row || nUpStart1Row == nUpEnd3Row || nUpEnd1Row == nUpStart2Row || nUpEnd1Row == nUpEnd2Row || nUpEnd1Row == nUpStart3Row || nUpEnd1Row == nUpEnd3Row || nUpStart2Row == nUpEnd2Row || nUpStart2Row == nUpStart3Row || nUpStart2Row == nUpEnd3Row || nUpEnd2Row == nUpStart3Row || nUpEnd2Row == nUpEnd3Row || nUpStart3Row == nUpEnd3Row){
		nValidated = 0; // Invalid because there would be more than 1 up tiles per row.
	}
	
	else if (nPlayer1DownStartRow == nPlayer1DownEndRow || nPlayer1DownStartRow == nPlayer2DownStartRow || nPlayer1DownStartRow == nPlayer2DownEndRow || nPlayer1DownStartRow == nDownStart1Row || nPlayer1DownStartRow == nDownEnd1Row || nPlayer1DownStartRow == nDownStart2Row || nPlayer1DownStartRow == nDownEnd2Row || nPlayer1DownStartRow == nDownStart3Row || nPlayer1DownStartRow == nDownEnd3Row || nPlayer1DownEndRow == nPlayer2DownStartRow || nPlayer1DownEndRow == nPlayer2DownEndRow || nPlayer1DownEndRow == nDownStart1Row || nPlayer1DownEndRow == nDownEnd1Row || nPlayer1DownEndRow == nDownStart2Row || nPlayer1DownEndRow == nDownEnd2Row || nPlayer1DownEndRow == nDownStart3Row || nPlayer1DownEndRow == nDownEnd3Row || nPlayer2DownStartRow == nPlayer2DownEndRow || nPlayer2DownStartRow == nDownStart1Row || nPlayer2DownStartRow == nDownEnd1Row || nPlayer2DownStartRow == nDownStart2Row || nPlayer2DownStartRow == nDownEnd2Row || nPlayer2DownStartRow == nDownStart3Row || nPlayer2DownStartRow == nDownEnd3Row || nPlayer2DownEndRow == nDownStart1Row || nPlayer2DownEndRow == nDownEnd1Row || nPlayer2DownEndRow == nDownStart2Row || nPlayer2DownEndRow == nDownEnd2Row || nPlayer2DownEndRow == nDownStart3Row || nPlayer2DownEndRow == nDownEnd3Row || nDownStart1Row == nDownEnd1Row || nDownStart1Row == nDownStart2Row || nDownStart1Row == nDownEnd2Row || nDownStart1Row == nDownStart3Row || nDownStart1Row == nDownEnd3Row || nDownEnd1Row == nDownStart2Row || nDownEnd1Row == nDownEnd2Row || nDownEnd1Row == nDownStart3Row || nDownEnd1Row == nDownEnd3Row || nDownStart2Row == nDownEnd2Row || nDownStart2Row == nDownStart3Row || nDownStart2Row == nDownEnd3Row || nDownEnd2Row == nDownStart3Row || nDownEnd2Row == nDownEnd3Row || nDownStart3Row == nDownEnd3Row){
		nValidated = 0; // Invalid because there would be more than 1 down tiles per row.
	}
	
	return nValidated; // Returns 1 or 0, depending on whether the conditions were met.
}


/*
	Description: This function assigns randomly-generated values to the special tile parameters (not including the player input ones).
	Precondition: Only the player input parameters are expected to already be available.
	
	@param: *nPlayer1DownTileStart - a pointer parameter for the start of the down tile inputted by Player 1.
	@param: *nPlayer1DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 1.
	
	@param: *nPlayer2DownTileStart - a pointer parameter for the start of the down tile inputted by Player 2.
	@param: *nPlayer2DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 2.
	
	@param: *nUpTile1Start - a pointer parameter for the start of the first randomly-generated up tile.
	@param: *nUpTile1End - a pointer parameter for the end of the first randomly-generated up tile.
	
	@param: *nUpTile2Start - a pointer parameter for the start of the second randomly-generated up tile.
	@param: *nUpTile2End - a pointer parameter for the end of the second randomly-generated up tile.
	
	@param: *nUpTile3Start - a pointer parameter for the start of the third randomly-generated up tile.
	@param: *nUpTile3End - a pointer parameter for the end of the third randomly-generated up tile.
	
	@param: *nDownTile1Start - a pointer parameter for the start of the first randomly-generated down tile.
	@param: *nDownTile1End - a pointer parameter for the end of the first randomly-generated down tile.
	
	@param: *nDownTile2Start - a pointer parameter for the start of the second randomly-generated down tile.
	@param: *nDownTile2End - a pointer parameter for the end of the second randomly-generated down tile.
	
	@param: *nDownTile3Start - a pointer parameter for the start of the third randomly-generated down tile.
	@param: *nDownTile3End - a pointer parameter for the end of the third randomly-generated down tile.
	
	@return: N/A

*/

void vRandomValidation(int *nPlayer1DownTileStart, int *nPlayer1DownTileEnd, int *nPlayer2DownTileStart, int *nPlayer2DownTileEnd, int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End){
	int nValidated;
	
	do {
	
		// This will generate placements, validate, and repeat until the placements are valid.
		*nUpTile1Start = nPlacementGenerator();
		*nUpTile1End = nPlacementGenerator();
		*nUpTile2Start = nPlacementGenerator();
		*nUpTile2End = nPlacementGenerator();
		*nUpTile3Start = nPlacementGenerator();
		*nUpTile3End = nPlacementGenerator();
		
		*nDownTile1Start = nPlacementGenerator();
		*nDownTile1End = nPlacementGenerator();
		*nDownTile2Start = nPlacementGenerator();
		*nDownTile2End = nPlacementGenerator();
		*nDownTile3Start = nPlacementGenerator();
		*nDownTile3End = nPlacementGenerator();
		
		nValidated = nValidation(nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
	
	}	while (nValidated == 0);
}


/*
	Description: This function generates the gameboard with the player positions and special tiles having their respective characters.
	Precondition: The parameters should already be generated and validated.
	
	@param: *nPlayer1DownTileStart - a pointer parameter for the start of the down tile inputted by Player 1.
	@param: *nPlayer1DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 1.
	
	@param: *nPlayer2DownTileStart - a pointer parameter for the start of the down tile inputted by Player 2.
	@param: *nPlayer2DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 2.
	
	@param: *nPlayer1Position - a pointer parameter for the value of Player 1's position on the board.
	@param: *nPlayer2Position - a pointer parameter for the value of Player 2's position on the board.
	
	@param: *nUpTile1Start - a pointer parameter for the start of the first randomly-generated up tile.
	@param: *nUpTile1End - a pointer parameter for the end of the first randomly-generated up tile.
	
	@param: *nUpTile2Start - a pointer parameter for the start of the second randomly-generated up tile.
	@param: *nUpTile2End - a pointer parameter for the end of the second randomly-generated up tile.
	
	@param: *nUpTile3Start - a pointer parameter for the start of the third randomly-generated up tile.
	@param: *nUpTile3End - a pointer parameter for the end of the third randomly-generated up tile.
	
	@param: *nDownTile1Start - a pointer parameter for the start of the first randomly-generated down tile.
	@param: *nDownTile1End - a pointer parameter for the end of the first randomly-generated down tile.
	
	@param: *nDownTile2Start - a pointer parameter for the start of the second randomly-generated down tile.
	@param: *nDownTile2End - a pointer parameter for the end of the second randomly-generated down tile.
	
	@param: *nDownTile3Start - a pointer parameter for the start of the third randomly-generated down tile.
	@param: *nDownTile3End - a pointer parameter for the end of the third randomly-generated down tile.
	
	@return: N/A

*/

void vCreateGameBoard(int *nPlayer1DownTileStart, int *nPlayer1DownTileEnd, int *nPlayer2DownTileStart, int *nPlayer2DownTileEnd, int *nPlayer1Position, int *nPlayer2Position, int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End){
	int nBoardSize, nTiles;
	int nDirection;
	int i, nCounter, nColumn;
	
	nBoardSize = 10; // Determines the size of the board.
	nTiles = 99; // Total number of tiles, not including 0.
	nDirection = 1; // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	nCounter = 0;
	nColumn = 0;
	
    // GAMEBOARD
	for (i = nTiles; i >= 0; i--){ // Printing tiles 99 to 0.
    	
    	if (nDirection == 1){ // Left to right. The respective values are printed once they match the number of tiles on the current iteration.
    		if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == i) && (*nPlayer2Position == i)){ 
    			printf("@<");
			}
			
	    	else if (*nPlayer1Position == i){
	    		printf("%c<", 153);
			}
			else if (*nPlayer2Position == i){
				printf("%c<", 154);
			}
			
			else if (*nUpTile1Start == i){
				printf("A<");
			}
			else if (*nUpTile1End == i){
				printf("A<");
			}
			else if (*nUpTile2Start == i){
				printf("B<");
			}
			else if (*nUpTile2End == i){
				printf("B<");
			}
			else if (*nUpTile3Start == i){
				printf("C<");
			}
			else if (*nUpTile3End == i){
				printf("C<");
			}
			
			else if (*nDownTile1Start == i){
				printf("a<");
			}
			else if (*nDownTile1End == i){
				printf("a<");
			}
			else if (*nDownTile2Start == i){
				printf("b<");
			}
			else if (*nDownTile2End == i){
				printf("b<");
			}
			else if (*nDownTile3Start == i){
				printf("c<");
			}
			else if (*nDownTile3End == i){
				printf("c<");
			}
			
			else if (*nPlayer1DownTileStart == i){ // Player input down tiles.
				printf("%c<", 148);
			}
			else if (*nPlayer1DownTileEnd == i){
				printf("%c<", 148);
			}
			else if (*nPlayer2DownTileStart == i){
				printf("%c<", 150);
			}
			else if (*nPlayer2DownTileEnd == i){
				printf("%c<", 150);
			}
			
			else if (i == 99){ // Final Tile designation.
				printf("%c<", 178);
			}
			else {
				printf("%c<" , 219); // "%c " , 219 or "%2d ", i (*Note to switch between character and integer.)
			}
			
			nCounter++; 
	    	
	    	if (nCounter == 10){ // Once the counter (column) reaches 10, it goes into the next line.
	    		nCounter = 0;
	    		nTiles -= 10;
	    		printf("\n\n");
			}
		} 
		
		else { // Right to left. The respective values are printed once they match the number of tiles on the current iteration.
			if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1) && (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1)){
    			printf("@>");
    			nColumn++;
			}
			
			
	    	else if (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1){
	    		printf("%c>", 153);
	    		nColumn++;
			}
			else if (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 154);
				nColumn++;
			}
			
			
			else if (*nUpTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("A>");
				nColumn++;
			}
			else if (*nUpTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("A>");
				nColumn++;
			}
			else if (*nUpTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("B>");
				nColumn++;
			}
			else if (*nUpTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("B>");
				nColumn++;
			}
			else if (*nUpTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("C>");
				nColumn++;
			}
			else if (*nUpTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("C>");
				nColumn++;
			}
			
			else if (*nDownTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("a>");
				nColumn++;
			}
			else if (*nDownTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("a>");
				nColumn++;
			}
			else if (*nDownTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("b>");
				nColumn++;
			}
			else if (*nDownTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("b>");
				nColumn++;
			}
			else if (*nDownTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("c>");
				nColumn++;
			}
			else if (*nDownTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("c>");
				nColumn++;
			}
			
			else if (*nPlayer1DownTileStart == nTiles - nBoardSize + nColumn + 1){ // Player input down tiles.
				printf("%c>", 148);
				nColumn++;
			}
			else if (*nPlayer1DownTileEnd == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 148);
				nColumn++;
			}
			else if (*nPlayer2DownTileStart == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 150);
				nColumn++;
			}
			else if (*nPlayer2DownTileEnd == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 150);
				nColumn++;
			}
			
			else {
				printf("%c>" , 219); // "%c " , 219 or "%2d ", nTiles - nBoardSize + nColumn + 1 (*Note to switch between character and integer.)
				nColumn++;
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){ // Once the counter reaches 10, it goes to the next line again.
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


/*
	Description: This function utilizes the gameboard function and dice roll function to increment the players' positions, and sets the conditions for the special tiles.
	Precondition: The parameters should already be generated and validated.
	
	@param: nCurrentPlayer - a parameter that switches between '1' and '2' to indicate which player's turn it is.
	
	@param: *nPlayer1DownTileStart - a pointer parameter for the start of the down tile inputted by Player 1.
	@param: *nPlayer1DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 1.
	
	@param: *nPlayer2DownTileStart - a pointer parameter for the start of the down tile inputted by Player 2.
	@param: *nPlayer2DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 2.
	
	@param: *nPlayer1Position - a pointer parameter for the value of Player 1's position on the board.
	@param: *nPlayer2Position - a pointer parameter for the value of Player 2's position on the board.
	
	@param: *nUpTile1Start - a pointer parameter for the start of the first randomly-generated up tile.
	@param: *nUpTile1End - a pointer parameter for the end of the first randomly-generated up tile.
	
	@param: *nUpTile2Start - a pointer parameter for the start of the second randomly-generated up tile.
	@param: *nUpTile2End - a pointer parameter for the end of the second randomly-generated up tile.
	
	@param: *nUpTile3Start - a pointer parameter for the start of the third randomly-generated up tile.
	@param: *nUpTile3End - a pointer parameter for the end of the third randomly-generated up tile.
	
	@param: *nDownTile1Start - a pointer parameter for the start of the first randomly-generated down tile.
	@param: *nDownTile1End - a pointer parameter for the end of the first randomly-generated down tile.
	
	@param: *nDownTile2Start - a pointer parameter for the start of the second randomly-generated down tile.
	@param: *nDownTile2End - a pointer parameter for the end of the second randomly-generated down tile.
	
	@param: *nDownTile3Start - a pointer parameter for the start of the third randomly-generated down tile.
	@param: *nDownTile3End - a pointer parameter for the end of the third randomly-generated down tile.
	
	@return: N/A

*/

void vUpdateGameBoard(int nCurrentPlayer, int *nPlayer1DownTileStart, int *nPlayer1DownTileEnd, int *nPlayer2DownTileStart, int *nPlayer2DownTileEnd, int *nPlayer1Position, int *nPlayer2Position, int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End) {
	
	int nBoardSize, nTiles;
	int nDirection;
	int i, nCounter, nColumn;
	
	int nDiceRollResult, nPlayer1RollTemp, nPlayer2RollTemp;
    char cContinueInput;
    
    
	nPlayer1RollTemp = 0; // Storage variable for the previous value of Player 1's die roll.
	nPlayer2RollTemp = 0; // Storage variable for the previous value of Player 2's die roll.
	nBoardSize = 10; // Determines the size of the board.
	nTiles = 99; // Total number of tiles, not including 0.
	nDirection = 1; // 1 for left to right, -1 for right to left. Multiplies by -1 to interchange.
	nCounter = 0;
	nColumn = 0;
	nDiceRollResult = 0; // Initial dice roll value.
    
    
    // GAMEBOARD
	for (i = nTiles; i >= 0; i--){
    	
    	if (nDirection == 1){ // Left to right. The respective values are printed once they match the number of tiles on the current iteration.
    		if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == i) && (*nPlayer2Position == i)){
    			printf("@<");
			}
			
	    	else if (*nPlayer1Position == i){
	    		printf("%c<", 153);
			}
			else if (*nPlayer2Position == i){
				printf("%c<", 154);
			}
			
			else if (*nUpTile1Start == i){
				printf("A<");
			}
			else if (*nUpTile1End == i){
				printf("A<");
			}
			else if (*nUpTile2Start == i){
				printf("B<");
			}
			else if (*nUpTile2End == i){
				printf("B<");
			}
			else if (*nUpTile3Start == i){
				printf("C<");
			}
			else if (*nUpTile3End == i){
				printf("C<");
			}
			
			else if (*nDownTile1Start == i){
				printf("a<");
			}
			else if (*nDownTile1End == i){
				printf("a<");
			}
			else if (*nDownTile2Start == i){
				printf("b<");
			}
			else if (*nDownTile2End == i){
				printf("b<");
			}
			else if (*nDownTile3Start == i){
				printf("c<");
			}
			else if (*nDownTile3End == i){
				printf("c<");
			}
			
			else if (*nPlayer1DownTileStart == i){ // Player input down tiles.
				printf("%c<", 148);
			}
			else if (*nPlayer1DownTileEnd == i){
				printf("%c<", 148);
			}
			else if (*nPlayer2DownTileStart == i){
				printf("%c<", 150);
			}
			else if (*nPlayer2DownTileEnd == i){
				printf("%c<", 150);
			}
			
			else if (i == 99){
				printf("%c<", 178);
			}
			else {
				printf("%c<" , 219); // "%c " , 219 or "%2d ", i
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){ // Goes to the next line once counter reaches 10.
	    		nCounter = 0;
	    		nTiles -= 10;
	    		printf("\n\n");
			}
		} 
		
		else { // Right to left. The respective values are printed once they match the number of tiles on the current iteration.
			if ((*nPlayer1Position == *nPlayer2Position) && (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1) && (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1)){
    			printf("@>");
    			nColumn++;
			}
			
			
	    	else if (*nPlayer1Position == nTiles - nBoardSize + nColumn + 1){
	    		printf("%c>", 153);
	    		nColumn++;
			}
			else if (*nPlayer2Position == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 154);
				nColumn++;
			}
			
			
			else if (*nUpTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("A>");
				nColumn++;
			}
			else if (*nUpTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("A>");
				nColumn++;
			}
			else if (*nUpTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("B>");
				nColumn++;
			}
			else if (*nUpTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("B>");
				nColumn++;
			}
			else if (*nUpTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("C>");
				nColumn++;
			}
			else if (*nUpTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("C>");
				nColumn++;
			}
			
			else if (*nDownTile1Start == nTiles - nBoardSize + nColumn + 1){
				printf("a>");
				nColumn++;
			}
			else if (*nDownTile1End == nTiles - nBoardSize + nColumn + 1){
				printf("a>");
				nColumn++;
			}
			else if (*nDownTile2Start == nTiles - nBoardSize + nColumn + 1){
				printf("b>");
				nColumn++;
			}
			else if (*nDownTile2End == nTiles - nBoardSize + nColumn + 1){
				printf("b>");
				nColumn++;
			}
			else if (*nDownTile3Start == nTiles - nBoardSize + nColumn + 1){
				printf("c>");
				nColumn++;
			}
			else if (*nDownTile3End == nTiles - nBoardSize + nColumn + 1){
				printf("c>");
				nColumn++;
			}
			
			else if (*nPlayer1DownTileStart == nTiles - nBoardSize + nColumn + 1){ // Player input down tiles.
				printf("%c>", 148);
				nColumn++;
			}
			else if (*nPlayer1DownTileEnd == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 148);
				nColumn++;
			}
			else if (*nPlayer2DownTileStart == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 150);
				nColumn++;
			}
			else if (*nPlayer2DownTileEnd == nTiles - nBoardSize + nColumn + 1){
				printf("%c>", 150);
				nColumn++;
			}
			
			else {
				printf("%c>" , 219); // "%c " , 219 or "%2d ", nTiles - nBoardSize + nColumn + 1
				nColumn++;
			}
			
			nCounter++;
	    	
	    	if (nCounter == 10){ // Goes to the next line once counter reaches 10.
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
		
		nDiceRollResult = nDiceRoll(); // Stores the value of the dice roll.
		if (nCurrentPlayer == 1){
			*nPlayer1Position += nDiceRollResult; // Increments Player 1's position, moving it up the board.
		}
		else if (nCurrentPlayer == 2){
			*nPlayer2Position += nDiceRollResult; // Increments Player 2's position, moving it up the board.
		}
		printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult); // Prints the player and their rolled value.
		
		if (nCurrentPlayer == 1){
			if(nDiceRollResult == 1 && nPlayer1RollTemp == 1){ // This portion gives Player 1 another turn after rolling '1' twice in a row.
				vCreateGameBoard(nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
				printf("Player 1, you rolled '1' twice in a row and get another turn! Press the Enter key to roll the die.");
				scanf("%c", &cContinueInput);
				nDiceRollResult = nDiceRoll();
				*nPlayer1Position += nDiceRollResult;
				printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
				nPlayer1RollTemp = 0;
			}
		}
		
		else if (nCurrentPlayer == 2){ 
			if(nDiceRollResult == 1 && nPlayer2RollTemp == 1){ // This portion gives Player 2 another turn after rolling '1' twice in a row.
				vCreateGameBoard(nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
				printf("Player 2, you rolled '1' twice in a row and get another turn! Press the Enter key to roll the die.");
				scanf("%c", &cContinueInput);
				nDiceRollResult = nDiceRoll();
				*nPlayer2Position += nDiceRollResult;
				printf("Player %d rolled %d.\n\n", nCurrentPlayer, nDiceRollResult);
				nPlayer2RollTemp = 0;
			}
		}
		
		if(nCurrentPlayer == 1){ // Stores each roll in the storage variable.
			nPlayer1RollTemp = nDiceRollResult;
		} else {
			nPlayer2RollTemp = nDiceRollResult;
		}
		
		// PLAYER MOVEMENT
		if (*nPlayer1Position >= 99){ // If Player 1's position is greater than or equal to '99', it is forced to be '99' as the board is displayed with the updated position.
			*nPlayer1Position = 99;
			vCreateGameBoard(nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
		}
		else if (*nPlayer2Position >= 99){ // If Player 2's position is greater than or equal to '99', it is forced to be '99' as the board is displayed with the updated position.
			*nPlayer2Position = 99;
			vCreateGameBoard(nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, nPlayer1Position, nPlayer2Position, nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
		}
		
		// In this portion, once the players' positions match the values of the start of the special tiles, they get transported to the tiles' respective ends.
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
		
		// This makes sure that Player 1 can only be affected by Player 2's down tile and vice versa.
		if (*nPlayer1Position == *nPlayer2DownTileStart){
			*nPlayer1Position = *nPlayer2DownTileEnd;
			printf("Player %d has stepped on the enemy player's DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer1Position);
		}
		else if (*nPlayer2Position == *nPlayer1DownTileStart){
			*nPlayer2Position = *nPlayer1DownTileEnd;
			printf("Player %d has stepped on the enemy player's DOWN TILE! They will be transported to Tile %d.\n\n", nCurrentPlayer, *nPlayer2Position);
		}
		
}


/*
	Description: This function initiates the game and is in charge of player switching and if the game is over or not.
	Precondition: The players' valid special tile values should already be inputted.
	
	@param: *nPlayer1DownTileStart - a pointer parameter for the start of the down tile inputted by Player 1.
	@param: *nPlayer1DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 1.
	
	@param: *nPlayer2DownTileStart - a pointer parameter for the start of the down tile inputted by Player 2.
	@param: *nPlayer2DownTileEnd - a pointer parameter for the end of the down tile inputted by Player 2.
	
	@return: N/A

*/

void vGameInstance(int *nPlayer1DownTileStart, int *nPlayer1DownTileEnd, int *nPlayer2DownTileStart, int *nPlayer2DownTileEnd){
    // Initializing of variables at the beginning of the game.
    int nCurrentPlayer;
    int nGameOver;      
	int nInitialPlayer1Position, nInitialPlayer2Position;
	int nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End;
	
	nCurrentPlayer = 1; // The game starts with Player 1.
	nGameOver = 0;		// The game is not over initially.
	
	nInitialPlayer1Position = 0; nInitialPlayer2Position = 0; // Player 1 and Player 2 start at the 0 position.
	
	nUpTile1Start = 0; nUpTile1End = 0; // Initial values of the special tiles before randomizing.
	nUpTile2Start = 0; nUpTile2End = 0;
	nUpTile3Start = 0; nUpTile3End = 0;
	
	nDownTile1Start = 0; nDownTile1End = 0;
	nDownTile2Start = 0; nDownTile2End = 0;
	nDownTile3Start = 0; nDownTile3End = 0;
	
	// Randomize and Validate Special Tile Positions
	
	vRandomValidation(nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, &nUpTile1Start, &nUpTile1End, &nUpTile2Start, &nUpTile2End, &nUpTile3Start, &nUpTile3End, &nDownTile1Start, &nDownTile1End, &nDownTile2Start, &nDownTile2End, &nDownTile3Start, &nDownTile3End);
	
	// Game Proper
    while (!nGameOver) { // While the game is not over.
    	
		vUpdateGameBoard(nCurrentPlayer, nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, &nInitialPlayer1Position, &nInitialPlayer2Position, &nUpTile1Start, &nUpTile1End, &nUpTile2Start, &nUpTile2End, &nUpTile3Start, &nUpTile3End, &nDownTile1Start, &nDownTile1End, &nDownTile2Start, &nDownTile2End, &nDownTile3Start, &nDownTile3End);
		
        if (nCurrentPlayer == 1) { // Turn switching.
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


/*
	Description: This function serves as the menu where the players' special tiles are inputted and validated.
	Precondition: There are no parameters.
	@param: N/A
	@return: N/A

*/

void vNewGame(void){
	// MENU SCREEN
	int nMenuSelection;
	int nPlayer1DownTileStart, nPlayer1DownTileEnd, nPlayer2DownTileStart, nPlayer2DownTileEnd, nPlayer1StartRow, nPlayer1EndRow, nPlayer2StartRow, nPlayer2EndRow;
	
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |                       |\n");
		printf(" | [1] Start a New Game  |\n");
		printf(" | [2] Quit              |\n");
		printf(" |                       |\n");
		printf("  -----------------------\n");
	
	printf("\nWelcome to Ups and Downs! This is a board game akin to Snakes and Ladders, with the main distinction being the presence of Up and Down Tiles, which do the same functions as Snakes and Ladders.\n");
	printf("\nPlease enter [1] to begin, or [2] to quit the game: ");
	scanf("%d", &nMenuSelection);
	
	while (nMenuSelection < 1 || nMenuSelection > 2){ // Ensures the user input is correct.
		printf("\nInvalid input. Please enter [1] to begin, or [2] to quit the game: ");
		scanf("%d", &nMenuSelection);
	}
	
	if (nMenuSelection == 1){ // Proceeds to the inputting of values.
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |   Input Down Tiles    |\n");
		printf(" |                       |\n");
		printf(" | Player 1:             |\n");
		printf(" | Player 2:             |\n");
		printf(" |                       |\n");
		printf("  -----------------------\n");
		
		printf("\nBefore the game starts, each player will be given the chance to place a Down Tile and its link anywhere on the board and only their opponent will be affected by it! However, the link may not be in the first row of the board.\n");
		printf("\nPlayer 1 will place their DOWN TILE in: ");
		scanf("%d", &nPlayer1DownTileStart);
		nPlayer1StartRow = nPlayer1DownTileStart / 10;
		
		while (nPlayer1DownTileStart <= 9 || nPlayer1DownTileStart >= 99){ // Since it is the first value, the other values will be compared to it.
				printf("\nInvalid input. Value must be between 10-98 and should not be in the same row as the other Down Tiles. Please enter another value: ");
				scanf("%d", &nPlayer1DownTileStart);
				nPlayer1StartRow = nPlayer1DownTileStart / 10;
		}
		
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |   Input Down Tiles    |\n");
		printf(" |                       |\n");
		printf(" | Player 1: %d          |\n", nPlayer1DownTileStart); // Each of the inputted values are printed.
		printf(" | Player 2:             |\n");
		printf(" |                       |\n");
		printf("  -----------------------\n");
		
		printf("\nPlayer 1 will place the link of their DOWN TILE in: ");
		scanf("%d", &nPlayer1DownTileEnd);
		nPlayer1EndRow = nPlayer1DownTileEnd / 10;
		
		// Compares the values then validates.
		while (nPlayer1DownTileEnd <= 0 || nPlayer1DownTileEnd >= 90 || nPlayer1DownTileEnd >= nPlayer1DownTileStart || nPlayer1EndRow == nPlayer1StartRow){ 
			printf("\nInvalid input. Value must be between 10-98, must be lower and must not be in the same row as the other Down Tiles. Please enter another value: ");
			scanf("%d", &nPlayer1DownTileEnd);
			nPlayer1EndRow = nPlayer1DownTileEnd / 10;
		}
		
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |   Input Down Tiles    |\n");
		printf(" |                       |\n");
		printf(" | Player 1: %d -> %d    |\n", nPlayer1DownTileStart, nPlayer1DownTileEnd);
		printf(" | Player 2:             |\n");
		printf(" |                       |\n");
		printf("  -----------------------\n");
		
		printf("\nPlayer 2 will place their DOWN TILE in: ");
		scanf("%d", &nPlayer2DownTileStart);
		nPlayer2StartRow = nPlayer2DownTileStart / 10;
		
		// Compares the values then validates.
		while (nPlayer2DownTileStart <= 9 || nPlayer2DownTileStart >= 99 || nPlayer2StartRow == nPlayer1StartRow || nPlayer2StartRow == nPlayer1EndRow){
				printf("\nInvalid input. Value must be between 10-98 and should not be in the same row as the other Down Tiles. Please enter another value: ");
				scanf("%d", &nPlayer2DownTileStart);
				nPlayer2StartRow = nPlayer2DownTileStart / 10;
		}
		
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |   Input Down Tiles    |\n");
		printf(" |                       |\n");
		printf(" | Player 1: %d -> %d    |\n", nPlayer1DownTileStart, nPlayer1DownTileEnd);
		printf(" | Player 2: %d          |\n", nPlayer2DownTileStart);
		printf(" |                       |\n");
		printf("  -----------------------\n");
		
		printf("\nPlayer 2 will place the link of their DOWN TILE in: ");
		scanf("%d", &nPlayer2DownTileEnd);
		nPlayer2EndRow = nPlayer2DownTileEnd / 10;
		
		// Compares the values then validates.
		while (nPlayer2DownTileEnd <= 0 || nPlayer2DownTileEnd >= 90 || nPlayer2DownTileEnd >= nPlayer2DownTileStart || nPlayer2EndRow == nPlayer1StartRow || nPlayer2EndRow == nPlayer1EndRow || nPlayer2EndRow == nPlayer2StartRow){
			printf("\nInvalid input. Value must be between 10-98, must be lower, and must not be in the same row as the other Down Tiles. Please enter another value: ");
			scanf("%d", &nPlayer2DownTileEnd);
			nPlayer2EndRow = nPlayer2DownTileEnd / 10;
		}
		
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |   Input Down Tiles    |\n");
		printf(" |                       |\n");
		printf(" | Player 1: %d -> %d    |\n", nPlayer1DownTileStart, nPlayer1DownTileEnd);
		printf(" | Player 2: %d -> %d    |\n", nPlayer2DownTileStart, nPlayer2DownTileEnd);
		printf(" |                       |\n");
		printf("  -----------------------\n");
		
		// Initializes the game proper after validating each of the inputted special tiles.
		printf("\nBoth players' Down Tiles and their links are displayed above. Are you ready to start?\n");
		printf("Legend: Player 1 - %c\tPlayer 2 - %c\n", 153, 154);
		printf("The game will commence shortly...\n\n");
		getchar();
		sleep(3);
		
		vGameInstance(&nPlayer1DownTileStart, &nPlayer1DownTileEnd, &nPlayer2DownTileStart, &nPlayer2DownTileEnd);
	}
	
	else if (nMenuSelection == 2){ // Closing screen.
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |                       |\n");
		printf(" |  Thanks for playing!  |\n");
		printf(" |                       |\n");
		printf(" |                       |\n");
		printf("  -----------------------\n");
	}
	
}

int main(){
	char cYesNo;
	
	srand(time(NULL));
	vNewGame();	// Starts the game.
	
	// Appears after the game, gives the user a chance to run through the entire code and play the game again.
	while (cYesNo != 'N' && cYesNo != 'n'){
	printf(" Do you want to play again? Enter [Y] if Yes and [N] if No: ");
    scanf(" %c", &cYesNo);
    while (cYesNo != 'Y' && cYesNo != 'y' && cYesNo != 'N' && cYesNo != 'n'){
    	printf("Invalid input. Enter [Y] if Yes and [N] if No: ");
    	scanf(" %c", &cYesNo);
	}
	
    if (cYesNo == 'Y' || cYesNo == 'y'){ // If the user selects 'Yes', the game will start anew.
    	system("cls");
        vNewGame();
	}
	
	else if (cYesNo == 'N' || cYesNo == 'n'){ // If the user selects 'No', the closing screen will be displayed.
		system("cls");
		
		printf("  -----------------------\n");
		printf(" |                       |\n");
		printf(" |    Ups and Downs!     |\n");
		printf(" |                       |\n");
		printf(" |  Thanks for playing!  |\n");
		printf(" |                       |\n");
		printf(" |                       |\n");
		printf("  -----------------------\n");
	}
	}
	
	return 0;
}