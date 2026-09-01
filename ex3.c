#include<stdio.h>
#include<omp.h>
#define size 10
int main(){
    int arr[size]={1,2,3,4,5,6,7,8,9,10};
    int sum=0;
    #pragma omp parallel
    {
        int local_sum=0;
        #pragma omp for
        for(int i=0;i<size;i++){
            local_sum+=arr[i];
        }
        #pragma omp critical
        {
            sum+=local_sum;
        }
    }
    printf("sum of elements: %d",sum);
    return 0;
}