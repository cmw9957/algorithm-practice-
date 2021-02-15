#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long> a;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++){
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		a.push_back(stoll(str));
	}
	sort(a.begin(), a.end());
	for(auto c : a) cout << c << '\n';
	return 0;
}
