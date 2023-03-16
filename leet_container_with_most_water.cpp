/*
https://leetcode.com/problems/container-with-most-water/description/
*/
#include <bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height) {
    int l=0,r=height.size()-1;

    int ans=0;
    while(l<r) {
        if(height[l]<=height[r]){
        	ans = max(ans,(r-l)*height[l]);
        	l++;
        }
        else{
        	ans = max(ans,(r-l)*height[r]);
        	r--;
        }
    }

    return ans;
}

int main(){
	// vector<int> height = {1,8,6,2,5,4,8,3,7};
	vector<int> height = {1,0,3,4,5,7,8};
	cout<<maxArea(height);
}