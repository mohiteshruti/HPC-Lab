#include<stdio.h>
#include<omp.h>

int main(){
	int n,b;
	int i;
	int index=0;
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

   	#pragma omp parallel firstprivate(index)
	{
        int thread=omp_get_thread_num();
      
        while(index<n){
        	if(index==thread-1){
        		c[index]=a[index]+b;
        		break;
        	}
        	index++;
        }

	}
	printf("i\ta[i]\t+\tb\t=\tc[i]\n");
    	for(i=0;i<n;i++){
    		printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b, c[i]);

	}
	return 0;


}