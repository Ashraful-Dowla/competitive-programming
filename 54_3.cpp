/*
https://codeforces.com/problemset/problem/474/B
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n+1),arr1(n+1),arr2(n+1);
	arr1[0]=arr2[0]=0;

	unordered_map<int,int>mp;

	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}

	for(int i=1;i<=n;++i){
		arr1[i]= arr2[i-1]+1;
		arr2[i] = arr2[i-1] + arr[i];
		mp[arr1[i]]=i;
	}

	int m;
	cin>>m;
	for(int i=0;i<m;++i){
		int val;
		cin>>val;
		auto it = lower_bound(arr1.begin()+1,arr1.begin()+n+1,val);
		if(it==arr1.end() || *it!=val) {
			it--;
			cout<<mp[*it]<<endl;
		}
		else if(val==*it) cout<<mp[*it]<<endl;
	}
}
