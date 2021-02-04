#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int arr2[10];
bool vis[10005];

void func(int k){
	if(k == m){
		for(int i = 0;i < m;i++)
			cout << arr2[i] << ' ';
		cout << '\n';
		return ;
	}
	for(int i = 0;i < n;i++){
		int num = arr[i];
		if(!vis[num]){
			if(k != 0 && arr2[k-1] > num) continue;
			arr2[k] = num;
			vis[num] = 1;
			func(k+1);
			vis[num] = 0;
		}
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
