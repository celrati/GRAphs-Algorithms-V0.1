#include <iostream>
#include <vector>
#include <stdio.h>
#define nil -1

using namespace std;
class Graph{
	int S;
	vector<int> * list_adj;
	string * Couleur;
	int * d;
	int * f;
	int * Pi;
	int temps;
public:
	Graph(int S);
	void add_edge(int u,int v);
	void PP(int s);
	void PPC();


};
Graph::Graph(int S){
		this->S = S;
		list_adj = new vector<int>[S];
		Couleur  = new string[S];
		d        = new int[S];
		f        = new int[S];
		Pi       = new int[S];
		temps = 0;
		for(int x=0;x<S;x++){
		Couleur[x] = "blanc";
		Pi[x] = nil;
	}
	}
void Graph::add_edge(int u,int v){
	list_adj[u].push_back(v);
}
void Graph::PP(int s){
	Couleur[s] = "gris";
	// testing 
	cout<<s<<" ";
	temps++;
	d[s] = temps;
	vector<int>::iterator i;
	for(i = list_adj[s].begin() ; i != list_adj[s].end() ; i++){
		int u = *i;
		if(Couleur[u] == "blanc"){
			Pi[u] = s;
			PP(u);
		}
	}
	Couleur[s] = "noir";
	temps++;
	f[s] = temps;

}
void Graph::PPC(){
	for(int x=0;x<S;x++){
		Couleur[x] = "blanc";
		Pi[x] = nil;
	}
	temps = 0;
	for(int x=0;x<S;x++){
		if(Couleur[x] == "blanc"){
			PP(x);
		}
	}





}



int main(){

	freopen("dfs_stdin", "r", stdin);
	int S; cin>>S;
	Graph G(S);
	int A; cin>>A;
	while(A--) {
		int u,v; cin>>u>>v;
		G.add_edge(u,v);
	}
	
	//G.PPC();
	G.PP(2);




	return 0;
}

