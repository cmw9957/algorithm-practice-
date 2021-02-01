#include<iostream>
using namespace std;

int foo(int n){
	if(n == 0) return;
	return n + foo(n - 1);
}

void foo1(int n){
	if(n == 0) return;
	cout << n << ' ';
	foo1(n - 1);
}

int main(){
	foo1(5);
	
} 
