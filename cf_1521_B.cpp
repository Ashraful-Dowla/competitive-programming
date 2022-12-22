/*
https://codeforces.com/contest/1521/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int i,j,x,y;
};

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int n;
	    cin>>n;

	    vector<int> vec(n);
	    for(int i=0;i<n;++i){
	    	 cin>>vec[i];
	    }

	    auto it = min_element(vec.begin(),vec.end());
	    int idx=it-vec.begin();

	    vector<node> res;
	    for(int i=0;i<n;++i){
	    	if(idx==i) continue;
	    	int val = *it;
	    	res.push_back({idx+1,i+1,val,val+abs(i-idx)});
	    }

	    cout<<res.size()<<endl;
	    for(auto val: res){
	    	cout<<val.i<<" "<<val.j<<" "<<val.x<<" "<<val.y<<endl;
	    }
	}
}