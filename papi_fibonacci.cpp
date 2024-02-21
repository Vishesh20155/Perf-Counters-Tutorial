#include <iostream>
#include <cstdlib>
#include <papi.h>

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

  int retval, EventSet = PAPI_NULL;
  long_long values[2] = {0};

  /* Initialize the PAPI library */
  retval = PAPI_library_init(PAPI_VER_CURRENT);
  if (retval != PAPI_VER_CURRENT)
  {
    fprintf(stderr, "PAPI library init error!\n");
    exit(1);
  }

  /* Create the Event Set */
  if ((retval=PAPI_create_eventset(&EventSet)) != PAPI_OK)
    printf("%s:%d\t ERROR (code = %d)\n", __FILE__, __LINE__, retval);

  /* Add Total Instructions Executed to our EventSet */
  if ((retval=PAPI_add_event(EventSet, PAPI_FNV_INS)) != PAPI_OK)
    printf("%s:%d\t ERROR (code = %d)\n", __FILE__, __LINE__, retval);

  /* Add Total Instructions Executed to our EventSet */
  if (PAPI_add_event(EventSet, PAPI_TOT_CYC) != PAPI_OK)
    printf("%s:%d\t ERROR\n", __FILE__, __LINE__);

  /* Start counting */
  if (PAPI_start(EventSet) != PAPI_OK)
    printf("%s:%d\t ERROR\n", __FILE__, __LINE__);

  // Compute Fibonacci number
  int result = fibonacci(n);

  if (PAPI_stop(EventSet, values) != PAPI_OK)
    printf("%s:%d\t ERROR\n", __FILE__, __LINE__);

  if (PAPI_read(EventSet, values) != PAPI_OK)
    printf("%s:%d\t ERROR\n", __FILE__, __LINE__);
  printf("\nTotal Instructions Completed:\t%lld\t Total Cycles:\t%lld\n", values[0], values[1]);

  // Output the Fibonacci result
  std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

  // Output PAPI counters
  // Shutdown PAPI
  PAPI_shutdown();

  return 0;
}