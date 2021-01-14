//N이하의 자연수 중에서 3이나 5로 나누어 떨어지는 수들의 합을 반환하는 함수를 작성. 

#include<iostream>

using namespace std;

int func1(int num);

int main(void){
	printf("%d", func1(16));
	return 0;
}

int func1(int num){
	int sum = 0;
	
	for(int i = 1;i <= num;i++)
		if(i % 3 == 0 || i % 5 == 0) sum += i;
	
	return sum;
}

//시간 복잡도는 O(N) 
