#include <iostream>
using namespace std;
bool inc(int arr[], int m){
	for (int i = 0; i < m - 1; i++){
		if (arr[i] > arr[i + 1]){
			return false;
		}
	}
	return true;
}
int subinc(int s[], int m){
	int ans = m;
	int sub[m];
	for (int l = 0; l < m; l++){
		for (int r = l; r < m; r++){
			for (int i = 0; i < m; i++) {
				sub[i] = s[i];
			}
			if(!(l == 0 && r == m-1)){
				if (l > 0 ) {
					for (int k = l; k <= r; k++) {
						sub[k] = s[l - 1];
					}
				}
				else {
					for (int k = l; k <= r; k++) {
						sub[k] = s[r + 1];
					}
				}
				int len = r - l + 1;
				if (inc(sub, m) && len < ans){
					ans = len;
				}
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	
	int* arr = new int[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	cout << subinc(arr,n) << endl;
	return 0;
}
