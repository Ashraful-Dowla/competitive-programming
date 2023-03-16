/*
https://leetcode.com/problems/integer-to-roman/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<int, string> mp = {
	{1, "I"},
	{4, "IV"},
	{5, "V"},
	{9, "IX"},
	{10, "X"},
	{40, "XL"},
	{50, "L"},
	{90, "XC"},
	{100, "C"},
	{400, "CD"},
	{500, "D"},
	{900, "CM"},
	{1000, "M"}
};

string intToRoman(int num) {
   vector<int> nums = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

   string ans="";

   while(num){
   	  auto it = lower_bound(nums.begin(),nums.end(), num);

   	  if(it==nums.end() || (*it)!=num) it--;

   	  int val = *it;
   	  while(num>=val){
   	  	  num-=val;
   	  	  ans+=mp[val];
   	  }
   }

   return ans;

}

int main(){
	int num = 8;
	cout<<intToRoman(num);
}