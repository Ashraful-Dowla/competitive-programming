/*
https://www.codechef.com/LRNDSA01/problems/CARVANS
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int mn=arr[0], cnt=1;
		for(int i=1;i<n;i++){
			if(arr[i]<=mn) {
				cnt++;
				mn=arr[i];
			}
		}

		cout<<cnt<<endl;
	}
}