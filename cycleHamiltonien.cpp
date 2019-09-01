!/**
	get a cycle hamiltonien
	a = (1,2,3,4,1) 

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
};
void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}
bool isInArray(int * a,int n,int k){
	bool ok = false;
	for(int i=0;i<n;i++){
		if(a[i] == k) ok =true;
	}
	return ok;
}
bool finished = false;
void process_solution(int * a,int k,int n,Graph g,bool * ok){	
	*ok = true; 
	printf("an hamiltonien cycle is : \n");
	debugArray(a,k);
}
bool is_a_solution(int * a,int k, int n, Graph g){

	bool ok = true;

	return (k  == g.getSize() + 1 && ok);
}
void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,Graph g){
	*ncandidates = 0;
	int kk = k - 1 ;
	if(kk == 0){
		for(int i= 0 ; i< g.getSize(); i++){
			c[*ncandidates] = i;
			(*ncandidates)++;
			//cout<<i<<endl;
		}
		//exit(0);
		
	}else if(kk == g.getSize()){
		for(int i=0; i<g.listAdj[a[kk - 1]].size() ; i++){
			
			if(g.listAdj[a[kk - 1]][i] == a[0]){
				*ncandidates = 1;
				c[0] = a[0];
			}
			
		}
	
	}else{
		for(int i=0; i<g.listAdj[a[kk -1]].size() ; i++){
			if(!isInArray(a,kk,g.listAdj[a[kk -1]][i]))
			c[(*ncandidates)++] = g.listAdj[a[kk -1]][i];
			
		}
	
	}

}

void backtrack(int * a, int k, int n,Graph g,bool *ok){
	int c[g.getSize()]; // the candidates
	int ncandidates;
	int i;

	if (is_a_solution(a,k,n,g))
		process_solution(a,k,n,g,ok);
	else{
		k++;
		
		construct_candidates(a,k,n,c,&ncandidates,g);
		//debugArray(a,7);
		for(i = 0; i< ncandidates; i++){
			a[k-1] = c[i]; 
			backtrack(a,k,n,g,ok);
			if(finished) return;
		}
	}
}

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(5,0);
	int a[7];
	bool ok;
	backtrack(a,0,7,g,&ok);
	cout<<"ok";

	return 0;
}