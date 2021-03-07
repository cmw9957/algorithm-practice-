#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int zero_cnt[45] = {0}, one_cnt[45] = {0};
		zero_cnt[0] = 1; zero_cnt[1] = 0;
		one_cnt[0] = 0; one_cnt[1] = 1;
		for(int i = 2;i <= n;i++){
			zero_cnt[i] = zero_cnt[i-1] + zero_cnt[i-2];
			one_cnt[i] = one_cnt[i-1] + one_cnt[i-2];
		}
		cout << zero_cnt[n] << ' ' << one_cnt[n] << '\n';
	}
	return 0;
}
