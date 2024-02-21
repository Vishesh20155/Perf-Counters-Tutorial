#include <iostream>
#include <cstdlib>

// Function to compute Fibonacci numbers
int fibonacci(int n)
{
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
    return 1;
  }

  int n = std::atoi(argv[1]);
  std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

  return 0;
}
