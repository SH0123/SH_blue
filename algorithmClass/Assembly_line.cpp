
//2018029416_김상효_12525

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int e1,e2,x1,x2;
    int *a1,*a2,*t1,*t2;
    int **s_arr, **l_arr;
    int landmark;
    scanf("%d",&num);
    scanf("%d",&e1);
    scanf("%d",&e2);
    scanf("%d",&x1);
    scanf("%d",&x2);
    int arr[num+1];
    a1=(int*)malloc(sizeof(int)*(num+1));
    a2=(int*)malloc(sizeof(int)*(num+1));
    t1=(int*)malloc(sizeof(int)*num);
    t2=(int*)malloc(sizeof(int)*num);
    
    a1[0]=0;
    a2[0]=0;

    for(int i=1;i<num+1;++i) scanf("%d",&a1[i]);
    for(int i=1;i<num+1;++i) scanf("%d",&a2[i]);
    
    for(int i=1;i<num;++i) scanf("%d",&t1[i]);
    for(int i=1;i<num;++i) scanf("%d",&t2[i]);
    
    s_arr=(int**)malloc(sizeof(int*)*3);
    for(int i=0; i<3;++i){
	s_arr[i]=(int*)malloc(sizeof(int)*(num+2));
    }

    l_arr=(int**)malloc(sizeof(int*)*3);
    for(int i=0;i<3;++i){
	l_arr[i]=(int*)malloc(sizeof(int)*(num+2));
    }
        
    s_arr[1][1]=e1+a1[1];
    s_arr[2][1]=e2+a2[1];
    
    for(int j=2;j<num+2;++j){
	s_arr[1][j]= s_arr[1][j-1]+a1[j] > s_arr[2][j-1]+a1[j]+t2[j-1] ? s_arr[2][j-1]+a1[j]+t2[j-1] : s_arr[1][j-1]+a1[j]; //1번라인에서 오는게 더 작은지 2번에서 오는게 더 작은지 판단
	if(s_arr[1][j]==s_arr[1][j-1]+a1[j]){ //1번에서 오는게 더 작은경우
	    l_arr[1][j]=1; //1번에서 왔다는 것을 표시
	    
	}
	else{ // 2번에서 오는게 더 작은경우
	    l_arr[1][j]=2; //2번에서 왔다는것을 표시
	}
	s_arr[2][j]= s_arr[2][j-1]+a2[j] >= s_arr[1][j-1]+t1[j-1]+a2[j] ? s_arr[1][j-1]+t1[j-1]+a2[j] : s_arr[2][j-1]+a2[j];
	if(s_arr[2][j]==s_arr[2][j-1]+a2[j]){
	    l_arr[2][j]=2;
	}
	else{
	    l_arr[2][j]=1;
	}
    }
	s_arr[1][num+1]+=x1;
	s_arr[2][num+1]+=x2;
	
	l_arr[1][num+1]=1;
	l_arr[2][num+1]=2;	
    
   
    
    // output
    if(s_arr[1][num+1]<=s_arr[2][num+1]){
       	printf("%d\n",s_arr[1][num+1]);
	landmark=1;
    }
    else{
       	printf("%d\n",s_arr[2][num+1]);
	landmark=2;
    }

    for(int i=num+1;i>0;--i){
	arr[i-1]=l_arr[landmark][i];
	landmark=l_arr[landmark][i];
	
    }
    for(int i=1;i<num+1;++i){
	printf("%d %d\n",arr[i],i);
    }
   
    return 0;
}
