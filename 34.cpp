#include <bits/stdc++.h>
using namespace std;

void printMap(unordered_map<int,string> &m){
	for(auto &val:m){
		cout<<val.first<<" "<<val.second<<endl;
	}
}

int main(){
	//1. inbuilt implementation - hashtable
	//2. time complexity - O(1)
	//3. valid key datatypes - containers not allowed
	unordered_map<int, string>m;
	m[1] = "abc";
	m[5] = "cdc";
	m[3] = "acd";
	m[6] = "a";
	m[5] = "cde";
	m.insert({4,"afg"});

	printMap(m);
}