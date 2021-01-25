#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> S;
	int pipe = 0;
	int piece = 0;
	string str;
	getline(cin, str);
	for(auto c : str){
		if(c == '('){
			S.push(c);
			++pipe;
		}
		else if(c == ')'){
			if(S.top() == '('){
				S.push(c);
				--pipe;
				piece += pipe;
			}
			else{
				S.push(c);
				--pipe;
				++piece;
			}
		}
	}
	cout << piece << '\n';
	
	return 0;
}
