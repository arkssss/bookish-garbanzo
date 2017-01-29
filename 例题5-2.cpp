#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 30;

int n;

vector<int> pile[Maxn];  

//Ӧ����3���������� 

//Ѱ��block��λ�� ����p h 
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

//���(p.h)�Ϸ�������block �����仹ԭ 
void clear_over(int p,int h){
	int t;
	for(int i=h+1;i<pile[p].size();i++){
		t=pile[p][i];
		pile[t].push_back(t);
	}

	pile[p].resize(h+1);
	
}


//��pa,ha���������ϵ�����block�ƶ���pb�� 
void move_to(int pa,int ha,int pb){
	

	for(int i=ha;i<pile[pa].size();i++){
				
			pile[pb].push_back(pile[pa][i]);
				
	}
	pile[pa].resize(ha);
}

//��ӡ���� 
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
	//����������bock 
	int a,b;
	//������ָ�� 
	string s1,s2;
	
	while(cin>>s1>>a>>s2>>b){
		
		int pa,ha,pb,hb;
	
		find_block(a,pa,ha);	
		find_block(b,pb,hb);
	
		//�Ƿ�	
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
