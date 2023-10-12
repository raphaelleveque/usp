#include <stdio.h>
#include <omp.h>

static long num_steps = 100000;
double step;

double calculate_pi(int quarter) {
    int initial = quarter * (num_steps / 4.0);
    int end = initial + (num_steps / 4.0);
    step = 1.0/(double)num_steps;

    double x, pi, sum = 0.0;
    for (int i = initial; i < end; ++i) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x*x);
    }
    return step * sum;
}
int main() {
    int i;
    step = 1.0/(double)num_steps;

    double pi_pie[4];
#pragma omp parallel num_threads(4)
    {
    int quarter = omp_get_thread_num();
    pi_pie[quarter] = calculate_pi(quarter);
    }

    double sum = 0.0;
    for (int i = 0; i < 4; i++) {
        sum += pi_pie[i];
    }
    printf("%lf", sum);
    return 0;
}
