#include<stdio.h>

int Max(int,int,int);
int Min(int,int,int);

int main(){
	int big,small;
	int num1,num2,num3;
	scanf("%d %d %d",&num1,&num2,&num3);
	big=Max(num1,num2,num3);
	small=Min(num1,num2,num3);

	printf("the biggest value is %d , the smallest value is %d\n",big,small);
	return 0;
}

int Max(int n1, int n2, int n3){
	int max;
	max=n1>=n2 ? n1 : n2;
	max= max>=n3 ? max : n3;
	return max;
}

int Min(int n1, int n2, int n3){
	int min;
	min=n1<=n2 ? n1 : n2;
	min= min<=n3 ? min : n3;
	return min;
}
