/*
https://codeforces.com/problemset/problem/1520/A
*/
#include <bits/stdc++.h>
using namespace std;

bool finished[100];

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(finished,false,sizeof(finished));
		int len;
		cin>>len;
		string s;
		cin>>s;
		if(s.size()==1 || s.size()==2) cout<<"YES"<<endl;
		else {
			string distract="YES";
			for(int i=1;i<s.size();++i){
				if(s[i]!=s[i-1]) {
					if(finished[(int)s[i]]){
						distract="NO";
						break;
					}
					finished[(int)s[i-1]]=true;
				}
			}
			cout<<distract<<endl;
		}
	}
}