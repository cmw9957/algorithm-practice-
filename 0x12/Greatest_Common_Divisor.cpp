#include<bits/stdc++.h>
using namespace std;

//최대공약수 
int gcd(int a, int b){
	int temp;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int gcd2(int a, int b){
	if(!b) return a;
	return gcd(b, a%b);
}

//최소공배수 
int lcm(int a, int b){
	//int overflow를 방지하기 위해 먼저 gcd를 나누었다. 
	return a / gcd(a, b) * b;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
