#include <iostream>
using namespace std;
int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int p = low;
	while(low <= high){
		while (low <= high && arr[low] <= pivot){
			low ++;
		}
		while (low <= high && arr[high] > pivot){
			high --;
		}
		if(low < high){
			swap( arr[low], arr[high]);
		}
	}
	swap(arr[p], arr[high]);
	return high;	
}
void quicksort(int arr[], int first, int last){
	if (first >= last) {
		return;
	}
	int pivotindex = partition(arr, first, last);
	quicksort(arr, first, pivotindex -1);
	quicksort(arr, pivotindex+1, last);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	int* arr = new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	quicksort(arr,0, n-1);
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << arr[i];
	}
	cout << '\n';
	delete[] arr;
	return 0;
}
