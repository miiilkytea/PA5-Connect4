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
    // for(int i = 0; i < rows; i++){
    //     delete [] grid[i];
    // }
    // delete [] grid;
    ~Board();
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

int Board::dropPiece(int col, char piece){
    if(isValidMove(col)==false){
        cout << "Invalid move, column full." << endl << "Select another column" << endl;
        return 9;
    }
    else{
        for(int i = 0; i < rows; i++){
            if(grid[i][col]!='X' || grid[i][col]!='O'){
                grid[i][col] = piece;
                return i;
            }
        }
    }
}
bool Board::isValidMove(int col){
    for(int i = 0; i < rows; i++){
        if(grid[i][col]!='X' || grid[i][col]!= 'O'){
            return true;
        }
    }
        return false;
}
bool Board::checkWin(int col, int row, char piece){ //gets row from dropPiece(), col from player choice, piece from player deets
    int inHor = inVert = inUpDiag = inDoDiag = 1; //counts pieces in that direction, starts at 1 since the piece inputted counts

    //horizontal check
    for(int i = col+1; i < 7; i++){ //(going right) doesn't count at column index of starting count piece
        if(inHor == 4){
            return true;
        }

        if(grid[row][i] == piece){ //going left
            inHor++;
        }
        else{
            break; //breaks loop if the next one that connects is not the same piece
        }
    }
    for(int i = col-1; i >= 0; i--){
        if(inHor == 4){
            return true;
        }

        if(grid[row][i] == piece){
            inHor++;
        }
        else{
            break; //breaks loop if the next one that connects is not the same piece
        }
    }

    //vertical check
    for(int i = row+1; i < 6 ; i++){ //going up
        if(inVert == 4){
            return true;
        }

        if(grid[i][col] == piece){
            inVert++;
        }
        else{
            break;
        }
    }
    for(int i = row-1; i >= 0 ; i--){ //going down
        if(inVert == 4){
            return true;
        }

        if(grid[i][col] == piece){
            inVert++;
        }
        else{
            break;
        }
    }

    //up and right diagonal check
    for(int i = row, j = col; i < 6 && j < 7; i++, j++){ // up & right
        if(inUpDiag == 4){
            return true;
        }

        if(grid[i][j] == piece){
            inUpDiag++;
        }
        else{
            break;
        }
    }
}
bool Board::checkTie(){
    if(isValidMove(0) == true){
        return false;
    }
    else if(isValidMove(1) == true){
        return false;
    }
    else if(isValidMove(2) == true){
        return false;
    }
    else if(isValidMove(3) == true){
        return false;
    }
    else if(isValidMove(4) == true){
        return false;
    }
    else if(isValidMove(5) == true){
        return false;
    }
    else if(isValidMove(6) == true){
        return false;
    }
    else{
        return true;
    }
}

ostream& Board::operator <<(ostream&, Board&){

}