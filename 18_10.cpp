/*
https://leetcode.com/problems/valid-sudoku/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string board[9][9] =   {{"5","3",".",".","7",".",".",".","."}
							,{"6",".",".","1","9","5",".",".","."}
							,{".","9","8",".",".",".",".","6","."}
							,{"8",".",".",".","6",".",".",".","3"}
							,{"4",".",".","8",".","3",".",".","1"}
							,{"7",".",".",".","2",".",".",".","6"}
							,{".","6",".",".",".",".","2","8","."}
							,{".",".",".","4","1","9",".",".","5"}
							,{".",".",".",".","8",".",".","7","9"}};
   
   bool check = true;
   for(int i=0;i<9;i++){
   	  for(int j=0;j<9;j++){
   	  	 string s = board[i][j];
   	  	 if(s==".") continue;

   	  	 for(int k=0;k<9;k++){
   	  	 	if(board[i][k]==s && j!=k){
   	  	 		cout<<"x"<<endl;
   	  	 		check = false;
   	  	 		return check;
   	  	 	}
   	  	 	if(board[k][j]==s && i!=k){
   	  	 		cout<<"y"<<endl;
   	  	 		check = false;
   	  	 		return check;
   	  	 	}
   	  	 }

   	  	 int x_start, x_end, y_start, y_end;

   	  	 int x_block = i/3+1;
   	  	 x_start = 3*(x_block-1);
   	  	 x_end = 3*x_block-1;

   	  	 int y_block = j/3+1;
   	  	 y_start = 3*(y_block-1);
   	  	 y_end = 3*y_block-1;

   	  	 for(int k=x_start;k<=x_end;k++){
   	  	 	for(int l=y_start;l<=y_end;l++){
   	  	 		if(board[k][l]==s && k!=i && j!=l){
   	  	 			check = false;
   	  	 			cout<<"z"<<endl;
   	  	 			return check;
   	  	 		}
   	  	 	}
   	  	 }
   	  }
   }

   cout<<check<<endl;
   return check;
}