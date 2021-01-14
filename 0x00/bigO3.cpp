//N이 제곱수이면  1을 반환하고 제곱수가 아니면 0을 반환하는 함수를 작성 N은 10억 이하의 자연수이다.

#include<iostream>

int func3(int N);

int main(void){
	printf("%d", func3(11));
	return 0;
} 

int func3(int N){
	for(int i = 1;i <= N;i++){
		if(i * i == N) return 1;
	}
	return 0;
}

//시간 복잡도는 O((root)N) 
