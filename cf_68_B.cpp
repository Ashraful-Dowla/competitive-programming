/*
https://codeforces.com/contest/68/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
int n;
double eps=1e-9,arr[N],k;

bool maxPossible(double mid){
	double transfer=0, need=0;
	for(int i=0;i<n;++i){
		if(mid>arr[i]) need+=(mid-arr[i]);
		else {
			double eff = (arr[i]-mid)*(1.0-k/100.0);
			transfer+=eff;
		}
	}
	return transfer>=need;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	double lo=0,hi=1000.0,mid,mx=-1.0;
	while(hi-lo>eps) {
	   mid = (hi+lo)/2.0;
	   if(maxPossible(mid)){
	   	  lo=mid;
	   	  mx = max(mx,mid);
	   }
	   else hi=mid;
	}
	cout<<fixed<<setprecision(9)<<mx<<endl;
}