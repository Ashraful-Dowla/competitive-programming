/*
https://codeforces.com/contest/1767/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

bool cmp1(pr a,pr b){
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}

bool cmp2(pr a,pr b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}

void solve(){
	vector<pr> cord1,cord2;
	for(int i=0;i<3;++i){
		int x,y;
		cin>>x>>y;
		cord1.push_back({x,y});
		cord2.push_back({x,y});
	}

	sort(cord1.begin(),cord1.end(),cmp1);
	sort(cord2.begin(),cord2.end(),cmp2);

	if(cord1[0].first<cord1[1].first && cord1[1].first<cord1[2].first){
		cout<<"YES"<<endl;
		return ;
	}
	else if(cord2[0].second<cord2[1].second && cord2[1].second<cord2[2].second){
		cout<<"YES"<<endl;
		return ;
	}
	else {
		cout<<"NO"<<endl;
		return ;
	}
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    solve();
	}
}