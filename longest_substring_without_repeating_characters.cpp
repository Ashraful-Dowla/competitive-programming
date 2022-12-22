#include <bits/stdc++.h>
using namespace std;


//pwwkew
//ans:3 

//bbbbb
// ans:1

//abcabcbb
//ans:3

//time complexity -> O(N)
int main(){
	string s;
	cin>>s;

	int dic[30];
	memset(dic,-1,sizeof(dic));
	int max_len=0,start=-1;
	for(int i=0;i<s.size();++i){
		if(dic[s[i]-'a']>start){
			start=dic[s[i]-'a'];
		}
		dic[s[i]-'a']=i;
		max_len = max(max_len, i-start);
	}
	cout<<max_len<<endl;
}