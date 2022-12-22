/*
https://codeforces.com/problemset/problem/476/B
*/
#include <bits/stdc++.h>
using namespace std;

string snd,rec;
vector<int>possible;
void generate(int idx,int cnt){
	if(idx==rec.size()) {
		possible.push_back(cnt);
		return ;
	}
	if(rec[idx]=='+')  generate(idx+1,cnt+1);
	else if(rec[idx]=='-') generate(idx+1,cnt-1);
	else {
		generate(idx+1,cnt+1);
		generate(idx+1,cnt-1);
	}
}

int main(){
	cin>>snd;
	cin>>rec;

	int res_snd=0;
	for(int i=0;i<snd.size();++i){
		if(snd[i]=='+') res_snd++;
		else res_snd--;
	}

	generate(0,0);

	int res_rec=0;
	for(int x: possible){
		if(x==res_snd) res_rec++;	
	}

	double ans= (double)res_rec/(double)possible.size();
	cout<<fixed<<setprecision(10)<<ans<<endl;	
}