#include "game.h"

Game::Game() {
    player1 = nullptr;
    player2 = nullptr;
    currentPlayer = nullptr;
    uCol = uRow = 0;
}

Game::Game(Player* p1, Player* p2) {
    player1 = p1;
    player2 = p2;
    currentPlayer = player1;
    uCol = uRow = 0;
}
Game::Game(const Game& rh) {
    player1 = rh.player1;
    player2 = rh.player2;
    board = rh.board;
    currentPlayer = rh.currentPlayer;
    uCol = rh.uCol;
    uRow = rh.uRow;
}

Player* Game::getP1() {
    return player1;
}
Player* Game::getP2() {
    return player2;
}
Player* Game::getCurrentPlayer(){
    return currentPlayer;
}
Board* Game::getBoard() {
    return &board;
}

void Game::start() {
    bool endGame = false;
    bool uWin = false;
    bool uTie = false;

    if(player1 == nullptr || player2 == nullptr){
        cout << "Error: players not initialized." << endl << endl;
        return;
    }

    if(currentPlayer == nullptr){
        currentPlayer = player1;
    }

    while (endGame == false) {
        cout << board;
        playTurn();
        uWin = board.checkWin(uCol, uRow, currentPlayer->getPiece());
        uTie = board.checkTie();

        if (uWin == true) {
            currentPlayer->recordWin();
            switchPlayer();
            currentPlayer->recordLoss();
            switchPlayer();
            cout << currentPlayer->getName() << " WINS!" << endl;
            endGame = true;
        } else if (uTie == true) {
                player1->recordTie();
                player2->recordTie();
                cout << "IT'S A TIE!"<< endl;
                endGame = true;
        }
        else{
            switchPlayer();
            endGame = false;
        }
    }
}
void Game::switchPlayer() {
    if(currentPlayer == player1) {
        currentPlayer = player2;
    } else {
        currentPlayer = player1;
    }
}
void Game::playTurn() {
    char piece;
    do {
        uCol = currentPlayer->makeMove(board);
        piece = currentPlayer->getPiece();
        uRow = board.dropPiece(uCol, piece);
    }while (uRow == 100);
    
}  
