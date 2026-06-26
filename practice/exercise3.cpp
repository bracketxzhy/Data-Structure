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
	cout << ID("IIDDD") << endl;
}
