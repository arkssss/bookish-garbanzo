/*
6 4
1 1 4
2 3 5
3 1 6
4 
6 3
1 1 4
2 3 5
3 1 6
100000 1
4

*/

#include <cstdio>
#include <iostream>

using namespace std;
const int maxn=100000+5;
int Left[maxn],Right[maxn];

//链接两个节点 
void Link(int L,int R){
	
	Right[L]=R;
	Left[R]=L;

}

int main (){

	freopen("i.txt","r",stdin);

	int n,m,Kase=0;

	while(scanf("%d%d",&n,&m)==2){
	for(int i=1;i<=n;i++){

		Left[i]=i-1;
		Right[i]=(i+1)%(n+1);
	
	}	
	int inv=0,op,X,Y;
	Left[0]=n;Right[0]=1;
	
	while(m--){
	scanf("%d",&op);
	if(op==4) inv=!inv;
	else{
		scanf("%d%d",&X,&Y);
	
	//此步骤之后则可以只考虑X在Y的左边的情况 缩略步骤 
	if(op==3 && Right[Y]==X) swap(X,Y);
	//在反转链表之后 操作1 和操作 2 互逆 而操作3无变化 		
	if(op!=3 && inv) op=3-op;
	//无效操作 
	if(op==1 && Left[Y]==X) continue;
	//无效操作 
	if(op==2 && Right[Y]==X) continue;

	//开始操作 
	
	int LX=Left[X],RX=Right[X],LY=Left[Y],RY=Right[Y];
	//将X移到Y的左边 
	if(op==1){
		Link(LY,X);
		Link(X,Y);
		Link(LX,RX);
	}	
	else if(op==2){
		Link(LX,RX);
		Link(X,RY);
		Link(Y,X);
	}
 	else if(op==3){
	
		if(Left[Y]==X){
	
			Link(LX,Y);
			Link(Y,X);
			Link(X,RY);
		
		}else{

			Link(LX,Y);
			Link(Y,RX);
			Link(LY,X);
			Link(X,RY);
	
		}
			
		 	}
		
		}




	}	
	 int b=0;long long ans=0;
	for(int i=1;i<=n;i++){
		b=Right[b];	
		if(i%2==1) ans+=b;
	}
	
	if(inv && n%2==0) {
		ans=(long long)(1+n)*n/2-ans;
	}
 
	printf("Case %d: %lld\n",++Kase,ans);

}

	return 0;





}
