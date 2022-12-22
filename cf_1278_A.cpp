/*
https://codeforces.com/problemset/problem/1278/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    string p,h;
	    cin>>p;
	    cin>>h;

	    int sz_p=p.size();
	    int sz_h=h.size();

	    int hsh[26],temp[26];
	    memset(hsh,0,sizeof(hsh));

	    for(int i=0;i<sz_p;++i){
	    	hsh[p[i]-'a']++;
	    }

	    bool ok=false;
	    for(int i=0;i<=sz_h-sz_p;++i){
	    	memset(temp,0,sizeof(temp));
	    	for(int j=i;j<i+sz_p;++j){
	    		temp[h[j]-'a']++;
	    	}
	    	bool chk=true;
	    	for(int k=0;k<26;++k){
	    		if(hsh[k]==temp[k]) continue;
	    		chk=false;
	    		break;
	    	}
	    	if(chk) {
	    		ok=true;
	    		break;
	    	}
	    }

	    cout<<(ok ? "YES":"NO")<<endl;	    
	}
}