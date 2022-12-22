/*
https://codeforces.com/problemset/problem/1343/C
*/
#include <bits/stdc++.h>
using namespace std;

bool check_sign(int x){
	return x>0;
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;

	    int arr[n];
	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    }

	    long long sum=0;
	    for(int i=0;i<n;++i){
	    	int cur = arr[i];
	    	int j=i;
	    	while(j<n && check_sign(arr[i])==check_sign(arr[j])){
	    		cur = max(cur,arr[j]);
	    		++j;
	    	}
	    	i=j-1;
	    	sum+=1LL*cur;
	    }
	    cout<<sum<<endl;
	}
}