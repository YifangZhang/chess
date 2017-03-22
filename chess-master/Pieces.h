#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Pieces{
public:
  Pieces();
  ~Pieces();
  string get_king();
  string get_queen();
  string get_rook();
  string get_bishop();
  string get_knight();
  string get_pawn();
  void set_all_pieces(string king_tmp, string queen_tmp, string rook_tmp, string bishop_tmp, string knight_tmp, string pawn_tmp);
private:
  string king;
  string queen;
  string rook;
  string bishop;
  string knight;
  string pawn;
};
