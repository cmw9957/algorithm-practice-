#include<bits/stdc++.h>
using namespace std;

//�ִ����� 
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

//�ּҰ���� 
int lcm(int a, int b){
	//int overflow�� �����ϱ� ���� ���� gcd�� ��������. 
	return a / gcd(a, b) * b;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
