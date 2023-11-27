#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int nPlacementGenerator(void){
	int nResult;
	int nMinimum = 1; // because special tiles cannot be placed at the start.
	int nMaximum = 98; // because special tiles cannot be placed at the end.
	
	nResult = (rand() % (nMaximum - nMinimum + 1)) + nMinimum;
	return nResult;
}

int nGetHighestTile (int *nTile1Start, int *nTile1End, int *nTile2Start, int *nTile2End, int *nTile3Start, int *nTile3End){
	int nHighestTile = *nTile1Start; // Assume the first parameter is initially the highest tile.
	
	// Check the remaining parameters and update nHighestTile if a larger value is found.
	
	if (*nTile1End > nHighestTile){
		nHighestTile = *nTile1End;
	}
	
	if (*nTile2Start > nHighestTile){ // If over else if because it will stop the entire process once nHighestTile gets updated.
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

int nValidation(int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End){
	int nUpStart1Row, nUpEnd1Row, nUpStart2Row, nUpEnd2Row, nUpStart3Row, nUpEnd3Row, nDownStart1Row, nDownEnd1Row, nDownStart2Row, nDownEnd2Row, nDownStart3Row, nDownEnd3Row;
	int nHighestUpTile, nHighestDownTile;
	int nValidated;
	
	nValidated = 1; // The special tiles' placements are initially valid.
	
	nUpStart1Row = *nUpTile1Start / 10;
	nUpEnd1Row = *nUpTile1End / 10;
	nUpStart2Row = *nUpTile2Start / 10;
	nUpEnd2Row = *nUpTile2End / 10;
	nUpStart3Row = *nUpTile3Start / 10;
	nUpEnd3Row = *nUpTile3End / 10;
	
	nDownStart1Row = *nDownTile1Start / 10;
	nDownEnd1Row = *nDownTile1End / 10;
	nDownStart2Row = *nDownTile2Start / 10;
	nDownEnd2Row = *nDownTile2End / 10;
	nDownStart3Row = *nDownTile3Start / 10;
	nDownEnd3Row = *nDownTile3End / 10;
	
	nHighestUpTile = nGetHighestTile(nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End);
	nHighestDownTile = nGetHighestTile(nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
	
	if (nHighestUpTile > nHighestDownTile){
		nValidated = 0; // Invalid because the last special tile would then be an up tile.
	}
	
	else if (*nUpTile1Start > *nUpTile1End || *nUpTile2Start > *nUpTile2End || *nUpTile3Start > *nUpTile3End){
		nValidated = 0; // Invalid because up tiles should go from Down to Up.
	}
	
	else if (*nDownTile1Start < *nDownTile1End || *nDownTile2Start < *nDownTile2End || *nDownTile3Start < *nDownTile3End){
		nValidated = 0; // Invalid because down tiles should go from Up to Down.
	}
	
	else if (nUpStart1Row == nUpEnd1Row || nUpStart1Row == nUpStart2Row || nUpStart1Row == nUpEnd2Row || nUpStart1Row == nUpStart3Row || nUpStart1Row == nUpEnd3Row || nUpEnd1Row == nUpStart2Row || nUpEnd1Row == nUpEnd2Row || nUpEnd1Row == nUpStart3Row || nUpEnd1Row == nUpEnd3Row || nUpStart2Row == nUpEnd2Row || nUpStart2Row == nUpStart3Row || nUpStart2Row == nUpEnd3Row || nUpEnd2Row == nUpStart3Row || nUpEnd2Row == nUpEnd3Row || nUpStart3Row == nUpEnd3Row){
		nValidated = 0; // Invalid because there would be more than 1 up tiles per row.
	}
	
	else if (nDownStart1Row == nDownEnd1Row || nDownStart1Row == nDownStart2Row || nDownStart1Row == nDownEnd2Row || nDownStart1Row == nDownStart3Row || nDownStart1Row == nDownEnd3Row || nDownEnd1Row == nDownStart2Row || nDownEnd1Row == nDownEnd2Row || nDownEnd1Row == nDownStart3Row || nDownEnd1Row == nDownEnd3Row || nDownStart2Row == nDownEnd2Row || nDownStart2Row == nDownStart3Row || nDownStart2Row == nDownEnd3Row || nDownEnd2Row == nDownStart3Row || nDownEnd2Row == nDownEnd3Row || nDownStart3Row == nDownEnd3Row){
		nValidated = 0; // Invalid because there would be more than 1 up tiles per row.
	}
	
	printf("\n\nThe highest up tile is %d\n\n", nHighestUpTile);
	printf("\n\nThe highest down tile is %d\n\n", nHighestDownTile);
	return nValidated;
}


void vRandomValidation(int *nUpTile1Start, int *nUpTile1End, int *nUpTile2Start, int *nUpTile2End, int *nUpTile3Start, int *nUpTile3End, int *nDownTile1Start, int *nDownTile1End, int *nDownTile2Start, int *nDownTile2End, int *nDownTile3Start, int *nDownTile3End){
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
		
		printf("\n%d\n", *nUpTile1Start);
		printf("\n%d\n", *nUpTile1End);
		printf("\n%d\n", *nUpTile2Start);
		printf("\n%d\n", *nUpTile2End);
		printf("\n%d\n", *nUpTile3Start);
		printf("\n%d\n", *nUpTile3End);
		
		printf("\n\n%d\n", *nDownTile1Start);
		printf("\n%d\n", *nDownTile1End);
		printf("\n%d\n", *nDownTile2Start);
		printf("\n%d\n", *nDownTile2End);
		printf("\n%d\n", *nDownTile3Start);
		printf("\n%d\n", *nDownTile3End);
		
		nValidated = nValidation(nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End);
	
	}	while (nValidated == 0);
}

int main(){
	srand(time(NULL));
	int test, test2;
	int nInitialPlayer1Position, nInitialPlayer2Position;
	int nUpTile1Start, nUpTile1End, nUpTile2Start, nUpTile2End, nUpTile3Start, nUpTile3End, nDownTile1Start, nDownTile1End, nDownTile2Start, nDownTile2End, nDownTile3Start, nDownTile3End;
	
	nInitialPlayer1Position = 0; nInitialPlayer2Position = 0; // Player 1 and Player 2 start at the 0 position.
	
	nUpTile1Start = 4; nUpTile1End = 95; // Initial values of the special tiles before randomizing.
	nUpTile2Start = 15; nUpTile2End = 85;
	nUpTile3Start = 33; nUpTile3End = 43;
	
	nDownTile1Start = 97; nDownTile1End = 8;
	nDownTile2Start = 81; nDownTile2End = 19;
	nDownTile3Start = 79; nDownTile3End = 26;
	
	
	test = nPlacementGenerator();
	printf("%d\n\n", test);
	
	test2 = nValidation(&nUpTile1Start, &nUpTile1End, &nUpTile2Start, &nUpTile2End, &nUpTile3Start, &nUpTile3End, &nDownTile1Start, &nDownTile1End, &nDownTile2Start, &nDownTile2End, &nDownTile3Start, &nDownTile3End);
	printf("%d\n", test2);
	
	vRandomValidation(&nUpTile1Start, &nUpTile1End, &nUpTile2Start, &nUpTile2End, &nUpTile3Start, &nUpTile3End, &nDownTile1Start, &nDownTile1End, &nDownTile2Start, &nDownTile2End, &nDownTile3Start, &nDownTile3End);
	return 0;
}