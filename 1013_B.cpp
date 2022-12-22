/*
https://codeforces.com/problemset/problem/1013/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int cnt[N],currnt[N];

int main(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	bool chk=false;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		cnt[arr[i]]++;
		currnt[arr[i]]++;
		if(cnt[arr[i]]>1) chk=true;
	}

	if(chk) {
		cout<<0<<endl;
		return 0;
	}
	int ct=INT_MAX;
	for(int i=0;i<n;++i){
		int val = arr[i]&x;
		if(val==arr[i]) continue;
		currnt[val]++;
		if(currnt[val]==2){
			ct = min(ct,currnt[val] - cnt[val]);
		}
	}
	cout<<(ct==INT_MAX ? -1: ct)<<endl;
}