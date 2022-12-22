/*
https://codeforces.com/contest/1736/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;

	    vector<int>a(n),b(n);

	    int a_0=0,a_1=0;
	    for(int i=0;i<n;++i){
	    	cin>>a[i];	
	    	if(a[i]==1) a_1++;
	    	else a_0++;
	    }

	    int b_0=0,b_1=0;
	    for(int i=0;i<n;++i){
	    	cin>>b[i];
	    	if(b[i]==1) b_1++;
	    	else b_0++;
	    }

	    int cnt=0;
	    if(a_1==b_1){
	    	for(int i=0;i<n;++i){
	    		if(a[i]==b[i]) continue;
	    		cnt++;
	    		break;
	    	}
	    }
	    else if(a_1>b_1) {
	    	cnt=a_1-b_1;
	    	int temp=cnt;

	    	for(int i=0;i<n;++i){
	    		if(a[i]==1 && b[i]==0 && temp) temp--;
	    		else if(a[i]!=b[i]) {
	    			cnt++;
	    			break;
	    		}
	    	}
	    }
	    else {
	    	cnt=b_1-a_1;
	    	int temp=cnt;

	    	for(int i=0;i<n;++i){
	    		if(a[i]==0 && b[i]==1 && temp) temp--;
	    		else if(a[i]!=b[i]) {
	    			cnt++;
	    			break;
	    		}
	    	}
	    }

	    cout<<cnt<<endl;
	    
	}
}