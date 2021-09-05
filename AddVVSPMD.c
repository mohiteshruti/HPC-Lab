#include<stdio.h>
#include<omp.h>

int main(){
	int n;
	int i;
	printf("Vector Space:\n");
	scanf("%d",&n);
	int a[n+1];
	int b[n+1];
	int c[n+1];
	printf("First vector\n");

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Second vector\n");
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	omp_set_num_threads(3);
   	#pragma omp parallel
	{
		int id,i,Nthrds,istart,iend;
		id=omp_get_thread_num();
		Nthrds=omp_get_num_threads();
		istart=id*n/Nthrds;
		iend=(id+1)*n/Nthrds;
		if(id==Nthrds-1)iend=n;
		for(i=istart;i<iend;i++)
		{
			c[i]=b[i]+a[i];
			printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
		} 		
	}
	printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
    	for(i=0;i<n;i++){
    		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);

	}
	return 0;


}