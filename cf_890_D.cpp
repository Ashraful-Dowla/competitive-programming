/*
https://codeforces.com/problemset/problem/890/D
*/
#include <bits/stdc++.h>
using namespace std;

string ans;
int nxt[30],prv[30];
bool vis[30];

bool add(int a,int b){

	if(a==b) return false;
	if(nxt[a]!=-1 && nxt[a]!=b) return false;
	if(prv[b]!=-1 && prv[b]!=a) return false;

	nxt[a]=b;
	prv[b]=a;

	return true;
}

void dfs(int x){
	if(x==-1 || prv[x]!=-1 || !vis[x]) return ;
	if(nxt[x]!=-1) prv[nxt[x]]=-1;

	ans+=(x+'a');

	vis[x]=false;

	dfs(nxt[x]); 
}

int main(){
	int n;
	cin>>n;

	memset(nxt,-1,sizeof(nxt));
	memset(prv,-1,sizeof(prv));
	memset(vis,false,sizeof(vis));

	for(int i=0;i<n;++i){
		string s;
		cin>>s;

		for(int j=0;j<s.size();++j) {
			vis[s[j]-'a']=true;
		}

		for(int j=1;j<s.size();++j){
			if(!add(s[j-1]-'a',s[j]-'a')){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}

	for(int i=0;i<26;++i){
		dfs(i);
	}

	for(int i=0;i<26;++i){
		if(vis[i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
}