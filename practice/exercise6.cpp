#include <iostream>
using namespace std;

void printheap(int arr[], int n){
	for (int i = 0; i < n; i++){
		cout << arr[i];
	}
}

void ins(int arr[], int n, int a){
	arr[n] = a;
	int i = n;
	while( i ){
		int parent = ( i - 1 ) / 2;
		if (arr[i] > arr[parent]){
			swap(arr[i], arr[parent]);
			i = parent;
		}
		else {
			break;
		}
	}
}

void ext(int arr[], int n){
	arr[0] = arr[n-1];
	n--;
	int i = 0;
	while (1){
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left >= n){
			break;
		}
		if (right >= n){
			if (arr[i] < arr[left]){
				swap(arr[i], arr[left]);
				i = left;
			}
			else {
				break;
			}
		}
		else {
			if (arr[i] >= arr[left] && arr[i] >= arr[right]){
				break;
			}
			else if (arr[left] >= arr[right]){
				swap(arr[i], arr[left]);
				i = left;
			}
			else {
				swap(arr[i], arr[right]);
				i = right;
			}
		}
	}
}


int main(){
	int arr[10] = {20, 15, 10, 4, 8};
	ins(arr, 5, 100);
	ext(arr,6);
	printheap(arr, 5);
	return 0;
}
