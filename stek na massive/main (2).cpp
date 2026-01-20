#include "header.h"

int main() {
    try {
        Stack s1(5);
        s1.push(10);
        s1.push(20);
        s1.push(30);
        std::cout << "s1 верхний: " << s1.peek() << '\n';

        Stack s2 = s1;
        std::cout << "s2 копия: " << s2.peek() << '\n';
        std::cout << "s1 пустой? " << (s1.IsEmpty() ? "да" : "нет") << '\n';

    } catch(const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}