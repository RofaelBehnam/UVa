#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
#include<map>
#include<vector>
using namespace std;
map<string , vector<string> > adjList;
map<string , vector<string> >::iterator it;
map<string, int> vis;
queue<string> BFS;
bool ans;
string word;
int main(){
	int T;
	int diff;
	cin >> T;
	while(T--){
		adjList.clear();
		cin >> word;
		while(word!="*"){
			adjList[word];
			vis[word]=0;
			for(it=adjList.begin();it!=adjList.end();it++){
				if((*it).first.size()==word.size()){
					diff=0;
					for(int i=0;i<word.size();i++){
						if(word[i]!=(*it).first[i]){
							diff++;
						}
					}
					if(diff==1){
						adjList[word].push_back((*it).first);
						adjList[(*it).first].push_back(word);
					}
				}
			}
			cin >> word;
		}
		string start, to, line;
		getline(cin, line);
		getline(cin, line);
		while(line!=""){
			size_t pos=line.find(" ");
			to=line.substr(pos+1, line.size());
			start=line.substr(0, pos);
			ans=false;
			BFS.push(start);
			vis.clear();
			vis[start]=0;
			while(!BFS.empty()){
				if(BFS.front()==to){
					ans=true;
					cout << start << " "<< to << " " << vis[to] << endl;
				}
				for(int i=0;i<adjList[BFS.front()].size()&&!ans;i++){
					if(vis[adjList[BFS.front()][i]]==0){
						BFS.push(adjList[BFS.front()][i]);
						vis[adjList[BFS.front()][i]]=vis[BFS.front()]+1;
					}
				}
				BFS.pop();
			}
			if(!getline(cin,line))
			     break;

		}
		if(T!=0)
			cout<< endl;
	}
	return 0;
}
