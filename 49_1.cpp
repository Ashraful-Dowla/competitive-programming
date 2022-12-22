/*
https://www.hackerearth.com/problem/algorithm/covid-rush/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

set<int>vacant;
map<int,vector<int>>mp;

void delete_discharge(int arrival){
	for(auto it=mp.begin();it!=mp.end();++it){
		if(arrival<it->first) break;
		auto centers = it->second;
		for(auto &center: centers){
			vacant.insert(center);
		}
		mp.erase(it);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pr>tm(n);
	vector<int>cnt(n,0);

	for(int i=0;i<n;++i){
		cin>>tm[i].first;
	}

	for(int i=0;i<n;++i){
		cin>>tm[i].second;
	}

	for(int i=0;i<m;++i){
		vacant.insert(i);
	}	

	sort(tm.begin(),tm.end());

	for(int i=0;i<n;++i){
		int mod = i%m;
		delete_discharge(tm[i].first);
		if(vacant.size()==0) continue;

		auto it = vacant.lower_bound(mod);
		if(it == vacant.end()) it = vacant.begin();
		int dischage_day = tm[i].first + tm[i].second;
		mp[dischage_day].push_back(*it);
		cnt[*it]++;
		vacant.erase(it);
	}

	for(int i=0;i<m;i++){
		cout<<cnt[i]<<" ";
	}
}