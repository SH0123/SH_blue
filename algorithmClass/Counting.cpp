//2017029416_김상효_12525

#include<stdio.h>
#include<stdlib.h>


int count_(int*,int*,int);

int main(){
    int input,max,num;
    int r_num;
    scanf("%d %d %d",&input,&max,&num);
    int* arr=(int*)malloc(sizeof(int)*input);//입력값
    int* countSum=(int*)malloc(sizeof(int)*(max+1));
    int* count=(int*)malloc(sizeof(int)*(max+1));
    int* r_arr=(int*)malloc(sizeof(int)*(2*num+1));
    int* s_arr=(int*)malloc(sizeof(int)*(input+1));//정렬된 배열
    for(int i=0;i<max+1;++i){
	count[i]=0;
    }
    for(int i=0;i<2*num;++i){
	scanf("%d",&r_num);
	r_arr[i+1]=r_num;
    }
    for(int i=0;i<input;++i){
	scanf("%d",&arr[i]);
	count[arr[i]]++;
    }
    
    countSum[0]=count[0];
  for(int i=1;i<=max;++i){//여기서 countSum[60]-counSum[20] 이런식으로
	countSum[i]=countSum[i-1]+count[i];
    }
/*  for(int i=1;i<=max;++i){
      printf("%d번 숫자%d\n",i,countSum[i]);

  }    for(int i=input-1;i>=0;--i){ //sort안해도 될듯
	s_arr[countSum[arr[i]]]=arr[i];
	countSum[arr[i]]--;
    }
  */  
    
  for(int i=1;i<=2*num;i=i+2){
	printf("%d\n",count_(countSum,r_arr,i));
    }


free(arr);
free(countSum);
free(count);
free(r_arr);
free(s_arr);
    return 0;
}

int count_(int* countSum_,int* r_arr1,int j){
    int spt=r_arr1[j]; 
    int ept=r_arr1[j+1];
    
    return countSum_[ept]-countSum_[spt-1];

}
