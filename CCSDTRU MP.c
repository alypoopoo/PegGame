#include <stdio.h>
#include <stdbool.h>

#define PEGCOUNT 9
#define ROW 3
#define COLUMN 3

void initialize_board(int board[ROW][COLUMN])
{
	int i,j;
  // Empty spaces are represented as 0
  for ( i = 0; i < 3; i++) 
  {
  	for(j=0;j<3;j++)
  	{
  		    board[i][j] = 0;
	  }
  }
}

void print_board(int board[ROW][COLUMN], int x, int y, int peg)
{
    int i,j;
    printf("\n");
    printf("    1   2   3\n");
    for (i = 0; i < 3; i++) 
    {
        printf("  +---+---+---+\n");
        printf("%d ", i + 1);
        for (j = 0; j < 3; j++) 
        {
            printf("| ");
            if (i == x-1 && j == y-1) 
            {
                printf("%d ", peg);
            } else {
                printf("%d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("  +---+---+---+\n");
}



void StoreValues(int ONE[3], int TWO[3], int THREE[3], int FOUR[3], int FIVE[3], int SIX[3], int x, int y, int peg, int* index1,int* index2,int* index3,int* index4, int* index5, int* index6)
{

	// Store the peg in the corresponding array
    if (x == 1) 
	{ // Top row
        if (y == 1 || y == 2 || y == 3) 
		{ 
            ONE[*index1] = peg;
            (*index1)++;
        }
    } else if (x == 2) 
	{ // Middle row
        if (y == 1 || y == 2 || y == 3) 
		{ 
            TWO[*index2] = peg;
            (*index2)++;

        }
    } else if (x == 3) 
	{ // Bottom row
        if (y == 1 || y == 2 || y == 3) 
		{ 
            THREE[*index3] = peg;
            (*index3)++;
        }
    }

    if (y == 1) 
	{ // Left column
        if (x == 1 || x == 2 || x == 3) 
		{ 
            FOUR[*index4] = peg;
            (*index4)++;

        }
    } else if (y == 2) 
	{ // Center column
        if (x == 1 || x == 2 || x == 3) 
		{ 
            FIVE[*index5] = peg;
            (*index5)++;
            
        }
    } else if (y == 3) 
	{ // Right column
        if (x == 1 || x == 2 || x == 3) 
		{ 
            SIX[*index6] = peg;
            (*index6)++;
        }
    }

}


int okPeg(int pegs[PEGCOUNT], int* peg, int* x, int* y)
{
    int i;
    for (i = 0; i < PEGCOUNT; i++)
    {
        if (pegs[i] == *peg) // checks if peg input is from 1-9
        {            
            if ((*x >= 1 && *x <= 3) && (*y >= 1 && *y <= 3)) // checks if coordinate is for 3x3 grid
            {
                return 1; // valid
            }
            else {
                return 0; // invalid
            }
        }
    }
    return 0; // peg not found
}

int okPos(int board[ROW][COLUMN], int x, int y)
{
    // Check if the specific position on the board is empty (0)
    if (board[x - 1][y - 1] == 0)
    {
        return 1; // valid
    }
    else
    {
        return 0; // invalid (position already has a peg)
    }
}


void removeusedpegs(int Peg[], int peg) // removes the peg from the available pegs
{
    int i;
    for (i = 0; i < 9; i++)
	{
        if (Peg[i] == peg)
		{
            Peg[i] = 0; // Set the peg value to 0 to remove it
        }
    }
}

bool GameOver(int ONE[3], int TWO[3], int THREE[3], int FOUR[3], int FIVE[3], int SIX[3], int* index1, int* index2, int* index3, int* index4, int* index5, int* index6)
{
	int a, b, c, d, e, f;
	
    int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	int sum5 = 0;
	int sum6 = 0;
	int totalsum = 0; 
	
    if(*index1==3) //all top row positions have a peg
    {
        for( a = 0; a < 3; a++)
        {
            sum1 += ONE[a];  //sum of top row
        }
        
        if(sum1 < 15)
        {
            return true; //sum is less than 15 == game ends
        }
    }
    
    if(*index2==3) //all middle row positions have a peg
    {
        for( b = 0; b < 3; b++)
        {
            sum2 += TWO[b];  //sum of middle row
        }
        
        if(sum2 < 15)
        {
            return true; //sum is less than 15 == game ends
        }
    }
    
    if(*index3==3) //all bottom row positions have a peg
    {
        for(c = 0; c < 3; c++)
        {
            sum3 += THREE[c]; //sum of bottom row
        }
        
        if(sum3 < 15)
        {
            return true; //sum is less than 15 == game ends
        }
    }
    
    if(*index4==3) //all left column positions have a peg
    {
        for( d = 0; d < 3; d++)
        {
            sum4 += FOUR[d]; //sum of left column
        }
        
        if(sum4 < 15)
        {
            return true; //sum is less than 15 == game ends
        }
    }
    
    if(*index5==3) //all center column positions have a peg
    {
        for( e = 0; e < 3; e++)
        {
            sum5 += FIVE[e]; //sum of center column
        }
        
        if(sum5 < 15)
        {
            return true; //sum is less than 15 == game ends
        }
    }
    
    if(*index6==3) //all right column positions have a peg
    {
        for(f = 0; f < 3; f++)
        {
            sum6 += SIX[f]; //sum of right column
        }
        
        if(sum6 < 15)
        {
            return true; //sum is less than 15 == game ends
        }
    }
    
    totalsum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6; 
    
    if(totalsum == 90)
    {
        return true; //sum of all rows and columns == all pegs have been placed == game ends
    }
    
    return false; // game continues
}

int main()
{
	//initialize board
    int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    
    //peg and their position to be used for sum
	int ONE[3], TWO[3], THREE[3], FOUR[3], FIVE[3], SIX[3];
	
	/*ONE[] (TOP ROW)
	T = {(1,1), (1,2), (1,3)} 
	if (x==1 && y==1) || (x==1 && y==2) || (x==1 && y==3)
	
	TWO[](MIDDLE ROW)
	M = {(2,1), (2,2), (2,3)}
	if (x==2 && y==1) || (x==2 && y==2) || (x==2 && y==3)
	
	THREE[](BOTTOM ROW)
	B = {(3,1), (3,2), (3,3)}
	if (x==3 && y==1) || (x==3 && y==2) || (x==3 && y==3)
	
	FOUR[](LEFT COLUMN)
	L = {(1,1), (2,1), (3,1)}
	if (x==1 && y==1) || (x==2 && y==1) || (x==3 && y==1)
	
	FIVE[](CENTER COLUMN)
	C = {(1,2), (2,2), (3,2)}
	if (x==1 && y==2) || (x==2 && y==2) || (x==3 && y==2)
	
	SIX[](RIGHT COLUMN)
	R = {(1,3), (2,3), (3,3)}
	if (x==1 && y==3) || (x==2 && y==3) || (x==3 && y==3)*/

	
	
	//useable pegs
	int pegs[PEGCOUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    //Indexes
    int index1=0;
	int index2=0;
	int index3=0;
	int index4=0;
	int index5=0;
	int index6=0;

	//Intro Screen
	printf("\n                                                 WELCOME TO OUR GAME\n");
	printf("\nMechanics: In this game of 2 Players, players will alternate between placing pegs that consist of numbers 1-9.\n");
	printf("\tThe first person who accumulates a sum of LESS THAN 15 within either a row or a column LOSES the game.\n");
	printf("\tGOODLUCK AND MAY THE BEST MAN WIN!\n");
	
	//other declarations
	int x=0;
	int y=0;
	int peg;
	int ok1;
	int ok2;
	bool over = false; 
	bool turn = true;

	
	over = GameOver(ONE,TWO,THREE, FOUR, FIVE, SIX, &index1, &index2, &index3, &index4, &index5, &index6);
	initialize_board(board);
	print_board(board, x, y, peg);
	
	do{
		if(turn)
		{
			printf("\nPlayer 1's Turn\n");
		}
		else
		{
			printf("\nPlayer 2's Turn\n");
		}
	    // get user input for peg number and coordinates
	    printf("Enter peg number (1-9): ");
	    scanf("%d", &peg);
	    printf("Enter x and y coordinate with a space in between: ");
	    scanf("%d %d", &x, &y);
	    
	    ok1=okPeg(pegs, &peg, &x, &y); //checks if peg input is valid 
		ok2=okPos(board, x, y); //checks if position input is valid
	    if( ok1 > 0 && ok2 > 0) //if both conditions are valid (return 1) proceed with the game
	    {
	    	//store values in corresponding array
	    	StoreValues(ONE, TWO, THREE, FOUR, FIVE, SIX, x, y, peg, &index1,&index2,&index3,&index4,&index5,&index6);
	    	
	    	// update grid with the peg at the specified coordinates
	    	board[x-1][y-1] = peg;
	    	
	    	// remove peg that has been used to prohibit repetition 
	    	removeusedpegs(pegs, peg);
	    	
			// display the grid with the peg at the specified position
	   		print_board(board, x, y, peg);
	   		 
	   		 
	   		//check if game is over
			over = GameOver(ONE,TWO,THREE, FOUR, FIVE, SIX, &index1, &index2, &index3, &index4, &index5, &index6);
			
			if(over)
			{
				turn=turn; //retains turn if game is over
			}else
			turn=!turn; //swaps turn if game is not over


		}else
		printf("Invalid Input!\n"); //if  conditions are invalid (return 0)


	}while(!over); //loop until game is not over
    
	if(over) //if game is over
    {
        if(turn)
        {
            printf("\nPlayer 2 is the Winner!!!\n"); //2nd player wins since 1st player accumulated less than 15 in a row or column
        }
        else
        {
            printf("\nPlayer 1 is the Winner!!!\n"); //1st player wins since 2nd player accumulated less than 15 in a row or column
        }
    }

	return 0;
	
}
