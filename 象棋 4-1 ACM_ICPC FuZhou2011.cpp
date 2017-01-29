#include <stdio.h>
#include <string.h>
#define MaxnRow 11
#define MaxnClw 11 
int square[MaxnRow][MaxnClw];
// 1->G 2->R 3->H 4->C 0->None 9->Black_G

//判断某个车是否可以将军 
int R(int R,int C,int Black_G_Row,int Black_G_Clw){
		
	int max,min,Fit=1;
		
	//车和将军的列相等 
	if(C==Black_G_Clw){
		
		if(R<Black_G_Clw){	
			max=Black_G_Row;	
			min=R;
		}else{	
			max=R;
			min=Black_G_Row;
		}
		//判断中间有没有其他的棋子 
		for(int i=min+1;i<max;i++){
				
				//说明中间有其他棋子 
				if(square[i][C]){
								
					Fit=0;
					break;
				}

		}
		
			//条件满足	
		if(Fit){
		
			return 1;

		}else{	

			return 0;
		}
	
	}

		//车和将军的行相等 
	if(R==Black_G_Row){
		
		if(R<Black_G_Clw){	
			max=Black_G_Clw;	
			min=C;
		}else{	
			max=C;
			min=Black_G_Clw;
		}
		//判断中间有没有其他的棋子 
		for(int i=min+1;i<max;i++){
				
				//说明中间有其他棋子 
				if(square[i][C]){
								
					Fit=0;
					break;
				}

		}
		
			//条件满足	
		if(Fit){
		
			return 1;

		}else{	

			return 0;
		}
	
	}


	
	
}

//判断某个马是否可以将军 
int H(int R,int C,int Black_G_Row,int Black_G_Clw){
	
	int Fit=1;
	int R_Des=R-Black_G_Row,C_Des=C-Black_G_Clw;
	//Case 1
	if((R_Des==2 && C_Des==-1) || (R_Des==2 && C_Des==1)){
			
				//蹩脚马 
				if(square[R-1][C]){
					return 0;
				}else{	
					return 1;
				}
	
	}//Case 2
	else if( (R_Des==-1 && C_Des==2) || (R_Des==1 && C_Des==2)){	
			
				if(square[R][C-1]){	
					return 0;
				}else{
					return 1;
				}
	
	}
    //Case 3 
	else if((R_Des==-1 && C_Des==-2) || (R_Des==1 && C_Des==-2)){
	
				if(square[R+1][C]){
					return 0;
				}else{
					return 1;
				}

	}//Case 4 
	else if((R_Des==-2 && C_Des==-1) || (R_Des==-2 && C_Des==1)){
				if(square[R][C+1]){	
					return 0;
				}else{
					return 1;
				} 
	
	}else {
		
			return 0;

	}
	

	
}

//判断某个炮是否可以将军 
int C(int R,int C,int Black_G_Row,int Black_G_Clw){
			
	int max,min,count=0;
		
	//车和将军的列相等 
	if(C==Black_G_Clw){
		
		if(R<Black_G_Clw){	
			max=Black_G_Row;	
			min=R;
		}else{	
			max=R;
			min=Black_G_Row;
		}
		//判断中间是否有且只有一个其他的棋子 
		for(int i=min+1;i<max;i++){
				
				//说明中间有其他棋子 
				if(square[i][C]){
					count++;					
					}

		}
		
	}
		//车和将军的行相等 
	if(R==Black_G_Row){
		
		if(R<Black_G_Clw){	
			max=Black_G_Clw;	
			min=C;
		}else{	
			max=C;
			min=Black_G_Clw;
		}
		//判断中间是否有且只有一个其他的棋子 
		for(int i=min+1;i<max;i++){
			//说明中间有其他棋子 
				if(square[i][C]){
					count++;					
					}
		}		
	
	}

		if(count==1){
			return 1;
		}else{
			return 0;
		}	


}

//判断帅是否可以将军 
int G(int R,int C,int Black_G_Row,int Black_G_Clw){
	

	//红方将军和黑方将军的列相等 (只有可能列相等) 且C一定大于 Black_G_Clw
	if(C==Black_G_Clw){
		
		//判断中间有没有其他的棋子 
		for(int i=Black_G_Row+1;i<R;i++){
				
				//说明中间有其他棋子 
				if(square[i][C]){
								
					return 0;
				}

		}
		//循环执行完 中间无其他棋子，则条件满足 
		return 1;
		
	}

	return 0;


}

//测试打印棋局 
void PrintfSquare (){	
	for(int i=1;i<=10;i++){	
		for(int j=1;j<10;j++){	
			printf(" %d ",square[i][j]);
		}
		    printf("\n");
	}
}

