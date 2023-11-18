#include<stdio.h>
void kelulusan(int nilai){
		
		if(nilai > 70){
			printf("kelulusan : LULUS");
		}else{
			printf("kelulusan : Tidak lulus");
		}
	}
int main(){
	int kelas[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int jum_kelas = sizeof(kelas)/sizeof(kelas[0]);
	char nama;
	int nilai;
	
	for(int i=0;i < 2;i++){
		printf("\nkelas %i : \n ",kelas[i]);
		printf("nama:\n ");
		scanf("%s",&nama);
		printf("nilai :\n");
		scanf("%i",&nilai);
		kelulusan(nilai);	
	}
	return 0;
}