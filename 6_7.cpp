/*
https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/friends-relationship-1/
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int first=2, last=2*n-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2*n;j++){
				if(j>=first && j<=last) cout<<"#";
				else cout<<"*";
			}
			cout<<endl;
			first++;
			last--;
		}
	}
}