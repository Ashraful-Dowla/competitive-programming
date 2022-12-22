#include <bits/stdc++.h>
using namespace std;

void prnt(set<string> &s){
	for(string val:s){
		cout<<val<<endl;
	}
}

int main(){
	set<string>s;
	s.insert("abc"); //log(n)
	s.insert("zfsg");
	s.insert("efg");
	s.insert("abc");
	auto it = s.find("abc");

	if(it!=s.end()){
		// s.erase(it);
		s.erase("abcd");
	}

	prnt(s);
}