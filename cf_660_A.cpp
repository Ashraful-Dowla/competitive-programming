/*
https://codeforces.com/problemset/problem/660/A
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;++i) cin>>arr[i];

	vector<int> ans;
	ans.push_back(arr[0]);

	for(int i=1;i<n;++i){
		int sz=ans.size()-1;
		if(__gcd(ans[sz],arr[i])==1){
			ans.push_back(arr[i]);
		}
		else {
			ans.push_back(1);
			ans.push_back(arr[i]);
		}
	}

	cout<<ans.size()-n<<endl;
	for(auto val: ans){
		cout<<val<<" ";
	}
	cout<<endl;
}