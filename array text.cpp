#include<stdio.h>

int main(){
	char nama[3][20] = {"dika","ardi","toni"};
	
	for (int i=0;i < 3;i++){
		printf("nama :%s\n",nama[i]);
	}
	return 0;
}