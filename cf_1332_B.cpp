/*
https://codeforces.com/problemset/problem/1332/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<int>d[1007];

int divisor(int n){
	for(int i=2;i<=n;++i){
		if(n%i==0) return i;
	}
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    for(int i=1;i<=1000;++i){
	    	d[i].clear();
	    }

	    for(int i=1;i<=n;++i){
	    	int x;
	    	cin>>x;
	    	d[divisor(x)].push_back(i);
	    }

	    int m=0,color[n+2];

	    for(int i=2;i<=1000;++i){
	    	if(d[i].size()){
	    		m++;
	    		for(auto idx:d[i]){
	    			color[idx]=m;
	    		}
	    	}
	    }

	    cout<<m<<endl;
	    for(int i=1;i<=n;++i){
	    	cout<<color[i]<<" ";
	    }
	    cout<<endl;
	}
}