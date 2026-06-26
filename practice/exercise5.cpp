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
			
			if (l > 0) {
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
	return ans;
}
int main(){
	int arr[6] = {1,2,2,2,1,5};
	cout << subinc(arr,6) << endl;
	return 0;
}
