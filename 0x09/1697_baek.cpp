#include<bits/stdc++.h>
using namespace std;
int road[100002];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	fill(road, road + 100002, -1);
	road[n] = 0;
	queue<int> Q;
	Q.push(n);
	while(road[k] == -1){
		auto cur = Q.front(); Q.pop();
		for(auto nxt : {cur - 1, cur + 1, cur * 2}){
			if(nxt < 0 || nxt > 100000) continue;
			if(road[nxt] != -1) continue;
			road[nxt] = road[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << road[k] << '\n';
	return 0;
}
