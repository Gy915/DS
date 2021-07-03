#include "Node.h"

Node* GetNode(char data){
	Node* p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}

Node* CreateList(string S){
	Node* head = GetNode('#');//头节点
	Node* rear = head;
	for (int i = 0; i < S.size(); i++) {
		Node* temp = GetNode(S[i]);
		rear->next = temp;
		rear = temp;
	}
	return head;
}

void PrintList(Node* head){
	Node* p = head;
	while (p) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << endl;
}

void Reverse(Node* &head){
	Node* p = head->next;//指向首结点
	head->next = NULL;
	/*头插法逆置链表*/
	Node* r = NULL;
	while (p) {
		r = p->next;
		p->next = head->next;
		head->next = p;
		p = r;
	}
}

void SortList(Node*& head){
	Node* first_node = head->next;//第一个节点
	Node* pre = head;//循环变量前一个位置
	Node* p = first_node;//循环变量
	Node* temp_node = first_node->next;//寻找位置插入该结点
	Node* next_node = temp_node;
	first_node->next = NULL;//L->data1->NULL
	while (next_node) {
		temp_node = next_node;//获取当前待插入结点
		next_node = next_node->next;//指向下一个结点
		
		pre = head;
		p = pre->next;//初始化循环变量

		char v = temp_node->data;
		while (p != NULL) {
			if (p->data < v) {
				pre = p;
				p = p->next;
			}//当前结点p小于搜索值v时
			else
				break;//在当前结点pre前面插入
		}
		temp_node->next = pre->next;
		pre->next = temp_node;
	}

}