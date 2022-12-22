/*
https://codeforces.com/contest/1348/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n,k;
	    cin>>n>>k;
	    
	    set<int>s;
	    int hsh[105];
	    memset(hsh,0,sizeof(hsh));

	    int mx=0;
	    for(int i=0;i<n;++i){
	    	int x;
	    	cin>>x;
	    	s.insert(x);
	    	hsh[x]++;
	    	mx = max(mx,hsh[x]);
	    }

	    if(k>=s.size()){
	    	int nk=k;
	    	vector<int>vec;
		    while(nk){
		    	for(auto it=s.begin();it!=s.end() && nk;++it){
		    		nk--;
		    		vec.push_back(*it);
		    	}
		    }
		    sort(vec.begin(),vec.end());

		    cout<<n*k<<endl;
	    	for(int i=0;i<n;++i){
	    		for(int j=0;j<k;++j){
	    			cout<<vec[j]<<" ";
	    		}
	    	}
	    	cout<<endl;
	    }
	    else cout<<-1<<endl;
	}
}