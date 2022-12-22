/*
https://codeforces.com/contest/1759/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int m,sum;
	    cin>>m>>sum;

	    bool arr[N];
	    memset(arr,false,sizeof(arr));

	    int mx=0;
	    for(int i=0;i<m;++i){
	    	int x;
	    	cin>>x;
	    	arr[x]=true;
	    	mx = max(mx,x);
	    }

	    int sum2=0;
	    for(int i=1;i<=mx;++i){
	    	if(!arr[i]) sum2+=i;
	    }

	    sum-=sum2;

	    if(sum>0){
	    	for(int i=mx+1;;++i){
		    	sum-=i;
		    	if(sum<=0) break;
		    }
	    }

	    cout<<(sum ==0 ? "YES": "NO")<<endl;
	}


}