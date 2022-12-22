#include <bits/stdc++.h>
using namespace std;

//time complexity -> O(n)
int main(){
	vector<int>v = {-1,2,4,-3,5,2,-5,2};

	int sum=0,best=0;
	for(int i=0;i<v.size();++i){
		sum = max(v[i],sum+v[i]);
		best = max(best,sum);
	}
	cout<<best<<endl;
	return 0;
}