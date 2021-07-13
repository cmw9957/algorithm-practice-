#include<bits/stdc++.h>
using namespace std;

vector<int> divisor(int n){
	vector<int> div;
	for(int i = 1;i*i <= n;i++)
		if(n%i == 0) div.push_back(i);
	
	for(int i = (int)div.size()-1;i >= 0;i--){
		if(div[i] * div[i] == n) continue;
		div.push_back(n/div[i]);
	}
	return div;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
