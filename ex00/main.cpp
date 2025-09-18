#include "Bureaucrat.hpp"

int main() {
  Bureaucrat a;
  Bureaucrat b("Yubeen", 100);
  Bureaucrat c(b);
  Bureaucrat d;

  d = b;

  std::cout << a;
  std::cout << b;
  std::cout << c;
  std::cout << d;
}
