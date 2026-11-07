#include <stdio.h>
#include <sys/utsname.h>

int main(void) {
  struct utsname u;
  if (uname(&u) == 0) {
    printf("hello, userspace! kernel=%s arch=%s\n", u.release, u.machine);
  } else {
    perror("uname");
    return 1;
  }
  return 0;
}

