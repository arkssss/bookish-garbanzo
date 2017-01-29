#include <stdio.h>
#include <string.h> 
int main (){
	double mass[]={12.01,1.008,16.00,14.01};
	//0 C ,1 H ,O 2,N 3
	int molar[5];
	memset(molar,0,sizeof(molar));
    char temp;
    int rev;
	double tot;
	while(scanf("%c",&temp)==1 && temp!='\n'){
		switch (temp) {
			case 'C' :
				molar[0]++;
				rev=0;
				break;

			case 'H' :
				molar[1]++;
				rev=1;
				break;	
				
 			case 'O' :
				molar[2]++;
				rev=2;
				break;
			case 'N' :
				molar[3]++;
				rev=3;
				break;
			default:
				molar[rev]+=temp-'1';
				break;

	 	}
		

	}


		for(int i=0;i<4;i++){
		
			tot+=mass[i]*molar[i];
		}	
		
		printf("%.3fg/mol",tot);


} 
