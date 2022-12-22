/*
https://www.hackerearth.com/problem/algorithm/ordered-triplets/
-incomplete
*/
#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int main(){
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(abs(arr[i]-arr[j])==abs(arr[j]-arr[k]) && i!=k && j!=k && i!=j){
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;
}