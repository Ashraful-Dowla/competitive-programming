#include <bits/stdc++.h>
using namespace std;

//Smallest/Largest number
int main(){
	int n=3;
	int arr[n];

	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	sort(arr,arr+n);

	int small_num = arr[0],large_num = arr[n-1];

	cout<<"Smallest num is "<<(small_num%2==0 ? "even": "odd")<<endl;
	cout<<"Largest num is "<<(large_num%2==0 ? "even": "odd")<<endl;

}