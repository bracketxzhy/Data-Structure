#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool rever( string s){
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
}

string p(string s){
	string ans;
	
	for (int i = 0; i < int(s.length()); i++){
		for (int j = 0; j <= i; j++){
			string substring = s.substr(i - j, i);
			
			if (rever(substring) && substring.length() >ans.length()){
				ans = substring;
			}
		}
			
	}
	return ans;
}

int main(){
	cout<< p("aavavvvvvvvv")<<endl;
	return 0;
}
