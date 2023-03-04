#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s){

	int r=0;
	bool neg=false,pos=false;

	int temp=0,n=-1,p=-1,cnt_n=0,cnt_p=0;
	for(int i=0;i<s.size();++i){
		if(s[i]==' ') continue;
		if(s[i]=='-'){
			neg=true;
			n=i;
			cnt_n++;
			continue;
		}
		if(s[i]=='+'){
			pos=true;
			p=i;
			cnt_p++;
			continue;
		}

		while(i<s.size() && s[i]>='0' && s[i]<='9') {
			int rem = s[i]-'0';
			if(r>INT_MAX/10 ||(r==INT_MAX/10 && rem>7)){
				if(temp> INT_MAX/10 ||(temp==INT_MAX/10 && rem>7)){
					temp=INT_MAX;
					break;
				}
				temp= temp*10 + rem;
				r = INT_MAX;
				++i;
				continue;
			}
			r = r*10 + rem;
			++i;
		}
		break;
	}

	if(!neg && !pos) pos=true;
	
	if(neg && pos) return 0;
	if(cnt_p>1 || cnt_n>1) return 0;
	else if(neg && n!=-1 && n+1<s.size() && !isdigit(s[n+1])) return 0;
    else if(pos && p!=-1 && p+1<s.size() && !isdigit(s[p+1])) return 0;
	else if(r==INT_MAX){
		if(pos && temp>=7) return INT_MAX;
		else if(neg && temp>=8) return INT_MIN;
		else return pos ? r: -r;
	}
	else return pos ? r: -r;
}

int main(){
	string s;
	s=" ++1";
	cout<<myAtoi(s)<<endl;
}