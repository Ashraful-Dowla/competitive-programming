#include <bits/stdc++.h>
using namespace std;

void increment(int *x){
	(*x)++;
}

int main(){
	int x=4;
	int * p_x=&x;
	cout<<"Address x: "<<&x<<endl;
	cout<<"Val p_x: "<<p_x<<endl;
	cout<<"Val *p_x: "<<*p_x<<endl;
	*p_x=5;
	cout<<"X: "<<x<<endl;
	cout<<"p_x+1: "<<p_x+1<<endl;

	//double pointers
	int **p_p_x = &p_x;
	cout<<"Address p_x: "<<&p_x<<endl;
	cout<<"Val p_p_x: "<<p_p_x<<endl;
	cout<<"Val *p_p_x: "<<*p_p_x<<endl;
	cout<<"Val **p_p_x: "<<**p_p_x<<endl;
	**p_p_x = 6;
	cout<<"Val x: "<<x<<endl;

	// Array pointers
	int a[10];
	a[0]=1;
	a[1]=2;

	cout<<"a: "<<a<<endl;
	cout<<"&a[0]: "<<&a[0]<<endl;
	cout<<"*a: "<<a<<endl;
	cout<<"a+1: "<<a+1<<endl;
	cout<<"&a[1]: "<<&a[1]<<endl;
	cout<<"*(a+1): "<<*(a+1)<<endl;

	x = 8;
	increment(&x);
	cout<<x<<endl;
}