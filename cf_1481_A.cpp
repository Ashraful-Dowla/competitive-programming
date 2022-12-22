/*
https://codeforces.com/problemset/problem/1481/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
map<char,bool>mp;
map<char,pr> directions = {
	{'L',{-1,0}},
	{'R',{1,0}},
	{'U',{0,1}},
	{'D',{0,-1}},
};

void validDirections(int x,int y){
	mp['R']=(x>0);
	mp['L']=(x<0);

	mp['U']=(y>0);
	mp['D']=(y<0);
}

bool checkDirection(int p,int val,int point){
	if(point>0) return p+val>point;
	else return p+val<point;
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    int x,y;
		cin>>x>>y;
		string d;
		cin>>d;

		validDirections(x,y);

		int p_x=0,p_y=0;
		bool reach=false;
		for(char ch:d){
			if(mp[ch]){
				int x_val=directions[ch].first; 
				int y_val=directions[ch].second;

				if(checkDirection(p_x,x_val,x) || 
					checkDirection(p_y,y_val,y)) continue;

				p_x+=x_val;
				p_y+=y_val;

				if(p_x==x && p_y==y){
					reach=true;
					break;
				}
			}
		}

		cout<<(reach ? "YES": "NO")<<endl;
		mp.clear();
	}
	
}