/*
https://codeforces.com/contest/1285/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define pno cout<<"NO"<<endl
#define pys cout<<"YES"<<endl
typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;

	    ll arr[n];
	    ll y_sum=0;
	    for(int i=0;i<n;++i){
 			cin>>arr[i];
 			y_sum+=arr[i];
	    }

	    ll a_sum=0,best=0;
	    int st=0,nd=0;
	    for(int i=0;i<n;++i){
	    	a_sum = max(arr[i],a_sum+arr[i]);
	    	if(a_sum==arr[i]) st=i;

	    	if(best<a_sum){
	    		best=a_sum;
	    		nd=i;
	    	}
	    }
	    a_sum = best;

	    if(y_sum == a_sum && (st>0 || nd<n-1)) pno;
	    else if(y_sum==a_sum) pys;
	    else if(y_sum>a_sum) pys;
	    else pno;
	}
}