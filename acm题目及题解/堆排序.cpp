// 堆排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class HEAP{
public:
	HEAP();
	void MAX_HEAPIFY(int i);
	void BUILD_HEAP();
	void HEAPSORT();
	int LEFT(int i);
	int RIGHT(int i);
	void exchange(int i, int largest);
	void display();
private:
	int *A;
	int heap_size;
	int heap_length;
};
HEAP::HEAP() {
	int length;
	std::cout << "please input the length of the array:";
	std::cin >> length;
	this->heap_length = length-1;
	this->heap_size = length-1;
	A = new int[length];
	std::cout << "please intput the array:";
	for (int i = 0; i < length; i++)
		std::cin >> A[i];
	HEAPSORT();
}

int HEAP::LEFT(int i) {
	return i * 2 + 1;
}
int HEAP::RIGHT(int i) {
	return i * 2 + 2;
}
void HEAP::exchange(int i, int largest) {
	int temp;
	temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
}

void HEAP::MAX_HEAPIFY(int i){
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;
	if (l <= heap_size&&A[l] > A[i]) {
		largest = l;
	}
	else largest = i;
	if (r <= heap_size&&A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i){
		exchange(i, largest);
		MAX_HEAPIFY(largest);
	}
}

void HEAP::BUILD_HEAP() {
	heap_size = heap_length;
	for (int i = heap_length/2; i >= 0; i--) {
		MAX_HEAPIFY(i);
	}
}

void HEAP::HEAPSORT() {
	BUILD_HEAP();
	for (int i =heap_length; i >0; i--)
	{
		exchange(0, i);
		heap_size = heap_size - 1;
		MAX_HEAPIFY(0);
	
	}
}
void HEAP::display() {
	std::cout << "sorted::";
	for (int i = 0; i <= heap_length; i++)
		std::cout << A[i] << ' ';
	std::cout << std::endl;
}


int main()
{
	HEAP H;
	H.display();
	system("pause");
    return 0;
} 

