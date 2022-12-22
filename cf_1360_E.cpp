/*
https://codeforces.com/contest/1360/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	   int n;
	   cin>>n;
	   string arr[n];

	   for(int i=0;i<n;++i){
	   	  cin>>arr[i];
	   }

	   bool isPossible = true;

	   for(int i=0;i<n-1;++i){
	   	  for(int j=0;j<n-1;++j){
	   	  	 if(arr[i][j]-'0'){
	   	  	 	isPossible&=(arr[i+1][j]-'0'|arr[i][j+1]-'0');
	   	  	 	if(!isPossible) break;
	   	  	 }
	   	  }
	   	  if(!isPossible) break;
	   }

	   cout<<(isPossible ? "YES": "NO")<<endl;
	}
}