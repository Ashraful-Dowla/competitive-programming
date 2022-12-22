#include <bits/stdc++.h>
using namespace std;

// 6 3
// 8 23 45 12 56 4
// time complexity -> O(n)
int main(){
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	pair<int,int> ans;
	int sum=0;

	for(int i=0;i<k;++i){
		sum+=arr[i];
	}

	bool found = false;
	if(sum%3==0) {
		found = true;
		ans = {0,k-1};
	}

	for(int i=k;i<n;++i){
		if(found) break;
		sum+=(arr[i]-arr[i-k]);
		if(sum%3==0){
			found=true;
			ans = {i-k+1,i};
		}
	}

	if(!found) {
		cout<<"nothing found"<<endl;
		return 0;
	}
	
	for(int i=ans.first;i<=ans.second;++i){
		cout<<arr[i]<<" ";
	}
}