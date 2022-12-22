#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

// two pointer technique
// time complexity -> O(N^2)
bool three_sum(int target){
	sort(vec.begin(),vec.end());

	int n=vec.size();

	for(int i=0;i<n;++i){
		int lo=i+1,hi=n-1;

		while(lo<hi) {
		    int sum = vec[i]+vec[lo]+vec[hi];
		    if(sum==target) {
		    	cout<<vec[i]<<" "<<vec[lo]<<" "<<vec[hi]<<endl;
		    	return true;
		    }
		    else if(sum<target) lo++;
		    else hi--;
		}
	}

	return false;
}

int main(){
	vec = {12,3,6,9,34,25};
	int target = 55;
	cout<<three_sum(target)<<endl;
}