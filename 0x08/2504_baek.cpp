#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<pair<char, int> > S;
	string str;
	getline(cin, str);
	int total = 0;
	for(auto c : str){
		if(c == '(' || c == '[') S.push(make_pair(c, 0));
		
		else if(c == ')'){
			if(S.empty() || S.top().first != '('){	//올바르지 않을 때 ,비어있거나 (가 아닐 때 
				cout << 0 << '\n';
				return 0;
			}
			else{
				int temp;
				if(S.top().second)
					temp = S.top().second;
				else
					temp = 2;
				S.pop();
				if(S.empty())
					total += temp;
				else{
					if(S.top().first == '(')
						S.top().second += temp * 2;
					else
						S.top().second += temp * 3;
				}
			}
		}
		else if(c == ']'){
			if(S.empty() || S.top().first != '['){	//올바르지 않을 때 ,비어있거나 [가 아닐 때 
				cout << 0 << '\n';
				return 0;
			}
			else{
				int temp;
				if(S.top().second)
					temp = S.top().second;
				else
					temp = 3;
				S.pop();
				if(S.empty())
					total += temp;
				else{
					if(S.top().first == '(')
						S.top().second += temp * 2;
					else
						S.top().second += temp * 3;
				}
			}
		}
	}
	cout << total << '\n';
	return 0;
}
