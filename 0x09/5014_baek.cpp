#include<bits/stdc++.h>
using namespace std;
int building[1000005];
int up_down[2];
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int f, s, g;
	cin >> f >> s >> g >> up_down[0] >> up_down[1];
	int idx = s - 1;
	building[idx] = 1;
	queue<int> Q;
	Q.push(idx);
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int dir = 0;dir < 2;dir++){
			int pos;
			if(dir == 1)
				pos = cur - up_down[dir];
			else
				pos = cur + up_down[dir];
			if(building[g - 1] != 0){
				cout << building[g - 1] - 1 << '\n';
				return 0;
			}
			if(pos < 0 || pos > f) continue;		//범위를 잘보고 코드를 작성하자 
			if(building[pos] != 0) continue;
			building[pos] = building[cur] + 1;
			Q.push(pos);
		}
	}
	cout << "use the stairs" << '\n';
	return 0;
}
