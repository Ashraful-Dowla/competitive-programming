/*
https://codeforces.com/contest/50/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	int arr[100];
	memset(arr,0,sizeof(arr));

	for(int i=0;i<s.size();++i){
		arr[s[i]-'0']++;
	}
	long long cnt=0;
	for(int i=0;i<s.size();++i){
		cnt+=arr[s[i]-'0'];
	}
	cout<<cnt<<endl;
}