#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
int T, v,e, i, j, x, y, d;
bool G[200][200], done=false;
queue<int> BFS;
vector<vector<int> > adjList;

int node;
int color[200];
int count[2];
bool isBipartite;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &v, &e);
		for(i=0;i<v;i++){
			color[i]=10;
		}
		adjList.resize(v);
		for(i=0;i<e;i++){
			scanf("%d%d", &x, &y);
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		//check Bipartite
		int ret=0;
		isBipartite =true;
		for(int j=0;j<v;j++){
			if(color[j]==10){
				count[0]=count[1]=0;
				BFS.push(j);
				color[j]=1;
				count[1]=1;
				while(!BFS.empty()){
					node = BFS.front();
					BFS.pop();
					for(i=0;i<adjList[node].size();i++){
						if(color[adjList[node][i]]==10){
							color[adjList[node][i]]=1-color[node];
							count[1-color[node]]++;
							BFS.push(adjList[node][i]);
						}else{
							if(color[adjList[node][i]]==color[node]){
								isBipartite=false;
							}
						}
					}
				}
				if(count[0]==0)
					ret+=count[1];
				else{
					if(count[1]==0)
						ret+=count[0];
					else
						ret+=count[0]<count[1]?count[0]:count[1];
				}
			}
		}

		if(isBipartite)
			printf("%d\n",ret);
		else
			printf("-1\n");
		adjList.clear();
	}
	return 0;
}
