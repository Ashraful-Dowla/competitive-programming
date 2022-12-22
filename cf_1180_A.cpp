/*
https://codeforces.com/problemset/problem/1180/A
*/
#include <bits/stdc++.h>
using namespace std;

int arr[102]; 
int main(){

	arr[1]=1;
	int n=1;
	for(int i=2;i<=100;++i){
		int len = (n-1)/2;
		len+=1;
		arr[i] = 2*len*len;
		n+=2;
		arr[i]+=n;
	}

	int x;
	cin>>x;
	cout<<arr[x]<<endl;
}