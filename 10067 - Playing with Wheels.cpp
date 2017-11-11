#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
queue<int> BFS;
int forbidden[10000];
int initial[4], target[4], inti=0, targ=0, n, forbid,tmp, x,xx,xxx,xxxx;
bool done = false;
int main(){
	freopen("q.in", "r", stdin);
	int T;
	cin >> T;
	while(T--){
		done = false;
		for(int i=0;i<10000;i++){
			forbidden[i]=0;
		}
		 inti=0;
		 targ=0;
		for(int i=0;i<4;i++){
			cin >> initial[i];
			inti*=10;
			inti+=initial[i];
		}
		for(int i=0;i<4;i++){
			cin >> target[i];
			targ*=10;
			targ+=target[i];
		}
		forbidden[inti]=0;
		cin >> n;
		while(n--){
			forbid=0;
			for(int i=0;i<4;i++){
				cin >> tmp;
				forbid*=10;
				forbid+=tmp;
			}
			forbidden[forbid]=100;
		}
		BFS.push(inti);
		while(!BFS.empty()){
			tmp=BFS.front();
			int q=tmp;
			if(tmp==targ){
				cout << forbidden[tmp] << endl;
				done = true;
			}
			if(!done){
				x=tmp%10;
				tmp/=10;
				xx=tmp%10;
				tmp/=10;
				xxx=tmp%10;
				tmp/=10;
				xxxx=tmp%10;
				tmp/=10;

				if(x==0){
					tmp=xxxx*1000+xxx*100+xx*10+9;
				}else{
					tmp=xxxx*1000+xxx*100+xx*10+(x-1)%10;
				}
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}

				tmp=xxxx*1000+xxx*100+xx*10+(x+1)%10;
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}
				//**********************************************************************
				if(xx==0){
					tmp=xxxx*1000+xxx*100+9*10+x;
				}else{
					tmp=xxxx*1000+xxx*100+(xx-1)%10*10+x;
				}
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}

				tmp=xxxx*1000+xxx*100+(xx+1)%10*10+x;
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}

				//**********************************************************************
				if(xxx==0){
					tmp=xxxx*1000+9*100+xx*10+x;
				}else{
					tmp=xxxx*1000+(xxx-1)%10*100+xx*10+x;
				}
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}

				tmp=xxxx*1000+(xxx+1)%10*100+xx*10+x;
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}
				//**********************************************************************
				if(xxxx==0){
					tmp=9*1000+xxx*100+xx*10+x;
				}else{
					tmp=(xxxx-1)%10*1000+xxx*100+xx*10+x;
				}
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}

				tmp=(xxxx+1)%10*1000+xxx*100+xx*10+x;
				if(forbidden[tmp]==0){
					forbidden[tmp] = forbidden[q]+1;
					BFS.push(tmp);
				}
			}
			BFS.pop();
		}
		if(!done)
			cout << "-1" << endl;
	}
	return 0;
}
