#include <stdio.h>

double Cel2Fah(int);
double Fah2Cel(int);

int main(){
	double cel,fah,select;
	while(1){
	printf("1. celsius to fahrenheit 2. fahrenheit to celsius select number :\n");
	scanf("%lf",&select);
	if(select==1){
		scanf("%lf",&cel);
		fah=Cel2Fah(cel);
		printf("fahrenheit : %lf\n",fah);
		break;
	}
	else if(select==2){
		scanf("%lf",&fah);
		cel=Fah2Cel(fah);
		printf("celsius : %lf\n",cel);
		break;
	}
	else
		printf("reselct the number\n");

	}
	return 0;
}

double Cel2Fah(int temper){
	double f;
	f=temper*1.8+32;
	return f;
}

double Fah2Cel(int temper){
	double c;
	c=(temper-32)/1.8;
	return c;

}
