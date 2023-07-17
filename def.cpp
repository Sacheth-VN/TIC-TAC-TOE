#include <iostream>
#include "dec.h"
using namespace std;

// Global Declarations
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position;
string wonSym;
string sym1, sym2;

// Introduction Function
void intro()
{
    cout << "Press [ENTER] to begin: " << endl;
    getchar();
    cout << "-------------------------------" << endl;
    cout << "          TIC-TAC-TOE          " << endl;
    cout << "-------------------------------" << endl
         << endl;

    cout << "Player 1, Enter your symbol: ";
    cin >> sym1;
    cout << "Player 2, Enter your symbol: ";
    cin >> sym2;
    cout << endl;

    cout << "Player 1's symbol is: " << sym1 << endl;
    cout << "Player 2's symbol is: " << sym2 << endl;
    cout << endl;

    cout << "The 3x3 board is shown below: " << endl;
    cout << "     |     |     " << endl;
    cout << "  1  |  2  |  3  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  4  |  5  |  6  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  7  |  8  |  9  " << endl;
    cout << "     |     |     " << endl
         << endl;

    return;
}

// Function to check whether there is a winner
bool isWinner()
{
    // Checking the rows
    if (board[0] == board[1] && board[1] == board[2] && board[1] != " ")
    {
        wonSym = board[1];
        return true;
    }
    else if (board[3] == board[4] && board[4] == board[5] && board[4] != " ")
    {
        wonSym = board[4];
        return true;
    }
    else if (board[6] == board[7] && board[7] == board[8] && board[7] != " ")
    {
        wonSym = board[7];
        return true;
    }

    // Checking the columns
    if (board[0] == board[3] && board[3] == board[6] && board[3] != " ")
    {
        wonSym = board[3];
        return true;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[4] != " ")
    {
        wonSym = board[4];
        return true;
    }
    else if (board[2] == board[5] && board[5] == board[8] && board[5] != " ")
    {
        wonSym = board[5];
        return true;
    }

    // Checking the diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[4] != " ")
    {
        wonSym = board[4];
        return true;
    }
    else if (board[2] == board[4] && board[4] == board[6] && board[4] != " ")
    {
        wonSym = board[4];
        return true;
    }

    return false;
}

// Function to check whether board is filled or not
bool filledUp()
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == " ")
            return false;
    }
    return true;
}

// Function to draw the board repeatedly
void draw()
{
    cout << "     |     |     " << endl;
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
    cout << "     |     |     " << endl
         << endl;
}

// Function to get position from player
void getPosition()
{
    cout << "Player " << player << "'s turn" << endl;
    cout << "Enter your position: ";
    while (true)
    {
        cin >> position;
        if (position > 9 || position < 1)
        {
            cout << "Invalid Position...!!!" << endl;
            cin.clear(); // flushing the buffer
            cin.ignore();
            cout << "Enter a valid position i.e between 1 to 9 : ";
        }
        else if (board[position - 1] != " ")
        {
            cout << "Oops, that position is already filled..!" << endl;
            cout << "Try Again" << endl;
            cin.clear(); // flushing the buffer
            cin.ignore();
            cout << "Enter position which is not filled : ";
        }
        else
            break;
    }
}

// Function to update the board
void updateBoard()
{
    if (player % 2 != 0)
        board[position - 1] = sym1;
    else
        board[position - 1] = sym2;
}

// Function to change player
void changePlayer()
{
    if (player == 1)
        player++;
    else
        player--;
}

// Function for a player to take his/her turn
void takeTurn()
{
    cout << "The Game Begins now:- " << endl;
    while (!isWinner() && !filledUp())
    {
        getPosition();
        updateBoard();
        changePlayer();
        draw();
    }
    endGame();
}

// Function to restore defaults for replay
void playAgain()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = " ";
    }
    player = 1;
    takeTurn();
}

// Function to decide the winner
void endGame()
{
    if (isWinner())
    {
        if (wonSym == sym1)
            cout << "Player 1 won...!!!" << endl;
        else
            cout << "Player 2 Won...!!!" << endl;
        cout << "Congratulations" << endl;
    }
    else if (filledUp())
        cout << "There is a tie..!" << endl;

    cout << "Do you want to play the game again??";
    char choice;
    cout << "Enter your choice[Y/N] : ";
    while (true)
    {
        cin >> choice;
        if (choice == 'Y' || choice == 'N' || choice == 'y' || choice == 'n')
            break;
        else
            cout << "Your input is invalid..!" << endl
                 << "Enter valid character : ";
        cin.clear();
        cin.ignore();
    }
    if (choice == 'N' || choice == 'n')
        cout << "Thank You for Playing" << endl
             << "Terminating the game.";
    else
        playAgain();

    cout << endl;
}