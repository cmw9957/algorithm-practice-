#include<bits/stdc++.h>
using namespace std;
long long d[105];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	d[1] = d[2] = d[3] = 1;
	d[4] = d[5] = 2;
	while(t--){
		int n;
		cin >> n;
		if(d[n] != 0){
			cout << d[n] << '\n';
			continue;
		}
		for(int i = 6;i <= n;i++)
			d[i] = d[i-1]+d[i-5];
		cout << d[n] << '\n';
	}
	return 0;
}
