#include<bits/stdc++.h>
using namespace std;
long long y[10005];
long long d[10005];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;i++)
		cin >> y[i];
	d[1] = y[1]; 
	if(n > 1)
		d[2] = y[1] + y[2];
	if(n > 2){
		for(int i = 3;i <= n;i++)
			d[i] = max({d[i-1], d[i-2]+y[i], d[i-3]+y[i-1]+y[i]});
	}
	cout << d[n];
	return 0;
}
