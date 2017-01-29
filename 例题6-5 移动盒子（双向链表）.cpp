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

//���������ڵ� 
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
	
	//�˲���֮�������ֻ����X��Y����ߵ���� ���Բ��� 
	if(op==3 && Right[Y]==X) swap(X,Y);
	//�ڷ�ת����֮�� ����1 �Ͳ��� 2 ���� ������3�ޱ仯 		
	if(op!=3 && inv) op=3-op;
	//��Ч���� 
	if(op==1 && Left[Y]==X) continue;
	//��Ч���� 
	if(op==2 && Right[Y]==X) continue;

	//��ʼ���� 
	
	int LX=Left[X],RX=Right[X],LY=Left[Y],RY=Right[Y];
	//��X�Ƶ�Y����� 
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
