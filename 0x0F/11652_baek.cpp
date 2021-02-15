#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[100005];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;i++) cin >> arr[i];
	sort(arr, arr+n);
	long long max_num;
	int max_cnt = 0;
	int cnt = 0;
	
	for(int i = 0;i < n;i++){
		if(i==0 || arr[i-1] == arr[i]) cnt++;
		else{
			if(cnt > max_cnt){
				max_cnt = cnt;
				max_num = arr[i-1];
			}
			cnt = 1;
		}
	}
	if(cnt > max_cnt) max_num = arr[n-1];
	cout << max_num;
	return 0;
}
