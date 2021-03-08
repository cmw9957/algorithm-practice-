#include<bits/stdc++.h>
using namespace std;
int arr[1005];
int d[1005];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	d[0] = 1;
	for(int i = 1;i < n;i++){
		int max_num = 0;
		for(int j = 0;j < i;j++){
			if(arr[j] < arr[i])
				max_num = max(max_num, d[j]);
		}
		d[i] = max_num+1;
	}
	cout << *max_element(d, d+n);
	return 0;
}
