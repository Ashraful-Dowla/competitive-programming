#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<[](int x){ return x+2;}(2)<<endl;
	cout<<[](int x,int y){ return x+y;}(2,4)<<endl;
	auto sum = [](int x,int y){ return x+y;};
	cout<<sum(2,3)<<endl;

	vector<int>v = {1,-2,3};
	cout<<all_of(v.begin(), v.end(),[](int x){ return x>0;})<<endl;
	cout<<any_of(v.begin(), v.end(),[](int x){ return x>0;})<<endl;
	cout<<none_of(v.begin(), v.end(),[](int x){ return x>0;})<<endl;
}