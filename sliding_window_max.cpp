#include <bits/stdc++.h>
using namespace std;

//time complexity -> O(nlogn)
int main(){
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(auto &i: arr){
		cin>>i;
	}

	multiset<int,greater<int>>ms;
	vector<int>ans;
	for(int i=0;i<k;++i){
		ms.insert(arr[i]);
	}
	ans.push_back(*ms.begin());

	for(int i=k;i<n;++i){
		ms.erase(ms.lower_bound(arr[i-k]));
		ms.insert(arr[i]);
		ans.push_back(*ms.begin());
	}

	for(auto val: ans){
		cout<<val<<" ";
	}

}