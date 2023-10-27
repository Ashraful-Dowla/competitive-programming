#include <bits/stdc++.h>
using namespace std;

void prnt(multiset<string> &s){
	for(string val:s){
		cout<<val<<endl;
	}
}

int main(){
	multiset<string>s;
	s.insert("abc"); //O(log(n))
	s.insert("zfsg");
	s.insert("efg");
	s.insert("abc");
	auto it = s.find("abc"); //O(log(n))

	if(it!=s.end()){
		s.erase(it);
		// s.erase("abc");
	}

	prnt(s);
}