#include<stdio.h>
#define SIZE 12

// 1)Function to print out the maze (2-dimentional array)
void Print_maze(char maze[SIZE][SIZE]){
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++)
			printf("%c ", maze[i][j]);
		printf("\n");
	}
	printf("\n");
}
// 2)Function to find the starting point when going inside the maze
int Find_starting_point(char maze[SIZE][SIZE]){
	int y_position;
	for(int i=0;i<SIZE;i++){
		//The starting point is in the first column so x_position is equal to 0
		//We just find the first y_position (row number) tho find the starting point
		if(maze[i][0]=='.')
			y_position=i;
	}
	return y_position;
}
// 3)Function to check if the point goes inside the maze or not
int Check_valid_spot(char maze[SIZE][SIZE],int row,int column){
	if(row >= 0 && row < 12 && column >= 0 && column < 12)
		return maze[row][column] == '.';
}
// 4)Function for moving point 
int Traverse(char maze[SIZE][SIZE], int row, int column){
	static int step = 1;
	//if Check_valid_spot function returns 1, assign this position equal to '*'
	if(Check_valid_spot(maze, row, column) == 1){
	    maze[row][column] = '*';
	    
	    printf("Step %d:\n", step++);
	    Print_maze(maze);
	    
		if(column == 11) //ending condition
			return 1;

		//up: We always go up first
		int value = Traverse(maze, row - 1, column);
		
		//right: If we cannot go up due to the '#', we go right
		if(value == 0)
			value = Traverse(maze, row, column + 1);
			
		//down: If we also cannot go right due to the '#', we go down
		if(value == 0)
			value=Traverse(maze, row + 1, column);
			
		//left: If we also cannot go down due to the '#', we go left
		if(value == 0)
			value = Traverse(maze, row, column - 1);
		//return its position for the next moving step	
		return value;
	}
}	
		
int main(){
	char maze[12][12] = {
       //0///1///2///3///4///5///6///7///8///9///10//11///
        {'#','#','#','#','#','#','#','#','#','#','#','#'},//0
        {'#','.','.','.','#','.','.','.','.','.','.','#'},//1
        {'.','.','#','.','#','.','#','#','#','#','.','#'},//2
        {'#','#','#','.','#','.','.','.','.','#','.','#'},//3
        {'#','.','.','.','.','#','#','#','.','#','.','.'},//4
        {'#','#','#','#','.','#','.','#','.','#','.','#'},//5
        {'#','#','.','#','.','#','.','#','.','#','.','#'},//6
        {'#','#','.','#','.','#','.','#','.','#','.','#'},//7
        {'#','.','.','.','.','.','.','.','.','#','.','#'},//8
        {'#','#','#','#','#','#','.','#','#','#','.','#'},//9
        {'#','.','.','.','.','.','.','#','.','.','.','#'},//10
        {'#','#','#','#','#','#','#','#','#','#','#','#'} //11
	};
	
	Print_maze(maze);
	int start=Find_starting_point(maze);//determine the starting point
	if(Traverse(maze, start, 0) == 1) 
		printf("COULD SOLVE\n");
	else
		printf("COULD NOT SOLVE\n");

	Print_maze(maze);

	return 0;
}
