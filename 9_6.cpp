/*
https://www.spoj.com/problems/MOZSATLA/
--incomplete
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n], arr2[n];
		for(int i=1;i<=n-1;i++){
			cin>>arr[i];
		}

		arr2[1] = 1; 
		for(int i=1;i<=n-1;i++){
			if(arr[i]==0){
				arr2[i+1] = arr2[i];
			}
			else if(arr[i]==1){
				arr2[i+1] = arr2[i]+1;
			}
			else {
				arr2[i] = arr2[i]-1;
			}
		}

		for(int i=1;i<=n;i++){
			cout<<arr2[i]<<" ";
		}
		cout<<endl;
	}
}