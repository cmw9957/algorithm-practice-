#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int d[100005];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		d[i] = d[i-1] + arr[i];
	}
	while(m--){
		int _begin, _end;
		cin >> _begin >> _end;
		cout << d[_end] - d[_begin-1] << '\n';
	}
	return 0;
}

//prefix-sum
