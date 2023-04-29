//Author: Ashraful Dowla

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N=1e5+10;
const int MOD=1e9+7;

ll n;
vi ans, temp;

void calc(ll i, int cnt){

	if(i==1 && cnt<=40){
		ans=temp;
		return ;
	}

	if((i+1)%2==0){
		temp.push_back(1);
		calc((i+1)/2, cnt+1);
		temp.pop_back();
	}

	if((i-1)%2==0){
		temp.push_back(2);
		calc((i-1)/2, cnt+1);
		temp.pop_back();
	}
	
}

void solve(){
	cin>>n;

	calc(n,0);

	if(ans.size()){
		prnt1(ans.size());
		reverse(ans.begin(), ans.end());
		vec_prnt(ans);
	}
	else {
		prnt1(-1);
	}

	ans.clear();
	temp.clear();
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}