#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row, column;
char turn = 'X';
bool draw = false;
string player1, player2;

void display_board() {
    cout << "\t\t     T I C K -- T A C -- T O E -- G A M E \t\t\t\n\n" << endl;
    cout << "\t\t     |     |     \n" << endl;
    cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n" << endl;
    cout << "\t\t_____|_____|_____ \n" << endl;
    cout << "\t\t     |     |      \n" << endl;
    cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n" << endl;
    cout << "\t\t_____|_____|_____ \n" << endl;
    cout << "\t\t     |     |      \n" << endl;
    cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n" << endl;
    cout << "\t\t     |     |       \n" << endl;
}

void player_turn() {
    if (turn == 'X') {
        cout << "\n\t" << player1 << " [X] turn : ";
    } else {
        cout << "\n\t" << player2 << " [O] turn : ";
    }
    cin >> choice;
    row = (choice - 1) / 3;
    column = (choice - 1) % 3;
    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        if (turn == 'X') {
            turn = 'O';
        } else {
            turn = 'X';
        }
    } else {
        cout << "Invalid move. Try again." << endl;
        player_turn();
    }
    display_board();
}

bool gameover() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true; 
        }
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true; 
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; 
            }
        }
    }
    draw = true;
    return true; 
    
}

int main() {
    cout << "Enter Player 1's name: ";
    cin >> player1;
    cout << "Enter Player 2's name: ";
    cin >> player2;

    display_board();
    while (!gameover()) {
        player_turn();
    }
    if (turn == 'X' && !draw) {
        cout << "Congratulations! " << player1 << " has won the game." << endl;
    } else if (turn == 'O' && !draw) {
        cout << "Congratulations! " << player2 << " has won the game." << endl;
    } else {
        cout << "GAME DRAW!!!" << endl;
    }
    return 0;
}
