/*
https://codeforces.com/contest/1549/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string arr[2];

	    for(int i=0;i<2;++i){
	    	cin>>arr[i];
	    }

	    int cnt=0;
	    bool taken[n];
	   	memset(taken,false,sizeof(taken));
	    for(int i=0;i<n;++i){
	    	if(arr[1][i]=='1'){
	    		if(arr[0][i]=='0'){
	    			cnt++;
	    		}
	    		else {
	    			if(i-1>=0 && arr[0][i-1]=='1' && !taken[i-1]){
	    				 cnt++;
	    				 taken[i-1]=true;
	    			}
	    			else if(i+1<n && arr[0][i+1]=='1' && !taken[i+1]){
						 cnt++;
	    				 taken[i+1]=true;
	    			}
	    		}
	    	}
	    }
	    cout<<cnt<<endl;
	}
}