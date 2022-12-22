#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>nums = {1};
	int n = 1e5;
	int arr[n];
	memset(arr, 0, sizeof(arr));
	int l = 3e4;
	for(int i=0;i<nums.size();i++){
		arr[nums[i]+l]++;
	}

	int output;
	for(int i=0;i<nums.size();i++){
		if(arr[nums[i]+l]==1) {
			output = nums[i];
		}
	}

	cout<<output<<endl;
}