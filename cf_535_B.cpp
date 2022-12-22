/*
https://codeforces.com/problemset/problem/535/B
*/
#include <bits/stdc++.h>
using namespace std;

vector<int>subset;

void generate(int idx,string sub=""){
	if(idx==10) return ;

	if(sub!="") subset.push_back(stoi(sub));

	sub.push_back('4');
	generate(idx+1,sub);
	sub.pop_back();

	sub.push_back('7');
	generate(idx+1,sub);
	sub.pop_back();
}

int main(){	

	generate(0);
	sort(subset.begin(),subset.end());
	
	int x;
	cin>>x;

	auto it = lower_bound(subset.begin(),subset.end(),x);
	cout<<(it-subset.begin()+1)<<endl;
}