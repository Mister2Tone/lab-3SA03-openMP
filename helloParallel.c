#include <omp.h>
#include <stdio.h> 
int main(int argc, char *argv[]) 
{  
	int t_id,num_t;  
	double start_time = omp_get_wtime();
	#pragma omp parallel num_threads(16)
	{
		num_t = omp_get_num_threads();
		t_id = omp_get_thread_num();
		printf("Hello world from thread ID %d/%d\n",t_id,num_t); 
	}
	double end_time = omp_get_wtime();
	double time_usage = end_time - start_time;
	printf("time usage : %12.10f",time_usage);
} 
