#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
vector<int> prices,ans;

//time complexity -> O(N)
void stock_span(){
	stack<pr> stk;

	for(auto &price: prices){
		int days=1;

		while(!stk.empty() && stk.top().first<=price) {
		    days+=stk.top().second;
		    stk.pop();
		}

		stk.push({price,days});
		ans.push_back(days);
	}
}

int main(){
	prices = {100,80,60,70,60,75,85};
	stock_span();

	for(auto &val: ans){
		cout<<val<<" ";
	}
	cout<<endl;
}