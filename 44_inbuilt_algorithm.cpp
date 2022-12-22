#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>v(n);

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int min = *min_element(v.begin(),v.end());
	cout<<min<<endl;
	int max = *max_element(v.begin(),v.end());
	cout<<max<<endl;
	int sum = accumulate(v.begin(),v.end(),0);
	cout<<sum<<endl;
	int cnt = count(v.begin(),v.end(),6);
	cout<<cnt<<endl;
	int element = *find(v.begin(),v.end(),3);
	cout<<element<<endl;
	reverse(v.begin(),v.end());

	for(int val: v){
		cout<<val<<" ";
	}
	cout<<endl;
	string s = "abcd";
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}