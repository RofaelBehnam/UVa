#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
vector<string> words[20];
int parent[30000];
queue<int> BFS;
bool first=true,ans;
int i,j;
int main(){
	string word;
	getline(cin, word);
	while(word!=""){
		words[word.size()].push_back(word);
		if(!getline(cin, word))
			break;
	}
	string start, end;
	while(cin >> start >> end){
		if(!first)
			cout <<  endl;
		ans=false;
		for(i=0;i<words[start.size()].size()&&words[start.size()][i]!=end;i++);
		BFS.push(i);
		if(start.size()!=end.size()){
			BFS.pop();
		}
		for(i=0;i<words[start.size()].size();i++)
			parent[i]=-1;
		parent[BFS.front()]=-2;
		while(!BFS.empty()){
			if(!ans){
				if(words[start.size()][BFS.front()] == start){
					i=BFS.front();
					while(parent[i]!=-2){
						cout << words[start.size()][i] << endl;
						i=parent[i];
					}
					cout << end << endl;
					ans=true;
				}
				for(i=0;i<words[start.size()].size();i++){
					int diff = 0;
					for(j=0;j<start.size();j++){
						if(words[start.size()][BFS.front()][j]!=words[start.size()][i][j])
							diff++;
					}
					if(parent[i]==-1 && diff==1){
						parent[i]=BFS.front();
						BFS.push(i);
					}
				}
			}
			BFS.pop();
		}
		first=false;
		if(!ans)
			cout << "No solution." << endl;
	}
	return 0;
}
