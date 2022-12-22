/*
https://codeforces.com/problemset/problem/1194/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    string s,t,p;
	    cin>>s;
	    cin>>t;
	    cin>>p;

	    bool hsh[t.size()],taken[p.size()];
	    memset(hsh,false,sizeof(hsh));
	    memset(taken,false,sizeof(taken));

	    int cnt=0;
	    for(int i=0,k=0;i<s.size();++i){
	    	for(int j=k;j<t.size();++j){
	    		if(s[i]==t[j]){
	    			hsh[j]=true;
	    			k=j+1;
	    			cnt++;
	    			break;
	    		}
	    	}
	    }

	    if(cnt!=s.size()){
	    	cout<<"NO"<<endl;
	    	continue;
	    }

	    for(int i=0;i<t.size();++i){
	    	if(hsh[i]) continue;

	    	for(int j=0;j<p.size();++j){
	    		if(taken[j]) continue;
	    		if(t[i]==p[j]){
	    			cnt++;
	    			taken[j]=true;
	    			break;
	    		}
	    	}
	    }

	    cout<<(cnt==t.size() ? "YES":"NO")<<endl;
	}
}