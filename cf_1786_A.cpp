/*
https://codeforces.com/contest/1786/problem/A1
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	int alice=0,bob=0, chk=0, i=1;

	alice+=i;
	n-=i;

	i++;
	while(n>=(2*i+1)){
		if(!chk){
		   bob+=(2*i+1);
		}
		else {
		   alice+=(2*i+1);
		}
		n-=(2*i+1);
		chk=1-chk;
		i+=2;
	}

	if(chk) alice+=n;
	else bob+=n;
	
	cout<<alice<<" "<<bob<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}