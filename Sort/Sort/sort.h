#pragma once
#include<iostream>
#include<vector>
using namespace  std;

void print(vector<int>A, int len);
/*对于1-n排序*/

/*插入排序*/
void InsertSort(vector<int>& A, int len);

/*希尔排序*/
void ShellSort(vector<int>& A, int len);

/*冒泡排序*/
void BubbleSort(vector<int>& A, int len);

/*快速排序*/
void QuickSort(vector<int>& A, int left, int right);

/*选择排序*/
void SelectSort(vector<int>& A, int len);

/*建立大根堆*/
void MaxHeap(vector<int>& A, int len);
/*大根堆插入元素*/
void Insert(vector<int>& heap, int& len, int data);

/*堆排序*/
void HeapSort(vector<int>& A, int len);

/*归并排序*/
void MergeSort(vector<int>& A, int left, int right);

/*基数排序*/
struct Node {
	int data;
	struct Node* next;
};

Node* CreateList(vector<int> A);
void ShowList(Node* head);
void LSDSort(Node*& head,int radix);