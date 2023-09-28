#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
vector<int> graph[100];

int diff(string a, string b) {

	int d = 0;
	for (int i = 0; i < 8; ++i) {
		if (a[i] == b[i]) continue;
		d++;
	}

	return d;
}

int minMutation(string startGene, string endGene, vector<string>& bank) {

	mp[startGene] = 1, mp[endGene] = 2;

	int cnt = 3;
	for (string s : bank) {
		if (mp[s] == 0) {
			mp[s] = cnt++;
		}
	}

	for (int i = 0; i < bank.size(); ++i) {
		for (int j = i + 1; j < bank.size(); ++j) {
			if (diff(bank[i], bank[j]) == 1) {
				int u = mp[bank[i]], v = mp[bank[j]];
				graph[u].push_back(v);
				graph[v].push_back(u);
			}
		}
	}

	for (int j = 0; j < bank.size(); ++j) {
		if (diff(startGene, bank[j]) == 1) {
			int u = mp[startGene], v = mp[bank[j]];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}

	for (int j = 0; j < bank.size(); ++j) {
		if (diff(endGene, bank[j]) == 1) {
			int u = mp[startGene], v = mp[bank[j]];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}

}

int main() {

	// string startGene = "AACCGGTT", endGene = "AACCGGTA";
	// vector<string>bank = {"AACCGGTA"};

	string startGene = "AACCGGTT", endGene = "AAACGGTA";
	vector<string>bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
}