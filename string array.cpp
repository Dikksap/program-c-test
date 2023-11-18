#include<stdio.h>
#include<string.h>
int main(){
	
	char string[10][25];
	int i,n;
	
	printf("total number of string :");
	scanf("%d",n);
	
	for(i=0; i<n;i++){
		printf("string[%d]",i+1);
		getchar();
		scanf("%[^n]s",string[i]);
	}
	
	for (i=0;i < n;i++){
		printf("[%2d]:%s\n",string[i]);
	}
	return 0;
}