#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	char data;
	struct Node* next;
};

/*获取结点*/
Node* GetNode(char data);

/*从字符串中创建单链表*/
Node* CreateList(string S);

/*打印单链表*/
void PrintList(Node* head);

/*头插法逆置链表，复杂度O(1)*/
void Reverse(Node* &head);

void SortList(Node*& head);

/*判断单链表回文*/
bool JudgeHuiWen(Node* head);