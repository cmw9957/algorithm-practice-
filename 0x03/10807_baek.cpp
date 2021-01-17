#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, arr[102] = {}, v, cnt = 0;
	cin >> N;
	for(int i = 0;i < N;i++)
		cin >> arr[i];
	cin >> v;
	for(int i = 0;i < N;i++)
		if(arr[i] == v) cnt++;
	
	cout << cnt;
	return 0;
}
