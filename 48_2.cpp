/*
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
-incomplete
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int arr[N][30],pf[N][30];

int sub_string(string s, int k){
	for(int i=1;i<=s.size();i++){
		arr[i][s[i-1]-'a']++;
	}

	for(int i=0;i<26;i++){
		for(int j=1;j<=s.size();j++){
			pf[j][i]+=(pf[j-1][i]+arr[j][i]);
		}
	}

	for(int i-)

	set<pair<int,int>>st;
	for(int i=1;i<=s.size();i++){
		int total = 0;
		int mn = INT_MAX;
		for(int j=0;j<26;j++){
			if(pf[i][j]>0) mn = min(mn, pf[i][j]);
			total+=pf[i][j];
		}
		st.insert({mn,total});
	}

	// for(auto &val: st){
	// 	cout<<val.first<<" "<<val.second<<endl;
	// }

	auto it = --st.end();

	return it->first <k ? 0: it->second;
}

int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;

	cout<<sub_string(s,k)<<endl;
}