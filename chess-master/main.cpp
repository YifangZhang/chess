#include <cstdlib>
#include <iostream>
#include "ChessBoard.h"
using namespace std;




//-----------------------------------------------------------
int main()
{
  ChessBoard chessboard;
  int r_current, c_current, r_move, c_move;
  while(userchoice == "yes"){
    chessboard.print_board();
    cout<<"Please enter the location of the piece to be moved then the place you would like to move it"<<endl;;
    cin>>r_current>>c_current>>r_move>>c_move;
    if(chessboard.get_board(r_current, c_current) == chessboard.get_black().get_pawn()){
      if(chessboard.legal_pawn_move(r_current,c_current,r_move,c_move, chessboard.get_black())){
        chessboard.set_board(r_move, c_move, chessboard.get_black().get_pawn());
        chessboard.set_board(r_current, c_current, chessboard.get_empty());
      }else
      {
          cout<<"Not a legal move please try again"<<endl;
      }
    }
    if(chessboard.get_board(r_current, c_current) == chessboard.get_white().get_pawn()){
      if(chessboard.legal_pawn_move(r_current,c_current,r_move,c_move, chessboard.get_white())){
        chessboard.set_board(r_move, c_move, chessboard.get_white().get_pawn());
        chessboard.set_board(r_current, c_current, chessboard.get_empty());
      }else
      {
          cout<<"Not a legal pawn move please try again"<<endl;
      }
    }
    if((chessboard.get_board(r_current, c_current) == chessboard.get_white().get_bishop()) || (chessboard.get_board(r_current, c_current) == chessboard.get_black().get_bishop())){
      chessboard.set_board(r_move, c_move, chessboard.get_white().get_bishop());
      chessboard.set_board(r_current, c_current, chessboard.get_empty());
    }else{
      cout<<"Not a legal bishop move please try again"<<endl;
    }
    chessboard.print_board();
    
  }
}
