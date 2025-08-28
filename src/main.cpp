#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double alpha = 0.01;
const double L = 1.0;
const double T = 0.1;
const int N = 1000000;
const int steps = 20000;

double dx = L / (N - 1);
double dt = T / steps;

double stability = alpha * dt / (dx * dx);

void initialize(std::vector<double>& u) {
    for (int i = 0; i < N; ++i) {
        double x = i * dx;
        u[i] = sin(M_PI * x);
    }
}

void heat_serial(std::vector<double>& u) {
    std::vector<double> u_new(N);
    for (int t = 0; t < steps; ++t) {
        for (int i = 1; i < N - 1; ++i) {
            u_new[i] = u[i] + stability * (u[i + 1] - 2 * u[i] + u[i - 1]);
            //std::cout << u_new[i] << std::endl;
        }
        
        u_new[0] = 0.0;
        u_new[N - 1] = 0.0;
        u.swap(u_new);
    }
}

void heat_parallel(std::vector<double>& u) {
    std::vector<double> u_new(N);
    for (int t = 0; t < steps; ++t) {
#pragma omp parallel for
        for (int i = 1; i < N - 1; ++i) {
            u_new[i] = u[i] + stability * (u[i + 1] - 2 * u[i] + u[i - 1]);
            //std::cout << u_new[i] << std::endl;
        }
        u_new[0] = 0.0;
        u_new[N - 1] = 0.0;
        u.swap(u_new);
    }
}

int main() {
    omp_set_num_threads(20);
    std::vector<double> u_serial(N), u_parallel(N);

    initialize(u_serial);
    u_parallel = u_serial;

    auto start1 = std::chrono::high_resolution_clock::now();
    heat_serial(u_serial);
    auto end1 = std::chrono::high_resolution_clock::now();

    auto start2 = std::chrono::high_resolution_clock::now();
    heat_parallel(u_parallel);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_serial = end1 - start1;
    std::chrono::duration<double> time_parallel = end2 - start2;

    std::cout << "Serial Time:   " << time_serial.count() << " seconds\n";
    std::cout << "Parallel Time: " << time_parallel.count() << " seconds\n";
    return 0;
}
