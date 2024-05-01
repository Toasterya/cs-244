#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& input, int left, int middle, int right) {
	int leftIndex{ left };
	int rightIndex{ middle };
	int* tmp = new int[right - left];
	for (int i = 0; i < right - left; i++) {
		if (leftIndex >= middle) {
			// take from right only no mroe left
			tmp[i] = input[rightIndex];
			rightIndex++;
		}
		else if (rightIndex >= right) {
			tmp[i] = input[leftIndex];
			leftIndex++;
		}
		else if (input[rightIndex] < input[leftIndex]) {
			tmp[i] = input[rightIndex];
			rightIndex++;
		}
		else {
			tmp[i] = input[leftIndex];
			leftIndex++;
		}
	}
	for (int i = 0; i < right - left; i++) {
		input[left + i] = tmp[i];
	}
	delete[] tmp;
}
// start is default 0
// end is defualt N (1 past last index)
void mergesort(vector<int>& input, int start, int end) {
	cout << start << ":" << end << endl;
	// base case
	if (start + 1 >= end) {
		return;
	}
	// First step divide into two halves & recurse
	mergesort(input, start, (end-start) / 2); // left half
	mergesort(input, (end-start) / 2, end); // right half

	// merge together
	merge(input, start, (end - start) / 2, end);
}


int main() {
	vector<int> v{ 2,7,50,56,427,27,2003,4,63 };
	mergesort(v, 0, v.size());
	for (int x : v) {
		cout << x << " ";

	}
	cout << endl;
}