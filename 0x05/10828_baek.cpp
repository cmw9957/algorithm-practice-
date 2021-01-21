#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> s;
	int n;
	cin >> n;
	string str;
	while(n--){
		cin >> str;
		if(str == "push"){
			int num;
			cin >> num;
			s.push(num);
		}
		else if(str == "pop"){
			if(s.empty()){
				cout << "-1" << '\n';
				continue;
			}
			cout << s.top() << '\n';
			s.pop();
		}
		else if(str == "size"){
			cout << s.size() << '\n';
		}
		else if(str == "empty"){
			cout << (int)s.empty() << '\n';
		}
		else if(str == "top"){
			if(s.empty()){
				cout << "-1" << '\n';
				continue;
			}
			cout << s.top() << '\n';
		}
	}
	return 0;
}