int main (){

	int Number,Black_General_Row,Black_General_Clw;
	int Hourse[8];
	int RCar[8];
	int Cannon[8];
	int RedGen[4];
	int BlaGen[4];
	int Possible[10];
	memset(Hourse,0,sizeof(Hourse));
	memset(RCar,0,sizeof(RCar));
	memset(Cannon,0,sizeof(Cannon));
	memset(RedGen,0,sizeof(RedGen));
	memset(BlaGen,0,sizeof(BlaGen));
	memset(Possible,0,sizeof(Possible));
	while(scanf("%d%d%d",&Number,&Black_General_Row,&Black_General_Clw)==3 && Number!=0 ){
				
				//一局开始前先清零	
				memset(square,0,sizeof(square));
					
				//确定黑方将军位置 
				square[Black_General_Row][Black_General_Clw]=9;
				BlaGen[0]=Black_General_Row;
				BlaGen[1]=Black_General_Clw;
	
				int count=0,Temp_Row,Temp_Clw,countR=0,countH=0,countC=0; 
				char tempIndetify;
				while(count<Number){
						
						//消除换行符号 
					while((tempIndetify=getchar())=='\n'){	

							continue;	
						}

					scanf("%d%d",&Temp_Row,&Temp_Clw);
	
					switch(tempIndetify){
		
						case 'R':
							square[Temp_Row][Temp_Clw]=2;	
							RCar[countR++]=Temp_Row;	
							RCar[countR++]=Temp_Clw;
							break;		
						case 'H':
							square[Temp_Row][Temp_Clw]=3;	
							Hourse[countH++]=Temp_Row;	
							Hourse[countH++]=Temp_Clw;
							break;
						case 'C':
							square[Temp_Row][Temp_Clw]=4;	
							Cannon[countC++]=Temp_Row;	
							Cannon[countC++]=Temp_Clw;
							break;
						case 'G':
							square[Temp_Row][Temp_Clw]=1;	
							RedGen[0]=Temp_Row;
							RedGen[1]=Temp_Clw;
							break;
						default:	
							printf("Wrong");	
							break;				
	
					}		
					count++;
			

				}
			
			//这里开始做判断 先判断黑方将的几种可能 
			int countP=0;
			//将可以向左移动 
			if(BlaGen[1]-1>=4){
					
			    Possible[countP++]=BlaGen[0];	
		    	Possible[countP++]=BlaGen[1]-1;				
			
			}
			//将可以向右移 
		    if(BlaGen[1]+1<=6){
			
				Possible[countP++]=BlaGen[0];	
		    	Possible[countP++]=BlaGen[1]+1;	

		    }		
			//将可以向上移	
			if(BlaGen[0]-1>=1){
	
				Possible[countP++]=BlaGen[0]-1;	
		    	Possible[countP++]=BlaGen[1];	

			}	
			//将可以向下移 
			if(BlaGen[0]+1<=3){
		
				Possible[countP++]=BlaGen[0]+1;	
		    	Possible[countP++]=BlaGen[1];	

			}
		
			int GameOver=0;
		
			//这里已经取出所有的黑将可能性 
		  for(int i=0;i<count;i+=2){
				
					//判断与车的情况 
					for(int j=0;j<countR;j+=2){
							
						//不满足 
						if(!R(RCar[j],RCar[j+1],Possible[i],Possible[i+1])){
								GameOver=1;	
								break;							
						}
	
					}
					if(GameOver){
						break;
					}
					//判断与马的情况
					for(int j=0;j<countH;j+=2){
	
							//不满足 
						if(!H(Hourse[j],Hourse[j+1],Possible[i],Possible[i+1])){
								GameOver=1;	
								break;
						}
	
					}
					if(GameOver){
						break;
					}

					//判断与跑的情况 
					for(int j=0;j<countC;j+=2){
							//不满足 
						if(!C(Cannon[j],Cannon[j+1],Possible[i],Possible[i+1])){
							GameOver=1;	
								break;
						}
	
					}
					if(GameOver){
						break;
					}

			 		//判断与帅的情况 
					for(int j=0;j<2;j+=2){
							//不满足 
						if(!G(RedGen[j],RedGen[j+1],Possible[i],Possible[i+1])){
							GameOver=1;	
								break;
						}			

	
					}
					if(GameOver){
						break;
					}

		  }

				if(GameOver){	
				printf("No!\n");
				}else{
				printf("Yes!\n ");
				}

	}
	
	
}



