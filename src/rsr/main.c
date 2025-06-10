#include <unistd.h>
int main() {
  char *argv[] = {"./app", NULL};
  execve("./app", argv, NULL);
}
