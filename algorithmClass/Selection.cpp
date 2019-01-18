//2017029416_김상효_12525

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m,tmp,min;
    scanf("%d %d", &n,&m);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;++i){
	scanf("%d",&arr[i]);
    }
    for(int i=0;i<m;++i){
	min=i;
	for(int j=i+1;j<n;j++){
	    if(arr[j]<arr[min]){
		min=j;
	    }
	}
	tmp=arr[min];
	arr[min]=arr[i];
	arr[i]=tmp;
    }
    for(int i=0; i<n;++i){
	printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}

