#include<stdio.h>
#include<unistd.h>
int main(){
	int kelas[12] = {1,2,3,4,5,6,7,8,9,10,12};
	
	for(int i=0;i < 11;i++){
		printf("kelas %d \n",kelas[i]);
		sleep(1);
	}
	return 0;
	
}