// ��� ���������� ������ � ������� �������� � Windows
#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <numeric>
#include <atomic>
#include <cmath>

// ���������� volatile, ����� ���������� �� "�������" ���� ����������
// � ���� �����������, �������� �� ������������.
struct ThreadData {
    volatile float a = 1.0f, b = 1.1f, c = 1.2f, d = 1.3f;
};

// �������, ������� ����� ��������� ������ �����
void benchmark_task(long long num_iterations_per_thread) {
    ThreadData data;
    // � ����� 4 ��������: 2 ��������� � 2 ��������.
    for (long long i = 0; i < num_iterations_per_thread; ++i) {
        data.a = data.a * data.b;
        data.c = data.c + data.d;
        data.b = data.a * data.c;
        data.d = data.b + data.a;
    }
}

int main() {
    // ������������� ��������� ��� ������� Windows
#ifdef _WIN32
    // ���������� ������� �������� 1251 ��� ��������� � Windows
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    // ���������� ���������� ��������� ���������� ���� ����������
    const unsigned int num_threads = std::thread::hardware_concurrency();

    const long long ops_per_iteration = 4;
    const long long total_iterations = 4000000000;
    const long long num_iterations_per_thread = total_iterations / num_threads;

    std::cout << "������ �������������� ����� ������������������..." << std::endl;
    std::cout << "������������� ����/�������: " << num_threads << std::endl;
    std::cout << "�������� �� �����: " << num_iterations_per_thread << std::endl;

    long long total_ops = num_threads * num_iterations_per_thread * ops_per_iteration;
    std::cout << "����� ���������� ��������: ~" << static_cast<double>(total_ops) / 1e9 << " ����������" << std::endl;

    std::vector<std::thread> threads;

    auto start_time = std::chrono::high_resolution_clock::now();

    for (unsigned int i = 0; i < num_threads; ++i) {
        threads.emplace_back(benchmark_task, num_iterations_per_thread);
    }

    for (auto& t : threads) {
        t.join();
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;
    double seconds = elapsed.count();

    double flops = static_cast<double>(total_ops) / seconds;

    // --- ������ ������������������ ---
    double gflops = flops / 1e9; // ���������� (10^9)
    double giflops = flops / pow(2, 30); // ���������� (2^30)

    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "����� ����� ����������: " << seconds << " ������" << std::endl;
    std::cout << "������������������ (GFLOPS, 10^9): " << gflops << std::endl;
    std::cout << "������������������ (GiFLOPS, 2^30): " << giflops << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // --- ������ �������� �� ��� ---
    const long long seconds_in_a_year = 365LL * 24 * 60 * 60;
    long double ops_per_year = flops * seconds_in_a_year;

    std::cout << "\n��� ����� ������� ������������������ ��������� ����� ���������:" << std::endl;
    std::cout.precision(4);
    std::cout << std::scientific;
    std::cout << ops_per_year << " �������� �� ��� ����������� ������." << std::endl;

    long double exa_ops_per_year = ops_per_year / 1e18;
    std::cout.precision(4);
    std::cout << std::fixed;
    std::cout << "(�������� " << exa_ops_per_year << " ����-�������� � ���)" << std::endl;

    return 0;
}