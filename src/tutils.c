#include "tutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int time_to_minutes(const char *tstr) {
  int h, m;
  if (sscanf(tstr, "%d:%d", &h, &m) != 2 || h < 0 || h > 23 || m < 0 ||
      m > 59) {
    fprintf(stderr, "Invalid time format: %s\n", tstr);
    exit(1);
  }
  return h * 60 + m;
}

int get_current_minutes() {
  time_t now = time(NULL);
  struct tm *lt = localtime(&now);
  return lt->tm_hour * 60 + lt->tm_min;
}

int is_time_in_range(const char *start, const char *end) {
  int start_min = time_to_minutes(start);
  int end_min = time_to_minutes(end);
  int curr_min = get_current_minutes();

  if (start_min <= end_min) {
    // e.g. 01:00 - 23:00
    return curr_min >= start_min && curr_min <= end_min;
  } else {
    // e.g. 23:00 - 01:00 (wrap around midnight)
    return curr_min >= start_min || curr_min <= end_min;
  }
}
