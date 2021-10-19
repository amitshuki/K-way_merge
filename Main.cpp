#include "Myarr.h"
using namespace std;
int main() {
	string fileInput;
	string fileOutput;
	int k;
	int n;


	cin >> n;
	cin >> k;
	cin >> fileInput;
	cin >> fileOutput;


	Myarr arr(fileInput, n, k);


	arr.K_WayMerge();
	arr.printToFile(fileOutput);
}