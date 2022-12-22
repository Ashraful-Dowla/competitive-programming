/*
https://leetcode.com/problems/word-pattern
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	string pattern ="abba", s = "dog dog dog dog";
	map<char, string>mp;
	map<string, string>mp_r;

	s.push_back(' ');
	int indx=0, word=0;
	bool check = true;

	string temp = "";
	vector<string>vec;
	while(indx<=s.size()){
		if(s[indx]!=' ') {
			temp.push_back(s[indx]);
		}
		else {
			vec.push_back(temp);
			temp="";
		}
		indx++;
	}

	if(vec.size()!=pattern.size()) check=false;
	else {
		for(int i=0;i<pattern.size();i++){
			string st(1,pattern[i]);
			if(mp[pattern[i]]=="" && mp_r[vec[i]]=="") {
				mp[pattern[i]] = vec[i];
				mp_r[vec[i]] = st;
			}
			if(mp[pattern[i]]!=vec[i] || mp_r[vec[i]]!=st){
				check = false;
				break;
			}
		}
	}
	
	cout<<check<<endl;
}