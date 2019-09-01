/*
	this exo we're gonna try to construct a vector A
	example
	and show all the solution vector of the search space
	if n = 3
	A = (1,0,0,0,0,1,0,1,0)  
	size = n * n 
	1 0 0
	0 0 1
	1 0 0     a false a vector
	by Charif Achraf
*/

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h> // for the abs function

using namespace std;
bool finished = false;

void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}
bool is_a_solution(int * a,int k, int n){ // check whether this solution is a complete solution
	return (k == (n*n));
}
void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,int * input){
// fill the array c with the complete set of 
// posible candidates for the kth position of a, giben the content of the first k - 1 elements
//
	bool legal_to_put_1 = true;
	*ncandidates = 1;
	c[0] = 0;
	// now we re gonna test if we can put also 1 in it
	for(int i=0;i < k ; i++){
		//printf("h|");
		if(a[i] == 1){
			//printf("for i = %d : ",i);
			//printf("i")
			if((i%n) == (k%n)) legal_to_put_1 = false; // to check if they have the same column
			if((i/n) == (k/n)) legal_to_put_1 = false; // to check if they have the same row
			if(abs( (i%n) - (k%n)) == abs( (i/n) - (k/n)) ) legal_to_put_1 = false;
			// toc check diagonal if there is a threat
		}
	}
	if(legal_to_put_1){
		(*ncandidates)++;
		c[1] = 1;
	}

}
void process_solution(int * a,int k,int n,int *  input){ // print a resul from the vector a
	// here we're gonna draw the chessBoard
	bool ok = true;
	if( k == (n*n)){
		for(int i=0;i<n;i++){
			int c = 0;
			for(int j=0;j<n;j++){
				c += a[i+j*n]; 
			}
			if(c != 1 ) ok = false; // to check if the sum of a column is 1
		}
	}
	if(ok){
	for(int i= 0; i< (n*n) ; i++){
		if( i % n == 0) printf("\n");
		printf("%d | ",a[i]);
	}
	printf("\n");		
	}

	//exit(0);
}
void backtrack(int * a, int k, int n,int * input){
	int c[2];  // the candidates are 1 or 0
	int ncandidates;
	int i;
	if (is_a_solution(a,k,n))
		process_solution(a,k,n,input);
	else{
		k++;
		construct_candidates(a,k,n,c,&ncandidates,input);
		for(i = 0; i< ncandidates; i++){
			a[k] = c[i];
			//printf(" %d \n",a[k]);
			backtrack(a,k,n,input);
			if(finished) return;
		}
	}
}

int main(){
	int a[4*4];
	backtrack(a,-1,4,a); // to start with 0 in the array
	return 0;
}

