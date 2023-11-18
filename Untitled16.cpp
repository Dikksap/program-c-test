#include <stdio.h>
int main (){
    int nilai,jumlah_siswa,siswa,a;
    char nama;

    printf("masukan jumlah siswa :");
    scanf("%d",&jumlah_siswa);
    
    for(int i=0;i < jumlah_siswa;i++){}
    
    
    	for(a=0;a< jumlah_siswa;a++){
		
    	printf("siswa ke %d \n",a+1);
    	printf("nama : \n");
    	scanf("%s",&nama);
    	printf("nilai : \n");
    	scanf("%i",&nilai);
    	printf("kelulusan: \n\n");
	}
    return 0;
}