#include <bits/stdc++.h>
using namespace std;

int main(){
	map<int,string>m;
	m[1] = "abc"; //O(logn)
	m[5] = "cdc";
	m[3] = "acd";
	m[6] = "a";
	m[5] = "cde";
	m.insert({4,"afg"});

	map<int,string>::iterator it;

	for(it = m.begin();it!=m.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}

	//m.erase(5); //O(logn)
	auto itr = m.find(5);
	m.erase(itr);

	for(auto &pr: m){
		cout<<pr.first<<" "<<pr.second<<endl;
	}

	auto itt = m.find(3); //O(logn)

	if(itt==m.end()){
		cout<<"No value"<<endl;
	}else {
		cout<<(*itt).first<<" "<<(*itt).second<<endl;
	}

	m.clear();

	map<string,string>m_s;

	m_s["abcd"] = "abcd"; // s.size()*log(n)

}