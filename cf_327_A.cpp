/*
https://codeforces.com/contest/327/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=105;
int arr[N],pf1[N],pf0[N];

int main(){
	int n;
	cin>>n;

	for(int i=1;i<=n;++i){
		cin>>arr[i];
		pf1[i]=pf1[i-1]+arr[i];
		pf0[i]=pf0[i-1]+(arr[i]==0);
	}

	int total1=pf1[n],mx=0;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			int cnt0=pf0[j]-pf0[i-1];
			int cnt1=pf1[j]-pf1[i-1];
			mx = max(mx, total1-cnt1+cnt0);
		}
	}

	cout<<mx<<endl;
}