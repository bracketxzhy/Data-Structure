#include <iostream>
#include <stack>
#include <string>
using namespace std;

int validparentheses(string s){
	stack<int> index;
	index.push(-1);
	int ans = 0;
	
	for(int i = 0; i < int(s.length()); i++){
		if( s[i] == '('){
			index.push(i);
		}
		else{
			index.pop();
			if(index.empty()){
				index.push(i);
			}
			else{
				ans = max(ans, i - index.top());
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
	cout << validparentheses(s)<<endl;
	return 0;
}
