# Perf Counters

Important links:
https://perf.wiki.kernel.org/index.php/Tutorial

https://unix.stackexchange.com/questions/14227/do-i-need-root-admin-permissions-to-run-userspace-perf-tool-perf-events-ar

### Installation

Command: `sudo apt-get install linux-tools-common linux-tools-$(uname -r)`

### Example

* File: fibonacci.cpp

* Compile using the command `make`

* Ensure that the hardware permissions are set using the command:
`sudo sysctl kernel.perf_event_paranoid=-1`
  
  * The permissions can also be set permanently by modifying the file `/etc/sysctl.conf` and setting this value: `kernel.perf_event_paranoid = -1`

  * Meanings of different levels:

    > -1: Allow use of (almost) all events by all users
        Ignore mlock limit after perf_event_mlock_kb without CAP_IPC_LOCK

    > \>= 0: Disallow ftrace function tracepoint by users without CAP_SYS_ADMIN
        Disallow raw tracepoint access by users without CAP_SYS_ADMIN
    
    > \>= 1: Disallow CPU event access by users without CAP_SYS_ADMIN
    
    > \>= 2: Disallow kernel profiling by users without CAP_SYS_ADMIN

* Run using: `perf stat ./fibonacci <number>`
  specify a number to compute fibonacci in place of `<number>`.

## PAPI Library


This labrary allows us to read perf counter variables from C/C++ code.

Links:

* https://github.com/icl-utk-edu/papi/wiki/

* https://github.com/icl-utk-edu/papi


## Installation

* Using apt `sudo apt-get install libpapi-dev`

* In case the above method does not work, build it from source using the following: https://github.com/icl-utk-edu/papi/wiki/Downloading-and-Installing-PAPI

* Example usage in papi_fibonacci.cpp

* Execute using:

  * `make`

  * `./papi_fibonacci.cpp <number>`

* Do not forget to add `-lpapi` flag for compiling the code using papi library.