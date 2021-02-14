#include<bits/stdc++.h>
using namespace std;
int n;

bool cmp(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, string> > v(n);
	for(int i = 0;i < n;i++) cin >> v[i].first >> v[i].second;
	stable_sort(v.begin(), v.end(), cmp);
	for(int i = 0;i < n;i++) cout << v[i].first << ' ' << v[i].second << '\n';
	return 0;
}
