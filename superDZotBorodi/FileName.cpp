// Для корректной работы с русской консолью в Windows
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

// Используем volatile, чтобы компилятор не "выкинул" наши вычисления
// в ходе оптимизации, посчитав их бесполезными.
struct ThreadData {
    volatile float a = 1.0f, b = 1.1f, c = 1.2f, d = 1.3f;
};

// Функция, которую будет выполнять каждый поток
void benchmark_task(long long num_iterations_per_thread) {
    ThreadData data;
    // В цикле 4 операции: 2 умножения и 2 сложения.
    for (long long i = 0; i < num_iterations_per_thread; ++i) {
        data.a = data.a * data.b;
        data.c = data.c + data.d;
        data.b = data.a * data.c;
        data.d = data.b + data.a;
    }
}

int main() {
    // Устанавливаем кодировку для консоли Windows
#ifdef _WIN32
    // Используем кодовую страницу 1251 для кириллицы в Windows
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    // Определяем количество доступных логических ядер процессора
    const unsigned int num_threads = std::thread::hardware_concurrency();

    const long long ops_per_iteration = 4;
    const long long total_iterations = 4000000000;
    const long long num_iterations_per_thread = total_iterations / num_threads;

    std::cout << "Запуск многопоточного теста производительности..." << std::endl;
    std::cout << "Задействовано ядер/потоков: " << num_threads << std::endl;
    std::cout << "Итераций на поток: " << num_iterations_per_thread << std::endl;

    long long total_ops = num_threads * num_iterations_per_thread * ops_per_iteration;
    std::cout << "Общее количество операций: ~" << static_cast<double>(total_ops) / 1e9 << " миллиардов" << std::endl;

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

    // --- Расчет производительности ---
    double gflops = flops / 1e9; // Гигафлопсы (10^9)
    double giflops = flops / pow(2, 30); // Гибифлопсы (2^30)

    std::cout.precision(2);
    std::cout << std::fixed;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Общее время выполнения: " << seconds << " секунд" << std::endl;
    std::cout << "Производительность (GFLOPS, 10^9): " << gflops << std::endl;
    std::cout << "Производительность (GiFLOPS, 2^30): " << giflops << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // --- Расчет операций за год ---
    const long long seconds_in_a_year = 365LL * 24 * 60 * 60;
    long double ops_per_year = flops * seconds_in_a_year;

    std::cout << "\nПри такой пиковой производительности компьютер может выполнить:" << std::endl;
    std::cout.precision(4);
    std::cout << std::scientific;
    std::cout << ops_per_year << " операций за год непрерывной работы." << std::endl;

    long double exa_ops_per_year = ops_per_year / 1e18;
    std::cout.precision(4);
    std::cout << std::fixed;
    std::cout << "(Примерно " << exa_ops_per_year << " экса-операций в год)" << std::endl;

    return 0;
}
