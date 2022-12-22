/*
https://codeforces.com/problemset/problem/1486/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e3+5;
ll x[N],y[N];

ll calc(ll *arr,int n){
	sort(arr,arr+n);
	ll res = arr[n/2] - arr[(n-1)/2]+1;
	return res;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;
	    
	    for(int i=0;i<n;++i){
	    	cin>>x[i]>>y[i];
	    }

	    cout<<calc(x,n)*calc(y,n)<<endl;
	}
}