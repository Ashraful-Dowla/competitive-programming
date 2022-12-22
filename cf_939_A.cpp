/*
https://codeforces.com/problemset/problem/939/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n+1];

	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}

	int cnt;
	for(int i=1;i<=n;++i){
		int j,idx;
		cnt=1;
		j=idx=i;
		while(idx!=arr[j] && cnt<4) {
		    j=arr[j];
		    cnt++;
		}

		if(cnt==3) break;
	}

	cout<<(cnt==3 ? "YES":"NO")<<endl;
}