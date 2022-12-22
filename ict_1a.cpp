#include <bits/stdc++.h>
using namespace std;

int main(){
	int num=0;
	for(int i=0;i<6;++i){
		char ch;
		cin>>ch;
		if(ch>='0'&&ch<='9') num++;
	}
	cout<<"Numeric: "<<num<<endl;
	cout<<"Non numeric: "<<6-num<<endl;
}