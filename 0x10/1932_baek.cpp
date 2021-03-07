#include<bits/stdc++.h>
using namespace std;
int d[505][505];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			int num;
			cin >> num;
			d[i][j] = max(d[i-1][j-1], d[i-1][j]) + num;
		}
	}
	int ans = -1;
	for(int i = 1;i <= n;i++)
		ans = max(ans, d[n][i]);
	cout << ans;
	return 0;
}
