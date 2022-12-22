/*
https://codeforces.com/problemset/problem/1688/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int x;
	   cin>>x;

	   int y=x&-x;
	   while(true){
	   	  if((x&y)>0 && (x^y)>0) {
	   	  	cout<<y<<endl;
	   	  	break;
	   	  }
	   	  y++;
	   }
	}
}