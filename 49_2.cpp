/*
https://www.hackerearth.com/problem/algorithm/doraemon-andd-his-pocket-of-wonder/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		map<int,int>hsh;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			hsh[arr[i]]++;
		}
		int m;
		cin>>m;
		int arr1[m];
		for(int i=0;i<m;i++){
			cin>>arr1[i];
		}

		for(int i=0;i<m;i++){
			if(hsh[arr1[i]]>0){
				for(int j=0;j<hsh[arr1[i]];j++){
					cout<<arr1[i]<<" ";
				}
				hsh[arr1[i]]=0;
			}
		}

		multiset<int>ms;
		for(int i=0;i<n;i++){
			if(hsh[arr[i]]>0) ms.insert(arr[i]);
		}
		for(auto &val:ms){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}