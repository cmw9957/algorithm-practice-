#include<bits/stdc++.h>
using namespace std;

int is_prime(int a){
	if(a == 1)
		return 0;
	for(int i = 2;i*i <= a;i++)
			if(a%i == 0)
				return 0;
	return 1;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	int ans = 0;
	while(t--){
		int num;
		cin >> num;
		ans += is_prime(num);
	}
	
	cout << ans;
	return 0;
}
