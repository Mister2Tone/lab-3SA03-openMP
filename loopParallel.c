#include <omp.h>
#include <stdio.h>
#include <math.h>
#define NUMBER 500000
int main(int argc, char *argv[]){
	int i, data[NUMBER];
	int num_t,t_id;
	double result=0.0;
	for(i=0;i<NUMBER;i++){
		data[i]=i*i;
	}
	double start_time = omp_get_wtime();
	#pragma omp parallel for 
	for(i=0;i<NUMBER;i++){
		num_t = omp_get_num_threads();
		t_id = omp_get_thread_num();
		result+=(sin(data[i])-cos(data[i]))/(sin(data[i]+cos(data[i])));
		//printf("t_id : %d/%d\n",t_id,num_t);
	}
	double end_time = omp_get_wtime();
	double time = end_time - start_time;
	printf("Result = %f\n",result);
	printf("Time : %f\n",time);
}
