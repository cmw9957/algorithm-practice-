#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	int k;
	cin >> k;
	
	while(k--){
		int n;
		cin >> n;
		if(n)
			S.push(n);
		else
			S.pop();
	}
	int sum = 0;
	int len = (int)S.size();
	
	for(int i = 0;i < len;i++){
		sum += (int)S.top();
		S.pop();
	}
	cout << sum << '\n';
	return 0;
}
