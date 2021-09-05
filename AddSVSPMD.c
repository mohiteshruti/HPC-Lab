#include<stdio.h>
#include<omp.h>

int main(){
	int n,b;
	int i;
	printf("Vector Space:\n");
	scanf("%d",&n);
	int a[n+1];
	int c[n+1];
	printf("Vector\n");

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Scalar to add\n");
	scanf("%d",&b);
	omp_set_num_threads(3);
   	#pragma omp parallel
	{
		int id, i, Nthrds, istart, iend;
 		id = omp_get_thread_num();
 		Nthrds = omp_get_num_threads();
 		istart = id*n/Nthrds;
 		iend = (id+1)*n/Nthrds;
 		if(id == Nthrds-1) iend = n;
 		for(i = istart; i<iend; i++) {
			c[i] = b+a[i];		
			printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
		}
 		
	}
	printf("\nOutput Vector\n");
	printf("i\ta[i]\t+\tb\t=\tc[i]\n");
    	for(i=0;i<n;i++){
    		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b, c[i]);

	}
	return 0;
}