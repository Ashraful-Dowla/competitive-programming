/*
https://codeforces.com/contest/1790/problem/D
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);

	vector<int> vec;
	map<int,int> mp;

	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);

		if(!mp[x]) vec.push_back(x);
		mp[x]++;
	}

	sort(vec.begin(),vec.end());

	int ans=mp[vec[vec.size()-1]];
	for(int i=vec.size()-2;i>=0;--i){
		if(vec[i]+1==vec[i+1]){
			ans+=max(0, mp[vec[i]]-mp[vec[i+1]]);
		}
		else if(vec[i+1]-vec[i]>1) {
			ans+=mp[vec[i]];
		}
	}

	printf("%d\n",ans);
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
	   solve();
	}
}