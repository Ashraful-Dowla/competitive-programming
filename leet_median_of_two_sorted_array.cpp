/*
https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/898301592/
*/
#include <bits/stdc++.h>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    for(auto x: nums2){
       nums1.push_back(x);
    }

    int total=nums1.size();
    double ans;

    sort(nums1.begin(),nums1.end());
    if(total&1) ans = nums1[total/2];  
    else {
        ans = (nums1[total/2] + nums1[(total-1)/2])/2.0;
    }

    return ans;
}

int main(){
   vector<int> nums1 = {1,2};
   vector<int> nums2 = {3,4};

   cout<<findMedianSortedArrays(nums1,nums2)<<endl;
}