#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#define nil -1
#define infinity 1 << 9

using namespace std;


class Graph{
	int S;
	vector<int> * list_adj;
	string * Couleur;
	int * Pi;
	int * Dist;
public:
	Graph(int S);
	void add_edge(int u,int v);
	void BFS(int s);
	void find_connected_components();

};

Graph::Graph(int S){
	this->S = S;
	list_adj = new vector<int>[S];
	Couleur  = new string[S];
	Pi       = new int[S];
	Dist     = new int[S];
	for(int i=0;i<S;i++) Couleur[i]="blanc";
}
void Graph::add_edge(int u,int v){
	list_adj[u].push_back(v);
	list_adj[v].push_back(u); // non orienté
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
		cout<<x<<" ";

		for(  i= list_adj[x].begin() ; i != list_adj[x].end() ; i++ ){
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
	cout<<endl;


}
void Graph::find_connected_components(){
	for(int i=0; i<S ; i++){
		if(Couleur[i] == "blanc"){
			BFS(i);
		}
	}
}




int main(){

	// we are gonna use  bfs to find the CC's
	freopen("cc_stdin", "r", stdin);
	int S; cin>>S;
	Graph G(S);
	int A; cin>>A;
	while(A--) {
		int u,v; cin>>u>>v;
		G.add_edge(u,v);
	}
	
//	G.BFS(0);
	G.find_connected_components();







	return 0;
}