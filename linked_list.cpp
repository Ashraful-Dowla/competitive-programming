#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;

	node(int val) {
		data = val;
		next = NULL;
	}
};

void insert_at_head(node* &head, int val) {
	node* n = new node(val);
	n->next = head;
	head = n;
}

void insert_at_tail(node* &head, int val) {
	node* n = new node(val);

	if (head == NULL) {
		head = n;
		return ;
	}

	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = n;
}

bool search(node* head, int key) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void delete_head(node* &head) {
	node* temp = head;
	head = head->next;
	delete temp;
}

void deletion(node* head, int val) {

	if (head == NULL) return;
	if (head->next == NULL) {
		delete_head(head);
		return ;
	}

	node* temp = head;

	while (temp->next->data != val) {
		temp = temp->next;
	}

	node* del = temp->next;
	temp->next = temp->next->next;

	delete del;
}

node* reverse(node* &head) {
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;

	while (currptr != NULL) {
		nextptr = currptr->next;
		currptr->next = prevptr;

		prevptr = currptr;
		currptr = nextptr;
	}

	return prevptr;
}

void prnt(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int main() {
	node* head = NULL;
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 3);
	// prnt(head);
	insert_at_tail(head, 4);
	prnt(head);
	// cout<<search(head,6)<<endl;
	// deletion(head,3);
	// delete_head(head);
	node* new_head = reverse(head);
	prnt(new_head);
}