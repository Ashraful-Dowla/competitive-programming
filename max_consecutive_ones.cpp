#include <bits/stdc++.h>
using namespace std;

// 11 2
// 1 1 1 0 0 0 1 1 1 1 0
// ans: 6

// 5 2
// 1 0 0 0 1 
// ans: 3


//time complexity -> O(N)
int main(){
	int n,k;
	cin>>n>>k;

	int arr[n];

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	int zero_cnt = 0, ans=0,i=0;

	for(int j=0;j<n;++j){
		if(arr[j]==0) zero_cnt++;

		while(zero_cnt>k) {
		    if(arr[i]==0) zero_cnt--;
		    i++;
		}

		ans = max(ans,j-i+1);
	}
	cout<<ans<<endl;
}