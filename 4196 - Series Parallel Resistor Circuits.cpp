#include <stdio.h>
#include<iostream>
using namespace std;
int N;
bool nodes[26];
char x,y;
int w;
double graph[26][26];
int node1, node2;
void CLR(){
	for(int i=0;i<26;i++){
		nodes[i]=false;
		for(int j=0;j<26;j++)
			graph[i][j]=0;
	}
}

void input(){
	for(int i=0;i<N;i++){
		cin>>x>>y>>w;
		node1=x-'A';
		node2=y-'A';
		nodes[node1]=nodes[node2]=true;
		if(graph[node1][node2]==0)
			graph[node1][node2]=graph[node2][node1]=w;
		else
			graph[node1][node2]=graph[node2][node1]=(graph[node1][node2]*w)/(graph[node1][node2]+w);
	}
}

void calc(){
	while(N--){
		for(int i=1;i<25;i++){
			if(nodes[i]){
				int x=-1,y=-1,count=0;
				for(int j=0;j<26;j++){
					if(graph[i][j]!=0){
						if(x==-1)
							x=j;
						else
							y=j;
						count++;
					}
				}
				if(count==2){
					double r = graph[x][i]+graph[i][y];
					if(graph[x][y]==0)
						graph[x][y]=graph[y][x]=r;
					else
						graph[x][y]=graph[y][x]=(graph[y][x]*r)/(graph[y][x]+r);
					graph[x][i]=graph[i][x]=graph[i][y]=graph[y][i]=0;
				}
			}
		}
	}
}

void output(){
	double ans=0;
	for(int i=0;i<26;i++){
		if(nodes[i]){
			for(int j=i+1;j<26;j++){
				if(nodes[j]){
					if(graph[i][j]!=0 && (i!=0 || j!=25))
						ans=-1;
				}
			}
		}
	}
	if(ans==0)
		ans=graph[0][25];
	printf("%.3lf\n", ans);
}
int main() {
	scanf("%d", &N);
	while(N!=0){
		CLR();
		input();
		calc();
		output();
		scanf("%d", &N);
	}
	return 0;
}
