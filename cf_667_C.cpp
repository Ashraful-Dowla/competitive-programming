/*
https://codeforces.com/contest/667/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int dp[N][4];
string s;
set<string> ans;

void generate(int pos,int cnt,string last=""){
	if(pos<=4 || dp[pos][cnt]) return ;

	string curr = s.substr(pos,cnt);

	if(last!=curr){
		dp[pos][cnt]=1;
		ans.insert(curr);
		generate(pos-2,2,curr);
		generate(pos-3,3,curr);
	}
}

int main(){
	cin>>s;
	int sz = s.size();

	memset(dp,0,sizeof(dp));
	generate(sz-2,2);
	generate(sz-3,3);

	cout<<ans.size()<<endl;
	for(auto val: ans){
		cout<<val<<endl;	
	}
}