#include <cstdio>
#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

int main (){
// 	freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);  
	//∑≈÷√»›∆˜ 
	queue<int> card;
	vector<int> discard;

	int n;

	while(scanf("%d",&n)==1 && n){
	
	
	for(int i=1;i<=n;i++){

		card.push(i);				

	}	

	while(card.size()>1){
		
		int dis=card.front();
		discard.push_back(dis);
		card.pop();
		int Toop=card.front();
		card.pop();
		card.push(Toop);

	}

	
		
		int size=discard.size();
		cout<<"Discarded cards:";
		for(int k=0;k<size;k++){

			if(k==size-1){
				cout<<' '<<discard[k];
			}else{
			
				cout<<' '<<discard[k]<<',';
			}

		
		}
		
		cout<<"\nRemaining card: "<<card.front()<<endl;	
		
		discard.clear();	
		card.pop();
		
	}

} 
