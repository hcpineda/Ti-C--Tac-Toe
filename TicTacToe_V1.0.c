/* Game Program made by Hector Cortez Pineda :) */

#include <stdio.h>

#include <stdlib.h>

#include <time.h>
   
//Function Declarations
 
    //declaring the function of a player's choice on the board.
    void oppTurn();
    
    //displays the gameboard on the virtual monitor.
    void GameBoard();
    
    //checks whether or not the space entered by the user is reasonable.
    int SanityCheck(int);
    
    //checks if the player has won the game.
    int WinCheck();
    
    //checks if there has been a vertical win pattern.
    int Vertical();
    
    //checks if there has been a horizontal win pattern.
    int Horizontal();
    
    //checks if there has been a diagonal win pattern.
    int Diagonal();
    
    //checks if the computer has won the game.
    int OppWinCheck();
    
    //checks if the computer has a vertical win pattern.
    int OppVertical();
    
    //checks if the computer has a horizontal win pattern.
    int OppHorizontal();
    
    //checks if the computer has a diagonal win pattern.
    int OppDiagonal();

    //global declaration of a string array which draws the tic-tac-toe board
    char board[] = {"______   "};

//main function of the program.
int main() {
    
    int square;     //this variable corresponds to the space a player chooses. 
    
    printf("Welcome to Tic-Tac-Toe!\n"); //prints a small welcome message.
    
    //this for loop runs for the amount of turns the player has, which is five.
    for(int turn = 1; turn <= 5; turn++) {
        
        GameBoard(); //anytime GameBoard is called, the board is displayed.
        
        scanf("%d", &square);
        
        /* after checking if the user's input is within a reasonable range, 
        it is stored to "square". */
        square = SanityCheck(square);
        
        /* if an X or an O has not yet been assigned to a space on the board,
        the user's choice of square is placed on the board. */
        if(board[square - 1] != 'X' && board[square - 1] != 'O')
            board[square - 1] = 'X';
        
        //otherwise, while the user inputs an erroneous value, this loop runs.
        else
            while(board[square - 1] == 'X' || board[square - 1] == 'O' && square != 0) {
                
                //an error message.
                printf("\nThere's already an X or an O there... try again.\n");
                
                //prompts the user to input a new value.
                scanf("%d", &square);
                
                //once the value chosen is reasonable, that value is used.
                if(board[square - 1] != 'X' && board[square - 1] != 'O') {
                    
                    //the value chosen is placed on the board.
                    board[square - 1] = 'X';
                    
                    /* square gets the value "0" to exit the while loop once
                    the if statement's condition is met. */
                    square = 0;
                    
                }
                
            }
        
        //the computer gets a turn until the user's fifth turn, where the game ends.
        if(turn != 5)
            oppTurn(); //oppTurn is called for the computer to place an "O" on the board.
            
        /* each time the loop runs, the program checks if the user or the 
        computer has won. */
        if(WinCheck() == 1 || OppWinCheck() == 1) {
            
            //GameBoard is called to print the completed board one last time.
            GameBoard();
            
            return 0;   //terminates the program.
            
        }
        
    }

    //GameBoard is called to print the completed board one last time.
    GameBoard();
    
    //text which indicates that a game ended in a tie.
    printf("\nCat's Game...\n");
    
    return 0;   //terminates the program.
    
}

//this function checks whether or not the user's input is within a resonable range.
int SanityCheck(int space) {
    
    //this while loop checks the condition of the value in the correct range, (0,9).
    while(space < 1 || space > 9) {
        
        //error message.
        printf("\nThat space is not on the board! Try again :\n");
        
        //prompts for a new value to be entered.
        scanf("%d", &space);
            
            //if the new value entered is reasonable, this value is returned.
            if(space > 0 && space < 9)
                return(space);
        
    }
    
    //if the original value entered is reasonable, the same value is returned.
    return(space);
    
}

//this function runs for the computer to randomly place an "O" on the board.
void oppTurn() {
    
    //this variable exists for the while loop to run until a resonable value is chosen.
    int hold = 0;

    //ensures the value chosen is pseudorandom 
    srand(time(0));
    
    while(hold == 0) {
        
        //choice gets a pseudorandom value between 1 and 9.
        int choice = rand() % 10;
        
        //this if statement checks if the value chosen has not been chosen already.
        if(board[choice - 1] != 'X' && board[choice - 1] != 'O') {
            
            //if it hasn't, the computer picks this spot to place an "O".
            board[choice - 1] = 'O';
            
            //hold is given a value other than 0 to break the while loop.
            hold = choice;
        
        }
        
    }
    
}

