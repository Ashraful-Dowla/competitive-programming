#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

//time complexity -> O(N)
int trapping_water(){
	int n= vec.size();
	int left[n],right[n];

	left[0]=vec[0];
	for(int i=1;i<n;++i){
		left[i] = max(left[i-1], vec[i]);
	}

	right[n-1]=vec[n-1];
	for(int i=n-2;i>=0;--i){
		right[i] = max(right[i+1],vec[i]);
	}

	int water=0;
	for(int i=1;i<n-1;++i){
		int val = min(left[i-1],right[i+1]);
		if(val>vec[i]){
			water+=(val-vec[i]);
		}
	}
	return water;
}

int main(){
	 vec= { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	 cout<<trapping_water()<<endl;
}