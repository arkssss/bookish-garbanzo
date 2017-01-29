#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 30;

int n;

vector<int> pile[Maxn];  

//应该有3个操作函数 

//寻找block的位置 存入p h 
void find_block(int a,int& p,int& h){

	for(int i=0;i<n;i++){
		for(int j=0;j<pile[i].size();j++){
			if(pile[i][j]==a){
				p=i;h=j;
				return;
			}
		}
	}	

}

//清除(p.h)上方的所有block 并将其还原 
void clear_over(int p,int h){
	int t;
	for(int i=h+1;i<pile[p].size();i++){
		t=pile[p][i];
		pile[t].push_back(t);
	}

	pile[p].resize(h+1);
	
}


//将pa,ha包括其以上的所有block移动到pb上 
void move_to(int pa,int ha,int pb){
	

	for(int i=ha;i<pile[pa].size();i++){
				
			pile[pb].push_back(pile[pa][i]);
				
	}
	pile[pa].resize(ha);
}

//打印函数 
void print(){
	

	for (int i=0;i<n;i++){
		
		int size=pile[i].size();
	
		cout<<i<<':'<<' '; 

		for(int j=0;j<size;j++){

		cout<<pile[i][j]<<' ';								
		
		}

		cout<<'\n';
		
	} 

}

int main (){

	cin>>n;
	for(int i=0;i<n;i++){
		pile[i].push_back(i);
	}	
	//操作的两个bock 
	int a,b;
	//操作的指令 
	string s1,s2;
	
	while(cin>>s1>>a>>s2>>b){
		
		int pa,ha,pb,hb;
	
		find_block(a,pa,ha);	
		find_block(b,pb,hb);
	
		//非法	
		if(pa==pb){
	
			continue;
		}		

		if(s1=="move"){
			clear_over(pa,ha);		
		}
		if(s2=="onto"){
			clear_over(pb,hb);
		}
		
		move_to(pa,ha,pb);
		
	}	

	print();

	return 0;

}
