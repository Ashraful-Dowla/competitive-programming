/*
https://leetcode.com/problems/first-missing-positive/description/
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
bool chk[N];

int firstMissingPositive(vector<int>& nums) {

    for(auto x: nums){
    	if(x<1) continue;
    	if(x>=N) x=N-1;
    	chk[x]=true;
    }

    for(int i=1;i<N;++i){
    	if(!chk[i]) return i;
    }
}

int main(){

	vector<int> nums = {7,8,9,11,12};
	cout<<firstMissingPositive(nums)<<endl;
}