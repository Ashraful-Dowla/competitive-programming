#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v = {1,2,3,4,5};

	for(auto it=v.begin();it!=v.end();it++){
		cout<<*it<<endl;
	}

	//range loop
	for(int &value: v){
		cout<<value<<" ";
	}
	cout<<endl;

	vector<pair<int,int>>v_p = {{1,2},{2,3}};

	for(pair<int,int> &value: v_p){
		cout<<value.first<<" "<<value.second<<endl;
	}

	for(auto &value: v_p){
		cout<<value.first<<" "<<value.second<<endl;
	}
}