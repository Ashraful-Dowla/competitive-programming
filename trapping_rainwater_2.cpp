#include <bits/stdc++.h>
using namespace std;

vector<int> height;

//time complexity-> O(N)
int trapping_water(){
	stack<int> stk;
	int ans=0,n=height.size();

	for(int i=0;i<n;++i){
		while(!stk.empty() && height[stk.top()]<height[i]) {
		  	int pop_height = height[stk.top()];
		  	stk.pop();

		  	if(stk.empty()) break;

		  	int dis = i-stk.top()-1;
		  	int min_height = min(height[stk.top()],height[i]) - pop_height;
		  	ans+=(dis*min_height);
		}
		stk.push(i);
	}
	return ans;
}

int main(){
	height= { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout<<trapping_water()<<endl;
}