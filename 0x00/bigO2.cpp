//주어진 길이 N의 int 배열 arr 에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을 반환 그렇지 않으면 0 을 반환하는 함수를 작성 arr 의 각 수는 0이상 100이하고 N은 1000이하이다.

#include<iostream>

int func2(int arr[], int N);

int main(void){
	int a[5] = {1,2,99,4,7};
	printf("%d", func2(a, 5));
	return 0;
}

int func2(int arr[], int N){
	for(int i = 0;i < N - 1;i++){
		for(int j = i + 1;j < N;j++){
			if((arr[i] + arr[j]) == 100) return 1;
		}
	}
	return 0;
}

//시간 복잡도는 O(N^2) 
