#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <conio.h>

/*      
*   Source by CPPReference
*   Modified For Learn by Rizky Khapidsyah
*   I.D.E : VS2019
*/

int main() {
    
    std::cout << "pow(2, 10) = " << std::pow(2, 10) << '\n'
        << "pow(2, 0.5) = " << std::pow(2, 0.5) << '\n'
        << "pow(-2, -3) = " << std::pow(-2, -3) << '\n';
    
    std::cout << "pow(-1, NAN) = " << std::pow(-1, NAN) << '\n'
        << "pow(+1, NAN) = " << std::pow(+1, NAN) << '\n'
        << "pow(INFINITY, 2) = " << std::pow(INFINITY, 2) << '\n'
        << "pow(INFINITY, -1) = " << std::pow(INFINITY, -1) << '\n';
    
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "pow(-1, 1/3) = " << std::pow(-1, 1.0 / 3) << '\n';

    if (errno == EDOM) {
        std::cout << "    errno == EDOM " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "    FE_INVALID raised\n";
    }
        
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "pow(-0, -3) = " << std::pow(-0.0, -3) << '\n';

    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "    FE_DIVBYZERO raised\n";
    }
        
    _getch();
    return 0;
}