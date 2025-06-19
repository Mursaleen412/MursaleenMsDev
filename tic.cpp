#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

int row, col;
char turn = 'X';
bool draw = false;

// Show current board
void displayBoard() {
    cout << "\nTic Tac Toe\n";
    cout << "You [X]  vs  Computer [O]\n\n";
    for(int i=0;i<3;i++) {
        cout << " ";
        for(int j=0;j<3;j++) {
            cout << board[i][j];
            if(j<2) cout << " | ";
        }
        if(i<2) cout << "\n---|---|---\n";
    }
    cout << "\n";
}

// Check game status
bool gameOver() {
    for(int i=0;i<3;i++) {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return false;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) return false;
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return false;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return false;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]!='X' && board[i][j]!='O')
                return true;

    draw = true;
    return false;
}

// Convert number to board position
bool placeMark(int choice, char mark) {
    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    if(board[row][col]!='X' && board[row][col]!='O') {
        board[row][col] = mark;
        return true;
    } else return false;
}

// Computer turn (simple AI)
void computerTurn() {
    for(int i=1;i<=9;i++) {
        if(placeMark(i, 'O')) {
            break;
        }
    }
}

int main() {
    int choice;

    while(gameOver()) {
        displayBoard();

        // Player Turn
        cout << "Your turn (choose 1-9): ";
        cin >> choice;

        if(!placeMark(choice, 'X')) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if(!gameOver()) break;

        // Computer Turn
        cout << "Computer's turn...\n";
        computerTurn();
    }

    displayBoard();

    if(draw) cout << "It's a draw!\n";
    else {
        if(turn == 'X') cout << "Computer [O] wins!\n";
        else cout << "You [X] win!\n";
    }

    return 0;
}
