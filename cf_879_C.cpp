#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> pr;

int main(){
	int n;
	cin>>n;

	int ans=1;
	vector<pr>vec;
	for(int i=0;i<n;++i){
		char ch;
		int x;
		cin>>ch>>x;

		int prev=ans;
		if(ch=='|') ans|=x;
		else if(ch=='&') ans&=x;
		else ans^=x;

		if(prev!=ans) vec.push_back({ch,x});
	}

	cout<<vec.size()<<endl;
	for(int i=0;i<vec.size();++i) 
		cout<<vec[i].first<<" "<<vec[i].second<<endl;


}