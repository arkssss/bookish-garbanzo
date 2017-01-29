#include <stdio.h>
#include <string.h>
int main (){
	
	int m,n,row=0,len,record=0,min=0,newrow_record=0,count=0;
	scanf("%d%d",&m,&n);
	char DNA[m+5][n+5],temp;
	int same[100];
	memset(same,0,sizeof(same));
		
	while(row<m){
				
			//获取一行一行的输入 
			while(scanf("%s",DNA[row])==1){

				len=strlen(DNA[row]);
				//判断输入是否大于要求 
				if(len!=n){
					printf("输入不符合要求\n");
					continue;
					}
					else{
					break;
				}
			}		


		//如果是第一次输入，则跳过，因为需要比较 
			if(!row){
				row++;
				continue;
			
			}else if(row==1){
	
				for(int i=0;i<n;i++){
					if(DNA[0][i]==DNA[1][i]){
						record++;
					} 
				}	
				min=0;
				same[count++]=min;		
				row++;
				//此时已有前两项的HAMMING record ;剩下的只需要用record+new_row && nwe_row 需要与之上所有ROW hanmming  
			}else{
				

				//先得到min 与new_row 的hamming
				for(int i=0;i<n;i++){
					if(DNA[min][i]==DNA[row][i])
						{
							record++;
						}
				} 
			
				//后得到 new_row 与之前所有row 的hanmming
				for(int i=row-1;i>=0;i--){
					for(int j=0;j<n;j++){
						if(DNA[row][j]==DNA[i][j]){
							newrow_record++;	
						}
					}							
				} 

				//最后比较 取record小的 
					  if(record>newrow_record){
							record=newrow_record;
							min=row;
							memset(same,0,sizeof(same));	
							count=0;
							same[count++]=min;
					  }else if(record==newrow_record){
							//如果有相等的情况 则存入same数组里面 
							same[count++]=row;
					  }

					newrow_record=0;
					row++;
			}						
			
	}	

				 for(int i=0;i<count;i++){
					row=same[i];
					printf("%s\n",DNA[row]);
				 }




} 
