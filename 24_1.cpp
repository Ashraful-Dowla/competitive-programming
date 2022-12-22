/*
https://www.hackerearth.com/problem/algorithm/santa-and-gifts-2/
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;
int hsh[N];

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		hsh[arr[i]]++;
		if(hsh[arr[i]]==(k+1)) cnt++;
	}	
	cout<<cnt<<endl;
}