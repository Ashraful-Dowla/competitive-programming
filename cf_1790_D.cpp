#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;

	vector<int> vec;
	unordered_map<int,int> mp;

	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(!mp[x]) vec.push_back(x);
		mp[x]++;
	}

	sort(vec.begin(),vec.end());

	int ans=0;
	for(int i=0;i+1<vec.size();++i){
		int mx=0;
		while(i+1<vec.size() && vec[i]+1==vec[i+1]){
			++i;
			mx = max(mx,mp[vec[i]]);
			mx = max(mx,mp[vec[i+1]]);
		}
		ans+=mx;
	}
	cout<<(ans==0 ? n : ans)<<endl;
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