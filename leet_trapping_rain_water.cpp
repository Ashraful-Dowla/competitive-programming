/*
https://leetcode.com/problems/trapping-rain-water/description/
*/
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {

	int n = height.size();
	int mx_left_height[n],mx_right_height[n], mn_height[n];

	mx_left_height[0]=mx_right_height[n-1]=mn_height[n-1]=-1;

	for(int i=1;i<n;++i){
		mx_left_height[i] = max(height[i-1],mx_left_height[i-1]);
	}

	for(int i=n-2;i>=0;--i){
		mx_right_height[i] = max(height[i+1], mx_right_height[i+1]);
		mn_height[i] = min(mx_left_height[i], mx_right_height[i]);
	}

	int ans=0;
	for(int i=0;i<n;++i){
		ans+=max(mn_height[i]-height[i],0);
	}

	return ans;
}

int main(){

	// vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height = {4,2,0,3,2,5};
	cout<<trap(height)<<endl;
}