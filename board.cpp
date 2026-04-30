#include "board.h"

Board::Board(){
    rows = 6;
    cols = 7;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        grid[i] = new char[cols];
    }
}
Board::Board(int r, int c){
    rows = r;
    cols = c;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        grid[i] = new char[cols];
    }
}
Board::Board(const Board& rhs){
    rows = rhs.rows;
    cols = rhs.cols;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        grid[i] = new char[cols];
    }
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            grid[r][c] = rhs.grid[r][c];
        }
    }
}

int Board::getRows(){
    return rows;
}
int Board::getCols(){
    return cols;
}
char** Board::getGrid(){
    return grid;
}

void Board::setRows(int r){
    rows = r;
}
void Board::setCols(int c){
    cols = c;
}

Board& Board::operator =(const Board& rhs){
    for(int i = 0; i < rows; i++){
        delete [] grid[i];
    }
    delete [] grid;
    rows = rhs.rows;
    cols = rhs.cols;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        grid[i] = new char[cols];
    }
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            grid[r][c] = rhs.grid[r][c];
        }
    }
    return *this;
}
Board::~Board(){
    for(int i = 0; i < rows; i++){
        delete [] grid[i];
    }
    delete [] grid;
}

bool Board::dropPiece(int, char){

}
// bool Board::isValidMove(int){

// }
bool Board::checkWin(char){

}
bool Board::checkTie(){

}

ostream& Board::operator <<(ostream&, Board&){

}