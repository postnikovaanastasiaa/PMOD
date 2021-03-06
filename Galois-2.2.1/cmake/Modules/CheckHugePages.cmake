include(CheckCSourceRuns)
set(HugePages_C_TEST_SOURCE
"
#ifdef __linux__
#include <linux/mman.h>
#endif
#include <sys/mman.h>

int main(int c, char** argv) {
  void *ptr = mmap(0, 2*1024*1024, PROT_READ|PROT_WRITE, MAP_HUGETLB, -1, 0);

  return ptr != MAP_FAILED;
}
")
CHECK_C_SOURCE_RUNS("${HugePages_C_TEST_SOURCE}" HAVE_HUGEPAGES)
if(HAVE_HUGEPAGES)
  message(STATUS "Huge pages found")
endif()
