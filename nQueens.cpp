/**
solving the N queens problem with backtracking
by Charif Achraf

**/
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#define NMAXCANDIDATE 4

using namespace std;

bool finished = false;
int countSolution = 0;

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
	int i,j;
/* counters */
	bool legal_move;
/* might the move be legal? */
	*ncandidates = 0;
	for (i=1; i<=n; i++) {
		legal_move = true;
		for (j=1; j<k; j++) {
if (abs((k)-j) == abs(i-a[j])) /* diagonal threat */
			legal_move = false;
			if (i == a[j])
/* column threat */
				legal_move = false;
		}
		if (legal_move == true) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}

}
void process_solution(int * a,int k,int n,int *  input){
	countSolution++;
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