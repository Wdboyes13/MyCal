#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
void launcher() {
  int opt;
  printf("1 - Doom\nEnter Option: ");
  scanf("%d", &opt);
  if (opt == 1){
    struct stat st;
    const char* HOME = getenv("HOME");
    char fp[1024];
    snprintf(fp, sizeof(fp), "%s/.mycal/doom/launch/usr/local/bin", HOME);
    if (stat(fp, &st) == 0){
      if ((st.st_mode & S_IFDIR) != 0){
	system("wget ");
	system("./rnd.sh");
      }
    } else {
      // Install Here
    }
  }
  system("");
}
