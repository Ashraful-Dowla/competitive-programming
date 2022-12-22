#include <bits/stdc++.h>
using namespace std;

void printBinary(int num){
	for(int i=10;i>=0;i--){
		cout<<((num>>i)&1);
	}
	cout<<endl;
}

int main(){
	for(int i=0;i<8;++i){
		//printBinary(i);
		if(i&1) cout<<"odd"<<endl;
		else cout<<"even"<<endl;
	}

	int n=5;

	cout<<(n>>1)<<endl;
	cout<<(n<<1)<<endl;


	for(char c='A';c<='E';++c){
		cout<<c<<endl;
		printBinary((int)c);
	}
	for(char c='a';c<='e';++c){
		cout<<c<<endl;
		printBinary((int)c);
	}

	char A = 'A';
	char a = A | (1<<5); //lowercase
	cout<<a<<endl;
	A = a ^ (1<<5); // uppercase
	cout<<A<<endl;
	cout<<char(a&(~(1<<5)))<<endl; //uppercase

	cout<<char(1<<5)<<endl;

	cout<<char('C'| ' ')<<endl;
	cout<<char('c'^' ')<<endl;
	cout<<char('c'&'_')<<endl;


	printBinary(59);

	int i = 3;
	int n1=59;
	int n2 = (n1 & (~((1<<(i+1))-1))); //clear lsb 
	printBinary(n2);
	int c = n1 &((1<<(i+1))-1); //clear msb
	printBinary(c);

	int x = 10;
	if(x&(x-1)) cout<<"not power of 2"<<endl;
	else cout<<"power of 2"<<endl;
}