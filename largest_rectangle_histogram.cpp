#include <bits/stdc++.h>
using namespace std;

vector<int> his;

//time complexity -> O(N)
int get_max_area(){
	int n = his.size(),ans=0,i=0;
	stack<int> stk;

	while(i<n) {
	   if(stk.empty() || his[stk.top()]<=his[i]){
	   	 stk.push(i++);
	   }
	   else {
	   	  int top = stk.top();
	   	  stk.pop();
	   	  int area = his[top]*(stk.empty() ? i: i-stk.top()-1);
	   	  ans = max(ans,area);
	   }
	}

	while(!stk.empty()){
		int top = stk.top();
	   	stk.pop();
	   	int area = his[top]*(stk.empty() ? i: i-stk.top()-1);
	   	ans = max(ans,area);
	}

	return ans;
}

int main(){
	his =  {6, 2, 5, 4, 5, 1, 6};
	cout<<get_max_area()<<endl;
}