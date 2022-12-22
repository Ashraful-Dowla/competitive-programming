/*
https://codeforces.com/problemset/problem/217/A
*/
#include <bits/stdc++.h>
using namespace std;

const int N=105;
bool visited[N];
int x[N],y[N],ans,n;

void dfs(int v){
	visited[v]=true;
	for(int i=1;i<=n;++i){
		if((x[i]==x[v]||y[i]==y[v])&&!visited[i]){
			dfs(i);
		}
	}
}

int main(){
	cin>>n;

	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
	}

	for(int i=1;i<=n;++i){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}

	cout<<ans-1<<endl;
}