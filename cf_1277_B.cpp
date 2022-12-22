/*
https://codeforces.com/contest/1277/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int main(){
	int t;
	// cin>>t;
	scanf("%d",&t);

	while(t--) {
	    int n;
	    // cin>>n;
		scanf("%d",&n);


	    int arr[n];
	    unordered_map<int,int>cnt;
	    unordered_map<int,bool>taken;

	    for(int i=0;i<n;++i){
	    	cin>>arr[i];
	    	if(arr[i]%2==0) cnt[arr[i]]++;
	    }

	    sort(arr,arr+n);

	    int ct=0;
	    for(int i=n-1;i>=0;--i){
	    	int val = arr[i];
	    	if(val%2==1) continue;
	    	if(!taken[val]){
	    		taken[val]=true;
	    		while(val%2==0){
	    			val/=2;
	    			ct++;
	    			if(cnt[val]) taken[val]=true;
	    		}
	    	}
	    }

	 	printf("%d\n",ct);
	}
}