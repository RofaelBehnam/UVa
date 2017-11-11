#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
long long parent[500];
int getParent(int i){
	return parent[i]==i?i:(parent[i]=getParent(parent[i]));
}

typedef struct edge E;
struct edge{
		int t,f;
		double w;
};
int cmp(const void *a, const void *b){
	if((*(E*)a).w<(*(E*)b).w)
	        return -1;
	    else
	        return 1;
}

int T, S, e, i, j, d;
int coordinates[500][2];
E edges[250000];
long long count, counter;
int main(){
	cin  >> T;
	while(T--){
		cin >> S >> e;
		counter=0;
		for(i=0;i<e;i++){
			cin >> coordinates[i][0] >> coordinates[i][1];
			parent[i]=i;
			for(j=0;j<i;j++){
				edges[counter].f=i;
				edges[counter].t=j;
				edges[counter].w=sqrt(pow(coordinates[i][0]-coordinates[j][0],2.0)+pow(coordinates[i][1]-coordinates[j][1],2.0));
				counter++;
			}
		}
		qsort(edges, counter,sizeof(E),&cmp);
		d=e;
		double ans=0;
		count=0;
		while(d>S&&count<counter){
			if(getParent(edges[count].f)!=getParent(edges[count].t)){
				d--;
				if(edges[count].w>ans)
					ans=edges[count].w;
				parent[getParent(edges[count].f)]=getParent(edges[count].t);
			}
			count++;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
