
//2018029416_김상효_12525

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    
    scanf("%d",&num);
    int* arr_p;
    int* arr_r;
    int* arr_s;
    arr_p=(int*)malloc(sizeof(int)*(num+1));
    arr_r=(int*)malloc(sizeof(int)*(num+1));
    arr_s=(int*)malloc(sizeof(int)*(num+1));
    arr_p[0]=0;
    arr_r[0]=0;
    arr_s[0]=0;
    for(int i=1;i<=num;++i){
	scanf("%d",&arr_p[i]);
    }

    for(int j=1; j<=num;++j){
	int q=-1;
	for(int k=1;k<=j;++k){
	    if(q<arr_p[k]+arr_r[j-k]){
		q=arr_p[k]+arr_r[j-k];
		arr_s[j]=k;
	    }
	}
	arr_r[j]=q;
    }
    printf("%d\n",arr_r[num]);

	while(num>0){
	printf("%d ",arr_s[num]);
	num = num - arr_s[num];
    }
	printf("\n");
    free(arr_r);
    free(arr_s);
    free(arr_p);

    return 0;
}
