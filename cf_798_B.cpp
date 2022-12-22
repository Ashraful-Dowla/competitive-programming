/*
https://codeforces.com/problemset/problem/798/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<map<string,int>>vec;

void generate(string s){
	map<string,int> mp;

	mp[s]=0;
	int k=1,len=s.size();
	for(int i=1;i<len;++i){
		string temp = s.substr(i,len-i);

		for(int j=0;j<i;++j){
			temp.push_back(s[j]);
		}	
		mp[temp]=(len-k++);
	}

	vec.push_back(mp);
}

int main(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;++i){
		cin>>s[i];
	}

	for(int i=0;i<n;++i){
		generate(s[i]);
	}

	int ct=1;
	for(int i=1;i<n;++i){
		if(s[i]==s[i-1]) ct++;
	}

	int ans=INT_MAX;
	for(int i=0;i<n;++i){
		map<string,int> mp = vec[i];
		int cnt=0;
		for(int j=0;j<n;++j){
			if(i==j || s[i]==s[j]) continue;

			auto it = mp.find(s[j]);
			if(it!=mp.end()) cnt+=it->second;
			else {
				cnt=INT_MAX;
				break;
			}
		}
		ans = min(ans,cnt);
	}

	if(ct==n) ans=0;

	cout<<(ans==INT_MAX ? -1: ans)<<endl;
}