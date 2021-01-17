#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int girl[6] = {0}, boy[6] = {0};
	int N, K, sex, grade, cnt = 0;
	
	cin >> N >> K;
	
	while(N--){
		cin >> sex >> grade;
		if(sex)
			boy[grade - 1]++;
		else
			girl[grade - 1]++;
	}
	for(int i = 0;i < 6;i++){
		while(boy[i] > 0){
			cnt++;
			boy[i] -= K;
		}
		while(girl[i] > 0){
			cnt++;
			girl[i] -= K;
		}
	}
	cout << cnt << '\n';
	
	return 0;
}
