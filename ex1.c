#include <omp.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    #pragma omp parallel
    {
        int rank = omp_get_thread_num();
        int num_processors = omp_get_num_threads();
        printf("Rank/Thread ID: %d, Number of Processors: %d\n",
               rank, num_processors);
    }
    return 0;
}