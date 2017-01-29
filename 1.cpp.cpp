#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1000;
char s[maxn];

struct Node{
	
	int value;
	bool have_value;
	Node *left,*right;	
	Node():have_value(false),left(NULL),right(NULL){}; //构造函数 

};

//root 为根节点 
 Node* root;

//申请新节的操作封装 new函数代替malloc 
Node* newnode(){
	return new Node();
}

bool failed;

void addnode(int v,char *st){
	
	int n=strlen(st);
	Node * u=root;
	for(int i=0;i<n;i++){
	
		if(st[i]=='L'){
	
			if(u->left==NULL) u->left=newnode();
			u=u->left;
		}
		else if(st[i]=='R'){
			if(u->right==NULL) u->right=newnode();
			u=u->right;

		}	
				
	}	

	if(u->have_value) failed=true;
	u->value=v;
	u->have_value=true;

}



bool read_input(){
	
  bool failed=false;
  root = newnode();
  for(;;){
	
		if(scanf("%s",s)!=1) return false; //输入结束 
		if(!strcmp(s,"()")) break; //结束标志
		int v;
		sscanf(&s[1],"%d",&v); 
		addnode(v,strchr(s,',')+1);

  }

	return true;
}

//释放二叉树的代码 
void remove_node(Node * u){
	if(u==NULL) return; 
	remove_node(u->left);
	remove_node(u->right);
	delete u;
}


   //BFS 队列实现的遍历算法 
bool bfs(vector<int> & ans){
	
	queue<Node *> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		Node* u=q.front();
		q.pop();
		if(!u->have_value) return false;
		ans.push_back(u->value);
		if(u->left !=NULL) q.push(u->left);
		if(u->right !=NULL) q.push(u->right); 
	}	

}


int main (){
	
	freopen("i.txt","r",stdin);
	read_input(); 
	vector<int> ans;	
	if(failed) cout<<"error";	
	bfs(ans);	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}		
	remove_node(root);

}










 
