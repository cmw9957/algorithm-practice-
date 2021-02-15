#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int cnt = 0;
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0;i < n;i++) cin >> a[i];
		for(int i = 0;i < m;i++) cin >> b[i];
		sort(b.begin(), b.end());
		for(auto c : a)
			cnt += lower_bound(b.begin(), b.end(), c) - b.begin();
		cout << cnt << '\n';
	}
	return 0;
}
