/*
https://codeforces.com/problemset/problem/1553/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    string s,t;
	    cin>>s;
	    cin>>t;

	    int chk=false;
	    int sz_s=s.size();
	    int sz_t=t.size();

	    for(int i=0;i<sz_s;++i){
	    	int k=i,j=0;
	    	while(k<sz_s && j<sz_t && s[k]==t[j]){
	 	    	k++;
	 	    	j++;
	    		int p=j-1;
	    		for(int l=k-1;l>=0;--l){
		    		if(s[l]==t[p]) p++;
		    		else break;
		    	}

		    	if(p==sz_t){
		    		chk=true;
		    		break;
		    	} 
	    	}

	    	if(chk) break;
	    
	    }

	    cout<<(chk ? "YES":"NO")<<endl;
	}
}