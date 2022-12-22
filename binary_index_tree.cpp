#include <bits/stdc++.h>
using namespace std;

int tree[1000],arr[1000],n;

void add(int k,int x){
	while(k<=n) {
	    tree[k]+=x;
	    k+=(k&-k);
	}
}

int sum(int k){
	int sum=0;
	while(k>=1){
		sum+=tree[k];
		k-=(k&-k);
	}
	return sum;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		add(i,arr[i]);
	}

	cout<<sum(7)<<endl;
	add(7,3);
	cout<<sum(7)-sum(6-1)<<endl;
}