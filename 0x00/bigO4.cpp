//N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수를 작성 N은 10억 이하의 자연수이다.

#include<iostream>

int func4(int N);

int main(void){
	printf("%d", func4(1));
	return 0;
} 

int func4(int N){
	int a = 1;
	for(int i = 0;i < N;i++){
		if(a * 2 <= N)
			a *= 2;
	}
	return a;
}

//시간 복잡도는 O(lgN)
//N이 2k 이상 2^k+1 미만이라고 할 때 while문 안에서 val은 최대 k번만 2배로 커집니다. 
//그러고나면 val은 2^k가 되고, 이후 2*val <= N이 거짓이 되기 때문입니다. 
//그러니까 N이 2^k 이상 2^k+1 미만이라고 할 때 시간복잡도가 O(k)이고 로그의 정의에 입각해서 생각할 때 k는 lgN이니 결국 시간복잡도는 O(lgN)이 됩니다. 
