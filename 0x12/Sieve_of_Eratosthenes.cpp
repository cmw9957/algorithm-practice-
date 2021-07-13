#include<bits/stdc++.h>
using namespace std;

//에라토스테네스의 체 구현 함수 
vector<int> sieve(int n){
	vector<int> primes;
	vector<bool> state(n+1, true);
	state[1] = false;
	for(int i = 2;i <= n;i++){
		if(!state[i]) continue;
		for(int j = 2*i;j <= n;j += i)
			state[j] = false;
	}
	for(int i = 2;i <= n;i++)
		if(state[i]) primes.push_back(i);
	return primes;
}

//에라토스테네스의 체 구현 함수 개선 
vector<int> sieve2(int n){
	vector<int> primes;
	vector<bool> state(n+1, true);
	state[1] = false;
	for(int i = 2;i*i <= n;i++){
		if(!state[i]) continue;
		for(int j = i*i;j <= n;j += i)
			state[j] = false;
	}
	for(int i = 2;i <= n;i++)
		if(state[i]) primes.push_back(i);
	return primes;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
