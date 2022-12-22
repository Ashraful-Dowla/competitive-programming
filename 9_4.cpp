/*
https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/roy-and-symmetric-logos-1/
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char arr[n][n];
		bool chk = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				char ch;
				cin>>ch;
				arr[i][j]=ch;
			}
		}

		int rn = n%2==0 ? (n/2)-1 : n/2;

		//y-axis
		for(int i=0;i<n;i++){
			for(int j=0;j<=rn;j++){
				if(arr[i][j]!=arr[i][n-j-1]){
					chk=false;
				}
			}
		}

		//x-axis
		for(int i=0;i<=rn;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]!=arr[n-i-1][j]){
					chk=false;
				}
			}
		}
		chk ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
}