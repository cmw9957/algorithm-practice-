#include<bits/stdc++.h>
using namespace std;
int day[20];
int income[20];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;i++)
		cin >> day[i] >> income[i];
	int ans = 0;
	for(int i = n;i >= 1;i--){
		if(i+day[i] > n+1) income[i] = income[i+1];
		else{
			income[i] = max(income[i+1], income[i]+income[i+day[i]]);
			ans = max(ans, income[i]);
		}
	}
	cout << ans;
	return 0;
}
