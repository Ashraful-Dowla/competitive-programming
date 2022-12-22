/*
https://codeforces.com/contest/42/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

double a[25],b[25],n,v,eps=1e-6,mn=100;

bool maxPossible(double mid){
	double nw=0;
	for(int i=0;i<n;++i){
		nw+=(a[i]*mn);
	}
	return mid<=nw;
}

int main(){
	cin>>n>>v;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<n;++i){
		cin>>b[i];
	}

	for(int i=0;i<n;++i){
		mn = min(mn,b[i]/a[i]);
	}

	double lo=0,hi=v,mid,mx=0;
	while(hi-lo>eps) {
	    mid = (hi+lo)/2.0;
	    if(maxPossible(mid)){
	    	lo = mid;
	    	mx = max(mx,mid);
	    }
	    else hi = mid;
	}
	cout<<fixed<<setprecision(6)<<mx<<endl;
}