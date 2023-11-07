/*
	Description: This program is a board game called Ups and Downs.
	Author: Marvin Ivan C. Mangubat - S21A
	Acknowledgments: (references and sites/sources)
*/

#include<stdio.h>



int main(){
    // Initializing of variables at the beginning of the game.
    int nCurrentPlayer = 1;  // The game starts with Player 1.
    int nGameOver = 0;      // The game is not over initially.

    while (!nGameOver) { // While the game is not over.
		
		// * PUT FUNCTION FOR DICE ROLL AND UPDATED GAME BOARD HERE.
		
        if (nCurrentPlayer == 1) { // Switch turns
            nCurrentPlayer = 2;
        } else {
            nCurrentPlayer = 1;
        }
    }
	// * GAME OVER	
	return 0;
}