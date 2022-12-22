#include <bits/stdc++.h>
using namespace std;

bool operatorCheck(char ch){
	return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

//time complexity ->O(N)
int main(){
	string s;
	cin>>s;
	stack<char> stk;	

	bool ans;
	for(int i=0;i<s.size();++i){
		if(s[i]==')') {
			bool flag=true;

			char top = stk.top();
			stk.pop();
			
			while(!stk.empty() && top!='(') {
				if(operatorCheck(top)) flag=false;
				top = stk.top();
				stk.pop();
			}
			if(flag) ans=true;
		}
		else stk.push(s[i]);
	}
	cout<<ans<<endl;
}