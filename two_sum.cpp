#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
vector<int> vec;
vector<pr> p_vec;

bool cmp(pr a,pr b){
	return a.first<b.first;
}

// two pointer technique
// time complexity -> O(NlogN)
pr two_sum(int target){
	sort(p_vec.begin(),p_vec.end(),cmp);

	int l=0,r=p_vec.size()-1;
	while(l<r) {
		int sum = p_vec[l].first+p_vec[r].first;
	    if(sum==target) return {p_vec[l].second,p_vec[r].second};
	    else if(sum<target) l++;
	    else r--;
	}

	return {-1,-1};
}

int main(){
	vec = {9,8,3,7};

	for(int i=0;i<vec.size();++i){
		p_vec.push_back({vec[i],i});
	}

	int target=19;
	pr ans = two_sum(target);

	cout<<ans.first<<" "<<ans.second<<endl;
}	