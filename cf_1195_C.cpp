/*
https://codeforces.com/contest/1195/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll team1[N],team2[N],dp1[N],dp2[N];

int main(){
	int n;
	cin>>n;

	for(int i=0;i<n;++i){
		cin>>team1[i];
	}
	for(int i=0;i<n;++i){
		cin>>team2[i];
	}

	dp1[0]=team1[0];
	dp2[0]=team2[0];

	ll m1=dp1[0];
	ll m2=dp2[0];

	for(int i=1;i<n;++i){
		dp1[i] = m2 + team1[i];
		dp2[i] = m1 + team2[i];

		m1 = max(m1,dp1[i]);
		m2 = max(m2,dp2[i]);
	}

	cout<<max(m1,m2)<<endl;
}