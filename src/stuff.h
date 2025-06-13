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

#pragma once

void sched();
int rlmain();
void assched();
void launcher(int cl);
void ulaunch(int cl);

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static inline void shutup_begin(int *old_stdout_fd, int *old_stderr_fd) {
  *old_stdout_fd = dup(STDOUT_FILENO); // Save stdout
  *old_stderr_fd = dup(STDERR_FILENO); // Save stderr

  int devnull = open("/dev/null", O_WRONLY);

  dup2(devnull, STDOUT_FILENO); // Redirect stdout -> /dev/null
  dup2(devnull, STDERR_FILENO); // Redirect stderr -> /dev/null

  close(devnull);
}

static inline void shutup_end(int old_stdout_fd, int old_stderr_fd) {
  dup2(old_stdout_fd, STDOUT_FILENO); // Restore stdout
  close(old_stdout_fd);

  dup2(old_stderr_fd, STDERR_FILENO); // Restore stderr
  close(old_stderr_fd);
}
