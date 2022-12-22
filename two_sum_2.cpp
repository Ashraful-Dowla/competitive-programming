#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
vector<int> vec;
unordered_map<int,int> mp;

//hash technique
//time complexity->O(N)
pr two_sum(int target){
	for(int i=0;i<vec.size();++i){
		auto it = mp.find(target-vec[i]);
		if(it==mp.end()) mp[vec[i]]=i;
		else return {i,it->second};
	}
	return {-1,-1};
}

int main(){
	vec = {9,8,3,7};	
	int target = 14;
	pr ans = two_sum(target);


	cout<<ans.first<<" "<<ans.second<<endl;
}