#include<stdio.h>

int fibo(int);
void showFibo(int);

int main(){
	int cnt;
	printf("how many numbers do you want? : ");
	scanf("%d",&cnt);
	showFibo(cnt);
	printf("\n");
	return 0;
}

int fibo(int num){
	if(num==0 || num==1)
		return num;
	else
		return fibo(num-2) + fibo(num-1);
}

void showFibo(int n){
	for(int i=0;i<n;++i){
		printf("%d ",fibo(i));
	}
}
