#include<bits/stdc++.h>
using namespace std;
char a[10010];
int cnt=0;
int cnt2=0;
struct tree{
	char c;
	tree*l;
	tree*r;	
};
tree*root=NULL;
int main(){
	char c;
	while((c=getchar())!='\n'){
		if(c==' ')
			continue;
		a[++cnt] = c;
	}
	vector<vector<int> > v;
	deque<tree*> q;
	root->c = getchar();
	q.push_back(a[++cnt2]);
	int count = 1;
		while (!q.empty())
		{
			int size = q.size();
			vector<int> tmp;
			if (count % 2 == 0)
			{
				while(size--)
				{
					tree* back = q.back();
					tmp.push_back(back->c);
					q.pop_back();
 
					if (back->r)
						q.push_front(back->r);
 
					if (back->l)
						q.push_front(back->l);
					
				}
			}
			else
			{
				while (size--)
				{
					tree* front = q.front();
					tmp.push_back(front->c);
					q.pop_front();
					if (front->l)
						q.push_back(front->l);
					if (front->r)
						q.push_back(front->r);
				}
			}
			count++;
			v.push_back(tmp);
		}
	for(int i =0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
	}
	return 0;
}
