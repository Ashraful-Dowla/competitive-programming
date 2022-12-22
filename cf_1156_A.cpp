/*
https://codeforces.com/problemset/problem/1156/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n+2];

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	map<pair<int,int>,int>mp;

	//1->circle
	//2->triangle
	//3->square

	mp[{1,2}]=mp[{2,1}]=3;

	mp[{3,1}]=mp[{1,3}]=4;

	mp[{2,3}]=mp[{3,2}]=INT_MAX;

	int sum=0,sub=0;
	for(int i=1;i<n;++i){
		int val = mp[{arr[i],arr[i-1]}];
		if(val==INT_MAX){
			cout<<"Infinite"<<endl;
			return 0;
		}
		if(i>=2 && arr[i-2]==3 && arr[i-1]==1 && arr[i]==2) sub--;
		sum+=val;
	}

	cout<<"Finite"<<endl;
	cout<<sum+sub<<endl;
}