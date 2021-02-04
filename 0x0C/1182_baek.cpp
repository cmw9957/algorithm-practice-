#include<bits/stdc++.h>
using namespace std;
int n, s;
int arr[30];
int cnt;

void func(int cur, int sum){
	if(cur == n){
		if(sum == s) cnt++;
		return;
	}
	func(cur+1, sum);
	func(cur+1, sum+arr[cur]);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	func(0, 0);
	if(s == 0) cnt--;
	cout << cnt << '\n';
	return 0;
}
