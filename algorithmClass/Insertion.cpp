//2018029416_김상효_12525

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int key, num, k;
    scanf("%d", &num);
    
    int* arr = (int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;++i){
	scanf("%d",&arr[i]);
    }
    for(int j=1; j< num; ++j){
	key = arr[j];
	k=j-1;
	while(k>=0&&arr[k]>key){
	    arr[k+1] = arr[k];
	    k--;
	}
	arr[k+1] = key;
    }
    for(int i=num-1;i>=0;--i){
	printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}
