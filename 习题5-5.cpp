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
	
//keyΪ��������ĸ valueΪ���� ��dictionary 
map<char,set<string> >dict;
//����ĸ��dictionary 
set<char> HeadLetter;
char head;
string s;

while (cin>>s){

	head=s[0];
	HeadLetter.insert(head);
	dict[head].insert(s);

}
//��������ĸ 
for(set<char>::iterator it=HeadLetter.begin();it!=HeadLetter.end();it++){
		
	head=*it;
	
	//�������dict[head] ��Ϊǰ��Ĳ��п���Ϊ�����һ���� 
	for(set<string>::reverse_iterator it1=dict[head].rbegin();it1!=dict[head].rend();it1++){
		
			
			for(set<string>::iterator it2=dict[head].begin();it2!=dict[head].find(*it1);it2++){

				string tmps1=*it1;	
				string tmps2=*it2;
				int tmps2Size=tmps2.length();
				//˵������λ  

				if(tmps1.find(tmps2)==0){
					//tmps1��tmps2�м� ��ʱ�ҵ���ֹ����һ��
					string NextWord=tmps1.substr(tmps2Size);

					//��ʱ��dict�����ҵڶ����ַ�
					//����ͷ 
					char NextHead=NextWord[0];
					//˵������					
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
