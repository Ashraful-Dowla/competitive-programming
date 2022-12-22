#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums){
	int n = nums.size();
	int subset_ct = (1<<n);

	vector<vector<int>> subsets;
	for(int mask=0; mask<subset_ct; ++mask){
		vector<int>subset;
		for(int i=0;i<n;++i){
			if(mask&(1<<i)) {
				subset.push_back(nums[i]);
			}
		}
		subsets.push_back(subset);
	}

	for(auto &subset: subsets){
		for(auto &val: subset){
			cout<<val<<" ";
		}
		cout<<endl;
	}

	//O(n*2^n)
}

int main(){
	int n;
	cin>>n;
	vector<int>vec(n);

	for(int i=0;i<n;++i){
		cin>>vec[i];
	}

	subsets(vec);
}