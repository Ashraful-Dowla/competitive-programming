/*
https://codeforces.com/contest/1749/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    bool arr[n+1][n+1];

	    memset(arr,true,sizeof(arr));

	    for(int i=0;i<m;++i){
	    	int x,y;
	    	cin>>x>>y;
	    	arr[x][y]=false;

	    	for(int k=1;k<=n;++k){
	    		arr[x][k]=arr[k][y]=false;
	    	}
	    }

	    bool isPossible=false;
	    for(int i=1;i<=n;++i){
	    	for(int j=1;j<=n;++j){
	    		if(arr[i][j]){
	    			for(int k=1;i<=n;++k){
	    				if(arr[i][k]==false || arr[k][j]==false){
	    					isPossible=true;
	    					break;
	    				}
	    			}
	    		}
	    		if(isPossible) break;
	    	}
	    	if(isPossible) break;
	    }

	    cout<<(isPossible ? "YES":"NO")<<endl;
	}
}