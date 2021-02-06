#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int box[55][55];
vector<pair<int, int> > house;
vector<pair<int, int> > chicken;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> box[i][j];
			if(box[i][j] == 1) house.push_back({i, j});
			else if(box[i][j] == 2) chicken.push_back({i, j});
		}
	}
	//총 ~개중에서 m개만을 사용한다할때 백트래킹 사용, 경우의 수, 순열의 조합 등 
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	//모든 경우의 수를 계산하여 도출한 최소값 
	int total = 0x7f7f7f7f;
	do{
		int dist = 0;
		//한 경우의 수에서 각 집마다 치킨거리를 구함 
		for(auto h : house){
			int temp = 0x7f7f7f7f;
			for(int i = 0;i < chicken.size();i++){
				if(brute[i] == 0) continue;
				temp = min(temp, abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y));
			}
			dist += temp;
		}
		//많은 경우의 수 중에서 하나의 도시 치킨거리 최소값을 비교 
		total = min(total, dist);
	}while(next_permutation(brute.begin(), brute.end()));
	cout << total;
	return 0;
}
