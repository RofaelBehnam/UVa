#include<stdio.h>
#include<stdlib.h>
typedef struct edge E;
struct edge{
		long long f,t,w;
		bool heavyCycle;
};
int cmp(const void *a, const void *b){
	return ((E*)a)->w-((E*)b)->w;
}
int V, e, parent[1000];
E list[25000];
long long w;
int getParent(int i){
	if(parent[i]==i)
		return i;
	return parent[i]=getParent(parent[i]);
}
bool first;
int main(){
	scanf("%d%d", &V, &e);
	while(V||e){
		for(int i=0;i<e;i++){
			scanf("%lld%lld%lld",&list[i].f, &list[i].t, &list[i].w);
			list[i].heavyCycle=false;
		}
		qsort(list,e,sizeof(E),&cmp);
		for(int i=0;i<V;i++){
			parent[i]=i;
		}
		w=0;
		int i=0,d=0;
		while(d<V-1 && i<e){
			if(getParent(list[i].f)!=getParent(list[i].t)){
				d++;
				parent[getParent(list[i].f)]=getParent(list[i].t);
				w+=list[i].w;
				list[i].heavyCycle=true;
			}
			i++;
		}
		first=true;
		for(i=0;i<e;i++){
			if(!list[i].heavyCycle){
				if(first){
					printf("%lld",list[i].w);
					first=false;
				}else
					printf(" %lld", list[i].w);
			}
		}
		if(first){
			printf("forest");
		}
		printf("\n");
		scanf("%d%d", &V, &e);
	}
	return 0;
}
