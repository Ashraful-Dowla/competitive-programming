#include <bits/stdc++.h>
using namespace std;


void matrix_rotate(int x1, int y1, int x2, int y2, vector<vector<int>>& matrix){

	while(x1<x2) {
     	swap(matrix[x1][y1],matrix[x2][y2]);
     	x1++,y1++;
     	x2--,y2--;
   	}
}

void rotate(vector<vector<int>>& matrix) {
     
     int n = matrix[0].size();

     for(int i=0;i<n;++i){
     	  int x1=i, y1=0;
     	  int x2=n-1, y2=n-1-i;

     	  matrix_rotate(x1,y1,x2,y2, matrix);
     	 
     	  if(i==0) continue;

     	  swap(x1,y1);
     	  swap(x2,y2);

     	  matrix_rotate(x1,y1,x2,y2, matrix);
     }

     for(int i=0;i<n;++i){
     	 int x1=0, x2=n-1;

     	 while(x1<x2){
     	 	 swap(matrix[x1][i], matrix[x2][i]);
     	 	 x1++,x2--;
     	 }
     }

     for(int i=0;i<n;++i){
     	for(int j=0;j<n;++j){
     		cout<<matrix[i][j]<<" ";
     	}
     	cout<<endl;
     }
}

int main(){
	// vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	// vector<vector<int>> matrix = {{1,2},{3,4}};
	vector<vector<int>> matrix = {{1}};
	//vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	rotate(matrix);
}