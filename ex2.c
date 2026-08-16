#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int nPoints = 10000000;
    int nthreads = 8;
    double nInside = 0.0;
    double pi;

    #pragma omp parallel reduction(+:nInside) num_threads(nthreads)
    {
        int tid = omp_get_thread_num();
        unsigned int seed = tid + 1;

        #pragma omp for
        for (int i = 0; i < nPoints; i++) {

            double rand_a = (double)rand_r(&seed) / RAND_MAX;
            double rand_b = (double)rand_r(&seed) / RAND_MAX;

            if (rand_a * rand_a + rand_b * rand_b <= 1.0) {
                nInside++;
            }
        }
    }

    pi = 4.0 * nInside / nPoints;

    printf("Number of points = %d\n", nPoints);
    printf("Points inside    = %.0f\n", nInside);
    printf("Value of Pi      = %.10f\n", pi);

    return 0;
}