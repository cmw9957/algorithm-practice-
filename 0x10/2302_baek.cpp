#include<bits/stdc++.h>
#define MOD 2000000000
using namespace std;
int seat[50];
int d[50];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long ans = 1;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		seat[i] = i;
	int m;
	cin >> m;
	while(m--){
		int idx;
		cin >> idx;
		seat[idx] = 0;
	}
	
	d[0] = 1; d[1] = 1; d[2] = 2;
	for(int i = 3;i <= 40;i++)
		d[i] = d[i-1]+d[i-2];

	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(seat[i] == 0){
			ans *= d[cnt];
			ans %= MOD;
			cnt = 0;
			continue;
		}
		cnt++;
	}
	ans *= d[cnt];
	ans %= MOD;
	cout << ans;
	return 0;
}
