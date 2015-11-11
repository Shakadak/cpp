#include <iostream>
#include <string>
#include <cctype>
#include <clocale>

#include "Array.hpp"

template<typename A, typename B, typename C>
void    iter(A& xs, B const& l, C& f) {
    for (B i = 0; i < l; i++) {
        xs[i] = f(xs[i]);
    }
}
/*static char toLower(char c) {
    return (std::tolower(c));
}

static char toUpper(char c) {
    return (std::toupper(c));
}*/

static int plusOne(int i) {
    return (i + 1);
}

template<typename A>
static A    minusOne(A x) {
    return (x - 1);
}

template<typename A>
A&    printIt(A& x) {
    std::cout << x << std::endl;
    return (x);
}

int main(void) {
    {
        Array<std::string> xs(12);
        xs[0] = "Hello World";
        xs[2] = "How y'all doin' ?";
        xs[3] = "Good ? Good.";
        xs[5] = "Well see y'all again then.";
        xs[11] = "Next time!!!";
        std::cout << "iter(xs, xs.size(), printIt): " << std::endl;
        iter(xs, xs.size(), printIt<std::string>);
    }
    std::cout << "---" <<std::endl;
    {
        Array<int> xs(4);
        xs[0] = 1;
        xs[1] = 4;
        xs[2] = 6;
        xs[3] = -57;
        std::cout << "xs: " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
        iter(xs, 4, plusOne);
        std::cout << "iter(xs, 4, plusOne): " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
        std::cout << "\t--- test copie constructor." <<std::endl;
        Array<int> ys(xs);
        std::cout << "iter(ys, ys.size(), printIt): " << std::endl;
        iter(ys, ys.size(), printIt<int>);
        std::cout << "iter(ys, ys.size(), minusOne): " << std::endl;
        iter(ys, ys.size(), minusOne<int>);
        iter(ys, ys.size(), printIt<int>);
        std::cout << "iter(xs, xs.size(), printIt): " << std::endl;
        iter(xs, xs.size(), printIt<int>);
        std::cout << "\t--- test void constructor then assignation operator" <<std::endl;
        Array<int> zs;
        zs = xs;
        std::cout << "iter(zs, zs.size(), printIt): " << std::endl;
        iter(zs, zs.size(), printIt<int>);
        std::cout << "iter(zs, zs.size(), minusOne): " << std::endl;
        iter(zs, zs.size(), minusOne<int>);
        iter(zs, zs.size(), printIt<int>);
        std::cout << "iter(xs, xs.size(), printIt): " << std::endl;
        iter(xs, xs.size(), printIt<int>);
    }
    std::cout << "---" <<std::endl;
    {
        Array<float> xs(4);
        xs[0] = 1.f;
        xs[1] = 4.2f;
        xs[2] = 6.f;
        xs[3] = -57.75f;
        std::cout << "xs: " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
        iter(xs, 4, minusOne<float>);
        std::cout << "iter(xs, 4, minusOne<float>): " << xs[0] << ", " << xs[1] << ", " << xs[2] << ", " << xs[3] << std::endl;
    }
    std::cout << "---" <<std::endl;
    {
        Array<char> xs;
        try {
            xs[0] = '!';
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}
