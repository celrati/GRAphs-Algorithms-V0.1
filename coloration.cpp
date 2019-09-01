/**
	algo to find the nombre chromatique sigma
	d'un graphe
**/

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Graph{
public:
	int size;
	vector<int> * listAdj;

	Graph(int s):size(s){
		this->listAdj = new vector<int>[s];
	}
	void addEdge(int u,int v){
		this->listAdj[u].push_back(v);
		this->listAdj[v].push_back(u);
	}
	int getSize(){
		return this->size;
	}
	int getDegreMaximal(){
		int c = 0;
		for(int i=0; i< size; i++){
			if(listAdj[i].size() > c) c = listAdj[i].size();
		}
		return c;
	}
};
/////////// debug
void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}
/////////////

bool finished = false;
void process_solution(int * a,int k,int n,Graph g,bool * ok){	
	*ok = true; 
	// print the solution
	//printf("the solution is \n");
	//debugArray(a,k);
}
bool is_a_solution(int * a,int k, int n, Graph g){
	bool ok = true;
	return (k == g.getSize() && ok);
}
void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,Graph g){
	// if k = 3  {1,2,3}
	//  aa = {f,f,t}
	// on affecte juste les t a c
	int kk = k - 1;
	*ncandidates = 0;
	vector<bool> aa(n,true);
	for(int i=0; i< g.listAdj[kk].size(); i++){
		if(g.listAdj[kk][i] < kk){
			aa[a[g.listAdj[kk][i]]] = false;
		}
	}
	for(int i=0; i<n ; i++){
		if(aa[i] == true){
			c[*ncandidates] = i;
			(*ncandidates)++;
		}
	}
}
void backtrack(int * a, int k, int n,Graph g,bool *ok){
	int c[n]; // the candidates
	int ncandidates;
	int i;
	if (is_a_solution(a,k,n,g))
		process_solution(a,k,n,g,ok);
	else{
		k++;
		construct_candidates(a,k,n,c,&ncandidates,g);
		for(i = 0; i< ncandidates; i++){
			a[k-1] = c[i]; 
			backtrack(a,k,n,g,ok);
			if(finished) return;
		}
	}
}
bool isThereKcolaration(Graph g, int k){

	int a[g.getSize()]; 
	bool ok = false;
	backtrack(a,0,k,g,&ok);
	return ok;
}
int getNombreChromatique(Graph g,int d /*degmax*/){
	if(isThereKcolaration(g,d)) return getNombreChromatique(g,d-1);
	else return (d+1);
	// we re gonna check and also print the solution if it exist
}

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,3);
	//g.addEdge(2,3);
	//int a[4]; 
	//bool ok =false;
	//backtrack(a,0,5,g,&ok);
	cout<<getNombreChromatique(g,g.getDegreMaximal() +1)<<endl;
	return 0;
}