/*
https://codeforces.com/contest/1407/problem/B
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


	   int arr[n],mx=0,idx;
	   for(int i=0;i<n;++i){
	   	 cin>>arr[i];
	   	 if(mx<arr[i]){
	   	 	idx=i;
	   	 	mx=arr[i];
	   	 }
	   }

	   bool taken[n];
	   memset(taken,false,sizeof(taken));
	   taken[idx]=true;

	   vector<int>res;
	   res.push_back(mx);

	   int gcd=mx;
	   for(int i=0;i<n;++i){
	   		int temp=0,idxx;
	   		for(int j=0;j<n;++j){
	   			if(taken[j]) continue;
	   			if(temp<__gcd(gcd,arr[j])){
	   				temp=__gcd(gcd,arr[j]);
	   				idxx=j;
	   			}
	   		}

	   		taken[idxx]=true;
	   		gcd=__gcd(gcd,arr[idxx]);
	   		res.push_back(arr[idxx]);
	   }

	   for(int i=0;i<res.size()-1;++i){
	   	 // cout<<res[i]<<" ";
	   	printf("%d ", res[i]);
	   }
	   // cout<<endl;
	   printf("\n");
	}
}