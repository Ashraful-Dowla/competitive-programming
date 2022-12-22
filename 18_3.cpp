/*
https://www.codechef.com/problems/ICL1905
-incomplete
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n>>a;

		long cost[n+5], mx_d = 0, mn_d = INT_MAX;
		cost[0]=0;
		for(int i=1;i<=n;i++){
			long c,d;
			cin>>c>>d;
			cost[i] = cost[i-1] + c;
			mn_d = min(mn_d, d);
			mx_d = max(mx_d, d);
		}
		long mx_total = 0, d = (mx_d-mn_d)*(mx_d-mn_d);
		for(int i=1;i<n;i++){
			long total;
			for(int j=i+1;j<=n;j++){
				total = (j-i+1)*a;
				total-=(cost[j]-cost[i-1]);
				total-=d;
			}
			mx_total = max(mx_total, total);
		}
		cout<<mx_total<<endl;
	}	
}