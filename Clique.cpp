/**
	a backtracking algorithm that returns
	the maximum size of a clique in a Graph G
	optimisation problem by ch@r|f

**/
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;

class Graph{
	int size;
	vector<int> * listAdj;
public:
	Graph(int s):size(s){
		this->listAdj = new vector<int>[s];
	}
	void addEdge(int u,int v){
		this->listAdj[u].push_back(v);
	}
	bool checkIfAnEdgeIsInTheGraph(int a,int b){
		bool ok = false;
		for(int i = 0; i < size; i++ ){
			for(int j=0; j< this->listAdj[i].size(); j++){
				//printf("{%d,%d} \n",i,this->listAdj[i][j]);
				if(i == a && this->listAdj[i][j] == b) ok = true;
				if(i == b && this->listAdj[i][j] == a) ok = true;
			}
		}
		return ok;
	}
	int getSize(){
		return this->size;
	}
};
/////////
void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}
bool finished = false;
bool is_a_solution(int * a,int k, int n, Graph g){
	bool ok = true;
	for(int i=0; i< n-1 ; i++){
		for(int j=i+1 ; j< n; j++){
			if(!g.checkIfAnEdgeIsInTheGraph(a[i],a[j])) ok =false;
		}
	}
	//debugArray(a,n);
	return (k == n && ok);
	// check if a form a clique
	
}
void process_solution(int * a,int k,int n,Graph g,bool * ok){
	// process the complete solution a once it"s there	
	*ok = true; // find a solution
}
void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,Graph g){
	//naive algo !!! not soo cool ! but working
	int ii = 0;   //iterate the nodes evrytimes all the nodes !!!!!!!!!! 
	*ncandidates = 0;
	for(int i= k-1 ; i< g.getSize() ; i++){
		c[ii++] = i;
		(*ncandidates)++;
	}


}
void backtrack(int * a, int k, int n,Graph g,bool *ok){
	int c[k]; // the candidates
	int ncandidates;
	int i;
	if (is_a_solution(a,k,n,g))
		process_solution(a,k,n,g,ok);


	else{
		k++;
		construct_candidates(a,k,n,c,&ncandidates,g);

		for(i = 0; i< ncandidates; i++){
			a[k-1] = c[i];   // always keep attention with the a[k-1] not a[k] !!
			//printf("%d\n",a[k]);
			//printf(" %d \n",a[k]);
			backtrack(a,k,n,g,ok);
			if(finished) return;
		}
	}
}

/////////

bool isThereAcliqueWithSizeInTheGraph(Graph g, int k){
	if(k == 0 || k == 1) return false;
	if(k == 2) return true;
	/** if k >= 3 run a backtracking algorithm to find out
		if we can construct a solution for this probleme with k
	**/
	int a[k]; // the array that gonna contains the solutions
	bool ok = false;
	backtrack(a,0,k,g,&ok);
	return ok;
}
int getSizeMaximumClique(Graph g,int s){
	//cout<<"ohayo"<<endl;
	if(isThereAcliqueWithSizeInTheGraph(g,s)) return s;
	else return getSizeMaximumClique(g,s-1);
}

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(2,4);
	g.addEdge(3,4);
	g.addEdge(3,5);
	g.addEdge(4,5);
	cout<<getSizeMaximumClique(g,g.getSize());
	
	return 0;
}