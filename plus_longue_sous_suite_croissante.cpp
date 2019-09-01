/*	S = {1,6,4,8,2,9}
	v = (1,6,8,9) or (1,4,8,9)
	a = (1,1,0,1,0,1) or a = (1,0,1,1,0,1) the vectors solution of our search space
	


*/

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool finished = false;
void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}
bool is_a_solution(int * a,int k, int n,int * input){

	// just to check if the vector a is complete just that!!!!!!!!!!!!!!!!
	return (k == n);
	// k is the height of the tree
}
void process_solution(int * a,int k,int n,int *  input){ // print a resul from the vector a
	// here we're gonna check the reel solution 
	int c = 1;
	int aaa = 0;
	int bbb ;
	for(int i=0; i< n ; i++){
		if(a[i] == 1){
			if(aaa == 0){
				bbb = input[i];
				aaa = 1;
			}
			if(input[i] < bbb){
				c = 0;
				break;
			}
			bbb = input[i];
		}
	}

	if(c){
	for(int i=0; i< n; i++){
		//,a[i]?printf("%d ",input[i]):printf(" "));
		if(a[i]) printf("%d - ",input[i]);
		
		
	}
	printf("\n");		
	}	

}
void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,int * input){
// fill the array c with the complete set of 
// posible candidates for the kth position of a, giben the content of the first k - 1 elements
//
	*ncandidates = 2;
	c[0] = 0;
	c[1] = 1;
}
void backtrack(int * a, int k, int n,int * input){
	int c[ 2 << 8];  // the candidates are the indexes  """"maxlength"""
	int ncandidates;
	int i;
	if (is_a_solution(a,k,n,input))
		process_solution(a,k,n,input);
	else{
		k++;
		construct_candidates(a,k,n,c,&ncandidates,input);
		for(i = 0; i< ncandidates; i++){
				a[k-1] = c[i];
				//printf("%d\n",c[i]);
				//debugArray(a,3);
				//printf("%d hell \n",(input[a[c[i]]]));
						
			//printf(" %d \n"1,a[k]);
			backtrack(a,k,n,input);
			if(finished) return;
		}
	}
}

int main(){
	int a[6] = {0,0,0,0,0,0};// init our vector that gonna contains the solutions
	int S[6] = {2,1,3,9,0,12};
	backtrack(a,0,6,S);
	return 0;
}