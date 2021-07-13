#include<bits/stdc++.h>
using namespace std;

//n������ ��� �Ҽ����� �����ϴ� �Լ� 
vector<int> prime_list(int n){
	vector<int> primes;
	for(int i = 2;i <= n;i++){
		bool is_prime = true;
		for(int j = 2;j*j <= i;j++){
			if(i%j == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime) primes.pushback(i);
	}
	return primes;
}

//���� ������ �Լ� 
vector<int> prime_list2(int n){
	vector<int> primes;
	for(int i = 2;i <= n;i++){
		bool is_prime = true;
		for(int p : primes){
			if(p*p > i) break;
			if(i%p == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime) primes.push_back(i);
	}
	return primes;
} 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
