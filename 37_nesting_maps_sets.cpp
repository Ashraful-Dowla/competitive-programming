#include <bits/stdc++.h>
using namespace std;

int main(){
	map<pair<int,int>,int>m;

	pair<int,int> p1,p2;

	p1 = {1,2};
	p2 = {2,3};
	cout<<(p1>p2)<<endl;

	set<int>s1,s2;
	s1 = {1,2,3};
	s2 = {2,3};

	cout<<(s1<s2)<<endl;

	map<pair<string,string>,vector<int>>mp;

	int t;
	cin>>t;
	while(t--){
		string fn,ln;
		int cnt;
		cin>>fn>>ln>>cnt;

		for(int i=0;i<cnt;i++){
			int x;
			cin>>x;
			mp[{fn,ln}].push_back(x);
		}
	}

	for(auto &pr:mp){
		auto &full_name = pr.first;
		auto &list = pr.second;
		cout<<full_name.first<<" "<<full_name.second<<endl;
		cout<<list.size()<<endl;

		for(auto &el: list){
			cout<<el<<" ";
		}
		cout<<endl;
	}
}