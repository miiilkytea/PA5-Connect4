#include "board.h"

Board::Board(){
    rows = 6;
    cols = 7;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        grid[i] = new char[cols];
        for(int j = 0; j < cols; j++){
            grid[i][j] = ' ';
        }
    }
}
Board::Board(int r, int c){
    rows = r;
    cols = c;
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        grid[i] = new char[cols];
        for(int j = 0; j < cols; j++){
            grid[i][j] = ' ';
        }
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

int Board::dropPiece(int col, char piece){
    if(col <+ 0 || col > cols){
        return 100;
    }
    if(isValidMove(col)==false){
        cout << "Invalid move, column full." << endl << "Select another column" << endl;
        return 100;
    }
    col--;
    int rIndex = 0;
    for(int i = 0; i < rows; i++){
        if(grid[i][col]== ' '){
            grid[i][col] = piece;
            return i;
        }
    }
    return 100;
}
bool Board::isValidMove(int col){
    col--;
    for(int i = 0; i < rows; i++){
        if(grid[i][col]==' '){
            return true;
        }
    }
        return false;
}
bool Board::checkWin(int col, int row, char piece){ //gets row from dropPiece(), col from player choice, piece from player deets
    int inHor = 0, inVert = 0, inUpDiag = 0, inDoDiag = 0;

    if(grid[row][col] == piece){
        inHor++;
        inVert++;
        inUpDiag++;
        inDoDiag++;
    }

    //horizontal check
    for(int i = col+1; i < cols; i++){ //(going right) doesn't count at column index of starting count piece
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
    for(int i = row+1; i < rows ; i++){ //going up
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

    //up and right diagonal check   /
    for(int i = row+1, j = col+1; i < rows && j < cols; i++, j++){ // up & right  /
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
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){ // down & left   /
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

    //down and right diagonal check   "\"
    for(int i = row-1, j = col+1; i >= 0 && j < cols; i--, j++){ // down and right "\"
        if(inDoDiag == 4){
            return true;
        }

        if(grid[i][j] == piece){
            inDoDiag++;
        }
        else{
            break;
        }
    }
    for(int i = row+1, j = col-1; i < rows && j >= 0; i++, j--){ // up and left "\"
        if(inDoDiag == 4){
            return true;
        }

        if(grid[i][j] == piece){
            inDoDiag++;
        }
        else{
            break;
        }
    }
    return false;
}
bool Board::checkTie(){
    for(int j = 0; j < cols; j++){
        if(isValidMove(j) == true){
            return false;
        }
    }
    return true;
}

ostream& operator <<(ostream& out, Board& matrix){
    out << "===============================" << endl;
    for(int i = matrix.rows-1; i >= 0; i--){
        out << "||";
        for(int j = 0; j < matrix.cols; j++){
            if(matrix.grid[i][j] == 'X' || matrix.grid[i][j] == 'O'){
                out << " " << matrix.grid[i][j] << " |";
            }
            else{
                out << " _ " << "|";
            }
        }
        out << "|" << endl;
    }
    out << "===============================" << endl;
    out << "   1   2   3   4   5   6   7" << endl << endl;

    return out;
}