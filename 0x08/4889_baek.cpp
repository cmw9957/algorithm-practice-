#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 1;
	while(1){
		int cnt = 0;
		string str;
		stack<char> S;
		getline(cin, str);
		if(str[0] == '-') break;
		for(auto c : str){
			if(c == '{') S.push(c);
			
			else{
				if(S.empty()){
					++cnt;
					S.push('{');
				}
				else if(S.top() == '{'){
					S.pop();
				}
			}
		}
		if(!S.empty())
			cnt += S.size() / 2;
		cout << n++ << ". " << cnt << '\n';
	}
	
	return 0;
}
