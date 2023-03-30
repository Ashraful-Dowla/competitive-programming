#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

bool chk(string s, string pos){
	int n = s.size();
	bool ok=true;

	bool chk[35];
	memset(chk, false,sizeof(chk));

	for(int i=0;i<n;++i){
		if(chk[s[i]-'a']) continue;
		for(int j=i+1;j<n;++j){
			if(s[i]!=s[j]) continue;
			if(s[i]==s[j] && pos[j]==pos[i]) continue;
			ok=false;
			break;
		}
		if(!ok) break;
		chk[s[i]-'a']=true;
	}

	return ok;
}

void solve(){
	int n;
	cin>>n;

	string s;
	cin>>s;

	string pos1,pos2;
	for(int i=0;i<n;++i){
		if(i%2==0){
			pos1.push_back('0');
			pos2.push_back('1');
		}
		else {
			pos1.push_back('1');
			pos2.push_back('0');
		}
	}

	// cout<<pos1<<endl;
	// cout<<pos2<<endl;

	bool res = chk(s,pos1);

	if(res) {
		cout<<"YES"<<endl;
		return ;
	}

	res = chk(s,pos2);

	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}