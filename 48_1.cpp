/*
https://codeforces.com/gym/102892/problem/3
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;

	int l_cnt=0,r_cnt=0,total;
	int a_cnt = count(s.begin(),s.end(),'a');
	total=a_cnt;
	for(int i=0;i<n;i++){
		if(s[i]!='b' && s[i]!= 'a') l_cnt++;
		else if(s[i]=='b') l_cnt=0;
		else {
			i++;
			while(i<n&&s[i]!='a'&&s[i]!='b'){
				r_cnt++;
				i++;
			}
			total+=(l_cnt+r_cnt); 
			l_cnt=r_cnt=0;
			i--;
		}
	}
	cout<<total<<endl;
}