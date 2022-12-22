#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v = {1,2,3,4,5};
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	vector<int>::iterator it = v.begin();

	cout<<*(it+1)<<endl;

	for(it=v.begin();it!=v.end();it++){
		cout<<*(it)<<" ";
	}
	cout<<endl;

	vector<pair<int,int>>v_p = {{1,2},{2,3},{3,4}};

	vector<pair<int,int>>::iterator it_v_p;

	for(it_v_p = v_p.begin(); it_v_p!=v_p.end();it_v_p++){
		cout<<(*it_v_p).first<<" "<<(*it_v_p).second<<endl; 
	}

	for(it_v_p = v_p.begin(); it_v_p!=v_p.end();it_v_p++){
		cout<<it_v_p->first<<" "<<it_v_p->second<<endl; 
	}
}