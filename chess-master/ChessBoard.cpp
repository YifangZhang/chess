#include "ChessBoard.h"

ChessBoard::ChessBoard(){
  Rows = 8;
  Cols = 8;
  Empty = '+';
  black.set_all_pieces("BK","BQ","BR","BB","Bk","BP");
  white.set_all_pieces("WK","WQ","WR","WB","Wk","WP");
  for(int c = 0; c<Cols; c++){
    Board[1][c] = white.get_pawn();
  }
  for(int c = 0; c<Cols; c++){
    Board[6][c] = black.get_pawn();
  }
  for(int c = 0; c<Cols; c++){
    if(c == 0 || c == 7){
      Board[0][c] = white.get_rook();
      Board[7][c] = black.get_rook();
    }
    if(c == 1 || c == 6){
      Board[0][c] = white.get_knight();
      Board[7][c] = black.get_knight();
    }
    if(c == 2 || c == 5){
      Board[0][c] = white.get_bishop();
      Board[7][c] = black.get_bishop();
    }
    if(c == 3){
      Board[0][c] = white.get_queen();
      Board[7][c] = black.get_queen();
    }
    if(c == 4){
      Board[0][c] = white.get_king();
      Board[7][c] = black.get_king();
    }
  }
  for(int c = 0; c<Cols; c++){
    for(int r = 2; r<6; r++){
      Board[r][c] = Empty;
    }
  }
}
ChessBoard::~ChessBoard(){

}
int ChessBoard::get_rows(){
  return Rows;
}
int ChessBoard::get_cols(){
  return Cols;
}
Pieces ChessBoard::get_white(){
  return white;
}
Pieces ChessBoard::get_black(){
  return black;
}
string ChessBoard::get_empty(){
  return Empty;
}
string ChessBoard::get_board(int row, int col){
  if(row<0 || row>Rows){
    return Empty;
  }
  if(col<0 || col > Cols){
    return Empty;
  }
  return Board[row][col];
}
void ChessBoard::set_board(int row, int col, string value){
  if(row<0 || row>Rows){
    return;
  }
  if(col<0 || col > Cols){
    return;
  }
  Board[row][col] = value;
}
void ChessBoard::initialize_board(int row, int col, string empty){
  Rows = row;
  Cols = col;
  Empty = empty;
  for(int i = 0; i<Rows; i++){
    for(int j = 0; j<Cols; j++){
      Board[i][j] = Empty;
    }
  }
  for(int c = 0; c<Cols; c++){
    Board[1][c] = 'p';
  }
  for(int c = 0; c<Cols; c++){
    Board[Rows-2][c] = 'p';
  }

}
void ChessBoard::print_board(){
  // Display border
  system("clear");
  for (int c=0; c<Cols; c++)
     cout <<setw(9)<< c;
  cout << "\n";
  int count = 0;
  char border_left = 'A';
  // Display data
  //cout<<Rows<<" "<<Cols<<endl;
  for (int r=0; r<Rows; r++)
  {
     border_left = 'A'+r;
     cout << border_left;
     for (int c=0; c<Cols; c++){
         cout<<setw(9)<< Board[r][c];
     }
     cout << "\n";
     cout << "\n";
     cout << "\n";
  }

  // Display border
  for (int r=0; r<Cols; r++)
     cout <<setw(9)<< r;
  cout << "\n";
}
void ChessBoard::read_board(string filename)
{
    ifstream din;
    int counter = 0;
    char getter;
    int col_counter = 0;
    int row_counter = 0;
    din.open(filename);
    // reads in the size and empty character of the board
    din>>Rows;
    din>>Cols;
    din>>Empty;
  while(!din.eof())
  {
    // stores the next character in the row in variable getter then assigns it to the board in row major order
    din>>getter;
    Board[row_counter][col_counter] = getter;
    col_counter++; // keeps track of how far accross the row has been traversed.
      if(col_counter == Cols){
        row_counter++;
        col_counter = 0; // starts back at 0 for the columns once the end of a row has been reached
      }
  }
}
void ChessBoard::write_board(string filename)
{
  ofstream dout;
  dout.open(filename);
  dout<<Rows<<" "<<Cols<<" "<<Empty<<endl;
  for(int r = 0; r < Rows; r++){
    for(int c = 0; c < Cols; c++){
      if(c == Cols-1){
        dout<<setw(2)<< Board[r][c];
        dout<<endl; // ensures the formatting is correct with a new line after the end of a column
      }else{
        dout<<setw(2)<< Board[r][c];
      }
    }
  }
  dout.close();
}
bool ChessBoard::legal_king_move(int r_current, int c_current, int r_move, int c_move){

}
bool ChessBoard::legal_queen_move(int r_current, int c_current, int r_move, int c_move){

}
bool ChessBoard::legal_rook_move(int r_current, int c_current, int r_move, int c_move){

}
bool ChessBoard::legal_bishop_move(int r_current, int c_current, int r_move, int c_move){
  if(((c_current-c_move+2)/(r_current-r_move+2) == 1 || (c_current-c_move+2)/(r_current - r_move) == -1)){
    return true;
  }else{
    return false;
  }
}
bool ChessBoard::legal_knight_move(int r_current, int c_current, int r_move, int c_move){

}
bool ChessBoard::legal_pawn_move(int r_current, int c_current, int r_move, int c_move, Pieces team){
  if(team.get_pawn() == "WP"){
    if((r_move == (r_current+1)) && (c_move == c_current)){
      return true;
    }
    else if(((r_move == (r_current+1)) && ((c_move == (c_current-1)) || (c_move == (c_current+1))) && Board[r_move][c_move] != Empty)){
      return true;
    }
    else{
      return false;
    }
  }
  if(team.get_pawn() == "BP"){
    if((r_move == (r_current-1)) && (c_move == c_current)){
      return true;
    }
    else if(((r_move == (r_current-1)) && ((c_move == (c_current-1)) || (c_move == (c_current+1))) && Board[r_move][c_move] != Empty)){
      return true;
    }
    else{
      return false;
    }
  }
}
