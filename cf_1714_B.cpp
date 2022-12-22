/*
https://codeforces.com/problemset/problem/1714/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n+2],hsh[n+2];

	    for(int i=0;i<n;++i){
           cin>>arr[i];
	    }
	    memset(hsh,0,sizeof(hsh));
	    stack<int>stk;
	    for(int i=n-1;i>=0;--i){
	    	int val=arr[i];
	    	hsh[val]++;
	    	int mx = stk.empty() ? hsh[val] : max(hsh[val],stk.top());
	    	stk.push(mx);
	    }

	    int cnt=0;
	    while(stk.top()!=1){
	    	cnt++;
	    	stk.pop();
	    }
	    cout<<cnt<<endl;
	}
}