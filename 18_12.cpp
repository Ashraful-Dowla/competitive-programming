/*
https://leetcode.com/problems/rabbits-in-forest/
-incomplete
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>answers = {1,1,2};

	int hsh[2000];
	memset(hsh, 0, sizeof(hsh));

	vector<int>nw;
	for(int i=0;i<answers.size();i++){
		hsh[answers[i]]++;
		if(hsh[answers[i]]==1) nw.push_back(answers[i]);
	}

	int total = 0;
	for(int i=0;i<nw.size();i++){
		total+=hsh[nw[i]];
	}
	cout<<total<<endl;
}