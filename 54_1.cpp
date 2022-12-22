/*
https://www.spoj.com/problems/PIE/
*/
#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-6;
const int N=1e4+10;

long double arr[N];
long double pi =3.141592653589793238;

int chk(long double mid, int n){
	int fr=0;
	if(mid==0) return 0;
	for(int i=0;i<n;i++){
		fr+=(int)(arr[i]/mid);
	}
	
	return fr;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n,f;
		cin>>n>>f;
		for(int i=0;i<n;++i){
			cin>>arr[i];
			arr[i] = pi*arr[i]*arr[i];
		}

		sort(arr,arr+n);
		long double lo=0,hi=arr[n-1],mid;
		f++;
		while(hi-lo>eps){
			mid = (hi+lo)/2.0;
			if(chk(mid,n)>=f) lo = mid;
			else hi=mid;
		}

		cout<<fixed<<setprecision(4)<<hi<<endl;
	}
}