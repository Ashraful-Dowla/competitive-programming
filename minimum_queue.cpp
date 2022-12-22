#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

deque<pr>dq;
int cnt_added,cnt_removed;

void add(int new_element){
	while(!dq.empty() && dq.back().first>new_element) {
	    dq.pop_back();
	}
	dq.push_back({new_element,cnt_added});
	cnt_added++;
}

void rmv(){
	if(!dq.empty() && dq.front().second ==  cnt_removed){
		dq.pop_front();
	}
	cnt_removed++;
}

//O(1)
int getMin(){
	cout<<dq.front().first<<endl;
}

int main(){
	add(4);
	add(5);
	getMin();
	add(1);
	getMin();
	rmv();
	getMin();
}