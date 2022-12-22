/*
https://leetcode.com/problems/valid-anagram/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	 string s = "anagram", t = "nagaram";

	 int hshS[30], hshT[30];

	 memset(hshS, 0, sizeof(hshS));
	 memset(hshT, 0, sizeof(hshT));

	 for(int i=0;i<s.size();i++){
	 	hshS[s[i]-'a']++;
	 }
	 for(int i=0;i<t.size();i++){
	 	hshT[t[i]-'a']++;
	 }

	 bool check = true;
	 for(int i=0;i<s.size();i++){
	 	if(hshS[s[i]-'a']!=hshT[s[i]-'a']){
	 		check = false;
	 		break;
	 	}
	 }

	 for(int i=0;i<t.size();i++){
	 	if(hshS[t[i]-'a']!=hshT[t[i]-'a']){
	 		check = false;
	 		break;
	 	}
	 }

	 cout<<check<<endl;
}