#include<bits/stdc++.h>
using namespace std;
int d[1005];
int card[1005];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> card[i];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			d[i] = max(d[i], d[i-j]+card[j]);
		}
	}
	cout << d[n];
	return 0;
}
