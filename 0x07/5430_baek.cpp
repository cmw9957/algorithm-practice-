#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	deque<int> DQ;
	int t;
	cin >> t;
	while(t--){
		string op = "";
		bool err = false;
		bool reverse = false;
		cin >> op;
		int n;
		cin >> n;
		string s;
		cin >> s;
		char *p = &s[0];
		
		while(*p != ']'){
			if(*p == '[' || *p == ','){
				if(*(p + 1) == ']') break;
				int num;
				num = atoi(p + 1);
				DQ.push_back(num);
			}
			p++;
		}
		
		if(DQ.size() != n){
			cout << "error" <<'\n';
			continue;
		}
		
		for(int i = 0;i < op.length();i++){
			if(op[i] == 'R'){
				if(reverse)
					reverse = false;
				else
					reverse = true;
			}
			else{
				if(DQ.empty()){
					err = true;
					break;
				}
				if(reverse)
					DQ.pop_back();
				else
					DQ.pop_front();
			}
		}
		
		if(err){
			cout << "error" << '\n';
			continue;
		}
		
		if(reverse){
			cout << '[';
			for(auto it = DQ.rbegin();it != DQ.rend();it++){
				if(it != DQ.rend() - 1)
					cout << *it << ',';
				else
					cout << *it;
			}
			cout << ']' << '\n';
		}
		else{
			cout << '[';
			for(auto it = DQ.begin();it != DQ.end();it++){
				if(it != DQ.end() - 1)
					cout << *it << ',';
				else
					cout << *it;
			}
			cout << ']' << '\n';
		}
		DQ.clear();
	}
}
