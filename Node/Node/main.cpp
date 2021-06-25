#include"Node.h"



int main(){
	int a[5] = { 5,4,3,2,1 };
	QuickSort(a, 0, 4);
	for (int i = 0; i <= 4; i++) {
		cout << a[i];
	}
}