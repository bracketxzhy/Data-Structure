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

#include <iostream>
#include <stack>
using namespace std;
string ID(string s){
	stack<int> index;
	string ans;
	for (int i = 0; i <= int (s.length()); i++){
		if (i < int(s.length()) && s[i] == 'D'){
			index.push(i+1);
		}
		else{
			index.push(i+1);
			int m=index.size();
			for(int j = 0; j < m; j++){
				ans += to_string(index.top());
				index.pop();
			}	
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	getline(cin,s);
	
	cout << ID(s)<<endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	
	Node(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};
int maxDepth(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	
	return max(leftDepth, rightDepth) + 1;
}
int main() {
	Node* root = new Node(3);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(7);
	
	cout << maxDepth(root) << endl;  // Output: 3
	
	return 0;
}
