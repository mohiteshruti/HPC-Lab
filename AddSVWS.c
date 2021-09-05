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

   	#pragma omp parallel
	{
		#pragma omp for
 		for(i=0; i<n; i++) 
 		{
			c[i]=a[i]+b;
			printf("Thread %d works on element%d\n", omp_get_thread_num(), i);
		}
 		
	}
	printf("i\ta[i]\t+\tb\t=\tc[i]\n");
    	for(i=0;i<n;i++){
    		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b, c[i]);

	}
	return 0;


}