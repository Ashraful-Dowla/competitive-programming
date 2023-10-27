#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int>vec;
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		vec.push_back(x);
	}

	printVector(vec);

	vector<int>vec2(5,3);
	vec2.push_back(7); //O(1)
	printVector(vec2);
	vec2.pop_back(); //O(1)
	printVector(vec2);
	vector<int> &vec3 = vec2;
	vec2.push_back(2);
	printVector(vec3);
	printVector(vec2);
}