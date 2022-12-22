#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

struct node {
	bool endmark;
	node* next[26];
	node(){
		for(int i=0;i<26;++i){
			next[i]=NULL;
		}
		endmark=false;
	}

}* root;


void insert(string str,int k){
	node* curr = root;

	for(int i=0;i<str.size();++i){
		int idx=str[i]-'a';
		if(curr->next[idx]==NULL){
			curr->next[idx]= new node();
		}
		curr=curr->next[idx];
	}
	curr->endmark=true;
}

bool search(string str,int l,int r){
	node* curr = root;

	for(int i=0;i<str.size();++i){
		int idx=str[i]-'a';
		if(curr->next[idx]==NULL) return false;
		curr=curr->next[idx];
	}
	return curr->endmark;
}

void del(node *curr){
	for(int i=0;i<26;++i){
		if(curr->next[i]){
			del(curr);
		}
	}
	delete(curr);
}	

int main(){
	int n;
	cin>>n;
	vector<string>vec(n);
	
	root = new node();

	for(int i=0;i<n;++i){
		cin>>vec[i];
		insert(vec[i],i);
	}

	int q;
	cin>>q;
	while(q--) {
	   	int type,l,r,idx;
	   	cin>>type;
	   	if(type==1){
	   		cin>>idx;
	   	}
	   	else if(type==2){
	   		cin>>l>>r;
	   	}
	   	else {
	   		cin>>l>>r;
	   	}
	}

	del(root);
}	