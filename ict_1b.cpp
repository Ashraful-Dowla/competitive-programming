#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[3];
	for(int i=0;i<3;++i) {
		cin>>arr[i];
	}
	sort(arr,arr+3);
	int a_square = arr[0]*arr[0];
	int b_square = arr[1]*arr[1];
	int c_square = arr[2]*arr[2];

	cout<<((a_square+b_square==c_square) ? "Yes": "No")<<endl;
}