//this function prints the current gameboard every time it is called.
void GameBoard() {
    
    printf("\n%c|%c|%c", board[0], board[1], board[2]); //first row.
    
    printf("\n%c|%c|%c", board[3], board[4], board[5]); //second row.
    
    printf("\n%c|%c|%c\n\n", board[6], board[7], board[8]); //third row.
    
}

//this function checks if the player has won in any manner.
int WinCheck() {
    
    //if the player has won horizontally, this statement runs.
    if(Horizontal() == 1) {
        
        printf("\nYou win!\n"); //winning message.
            
        return 1; //if true, the function returns 1.
    }
    
    //if the player has won vertically, this statement runs.    
    else if(Vertical() == 1) {
        
        printf("\nYou win!\n");
        
        return 1; //if true, the function returns 1.
        
    }
    
    //if the player has won diagonal, this statement runs.
    else if(Diagonal() == 1) {
        
        printf("\nYou win!\n"); //winning message.
        
        return 1; //if true, the function returns 1.
        
    }
    
}

//this functions checks for a horizontal win.
int Horizontal() {
    
    //if the top row has all "X", the function returns 1.
    if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
        return 1;
    
    //if the middle row has all "X", the function returns 1.
    else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
        return 1;
    
    //if the bottom row has all "X", the function returns 1.
    else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
        return 1;    
    
    //otherwise, the function returns 0.
    else
        return 0;
    
}

//this function checks for a vertical win.
int Vertical() {
    
    //if the first column has all "X", the function returns 1.
    if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
        return 1;
    
    //if the second column has all "X", the function returns 1.
    else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
        return 1;
    
    //if the third column has all "X", the function returns 1.
    else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
        return 1;    
    
    //otherwise, the function returns 0.
    else
        return 0;
}

//this function checks for a diagonal win.
int Diagonal() {
    
    //if the board has all "X" from the top left to the bottom right, 1 is returned.
    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
        return 1;
    
    //if the board has all "X" from the top right to the bottom left, 1 is returned.
    else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
        return 1;
    
    //otherwise, 0 is returned.
    else
        return 0;
}

//this function checks if the player has lost in any manner. 
int OppWinCheck() {
    
    //if the player has lost horizontally, this statement runs.
    if(OppHorizontal() == 1) {
        
        printf("\nYou lose!\n"); //losing message.
            
        return 1; //if true, the function returns 1.
    }
    
    //if the player has lost vertically, this statement runs.    
    if(OppVertical() == 1) {
        
        printf("\nYou lose!\n"); //losing message.
        
        return 1; //if true, the function returns 1.
        
    }
    
    //if the player has lost diagonally, this statement runs.
    else if(OppDiagonal() == 1) {
        
        printf("\nYou lose!\n"); //losing message.
        
        return 1; //if true, the function returns 1.
        
    }
    
}

//this functions checks for a horizontal loss.
int OppHorizontal() {
    
    //if the top row has all "O", the function returns 1.
    if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
        return 1;
    
    //if the middle row has all "O", the function returns 1.
    else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
        return 1;
    
    //if the bottom row has all "O", the function returns 1.
    else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
        return 1;    
    
    //otherwise, the function returns 0.
    else
        return 0;
    
}

//this function checks for a vertical win.
int OppVertical() {
    
    //if the first column has all "O", the function returns 1.
    if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
        return 1;
    
    //if the second column has all "O", the function returns 1.
    else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
        return 1;
    
    //if the third column has all "O", the function returns 1.
    else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
        return 1;    
    
    //otherwise, 0 is returned.
    else
        return 0;
}

//this function checks for a diagonal win.
int OppDiagonal() {
    
    //if the board has all "O" from the top left to the bottom right, 1 is returned.
    if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
        return 1;
    
    //if the board has all "X" from the top right to the bottom left, 1 is returned.
    else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
        return 1;
    
    //otherwise, 0 is returned.
    else
        return 0;
}

//thanks for playing! © 2023 HCP