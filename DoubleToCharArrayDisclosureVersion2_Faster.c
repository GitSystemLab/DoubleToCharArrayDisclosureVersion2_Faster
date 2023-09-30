#include "DoubleToCharArrayDisclosureVersion2_Faster.h"

int main(){
	double DoublePi = 3.141592653589793115997963468544185161590576171875000;
	int i = 0;
	
	for(i=1;i<=50;i++){
		printf("%s\n",DoubleToCharArray(DoublePi,(41-i),(41-i),(41-i),3,3,0,5,10));
	}//i
	for(i=1;i<=50;i++){
		printf("%s\n",DoubleToCharArray(DoublePi,7,(41-i),(31-i),3,3,0,5,10));
	}//i
	printf("------------------------------------------------------------------------\n");
	printf("[Round Down]\n");
	for(i=1;i<=50;i++){
		printf("%s\n",DoubleToCharArray(DoublePi,7,(31-i),(41-i),3,3,0,10,10));
	}//i
	//Round Down
	printf("------------------------------------------------------------------------\n");
	printf("[Round Up]\n");
	for(i=1;i<=50;i++){
		printf("%s\n",DoubleToCharArray(DoublePi,7,(31-i),(41-i),3,3,0,0,10));
	}//i
	
}//main