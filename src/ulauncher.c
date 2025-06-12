#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void ulaunch(int cl) {
  if (cl == 0) printf("\033[2J\033[H");;
  int opt;
  printf("1 - DC Calc\n2 - Email\nEnter your option: ");
  scanf("%d", &opt);
  if (opt == 1) {
      struct stat st;
      char fp[1024];
      const char* HOME = getenv("HOME");
      snprintf(fp, sizeof(fp), "%s/.mycal/dc", HOME);
      if (stat(fp, &st) == 0 && S_ISDIR(st.st_mode)){
	  system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/rndc.sh");
          system("chmod +x ./rndc.sh");
          system("./rndc.sh");
          if(unlink("./rndc.sh") == 0){
            printf("Runner removed\n");
          } else {
            printf("Runner cleanup failed\n");
          }
      } else {
	system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/indc.sh");
	system("chmod +x ./indc.sh");
	system("./indc.sh");
	if(unlink("./indc.sh") == 0){
          printf("GNU DC installer removed\n");
        } else {
          printf("Installer cleanup failed\n");
        }
	ulaunch(0);
      }
  }
  if (opt == 2) {
    struct stat st;
    char fp[1024];
    const char* HOME = getenv("HOME");
    snprintf(fp, sizeof(fp), "%s/.mycal/mail/bin/", HOME);
    if (stat(fp, &st) == 0 && S_ISDIR(st.st_mode)){
      system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/rnm.sh");
      system("chmod +x rnm.sh");
      system("./rnm.sh");
      if (unlink("./rnm.sh") == 0){
	printf("Runner removed\n");
      } else {
	printf("Runner cleanup failed\n");
      }
      } else {
      system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/inm.sh");
      system("chmod +x inm.sh");
      system("./inm.sh");
      system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/muttconfig.sh");
      system("chmod +x muttconfig.sh");
      system("./muttconfig.sh");
      if(unlink("./inm.sh") == 0 && unlink("muttconfig.sh") == 0){
	printf("Mail installer removed\n");
      } else {
	printf("Installer cleanup failed\n");
      }
      ulaunch(0);
    }
  }
}
