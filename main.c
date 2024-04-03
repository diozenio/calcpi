#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

void run(int initialN, int termsQnt, double *result, int num_threads)
{
    clock_t start, end;
    start = clock();

    double pi = 0.0;

    #pragma omp parallel for num_threads(num_threads) reduction(+:pi)
    for (int n = initialN; n < initialN + termsQnt; n++)
    {
        pi += pow(-1, n) / (2.0 * n + 1);
    }

    pi *= 4;
    *result = pi;
    end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("----------------------------------\n");
    printf("Tempo de execucao em %d threads: %f segundos\n", num_threads, time_taken);
}

int main()
{
    int initialN = 0;
    int termsQnt;
    double pi_result;

    printf("Quantidade de termos para calcular Pi: ");
    scanf("%d", &termsQnt);

    printf("Configuracao da maquina: %d threads disponiveis\n", omp_get_max_threads());
    printf("Quantas threads voce deseja utilizar? ");
    
    int num_threads;
    scanf("%d", &num_threads);
    
    if (num_threads <= 0 || num_threads > omp_get_max_threads()) {
        printf("Numero de threads invalido. Usando o maximo disponivel.\n");
        num_threads = omp_get_max_threads();
    }

    run(initialN, termsQnt, &pi_result, num_threads);
    printf("Pi: %.16g\n", pi_result);

    return 0;
}
