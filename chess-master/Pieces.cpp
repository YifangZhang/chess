#include "Pieces.h"


Pieces::Pieces(){
  king = "K";
  queen = "Q";
  rook = "R";
  bishop = "b";
  knight = "k";
  pawn = "p";
}
Pieces::~Pieces(){

}
string Pieces::get_king(){
  return king;
}
string Pieces::get_queen(){
  return queen;
}
string Pieces::get_rook(){
return rook;
}
string Pieces::get_bishop(){
  return bishop;
}
string Pieces::get_knight(){
  return knight;
}
string Pieces::get_pawn(){
  return pawn;
}
void Pieces::set_all_pieces(string king_tmp, string queen_tmp, string rook_tmp, string bishop_tmp, string knight_tmp, string pawn_tmp){
  king = king_tmp;
  queen = queen_tmp;
  rook = rook_tmp;
  bishop = bishop_tmp;
  knight = knight_tmp;
  pawn = pawn_tmp;
}
