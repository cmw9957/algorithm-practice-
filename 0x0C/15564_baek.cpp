#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int arr2[10];
bool vis[10];

void func(int k){
	if(k == m){
		for(int i = 0;i < m;i++)
			cout << arr2[i] << ' ';
		cout << '\n';
		return ;
	}
	int x = 0;						//트리구조에서 같은 행에 같은 숫자가 나오면 안된다. 
	for(int i = 0;i < n;i++){
		if(!vis[i] && x != arr[i]){
			if(k != 0 && arr2[k-1] > arr[i]) continue;
			arr2[k] = arr[i];
			x = arr[i];
			vis[i] = 1;
			func(k+1);
			vis[i] = 0;
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
