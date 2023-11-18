#include <iostream>
#include <vector>
#include <chrono>

// Функция для вычисления факториала
std::vector<int> CalculateFactorial(int n) {

    std::vector<int> result;

    result.reserve(n / 2);

    result.push_back(1);

    int carry = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    return result;
}

// Функция для вывода числа из вектора
void PrintNumber(const std::vector<int>& number) {
    for (int i = number.size() - 1; i >= 0; i--) {
        std::cout << number[i];
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;

    std::cout << "Введите неотрицательное целое число: ";
    std::cin >> n;

    auto start_time = std::chrono::high_resolution_clock::now();

    if (n < 0) {
        std::cout << "Факториал не определен для отрицательных чисел." << std::endl;
    }
    else if (n == 0) {
        std::cout << "Факториал 0 равен 1." << std::endl;
    }
    else {
        std::vector<int> result = CalculateFactorial(n);
        std::cout << n << "! = ";
        PrintNumber(result);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
    std::cout << "Время выполнения программы в секундах: " << duration.count() << std::endl;

    system("pause");

    return 0;
}