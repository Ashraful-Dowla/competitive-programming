/*
https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/mojtaba-prepares-contest-29b2a044/
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int green_cost, purple_cost;
		cin>>green_cost>>purple_cost;
		int n;
		cin>>n;
		int arr[n][2], p1=0,p2=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				cin>>arr[i][j];
				if(j==0 && arr[i][j]==1) p1++;
				else if(j==1 && arr[i][j]==1) p2++;
			}
		}
		int cost_1 = p1*green_cost + p2*purple_cost;
		int cost_2 = p2*green_cost + p1*purple_cost;
		cout<<min(cost_1,cost_2)<<endl;
	}
}