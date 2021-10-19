#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "TreeNode.h"
#include "Heap.h"

using namespace std;
class Myarr
{
	unsigned int  n;
	long  * arr;
	int k;
	int curr = 0;

	void isNumeric(string line);

public:
	Myarr(unsigned int _size, unsigned int _k);
	Myarr() {};
	Myarr(string fname, unsigned int n, int k);
	void quickSort(int left, int right);
	int Partition(int left, int right);
	void swap(long& a, long& b);
	void print();
	void K_WayMerge();
	void init(long* _arr, int from, int to,int k);
	void printToFile(string fname);
	

};
