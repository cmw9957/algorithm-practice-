#include<bits/stdc++.h>
using namespace std;
int d[100005];
int a[100005];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans;
	cin >> n;
	
	for(int i = 0;i < n;i++)
		cin >> a[i];
	
	d[0] = a[0];
	ans = d[0];
	
	for(int i = 1;i < n;i++){
		d[i] = max(d[i-1]+a[i], a[i]);
		ans = max(ans, d[i]);
	}
	cout << ans;
	return 0;
}
