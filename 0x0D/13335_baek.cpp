#include<bits/stdc++.h>
using namespace std;
int n, w, l;
int cnt;
int truck[1002];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w >> l;
	int truck_w = 0;
	queue<int> Q;
	for(int i = 0;i < n;i++)
		cin >> truck[i];
	for(int i = 0;i < n;i++){
		while(1){
			if(Q.size() == w){
				truck_w -= Q.front();
				Q.pop();
			}
			if(truck_w + truck[i] <= l) break;
			Q.push(0);
			cnt++;
		}
		truck_w += truck[i];
		Q.push(truck[i]);
		cnt++;
	}
	cout << cnt + w;
	return 0;
}
