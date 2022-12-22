/*
https://codeforces.com/problemset/problem/1487/C
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	// cin>>t;
	scanf("%d",&t);
	while(t--) {
	   int n;
	   // cin>>n;
	   scanf("%d",&n);
	   int arr[n+2];

	   int sum= 3*n*(n-1);
	   sum/=2;
	   int avg=sum/n;
	   for(int i=1;i<=n;++i){
	   		arr[i]=avg;
	   }

	   int N=n*(n-1);
	   N/=2;
	   int ans[N+10],k=0;
	   for(int i=1;i<=n;++i){
	   	  for(int j=i+1;j<=n;++j){
	   	  	 if(arr[i]>=3) {
	   	  	 	arr[i]-=3;
	   	  	 	ans[k]=1;
	   	  	 } 
	   	  	 else if(arr[i]>0){
	   	  	 	arr[i]-=1;
	   	  	 	arr[j]-=1;
	   	  	 	ans[k]=0;
	   	  	 }
	   	  	 else {
	   	  	 	arr[j]-=3;
	   	  	 	ans[k]=-1;
	   	  	 }
	   	  	 k++;
	   	  }
	   }

	   for(int i=0;i<k;++i){
	   	  // cout<<ans[i]<<" ";
	   	  printf("%d ",ans[i]);
	   }
	   // cout<<"\n;
	   printf("\n");
	}
}