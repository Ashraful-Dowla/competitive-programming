/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/?fbclid=IwAR2XcdRMJnGwG3ojY4diVU80L41VtxP85xk2VWMZ_lUYz58kKYk2TtZN3rc
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
const int M=1e7+10;
int arr[N];
int hsh[M];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		hsh[arr[i]]++;
	}

	bool check = false;
	for(int i=0;i<n;i++){
		if(k-arr[i]==arr[i] && hsh[arr[i]]==1) continue;
		else if(k>arr[i] && hsh[k-arr[i]]>0) {
			check = true;
			break;
		} 
	}
	check ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}