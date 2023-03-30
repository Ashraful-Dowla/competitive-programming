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
	string s;
	cin>>s;
	unordered_map<char,int> mp;

	int cnt=0;
	for(char ch: s){
		cnt = max(cnt, ++mp[ch]);
	}

	if(cnt==1 || cnt==2) cout<<4<<endl;
	else if(cnt==3) cout<<6<<endl;
	else cout<<-1<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}