#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Pieces.h"
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

class ChessBoard{
public:
  ChessBoard();
  ~ChessBoard();
  int get_rows();
  int get_cols();
  string get_empty();
  string get_board(int r, int c);
  Pieces get_white();
  Pieces get_black();
  void set_board(int row, int col, string value);
  void initialize_board(int row, int col, string empty);
  void print_board();
  void read_board(string filename);
  void write_board(string filename);
  void flood_fill(int r, int c, int start_r, int start_c, char filler, int radius);
  bool legal_king_move(int r_current,int c_current,int r_move,int c_move);
  bool legal_queen_move(int r_current,int c_current,int r_move,int c_move);
  bool legal_rook_move(int r_current,int c_current,int r_move,int c_move);
  bool legal_bishop_move(int r_current,int c_current,int r_move,int c_move);
  bool legal_knight_move(int r_current,int c_current,int r_move,int c_move);
  bool legal_pawn_move(int r_current, int c_current, int r_move, int c_move, Pieces team);
private:
  Pieces black;
  Pieces white;
  int Rows;
  int Cols;
  string Board[MAX_ROWS][MAX_COLS];
  string Empty;
};
