// TicTacGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//Игровое поле Task 9
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}
void printBoard(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}
//Совершение хода игроками поочередно Task 13
bool makeMove(char board[3][3], int row, int col, char currentPlayer) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

//Проверка победителя Тask 12
bool checkWin(const char board[3][3], char currentPlayer) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}

//Крестик или нолик Task 11
void playGame() {
    char board[3][3];
    initializeBoard(board);
    char currentPlayer = 'X';
    bool gameOver = false;
    while (!gameOver) {
        printBoard(board);
        int row, col;
        cout << "Ход игрока " << currentPlayer << ". Введите номер строки (0-2): ";
        cin >> row;
        cout << "Ход игрока " << currentPlayer << ". Введите номер столбца (0-2): ";
        cin >> col;
        if (makeMove(board, row, col, currentPlayer)) {
            if (checkWin(board, currentPlayer)) {
                cout << "Игрок " << currentPlayer << " победил!" << endl;
                gameOver = true;
            }
            else if (currentPlayer == 'X') {
                currentPlayer = 'O';
            }
            else {
                currentPlayer = 'X';
            }
        }
        else {
            cout << "Некорректный ход! Попробуйте снова." << endl;
        }
    }
    printBoard(board);
}

int main() {
    setlocale(LC_ALL, "ru");
    playGame();
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
