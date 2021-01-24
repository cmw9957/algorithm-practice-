#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	deque<int> DQ;
	int n;
	int arr[51];
	cin >> n;
	for(int i = 1;i <= n;i++)
		DQ.push_back(i);
	int m;
	cin >> m;
	for(int i = 0;i < m;i++)
		cin >> arr[i];
	int k = 0;
	int cnt = 0;
	while(k != m){
		if(DQ.front() != arr[k]){
			int len = 0;
			for(auto it = DQ.begin(); *it != arr[k];it++)
				len++;
			if(len >= DQ.size() - len){
				while(DQ.front() != arr[k]){
					int temp = DQ.back();
					DQ.pop_back();
					DQ.push_front(temp);
					cnt++;
				}
				DQ.pop_front();
			}
			else{
				while(DQ.front() != arr[k]){
					int temp = DQ.front();
					DQ.pop_front();
					DQ.push_back(temp);
					cnt++;
				}
				DQ.pop_front();
			}
		}
		else
			DQ.pop_front();
		k++;
	}
	cout << cnt << '\n';
	return 0;
}
