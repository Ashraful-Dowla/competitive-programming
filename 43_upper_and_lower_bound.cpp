#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	// int arr[n];
	vector<int>arr(n);
	set<int>s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		s.insert(arr[i]);
	}
	// sort(arr,arr+n);
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	// int *ptr = lower_bound(arr,arr+n,6);
	// int *ptr = upper_bound(arr,arr+n,2);
	// auto it = lower_bound(arr.begin(),arr.end(),3);
	auto it = upper_bound(arr.begin(),arr.end(),2);
	// cout<<*ptr<<endl;
	// cout<<*it<<endl;

	auto it_s = s.lower_bound(2);
	cout<<*it_s<<endl;
}