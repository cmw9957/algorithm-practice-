#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
int arr[MAX];
int arr2[MAX];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, n2;
	cin >> n >> n2;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	for(int i = 0;i < n2;i++)
		cin >> arr2[i];
	int idx = 0, idx2 = 0;
	while(1){
		if(arr[idx] > arr2[idx2])
			cout << arr2[idx2++] << ' ';
		else if(arr[idx] <= arr2[idx2])
			cout << arr[idx++] << ' ';
		
		if(idx >= n){
			for(int i = idx2;i < n2;i++)
				cout << arr2[i] << ' ';
			break;
		}
		else if(idx2 >= n2){
			for(int i = idx;i < n;i++)
				cout << arr[i] << ' ';
			break;
		}
	}
	return 0;
}
