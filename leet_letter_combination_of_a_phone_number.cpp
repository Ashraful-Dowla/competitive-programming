/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<char, string> mp = {
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"},
};

vector<string> letterCombinations(string digits) {
    int n=1;

    if(digits=="") return vector<string>();
 	 
    for(int i=0;i<digits.size();++i){
     	if(digits[i]=='9' || digits[i]=='7') n*=4;
     	else n*=3; 
    }
	
	vector<string> vec(n);
	
	int nn=n;
	for(int i=0;i<digits.size();++i){

		int sz = n/nn;
		nn/=mp[digits[i]].size();

		int k=0;
		for(int cy=0; cy<sz; ++cy){

			for(int t=0; t<mp[digits[i]].size(); ++t){

				char ch = mp[digits[i]][t];
				for(int j=0; j<nn; ++j){
					vec[k++].push_back(ch);
				}
			}
		}
	}    

    return vec;
}

int main(){

	string digits = "7";
	vector<string> ans = letterCombinations(digits);

	 for(auto x: ans){
     	cout<<x<<endl;
     }
}