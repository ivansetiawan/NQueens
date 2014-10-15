/* This is an algorithm to print all ways of arranging eight queens on a 8x8 chess
 * board so that none of them share the same row, column, or diagonal.
 * When the queen is placed in the current column, the program will check for clashes
 * with the already placed queen. If we find the a row with no clash, we mark the row and column
 * as true. When the queen clashes, we do the backtrack and return false.
*/

#define SIZE 8
#include<stdio.h>

 
/* A utility function to print solution */
void placeQueens(int board[SIZE][SIZE])
{
    for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			printf(" %d", board[i][j]);
		}
		printf("\n");
	}
}
 
/* This function will do the check if there is a clash between each queen */
bool checker(int board[SIZE][SIZE], int row, int col){
	int i, j;
	//Check the left side of the board
	for(i=0; i<col; i++){
		if(board[row][i])
			return false;
	}
	
	//Check the upper diagonal
	for(i=row, j=col; i>=0 && j>=0; i--, j--){
		if(board[i][j]){
			return false;
		}
	}
	
	//Check the lower diagonal
	for(i=row, j=col; i<SIZE && j>=0; i++, j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}
 
bool solve(int board[SIZE][SIZE], int col){
	//Return true if all of the queens are placed
	if(col >= SIZE){
		return true;
	}
	
	//Do the check and place the queens in the the rows one by one
	for(int i=0; i<SIZE; i++){
		//Check if we can place the queens in the board[i][col]
		if(checker(board, i, col)){
			board[i][col] = 1;
			//Recursively call the solve function
			if(solve(board, col + 1) == true)
				return true;
			//If we cannot place the queens, then we remove the queens from board[i][col]
			board[i][col] = 0;
		}
	}
	return false;
}


//This function will solve the problems using backtrack method. It return false if
//the queens cannot be placed. Otherwise, return true and print the solutions
bool solveBacktrack(){
	int board[SIZE][SIZE] = {{0,0,0,0,0,0,0,0}, 
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0}};
	if(solve(board, 0) == false){
		printf("No solution \n");
		return false;
	}
	//Call the method to print all queens
	placeQueens(board);
	return true;
}
 
// The main program
int main()
{
    solveBacktrack();
	getchar();
    return 0;
}

