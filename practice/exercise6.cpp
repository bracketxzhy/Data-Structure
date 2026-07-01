#include <iostream>
using namespace std;
void printheap(int arr[], int n){
	for (int i = 0; i < n; i++){
		cout << arr[i]<<" ";
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
		else if (right >= n){
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int* arr = new int[n];
	for(int i = 0; i<m; i++){
		cin>>arr[i];
	}
	printheap(arr, m);
	cout<<endl;
	ins(arr, m, 100);
	printheap(arr, m+1);
	cout<<endl;
	ext(arr,m+1);
	printheap(arr, m);
	return 0;
}
