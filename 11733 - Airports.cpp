#include<stdio.h>
#include<stdlib.h>
typedef struct edge E;
struct edge{
		long long f,t,w;
};
int cmp(const void *a, const void *b){
	return ((E*)a)->w-((E*)b)->w;
}
long long V, e, w,airport, cost, parent[100001];
E list[100001];
int getParent(int i){
	if(parent[i]==i)
		return i;
	return parent[i]=getParent(parent[i]);
}
int main(){
	int T;
	int counter=0;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%lld", &V, &e, &w);
		airport=0;
		cost=0;
		for(int i=0;i<e;i++){
			scanf("%lld%lld%lld",&list[i].f, &list[i].t, &list[i].w);
		}
		qsort(list,e,sizeof(E),&cmp);
		for(int i=0;i<=V;i++){
			parent[i]=i;
		}
		long long i=0,d=0;
		while(d<V-1 && i<e){
			if(getParent(list[i].f)!=getParent(list[i].t) && list[i].w<w){
				d++;
				parent[getParent(list[i].f)]=getParent(list[i].t);
				cost+=list[i].w;
			}
			i++;
		}
		for(i=1;i<=V;i++){
			cost+=w*(parent[i]==i);
			airport+=(parent[i]==i);
		}
		counter++;
		printf("Case #%d: %lld %lld\n", counter,cost, airport);
	}
	return 0;
}

