#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();

        #pragma omp critical
        {
            counter++;

            printf("Thread %d entered critical section\n", thread_id);
            printf("Counter = %d\n", counter);
        }
    }

    printf("\nFinal Counter = %d\n", counter);

    return 0;
}