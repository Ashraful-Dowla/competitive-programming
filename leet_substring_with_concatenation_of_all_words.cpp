/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    
    s+='#';
    int w_sz = words[0].size();
    int sz = s.size();

    unordered_map<string,int> mp, cnt;
    vector<int> ans;

    for(auto word: words){
    	  mp[word]++;
    }

    for(int i=0;i<sz;++i){
    	  string sub = s.substr(i,w_sz);

    	  if(!mp[sub]) continue;

    	  int ct=0,times=1;
    	  unordered_map<string,int> seen;

    	  seen[sub]++;
    	  if(mp[sub]==seen[sub]) ct+=seen[sub];

    	  for(int j=i+w_sz;j<sz;j+=w_sz){
    	  	if(times>words.size()) break;
    	  	if(ct==words.size()) {
    	  		ans.push_back(i);
    	  		break;
    	  	}

    	  	string ss = s.substr(j,w_sz);
    	  	if(!mp[ss]) break;

    	  	times++,seen[ss]++;
    	  	if(mp[ss]==seen[ss]) ct+=seen[ss];
    	  }
    }

    return ans;
}


int main(){
	string s="lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string> words = {"fooo","barr","wing","ding","wing"};

	vector<int> ans = findSubstring(s,words);

	cout<<"----"<<endl;
	for(auto x: ans){
		cout<<x<<" ";
	}
	cout<<endl;
}