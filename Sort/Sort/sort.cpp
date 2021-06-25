#include "sort.h"

void print(vector<int> A, int len){

	for (int i = 1; i <= len; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void InsertSort(vector<int>& A, int len){
	/*1-n*/
	for (int i = 2; i <= len; i++) {
		/*A0, 2,3,5,1,4,
						  |	
		*/
		if (A[i] < A[i - 1]) {
			A[0] = A[i];
			int j;
			for (j = i - 1; A[0]<A[j]; j--) 
				A[j + 1] = A[j];
			A[j + 1] = A[0];
		}

	}
}

void ShellSort(vector<int>& A, int len){
	int dk = len / 2;
	for (dk; dk >= 1; dk = dk / 2) {
		print(A, len);
		for (int i = dk + 1; i <= len; i++) {
			//需要进行插入排序，步长为dk
			if (A[i] < A[i - dk]) {
				int val = A[i];
				int k = i-dk;
				for (k = i - dk; k >= 1; k-=dk) {
					if (A[k] > val) {
						A[k + dk] = A[k];
					}
					else
						break;
				}
				A[k + dk] = val;
			}
		}
	}
}

void BubbleSort(vector<int>& A, int len){
	for (int i = 1; i <= len; i++) {
		bool flag = false;
		//从后往前
		for (int j = len; j > i; j--) {
			if (A[j] < A[j - 1]) {
				int temp = A[j-1];
				A[j - 1] = A[j];
				A[j] = temp;
				flag = true;
			}
		}
		if (!flag)
			return;
	}
}

int Partition(vector<int>& A, int left, int right) {
	//返回中间位置坐标
	int pivotpos = left;
	int pivot = A[pivotpos];//基准值
	//比pivot小的放到左边
	for (int i = left + 1; i <= right; i++) {
		if (A[i] < pivot) {
			pivotpos++;
			int temp = A[i];
			A[i] = A[pivotpos];
			A[pivotpos] = temp;
		}
	}
	A[left] = A[pivotpos];
	A[pivotpos] = pivot;
	return pivotpos;
}
void QuickSort(vector<int>& A, int left, int right){
	if (left < right) {
		int pivotpos = Partition(A, left, right);
		QuickSort(A, left, pivotpos - 1);
		QuickSort(A, pivotpos + 1, right);

	}
}

void SelectSort(vector<int>& A, int len){
	for (int i = 1; i <= len; i++) {
		int min = A[i];
		int pos = i;
		for (int j = i + 1; j <= len; j++) {
			if (A[j] < min) {
				min = A[j];
				pos = j;
			}
		}
		int temp = A[i];
		A[i] = A[pos];
		A[pos] = temp;

	}

}

/*自上而下调整*/
void SwiftDown(vector<int>& heap, int start, int end) {
	int i = start, j = 2 * i;//j指向左结点
	while (j <= end) {
		int RootValue = heap[i];
		if (j < end && heap[j] < heap[j + 1])
			j++;//指向较大结点
		if (RootValue > heap[j])
			break;//调整结束
		else {
			int temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
			i = j;
			j = 2 * i;
		}
	}





}

/*自下而上调整,自start至1*/
void SwiftUp(vector<int>& heap, int start) {
	int j = start;//子结点
	int i = j / 2;//父结点
	while (j > 1) {
		if (heap[j] < heap[i])
			return;
		else {
			int temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
			j = i;
			i = i / 2;
		}
	}

}

void Insert(vector<int>& heap, int& len, int data) {
	heap.push_back(data);
	len++;
	SwiftUp(heap, len);
	return;

}

void HeapSort(vector<int>& A, int len){
	MaxHeap(A, len);
	for (int i = len; i >= 1; i--) {
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		SwiftDown(A, 1, i - 1);
	}
}
void Merge(vector<int>& A, int left, int mid, int right) {
	//left->mid
	//mid+1->right
	int a[50] = { 0 };
	int b[50] = { 0 };
	for (int i = left; i <= mid; i++) {
		a[i-left + 1]= A[i];
	}
	for (int j = mid + 1; j <= right; j++) {
		b[j-mid]= A[j];
	}
	int i = left, j = 1, k = 1;//j指向a，k指向b
	int aLen = mid - left + 1;
	int bLen = right - mid;
	while (j <= aLen && k <= bLen) {
		if (a[j] < b[k]) {
			A[i++] = a[j++];
		}
		else
			A[i++] = b[k++];
	}
	if (j <= aLen) {
		for (j; j <= aLen; j++) {
			A[i++] = a[j];
		}
	}
	else {
		for (k; k <= bLen; k++) {
			A[i++] = b[k];
		}
	}

}
void MergeSort(vector<int>& A, int left, int right){
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(A, left, mid);
		MergeSort(A, mid + 1, right);
		Merge(A, left, mid, right);
		cout << "left: " <<left << "  right: " <<right<<"  ";
		print(A, 10);
	}
	
}
Node* GetNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

Node* CreateList(vector<int> A) {
	Node* head = GetNode(-1);//头节点
	Node* rear = head;
	for (int i = 1; i < A.size(); i++) {
		Node* temp = GetNode(A[i]);
		rear->next = temp;
		rear = temp;
	}
	return head;
}

void ShowList(Node* head){
	Node* p = head->next;
	while (p) {
		cout << p->data << "-> ";
		p = p->next;
	}
	cout << endl;
}


void LSDSort(Node*& head, int radix){
	Node* rear[10], * front[10];
	for (int i = 0; i < 10; i++) {
		rear[i] = front[i] = NULL;
	}
	
	for (int i = 1; i <= radix; i++) {
		Node* first = head->next;
		Node* p = first;
		while (p != NULL) {
			int v = p->data;
			int temp = pow(10, i - 1);
			int k = (v / temp) % 10;
			Node* q = GetNode(v);
			/*头为空，新建结点*/
			if (front[k] == NULL) {

				front[k] = rear[k] = q;
			}
			/*尾插*/
			else {
				rear[k]->next = q;
				rear[k] = q;
			}
			p = p->next;
		}//while
		/*收集*/
		Node* pos = head;
		for (int i = 0; i < 10; i++) {
			if (front[i] != NULL) {
				pos->next = front[i];
				pos = rear[i];
			}
		}
		for (int i = 0; i < 10; i++) {
			rear[i] = front[i] = NULL;
		}
	}//for







}


void MaxHeap(vector<int>& A, int len){
	int CurrentPos = len / 2;//第一个非叶结点
	while (CurrentPos >= 1) {
		SwiftDown(A, CurrentPos, len);
		CurrentPos--;
	}
}


