/*
https://codeforces.com/contest/1806/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){

	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;

	if(x1+y2-y1<x2 || y1>y2){
		cout<<-1<<endl;
		return ;
	}

	cout<<abs(y2-y1)+abs(x1+y2-y1-x2)<<endl;

}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}