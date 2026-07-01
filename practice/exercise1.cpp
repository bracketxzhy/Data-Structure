#include<iostream>
#include<stack>
#include<string>
using namespace std;
int pri(char c){
	if(c == '*' || c == '/'){return 2;} 
	if(c == '+' || c == '-'){return 1;} 
	return 0;
}
string infix2postfix(string s){
	stack<char> wait;
	string ans;
	for (char c : s){
		if(c >= '0' && c <= '9'){ ans += c; }
		else if (c == '('){ wait.push(c); }
		else if (c == ')'){ 
			while(wait.top() != '('){
				ans += wait.top();
				wait.pop();
			}
			wait.pop();
		}
		else{
			while( !wait.empty() && wait.top() != '(' && pri(wait.top()) >= pri(c)){
				ans += wait.top();
				wait.pop();
			}
			wait.push(c);
		}
	}
	while (!wait.empty())
	{
		ans += wait.top();
		wait.pop();
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	getline(cin,s);
	
	cout << infix2postfix(s)<<endl;
	return 0;
}




