#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {

	ordered_set s;

	s.insert(2);
	s.insert(3);
	s.insert(5);
	s.insert(7);

	auto x = s.find_by_order(0); // index access in set

	cout << *x << endl;

	cout << s.order_of_key(3) << endl; // return the count of value less than 3
	cout << s.order_of_key(6) << endl;
}