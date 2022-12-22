/*
https://codeforces.com/contest/1758/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int arr[N];

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    if(n==2){
	    	cout<<"1 3"<<endl;
	    	continue;
	    }
	    if(n==3){
	    	cout<<"7 6 3"<<endl;
	    	continue;
	    }
	    if(n==4){
	    	cout<<"25 21 23 31"<<endl;
	    	continue;
	    }
	    if(n==5){
	    	cout<<"20 29 18 26 28"<<endl;
	    	continue;
	    }

	    // 1+3+5+....+2*n-1 = n^2
	    // ((2*n-1) -1)^2 = 4n^2-8n+4 = n^2 + n*(3*n-8) + 4

	    int odd=1;
	    for(int i=1;i<=n;++i){
	    	arr[i]=odd;
	    	arr[i]+=(3*n-8);
	    	odd+=2;
	    }

	    int idx=2;
	    while(idx<=5){
	    	arr[idx]++;
	    	idx++;
	    }

	    for(int i=1;i<=n;++i){
	    	cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	  
	}
}