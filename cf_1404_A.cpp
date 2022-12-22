/*
https://codeforces.com/problemset/problem/1404/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
		int sz,k;
	    cin>>sz>>k;
	    string s;
	    cin>>s;

	    bool chk=true;
	    for(int i=0;i<sz;++i){
	    	if(s[i]!='?' && s[i%k]!='?' && s[i]!=s[i%k]){
	    		chk=false;
	    		break;
	    	}
	    	if(s[i]!='?') s[i%k]=s[i];
	    }

	    int cnt_1=0,cnt_0=0;
	    for(int i=0;i<k;++i){
	    	cnt_1+=(s[i]=='1');
	    	cnt_0+=(s[i]=='0');
	    }

	    if(!chk || cnt_0>k/2 || cnt_1>k/2) cout<<"NO"<<endl;
	    else cout<<"YES"<<endl;
	}
}