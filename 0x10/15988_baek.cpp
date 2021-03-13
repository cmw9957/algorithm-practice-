#include<bits/stdc++.h>
using namespace std;
long long d[1000050];
#define MOD 1000000009

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	d[1] = 1; d[2] = 2; d[3] = 4;
	while(t--){
		int n;
		cin >> n;
		if(d[n] != 0){
			cout << d[n] << '\n';
			continue;
		}
		for(int i = 4;i <= n;i++){
			d[i] = d[i-1]+d[i-2]+d[i-3];
			d[i] %= MOD;
		}
		cout << d[n] << '\n';
	}
	return 0;
}
