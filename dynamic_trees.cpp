#include <bits/stdc++.h>
using namespace std;

struct node {
	int value;
	int x, y;
	node *left, *right;

	node(int v, int x, int y) : value(v), x(x), y(y), left(nullptr), right(nullptr) {}
};

int main() {

	node *x = new node(2, 0, 7);

	cout << x->value << " " << x->x << " " << x->y << endl;
}