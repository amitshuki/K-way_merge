#include "Myarr.h"
using namespace std;

Myarr::Myarr(string fname, unsigned int _n, int _k) {
	n = _n;
	arr = new long[n];
	k = _k;
	ifstream infile;
	infile.open(fname);

	if (!infile) {
		cout << "Error with infile" << endl;
		exit(-1);
	}
	

	if (n < k||n<1||k<1) {
		cout << "wrong input";
		exit(-1);
	}
	string inputLine;
	unsigned int i = 0;
	while (!infile.eof() && i < n) {

		getline(infile,inputLine);
		isNumeric(inputLine);
		arr[i] = stol(inputLine);
		i++;
		if (infile.eof() && i < n) {
			cout << "wrong input";
			exit(-1);
		}
	}
	infile.close();


}
void Myarr::quickSort(int left, int right) {
	int pivot;
	if (left < right) {
		pivot = Partition(left, right);
		quickSort(left, pivot - 1);
		quickSort(pivot + 1, right);
	}
}

int Myarr::Partition(int left, int right) {
	long pivot = arr[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (arr[j] <= pivot) {
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return i + 1;
}

void Myarr::swap(long& a, long& b) {
	long  temp;

	temp = a;
	a = b;
	b = temp;

}

void Myarr::print() {
	for (size_t i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Myarr::K_WayMerge() {
	if (n < k||k==1) {
		this->quickSort(0, n - 1);

	}
	else
	{
		Myarr* subarr =  new Myarr[k];

		int from = 0;
		int to = n/k;
		for (int i = 0; i < k; i++) {

			if (i == k-1) {
				subarr[i].init(this->arr, from, n,k);

			}
			else {
				subarr[i].init(this->arr, from, to,k);
				from += n/k;
				to += n/k;
			}
			subarr[i].K_WayMerge();

		}
		Heap h(n);
		for (int i = 0; i < k; i++) {
			h.insert(new TreeNode(subarr[i].arr[(subarr[i].curr)++], i));
			
		}
		int t = 0;
		while ((h.size()!=0)) {

			int temp = h.min()->getIndex();
			this->arr[t] = h.deletemin()->getdata();
			
			t++;
			if (subarr[temp].curr != subarr[temp].n)
				h.insert(new TreeNode(subarr[temp].arr[(subarr[temp].curr)++], temp));
		}
		for (int i = 0; i < k; i++) {
			delete subarr[i].arr;
			}
	}
}
Myarr::Myarr(unsigned int _size, unsigned int _k)
{
	n = _size;
	arr = new long[n];
	k = _k;
}
void Myarr::init(long* _arr, int from, int to,int _k)
{
	k = _k;
	int j = 0;
	n = to - from;
	curr = 0;
	if (n != 0) {
		arr = new long[n];
		for (unsigned int i = from; i < to; i++) {
			this->arr[j] = _arr[i];
			j++;
		}
	}
}
void Myarr::printToFile(string fname) {
	ofstream myFile(fname);
	for (size_t i = 0; i < n; i++) {
		if(i<n-1)
		myFile << arr[i]<<endl;//without the final space
		else
		myFile << arr[i];
	}
	
	myFile.close();

}
 void Myarr::isNumeric(string line) {
	if (line[0] != '-' && (line[0] < '0' || line[0]>'9')) {
		cout << "wrong input";
		exit(-1);
	}
	else
	for (int i = 1; i < line.size(); i++) {
		if ((line[i] < '0' || line[i]>'9')) {
			cout << "wrong input";
			exit(-1);
		}
	}
}


