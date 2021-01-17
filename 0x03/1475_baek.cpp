#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, cnt[10] = {0}, six_nine = 0, max;
	cin >> N;
	if(!N){
		cout << "1" << '\n';
		return 0;
	}
	while(N){
		cnt[N % 10]++;
		N /= 10;
	}
	six_nine = cnt[6] + cnt[9];
	six_nine = six_nine / 2 + six_nine % 2;
	max = cnt[0];
	
	for(int i = 0;i < 10;i++)
		if(i != 6 && i != 9 && max < cnt[i]) max = cnt[i];
	
	if(max < six_nine)
		cout << six_nine << '\n';
	else
		cout << max << '\n';
	
	return 0;
}
