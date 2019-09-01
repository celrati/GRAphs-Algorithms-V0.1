/*
	generate all permutations of a set 
	by Charif Achraf
*/
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#define NMAXCANDIDATE 4

using namespace std;

bool finished = false;

void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}

bool is_a_solution(int * a,int k, int n){
	return (k == n);
}

void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,int * input){
// fill the array c with the complete set of 
// posible candidates for the kth position of a, giben the content of the first k - 1 elements
//
	 // {1,2,4}
	int i;
	bool in_perm[n]; // who is in the permutation maximum
	for (i=0; i<n; i++) in_perm[i] = false; // init the array with false
	for (i=1; i<k; i++) in_perm[ a[i] ] = true;  // now set true to the first k-1 element
	*ncandidates = 0;
	for (i=0; i<n; i++)
		if (in_perm[i] == false) {
			c[ *ncandidates] = i;
			//printf("%d ",c[ *ncandidates]);
			*ncandidates = *ncandidates + 1;
		}
		//debugArray(c,*ncandidates);

}
void process_solution(int * a,int k,int n,int *  input){
	// process the complete solution a once it"s there	
	for(int i=1; i<=k; i++){
			printf("%d ",input[a[i] - 1]);
	}
	printf("\n");

}
void backtrack(int * a, int k, int n,int * input){
	int c[n];
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
	int a[NMAXCANDIDATE]; // to the solution vector
	int theSet[] = {0,1,2};
	int n = 3; // size of the array
	backtrack(a,0,n,theSet);

	return 0;
}