/*
https://codeforces.com/contest/1760/problem/B
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

	    bool chk[26];
	    memset(chk,false,sizeof(chk));

	    for(int i=0;i<n;++i){
	    	chk[s[i]-'a']=true;
	    }

	    for(int i=25;i>=0;--i){
	    	if(chk[i]){
	    		cout<<i+1<<endl;
	    		break;
	    	}
	    }
	}
}