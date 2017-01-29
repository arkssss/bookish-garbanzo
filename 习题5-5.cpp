/*
a
alien
born
less
lien
never
nevertheless
new
newborn
the
zebra*/
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
int main (){
		
	//freopen("input.txt","r",stdin);
	
//key为单词首字母 value为单词 总dictionary 
map<char,set<string> >dict;
//首字母的dictionary 
set<char> HeadLetter;
char head;
string s;

while (cin>>s){

	head=s[0];
	HeadLetter.insert(head);
	dict[head].insert(s);

}
//遍历首字母 
for(set<char>::iterator it=HeadLetter.begin();it!=HeadLetter.end();it++){
		
	head=*it;
	
	//反向遍历dict[head] 因为前面的才有可能为后面的一部分 
	for(set<string>::reverse_iterator it1=dict[head].rbegin();it1!=dict[head].rend();it1++){
		
			
			for(set<string>::iterator it2=dict[head].begin();it2!=dict[head].find(*it1);it2++){

				string tmps1=*it1;	
				string tmps2=*it2;
				int tmps2Size=tmps2.length();
				//说明在首位  

				if(tmps1.find(tmps2)==0){
					//tmps1在tmps2中间 此时找到截止于哪一点
					string NextWord=tmps1.substr(tmps2Size);

					//此时在dict里面找第二个字符
					//先找头 
					char NextHead=NextWord[0];
					//说明存在					
					if(dict[NextHead].count(NextWord)){

						cout<<tmps1<<endl;	
						break;

					}
					
				}

			}

	}
	 
	

} 



	return 0;
	
	
} 
