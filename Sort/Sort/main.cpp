#include"sort.h"

int main() {
	
	int a[10] = { 149,338,465,397,976,324,137,549,165,874 };
	int n = 10;
	vector<int> A;
	A.push_back(-1);
	for (int i = 0; i < n; i++)
		A.push_back(a[i]);
	Node* head = CreateList(A);
	ShowList(head);
	LSDSort(head, 3);
	ShowList(head);

}