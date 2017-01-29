#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <string>
#include <string.h> 
#include <sstream> 
const int maxn=105; 
using namespace std;

//过滤单词中的各种标点符号 
string ClearPun(string a){

	int size=a.size();
	char tmp,tmparr[size+5];
	memset(tmparr,0,sizeof(tmparr));
	for(int i=0,j=0;i<size;i++){
		tmp=a[i];
		if(!isalpha(tmp)) continue;
		tmparr[j++]=tolower(tmp);
	
	}
	string line(tmparr);
	return line;
	

}
//判断并分割命令行 
char SpiltString(string & item1,string & item2,const string line){
			
		int a=line.find('A');
		int o=line.find('R');
		int n=line.find('T');
		
	if(a!=string::npos){
	
		item1=line.substr(0,a-1);
		item2=line.substr(a+4);	
		return 'A';
	}
	else if(o!=string::npos){
	
		item1=line.substr(0,o-2);
		item2=line.substr(o+2);	

		return 'O';
	}
	else if(n!=string::npos){
		item1=line.substr(n+2);
		return 'N';
	}
	else{
	
		item1=line;	
		return 'K';

	}	



} 


int main (){

//	freopen("i.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	//用于存储每一行的输入的不定向数组	
	vector<string> dict[maxn];
	//用于存放每个单词与相应的行的对应关系
	map<string,vector<pair<int,int> > > mapping;	
	//n篇文章 cnt记录行数 
	int n,cnt=0,n2;	
	//此队列用于存储要打印的 
	set<pair<int,int> > LineToPr;
	set<int> LineToPeForN;
	cin>>n;	
	//去除首行的换行符号 
	char tmp;
	scanf("%c",&tmp);
	string tmpline,tmpword;
	for(int i=0;i<n;i++){
		while(getline(cin,tmpline)){
			if(tmpline=="**********") break;
			//每一行存入对应的vector里面 
			dict[i].push_back(tmpline);			
			stringstream ss(tmpline);
			while(ss>>tmpword){	
				tmpword=ClearPun(tmpword);	
				if(tmpword.empty()) continue;
				pair<int,int>tmppair(i,cnt);	
				mapping[tmpword].push_back(tmppair);
			}			

			cnt++;
		} 
		
			cnt=0;
		
		}

	
		//读入指令的个数 
		cin>>n2;
		scanf("%c",&tmp);
		string item1,item2;
		int art1,art2,tline=0;
		char Logic;
		for(int i=0;i<n2;i++){
			
			getline(cin,tmpline);


			LineToPr.clear();
			LineToPeForN.clear();

			switch(SpiltString(item1,item2,tmpline)){
	


				case 'A':{
				for(vector<pair<int,int> >::iterator it1=mapping[item1].begin();it1!=mapping[item1].end();it1++){
							art1=(*it1).first;
							
				for(vector<pair<int,int> >::iterator it2=mapping[item2].begin();it2!=mapping[item2].end();it2++){
							art2=(*it2).first;
		
						//存在	
							if(art1==art2){	

								LineToPr.insert(pair<int,int>(art1,(*it1).second));
								LineToPr.insert(pair<int,int>(art1,(*it2).second));

							}				

				}

				}
				
								
				if(LineToPr.size()){
	
					int changeline;
		
					for(set<pair<int,int> >::iterator it=LineToPr.begin();it!=LineToPr.end();it++){
		
						if(it==LineToPr.begin()){
					
							changeline=(*it).first;

					}else{
	
			
							if(changeline!=(*it).first){
								cout<<"---------"<<endl;
							}
							
								changeline=(*it).first;
					}

							
						cout<<dict[(*it).first][(*it).second]<<endl;						

	
					}


				}else{
	
					cout<<"Sorry, I found nothing."<<endl;

				} 

					cout<<"=========="<<endl;
				break; 



				}

				case 'O':{
	
				
				for(vector<pair<int,int> >::iterator it1=mapping[item1].begin();it1!=mapping[item1].end();it1++){
	
					LineToPr.insert(pair<int,int>((*it1).first,(*it1).second));

				} 			

				
				for(vector<pair<int,int> >::iterator it1=mapping[item2].begin();it1!=mapping[item2].end();it1++){
				
					LineToPr.insert(pair<int,int>((*it1).first,(*it1).second)) ;

				}
								
				if(LineToPr.size()){
	
					int changeline;
		
					for(set<pair<int,int> >::iterator it=LineToPr.begin();it!=LineToPr.end();it++){
	

		
						if(it==LineToPr.begin()){
					
							changeline=(*it).first;

					}else{
	
			
							if(changeline!=(*it).first){
								cout<<"---------"<<endl;
							}
							
								changeline=(*it).first;
					}

							
						cout<<dict[(*it).first][(*it).second]<<endl;						

	
					}


				}else{
	
					cout<<"Sorry, I found nothing."<<endl;

				} 
					cout<<"=========="<<endl;

				break;


				}

				case 'N':{
		

			for(vector<pair<int,int> >::iterator it=mapping[item1].begin();it!=mapping[item1].end();it++){
	
				LineToPeForN.insert((*it).first);

			}

				
			if(n==LineToPeForN.size()){
				cout<<"Sorry, I found nothing."<<endl;
				cout<<"=========="<<endl;
				break;
			}
			int left=n-LineToPeForN.size()-1;
			for(int i=0;i<n;i++){
	
				if(LineToPeForN.count(i)) {
					LineToPeForN.erase(i);
					continue;
				}

	
				int size=dict[i].size();
				for(int j=0;j<size;j++){
	
					cout<<dict[i][j]<<endl;

				} 
			
					if(left--)
						cout<<"---------"<<endl;
					}

					
	
	
					cout<<"=========="<<endl;

		
	
				break;
			}
				
				case 'K':{
	

			for(vector<pair<int,int> >::iterator it=mapping[item1].begin();it!=mapping[item1].end();it++){
	
				LineToPr.insert(pair<int,int>((*it).first,(*it).second));

					}		

			if(LineToPr.size()){
	
					int changeline;
		
					for(set<pair<int,int> >::iterator it=LineToPr.begin();it!=LineToPr.end();it++){
		
						if(it==LineToPr.begin()){
					
							changeline=(*it).first;

					}else{
	
			
							if(changeline!=(*it).first){
								cout<<"---------"<<endl;
							}
							
								changeline=(*it).first;
					}

							
						cout<<dict[(*it).first][(*it).second]<<endl;						

	
					}


				}else{
	
					cout<<"Sorry, I found nothing."<<endl;

				} 

					cout<<"=========="<<endl;
	

				break;
				}



			
			}	
		
		
			
	
		}


	


}






//	string a="protected";
//	
//	for(vector<pair<int,int> > ::iterator it=mapping[a].begin();it!=mapping[a].end();it++){
//			
//			cout<<(*it).first<<' '<<(*it).second<<'\n';	
//
//	}















 
