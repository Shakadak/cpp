#include <iostream>
#include <string>

template<typename A>
void    swap(A& a, A& b) {
    A   c = a;
    a = b;
    b = c;
}

template<typename A>
A&  min(A& x, A& y) {
    return (x < y ? x : y);
}

template<typename A>
A&  max(A& x, A& y) {
    return (x > y ? x : y);
}

int main(void) {
    {
        int x = 1;
        int y = 2;
        int z = 2;

        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
        std::cout << "max(x, y): " << max(x, y) << ", swap(x, min(y, z)): "
            << std::endl;
        swap(x, min(y, z));
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    }
    std::cout << "---" << std::endl;
    {
        char x = 'c';
        char y = '4';
        char z = '4';

        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
        std::cout << "max(x, y): " << max(x, y) << ", swap(x, min(y, z)): "
            << std::endl;
        swap(x, min(y, z));
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    }
    std::cout << "---" << std::endl;
    {
        std::string x = "hello";
        std::string y = "not world";
        std::string z = "not world";

        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
        std::cout << "max(x, y): " << max(x, y) << ", swap(x, min(y, z)): "
            << std::endl;
        swap(x, min(y, z));
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    }
    return (0);
}
