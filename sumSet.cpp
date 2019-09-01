/**  SumSet by Charif Achraf im gonna try new way of implementing
	L = [1,2,3,4,7,9] 
	K = 10
    a = (1,9) or (3,7) or (1,2,3,4)
    a = (1,0,0,0,0,1)  or (0,0,1,0,1,0) or (1,1,1,1,0,0)
**/

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;



void debugArray(int * t,int n){
	for(int i=0;i<n;i++) printf("%d|",t[i]);
		printf("\n");
}
void construct_candidates(int * a,int k, int n,int * c, int * ncandidates,int * input,int K){
	c[0] = 0;
	*ncandidates = 1;
	if(k == 1){
		c[1] = 1;
		*ncandidates = 2;
	}else{
		// get the sum of all the number in the arra right now
		int cc = 0;
		for(int i=0;i<n;i++){
			if(a[i]) cc += input[i];
		}
		if(input[k-1] + cc <= K ){
			c[1] = 1;
			*ncandidates = 2;
		}
	}
	//debugArray(a,n);
}
void process_solution(int * a,int k,int n,int *  input,int K){
	// check is the sum equals K
	int cc = 0;
	for(int i=0;i<n;i++){
		if(a[i]) cc += input[i];
	}
	if(cc == K){
		for(int i=0; i<n; i++){
			if(a[i]) printf("%d | ",input[i]);
		}
		printf("\n");		
	}

}
bool is_a_solution(int * a,int k, int n,int * input,int K){
	//printf("for k = %d we have this array : ",k);
	//debugArray(a,n);
	bool ok =false;
	int cc =0;
	for(int i=0;i<n;i++){
		if(a[i]) cc += input[i];
	}
	if(K == cc) ok =true;
	return (k == n || ok); // not always check with k == n !!!!!!!!!!!!!
}
bool finished = false;
void RunBacktracking(int * a, int k, int n,int * input,int K){
	int c[2]; 
	int ncandidates;
	if (is_a_solution(a,k,n,input,K)){
		//debugArray(a,n);
		process_solution(a,k,n,input,K);		
	}

	else{
		k++;
		construct_candidates(a,k,n,c,&ncandidates,input,K);
		for(int i = 0; i< ncandidates; i++){
				a[k-1] = c[i];
				
			RunBacktracking(a,k,n,input,K);
			if(finished) return;
		}
	}
}
int main(){
	int T[6] = {1,2,3,4,7,9};
	int a[6] = {0,0,0,0,0,0};
	int K = 10;
	RunBacktracking(a,0,6,T,K);
	return 0;
}