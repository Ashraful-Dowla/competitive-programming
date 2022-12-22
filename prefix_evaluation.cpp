#include <bits/stdc++.h>
using namespace std;

int prefixEvaluation(string s){
	stack<int> stk;

	for(int i=s.size()-1;i>=0;--i){
		if(s[i]>='0' && s[i]<='9'){
			stk.push(s[i]-'0');
		}
		else {
			int op1 = stk.top();
			stk.pop();
			int op2 = stk.top();
			stk.pop();

			switch(s[i]){
			case '+':
				stk.push(op1+op2);
				break;
			case '-':
				stk.push(op1-op2);
				break;
			case '*':
				stk.push(op1*op2);
				break;
			case '/':
				stk.push(op1/op2);
				break;
			case '^':
				stk.push(pow(op1,op2));
				break;
			}
		}
	}

	return stk.top();
}

int main(){
	string s;
	cin>>s;

	cout<<prefixEvaluation("-+7*45+20")<<endl;
}