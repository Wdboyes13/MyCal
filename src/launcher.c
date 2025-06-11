/*
MyCal - A Planner & Calendar app with a UI
Copyright (C) 2025  Wdboyes13

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "stuff.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
void launcher(int cl) {
  if (cl == 0) printf("\033[2J\033[H");
  printf("Enter password: ");
  int pass = 2398;
  int epass;
  scanf("%d", &epass);
  if (epass == pass){
  int opt;
  printf("1 - Doom\nEnter Option: ");
  scanf("%d", &opt);
  if (opt == 1){
    struct stat st;
    const char* HOME = getenv("HOME");
    char fp[1024];
    snprintf(fp, sizeof(fp), "%s/.mycal/doom/launch/usr/local/bin", HOME);
    if (stat(fp, &st) == 0 && S_ISDIR(st.st_mode)){
	system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/rnd.sh");
	system("chmod +x rnd.sh");
	system("./rnd.sh");
	if (unlink("rnd.sh") == 0) {
	  printf("Runner removed\n");
	} else {
	  printf("Runner cleanup failed\n");
	}
    } else {
      printf("Doom not installed\n");
      system("wget https://github.com/Wdboyes13/MyCal/raw/refs/heads/main/other/ind.sh");
      system("chmod +x ind.sh");
      system("./ind.sh");
      if (unlink("ind.sh") == 0) {
	printf("Installer removed\n");
      } else {
	printf("Installer removal failed\n");
	exit(1);
      }
      launcher(0);
    }
  }
  } else {
    printf("Incorrect password\n");
    launcher(1);
  }
}
