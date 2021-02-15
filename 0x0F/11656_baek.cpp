#include<bits/stdc++.h>
using namespace std;
string str;
vector<string> v;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	int len = str.length();
	for(int i = 0;i < len;i++)
		v.push_back(str.substr(i));
	
	sort(v.begin(), v.end());
	for(auto c : v) cout << c << '\n';
	return 0;
}
