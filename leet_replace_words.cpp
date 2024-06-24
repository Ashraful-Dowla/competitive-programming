/*
https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	node* next[26];
	bool endmark;
	node() {
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
			endmark = false;
		}
	}
}* root;

void insert(string s) {

	node* curr = root;
	for (char ch : s) {
		int idx = ch - 'a';
		if (curr->next[idx] == NULL) {
			curr->next[idx] = new node();
		}
		curr = curr->next[idx];
	}

	curr->endmark = true;
}

string search(string s) {

	node* curr = root;

	string word;
	for (char ch : s) {
		int idx = ch - 'a';

		if (curr->next[idx] == NULL) {
			return s;
		}

		word.push_back(ch);
		curr = curr->next[idx];

		if (curr->endmark) {
			return word;
		}
	}

	return s;
}

string replaceWords(vector<string>& dictionary, string sentence) {

	root = new node();
	for (string s : dictionary) {
		insert(s);
	}

	string word, ans;
	for (char ch : sentence) {
		if (ch == ' ') {
			ans += search(word) + " ";
			word.clear();
		}
		else {
			word.push_back(ch);
		}
	}

	ans += search(word);
	return ans;
}

int main() {

	// vector<string> dictionary = {"cat", "bat", "rat"};
	// string sentence = "the cattle was rattled by the battery";

	vector<string> dictionary = {"a", "b", "c"};
	string sentence = "aadsfasf absbs bbab cadsfafs";


	cout << replaceWords(dictionary, sentence);
}