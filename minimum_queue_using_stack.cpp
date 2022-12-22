#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

stack<pr>stk1,stk2;

void add(int new_element){
	int min_element = stk1.empty() ? new_element : min(new_element,stk1.top().second);
	stk1.push({new_element,min_element});
}

int rmv(){
	if(stk2.empty()){
		while(!stk1.empty()) {
		  	int element = stk1.top().first;
		  	stk1.pop();
		  	int min_element = stk2.empty() ? element : min(element,stk1.top().second);
		  	stk2.push({element,min_element});
		}
	}
	int remove_element = stk2.top().first;
	stk2.pop();
}

int getMin(){
	int mn;
	if(stk1.empty() || stk2.empty()){
		mn = stk1.empty() ? stk2.top().second : stk1.top().second;
	}
	else mn = min(stk1.top().second, stk2.top().second);

	cout<<mn<<endl;
}

int main(){
	add(4);
	add(5);
	getMin();
	rmv();
	add(1);
	getMin();
}