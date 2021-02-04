#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int arr2[10];

void func(int k){
	if(k == m){
		for(int i = 0;i < m;i++)
			cout << arr2[i] << ' ';
		cout <<'\n';
		return ;
	}
	for(int i = 0;i < n;i++){
		if(k != 0 && arr2[k-1] > arr[i]) continue;
		arr2[k] = arr[i];
		func(k+1);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	sort(arr, arr+n);
	func(0);
	return 0;
}
