/*
"The Canterbury Tales" by Chaucer, G.
"The Canterbury Taless" by Chaucer, B.
"Algorithms" by Sedgewick, R.
"The C Programming Language" by Kernighan, B. and Ritchiee, D.
"The C Programming Languag" by Kernighan, B. and Ritchiee, D.
"The D Programming Language" by Kernighan, B. and Ritchiee, D.
"A House for Mr. Biswas" by Naipaul, V.S.
"A Congo Diary" by Naipaul, V.S.
END
BORROW "Algorithms"
BORROW "The C Programming Language"
BORROW "The C Programming Languag"
BORROW "The Canterbury Taless"
SHELVE
RETURN "Algorithms"
SHELVE
RETURN "The C Programming Languag"
SHELVE
BORROW "The C Programming Languag"
BORROW "The Canterbury Taless"
BORROW "A House for Mr. Biswas"
RETURN "The Canterbury Taless"
SHELVE
RETURN "The C Programming Language"
RETURN "A House for Mr. Biswas"
SHELVE
END
*/ 
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;


struct Book{
	
	string Title,Author;	
	bool operator < (const Book & coo) const{
		
		return Author<coo.Author || (Author==coo.Author && Title<coo.Title);	
	
	}


};

//用于分割字符 
void SpiltChar(const string & s,string & Title, string & Author){
	
	string tmps;
	int k=s.find_last_of('\"');
	Title=s.substr(0,k+1);
	tmps=s.substr(k+1);	
	int p=tmps.find("by");
	Author=tmps.substr(p+3);					
	

}


void SpiltChar2(const string & s,string & Comman ,string & Title){

		int k=s.find(' ');
		Comman=s.substr(0,k);		
		Title=s.substr(k+1);
}


int main (){
	
//	freopen("i.txt","r",stdin);
//	freopen("o.txt","w",stdout);	

	//书本放置容器 
	set<Book> dict;
	//存放借出书的信息 
	map <string,string> dict1;
	//返还队列 
	set<Book> RE;

	Book tmp;
	string line,tmpTitle,tmpAuthor;
	while(getline(cin,line)&& line!="END"){
		
		SpiltChar(line,tmpTitle,tmpAuthor);
		tmp.Title=tmpTitle;tmp.Author=tmpAuthor;
		dict1[tmpTitle]=tmpAuthor;
		dict.insert(tmp);
	}
	
	string Command,BookTitle;
	set<Book>::iterator it;

	while(getline(cin,line)){
	
		SpiltChar2(line,Command,BookTitle);
		if(Command=="END") break;
		tmp.Title=BookTitle; 
		tmp.Author=dict1[BookTitle];
		switch(Command[0]){

			//借 书本信息存入map dict删除s 
			case 'B':{
	
				dict.erase(tmp);
				
				break;
			}
			//还 书本信息存入queue 对应的map删除 
			case 'R':{
	
				RE.insert(tmp);

				break;
			}
			//整理	
			case 'S':{
			
				for(set<Book>::iterator k=RE.begin();k!=RE.end();k++){
					tmp=(*k);
					dict.insert(tmp);
					it=dict.find(tmp);
					set<Book>::reverse_iterator it2(it);
					if(it2==dict.rend()){
						cout<<"Put "<<tmp.Title<<" first"<<endl;
					}else{

					cout<<"Put "<<tmp.Title<<" after "<<(*it2).Title<<endl;
					}
					RE.erase(k); 
				}
				cout<<"END"<<endl;
				break;
			}
			
		}		

	} 

	
	return 0;
}



















