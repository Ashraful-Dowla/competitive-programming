/*
https://codeforces.com/gym/101908/my
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int>swtch[N];
int ans,cnt,n,m;

int calc(){
	for(int i=1;i<=n;++i){
		for(int x: swtch[i]){
			ans^=(1<<x);
		}
		cnt++;
		if(ans==0) break;
	}
	return cnt;
}

int main(){
	cin>>n>>m;
	int x;
	cin>>x;
	for(int i=0;i<x;++i){
		int y;
		cin>>y;
		ans^=(1<<y);
	}

	for(int i=1;i<=n;++i){
		cin>>x;
		for(int j=0;j<x;++j){
			int y;
			cin>>y;
			swtch[i].push_back(y);
		}
	}

	int res = calc();
	if(ans!=0) res = calc();
	cout<<(ans==0 ? res: -1)<<endl; 
}