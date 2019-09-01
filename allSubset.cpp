/*
what we are doing here is generates all subset with false true
by Charif Achraf
*/

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#define NMAXCANDIDATE 2 // working with 4 elements of the candidates

using namespace std;

bool finished = false;

bool is_a_solution(bool * a,int k, int n){
	return (k == n);
}
void construct_candidates(bool * a,int k, int n,bool * c, int * ncandidates){
// fill the array c with the complete set of 
// posible candidates for the kth position of a, giben the content of the first k - 1 elements
	c[0] = true;
	c[1] = false;
	*ncandidates = 2; // the number os the candidates possible for the k ith element
}
void process_solution(bool * a,int k,int n){
	// process the complete solution a once it"s there	
	printf("{ ");
	for(int i=1; i<=k; i++){
		if(a[i] == true){
			printf("%d ",i);
		}
		
	}
	printf("}\n");
}
void backtrack(bool * a, int k, int n){
	bool c[NMAXCANDIDATE];
	int ncandidates;
	int i;
	if (is_a_solution(a,k,n))
		process_solution(a,k,n);
	else{
		k++;
		construct_candidates(a,k,n,c,&ncandidates);
		for(i = 0; i< ncandidates; i++){
			a[k] = c[i];
			backtrack(a,k,n);
			if(finished) return;
		}
	}
}

int main(){
	bool a[2<< 8];
	backtrack(a,0,4); // taille 4
	return 0;
}