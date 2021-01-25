//쉬운 문제였는데 문자열 입력을 어떻게 해야하나에서 많이 헤맸다. 문제를 제대로 읽지 않는 습관을 고쳐야겠다. 

#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		stack<char> S;					//스택을 반복적으로 써야한다면 반복문 안에다가 선언을 두자 
		bool isValid = true;
		string s;
		getline(cin, s);
		if(s == ".") break;				//string이므로 ""으로 묶어주어야한다. 
		for(auto c : s){
			if(c == '(' || c == '[') S.push(c);
			else if(c == ')'){
				if(S.empty() || S.top() != '('){
					isValid = false;
					break;
				}
				S.pop();
			}
			else if(c == ']'){
				if(S.empty() || S.top() != '['){
					isValid = false;
					break;
				}
				S.pop();
			}
		}
		if(!S.empty()) isValid = false;
			if(isValid)
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';
	}
	return 0;
}
