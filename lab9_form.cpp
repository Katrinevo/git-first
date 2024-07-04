#include <iostream>
#include <string>
#include <format>


int main() {

    std::cout << std::format("{0} {0} {2}: {3}!\n", "Hello", "goodbye", "world", 2024);
    std::cout << std::format("{:+<7}", 'y') << '\n'; 
    std::cout << std::format("{:=^5}", 'x') << '\n';
    std::cout << std::format("{:>9}", false) << '\n';
    std::cout << "\n";
    std::cout << std::format("{0:+},{0:-},{0: }", 5) << '\n';
    std::cout << std::format("{0:+},{0:-},{0: }", -7) << '\n';
    std::cout << "\n";
    std::cout << std::format("{:g}", 120.00) << '\n'; 
    std::cout << std::format("{:#g}", 120.48345) << '\n'; //три числа после запятой
  

    return 0;
}