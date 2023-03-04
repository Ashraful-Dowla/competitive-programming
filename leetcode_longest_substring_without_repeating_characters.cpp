/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
#include <bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstring(string s) {
	int mx=0, ch[30], start=-1;
	memset(ch,-1,sizeof(ch));

	for(int i=0;i<s.size();++i){
		if(ch[s[i]-'a']>start){
			start = ch[s[i]-'a'];
		}
		ch[s[i]-'a']=i;
		mx = max(mx, i-start);
	}

	return mx;
}

int main(){
	// string s="pwwke";
	string s = "abcabcabb";
	cout<<lengthOfLongestSubstring(s)<<endl;
}