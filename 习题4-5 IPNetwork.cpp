#include <stdio.h>
#include <string.h> 
#define SizeFordecode 15
#define SizeForincode 35 
int tempincode[SizeForincode];
int Fitcode[5];

int decode(int a){
	
		int sum=0;
	for(int i=7;i<=0;i--){
	
		sum+=1<<i;

		if(sum<=a){	

			return sum;
	
	}
			
			}


}



int main (){
	
	int number,count=0,flag=3,flag2=7,max=0;
	scanf("%d",&number);

	//此数组用于存放读取的十进制ip 
	char TempNetwork[SizeFordecode];
	
	char tempcode[5];
		
	memset(tempcode,0,sizeof(tempcode));
	memset(TempNetwork,0,sizeof(TempNetwork));

	while(count<number){

		if(!count){
	
		scanf("%d.%d.%d.%d",&Fitcode[0],&Fitcode[1],&Fitcode[2],&Fitcode[3]);
			}else{
		

		scanf("%d.%d.%d.%d",&tempcode[0],&tempcode[1],&tempcode[2],&tempcode[3]);

		
		for(int i=0;i<=flag;i++){
			
			if(Fitcode[i]>tempcode[i] && !count) {
		
				Fitcode[i]=tempcode[i];
				
				flag=i;	
				
					}
		
			if(i==flag){
								
			} 



					}
		}
			count++;

				}
			
	

		//后位全部清理 
		for(int i=flag+1;i<4;i++){
			Fitcode[flag]=0;
		}


		Fitcode[flag]=decode(Fitcode[flag]);


		for(int i=0;i<4;i++){
			
				if(i<3){
				
				printf("%d.",Fitcode[i]);
			}else{
		
				printf("%d",Fitcode[i]);
			}


}


			
			}
