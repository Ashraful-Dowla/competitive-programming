/*
https://codeforces.com/contest/1703/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    map<char,bool>mp;
	    int cnt=0;
	    for(int i=0;i<n;++i){
	    	char ch = s[i];
	    	cnt+=(mp[ch] ? 1:2);
	    	mp[ch]=true;
	    }
	    cout<<cnt<<endl;
	}
}