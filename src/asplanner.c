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
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
void assched() {
  int odl;
  int oel;
  shutup_begin(&odl, &oel);
  InitWindow(800, 600, "After School Planner");
  bool wino = true;
  InitAudioDevice();
  Music music = LoadMusicStream("PixelPeekerPolka-faster.mp3");
  bool mlo = true;
  PlayMusicStream(music);
  Font roboto = LoadFontEx("Roboto.ttf", 35, 0, 0);
  bool robo = true;
  Image img = LoadImage("icon.png");
  bool imo = true;
  xmlInitParser();
  xmlDocPtr doc = xmlReadFile("asc.xml", NULL, 0);
  shutup_end(odl, oel);
  if (doc == NULL) {
    fprintf(stderr, "Failed to parse XML");
    exit(1);
  }
  const char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  int dayX[] = {50, 180, 310, 440, 570};
  int dayC = 5;

  xmlNodePtr root = xmlDocGetRootElement(doc);

  SetWindowIcon(img);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    UpdateMusicStream(music);
    if (!IsMusicStreamPlaying(music)) {
      PlayMusicStream(music);
    }
    for (int i = 0; i < dayC; i++) {
      time_t now = time(NULL);
      struct tm *local = localtime(&now);
      int wday = local->tm_wday;
      int adwday = (wday == 0) ? 6 : wday - 1;

      Color COLOUR = (i == adwday) ? RED : BLACK;
      DrawTextEx(roboto, days[i], (Vector2){dayX[i], 10}, 25, 1, COLOUR);
    }
    for (xmlNodePtr node = root->children; node != NULL; node = node->next) {
      if (node->type == XML_ELEMENT_NODE) {
        const char *dayN = (const char *)node->name;
        int col = -1;
        for (int i = 0; i < dayC; i++) {
          if (strcasecmp(dayN, days[i]) == 0) {
            col = i;
            break;
          }
        }
        if (col == -1)
          continue;

        int tDex = 0;
        for (xmlNodePtr task = node->children; task != NULL;
             task = task->next) {
          if (task->type == XML_ELEMENT_NODE &&
              strcasecmp((const char *)task->name, "task") == 0) {
            xmlChar *cont = xmlNodeGetContent(task);
            if (cont && col >= 0) {
              if (col == -1) {
                printf("Unknown day node: %s\n", dayN);
                continue;
              }
              Vector2 pos = {dayX[col], 50 + tDex * 40};
              DrawTextEx(roboto, (const char *)cont, pos, 20, 1, BLACK);
              xmlFree(cont);
              tDex++;
            }
          }
        }
      }
    }
    EndDrawing();
    if (IsKeyPressed(KEY_ESCAPE)) {
      if (robo == true) {
        UnloadFont(roboto);
        robo = false;
      }
      if (wino == true) {
        CloseWindow();
        wino = false;
      }
      if (imo == true) {
        UnloadImage(img);
        imo = false;
      }
      if (mlo == true) {
        StopMusicStream(music);
        UnloadMusicStream(music);
        CloseAudioDevice();
        mlo = false;
      }
      char *argv[] = {"./rsr", NULL};
      execve("./rsr", argv, NULL);
    }
  }
  xmlFreeDoc(doc);
  xmlCleanupParser();
  if (mlo == true) {
    StopMusicStream(music);
    UnloadMusicStream(music);
    CloseAudioDevice();
    mlo = false;
  }
  if (imo == true) {
    UnloadImage(img);
    imo = false;
  }
  if (robo == true) {
    UnloadFont(roboto);
    robo = false;
  }
  if (wino == true) {
    CloseWindow();
    wino = false;
  }
}
