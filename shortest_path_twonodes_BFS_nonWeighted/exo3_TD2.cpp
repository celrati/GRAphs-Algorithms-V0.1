#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define nil -1
#define infinity 1 << 9

using namespace std;

class Graph{
	int S;
	vector<int> * adj_list;
	string * Couleur;
	int * Pi;
	int * Dist; 
public:
	Graph(int S);
	void add_edge(int u,int v);
	void BFS(int s);
	int shortestPath(int a,int b);
};
Graph::Graph(int S){
	this->S= S;
	adj_list = new vector<int>[S];
	Couleur  = new string[S];
	Pi       = new int[S];
	Dist     = new int[S];
}
void Graph::add_edge(int u,int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

void Graph::BFS(int s){
	for(int i=0;i <this->S ;i++){
		Couleur[i] = "blanc";
		Pi[i]      = nil;  // -1 comme nil
		Dist[i]    =  infinity; // infinity
	}
	Couleur[s] = "gris";
	Pi[s]      = nil; 
	Dist[s]    = 0;
	queue<int> F;
	F.push(s);
	vector<int>::iterator i;

	while(!F.empty()){
		int x = F.front();
		F.pop();
		// testing
	//	cout<<x<<" ";

		for(  i= adj_list[x].begin() ; i != adj_list[x].end() ; i++ ){
			int y = *i;
			
			if( Couleur[y] == "blanc" ){
				Couleur[y] = "gris";
				Dist[y]    = Dist[x] + 1;
				Pi[y]      = x;
				F.push(y);
			}
		}
		Couleur[x] = "noir";
	}


}

int Graph::shortestPath(int a,int b){
	BFS(a);
	return Dist[b];
}


int main(){


	freopen("exo3_stdin", "r", stdin);
	int S; cin>>S;
	Graph G(S);
	int A; cin>>A;
	while(A--) {
		int u,v; cin>>u>>v;
		G.add_edge(u,v);
	}
	//G.BFS(2);
	cout<<G.shortestPath(5,6);
	




	return 0;
}