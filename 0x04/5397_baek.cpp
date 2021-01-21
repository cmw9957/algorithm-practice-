#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	list<char> l;
	string s;
	while(n--){
		cin >> s;
		list<char>::iterator t = l.end();
		for(auto c : s){
			if(c == '<'){
				if(!l.empty() && t != l.begin()){
					t--;
				}
			}
			else if(c == '>'){
				if(!l.empty() && t != l.end()){
					t++;
				}
			}
			else if(c == '-'){
				if(!l.empty() && t != l.begin()){
					t--;
					t = l.erase(t);
				}
			}
			else{
				l.insert(t, c);
			}
		}
		for(auto c : l)
			cout << c;
		cout << '\n';
		l.clear();
	}
	return 0;
}
