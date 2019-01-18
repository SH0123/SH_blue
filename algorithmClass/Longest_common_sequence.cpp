//2017029416_김상효_12525

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define UP 0
#define LEFT 1
#define CROSS 2

void print(int**,char*,int,int);

int main(){
	int m,n;
	char x[501],y[501];
	int **b;
	int	**c;

	scanf("%s %s", &x[1], &y[1]);
	n=strlen(x)-1;
	m=strlen(y)-1;
	
	b=(int**)malloc(sizeof(int*)*(m+1));
	
	for(int i=0;i<m+1;++i){
		b[i]=(int*)malloc(sizeof(int)*(n+1));
	}

	c=(int**)malloc(sizeof(int*)*(m+1));
	
	for(int i=0;i<m+1;++i){
		c[i]=(int*)malloc(sizeof(int)*(n+1));
	}

	for(int i=0;i<m+1;++i) c[i][0]=0;
	for(int i=0;i<n+1;++i) c[0][i]=0;


	for(int i=1;i<m+1;++i){
		for(int j=1;j<n+1;++j){
			if(x[j]==y[i]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=CROSS;
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=UP;
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]=LEFT;
			}
		}
	}

/*	for(int i=0;i<m+1;++i){
		for(int j=0;j<n+1;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}*/
	print(b,x,m,n);

	return 0;
}

void print(int** b_,char* x_,int i_,int j_){
	if(i_==0||j_==0)
		return;
	if(b_[i_][j_]==CROSS){
		print(b_,x_,i_-1,j_-1);
		printf("%c",x_[j_]);
	}
	else if(b_[i_][j_]==UP)
		print(b_,x_,i_-1,j_);
	else
		print(b_,x_,i_,j_-1);
}


