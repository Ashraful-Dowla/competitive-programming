#include <bits/stdc++.h>
using namespace std;

void prnt(unordered_set<string> &s){
	for(string val:s){
		cout<<val<<endl;
	}
}

int main(){
	unordered_set<string>s;
	s.insert("abc"); //O(1)
	s.insert("zfsg");
	s.insert("efg");
	s.insert("abc");
	auto it = s.find("abc"); //O(1)

	if(it!=s.end()){
		// s.erase(it);
		s.erase("abcd");
	}

	prnt(s);
}