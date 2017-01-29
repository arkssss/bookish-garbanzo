#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[]={"not a palindrome","a regular palindrome","amirroed string","a mirrored palimdmore"};
char r(char ch){
	if(isalpha(ch)) return rev[ch-'A'];
	
		return rev[ch-'1'+26];
			
	
}

int main (){
	
	char s[30];
	while(scanf("%s",s)==1){
		int len=strlen(s);
		int p=1,m=1;
		for (int i=0;i<(len+1)/2;i++){
				if(p && s[i]!=s[len-i-1]){
					p=0;
				}
				if(m && r(s[i])!=s[len-i-1]){
					m=0;
				}
					
		}		
		printf("%s -- is %s",s,msg[p+2*m]);
	}
	

	return 0;

}
