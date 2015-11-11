#include <iostream>
#include <string>
#include <cctype>
#include <clocale>

template<typename A, typename B, typename C>
void    iter(A& xs, B const& l, C& f) {
    for (B i = 0; i < l; i++) {
        xs[i] = f(xs[i]);
    }
}

static char toLower(char c) {
    return (std::tolower(c));
}

static char toUpper(char c) {
    return (std::toupper(c));
}

static int plusOne(int i) {
    return (i + 1);
}

template<typename A>
static A    minusOne(A x) {
    return (x - 1);
}

int main(void) {
    {
        std::string xs = "Hello World";
        std::cout << "xs: " << xs << std::endl;
        iter(xs, xs.length() / 2, toUpper);
        std::cout << "iter(xs, xs.length() / 2, toUpper): " << xs << std::endl;
    }
    {
        std::string xs = "Hello World";
        std::cout << "xs: " << xs << std::endl;
        iter(xs, xs.length(), toLower);
        std::cout << "iter(xs, xs.length(), toLower): " << xs << std::endl;
    }
    {
        int xs[4] = {1, 2, 3, 4};
        std::cout << "xs: " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
        iter(xs, 4, plusOne);
        std::cout << "iter(xs, 4, plusOne): " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
    }
    {
        float xs[4] = {1.0f, 2.0f, 3.0f, 4.2f};
        std::cout << "xs: " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
        iter(xs, 4, minusOne<float>);
        std::cout << "iter(xs, 4, minusOne<float>): " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
    }
    return (0);
}
