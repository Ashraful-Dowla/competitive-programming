/*
https://www.hackerrank.com/challenges/printing-pattern-2/problem
*/
#include <bits/stdc++.h>
using namespace std;

int arr[2010][2010];

void prnt(int n){
	for(int i=1;i<=(2*n-1);i++){
		for(int j=1;j<=(2*n-1);j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	int first=1, last=2*n-1;
	int val=n;
	for(int i=1;i<=(2*n-1);i++){
		for(int j=1;j<=(2*n-1);j++){
			if(i==1 || i==2*n-1) arr[i][j]=n;
			else if(j>=first && j<=last) {
				arr[i][j] = val;
			}
			else arr[i][j] = arr[i-1][j];
		}

		if(i<=(2*n-1)/2){
			first++;
			last--;
			val--;
		}
		else {
			first--;
			last++;
			val++;
		}
	}
	prnt(n);
}