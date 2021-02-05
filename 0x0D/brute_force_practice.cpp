#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int box[55][55];
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

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
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	int total = 0x7f7f7f7f;
	do{
		int dist = 0;
		for(auto h : house){//m���� ġŲ���� ���� �ϳ��� ����� ������ ��� �������� �Ÿ��� ��� 
			int temp = 0x7f7f7f7f;
			for(int i = 0;i < chicken.size();i++){
				if(brute[i] == 0) continue;
				//m���� ġŲ���߿��� ���� ����� ġŲ�������� �Ÿ��� ���� 
				temp = min(temp, abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y));
			}
			dist += temp;
		}
		//m���� ġŲ���� �ִ� ����� ���� �� �ּҰ��� ���� 
		total = min(total, dist);
	}while(next_permutation(brute.begin(), brute.end()));
	cout << total;
	return 0;
}
