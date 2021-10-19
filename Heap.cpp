#include "Heap.h"
#include "TreeNode.h"

using namespace std;



Heap::Heap(int max) {
	data = new TreeNode[max];
	maxSize = max;
	heapSize = 0;
}
Heap::~Heap() {

	delete[] data;
}
int Heap::leftChild(int node) {
	return ((2 * node) + 1);
}
int Heap::rightChild(int node) {
	return ((2 * node) + 2);
}
int Heap::parent(int node) {
	return ((node - 1) / 2);
}

void Heap::insert(TreeNode* item)
{
	if (heapSize == maxSize)
	{
		cout << "Heap full";
		exit(1);
	}
	else
	{

		int i = heapSize;
		heapSize++;
		while ((i > 0) && (data[parent(i)].getdata()) > item->getdata())
		{
			data[i] = data[parent(i)];
			i = parent(i);
		}

		data[i] = *item;

	};
}
TreeNode* Heap::min() {
	return &data[0];
}
void Heap::fixHeap(int node) {
	int min, left, right;
	bool end = false;
	while (end == false) {
		left = leftChild(node);
		right = rightChild(node);
		// Find min among node, left and right.
		if ((left <= heapSize) && (data[left].data < data[node].data))
			min = left;
		else
			min = node;
		if ((right <= heapSize) && (data[right].data < data[min].data))
			min = right;
		if (min == node)
			end = true;
		else
			swap(data[node], data[min]);
		node = min;
	}
}
TreeNode* Heap::deletemin() {
	if (heapSize == 0) { return nullptr; }
	TreeNode* min = new TreeNode(data[0]);
	data[0] = data[heapSize - 1];
	heapSize--;
	if (heapSize >= 1)
		fixHeap(0);
	return min;
}
void Heap::buildHeap(TreeNode A[], int n) {

	heapSize = maxSize;
	data = A;
	for (int i = (heapSize / 2) - 1; i >= 0; i--)
		fixHeap(i);
}

void Heap::swap(TreeNode& t, TreeNode& y) {
	TreeNode temp = t;
	t = y;
	y = temp;
}





void Heap::makeEmpty() {
	heapSize = 0;

}
