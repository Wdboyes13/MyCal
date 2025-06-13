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
#include "tutils.h"
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
void sched() {
  int odl;
  int oel;
  shutup_begin(&odl, &oel);
  InitWindow(1000, 600, "Planner");
  bool wino = true;
  InitAudioDevice();
  Music music = LoadMusicStream("PixelPeekerPolka-faster.mp3");
  bool mlo = true;
  PlayMusicStream(music);

  Font roboto = LoadFontEx("Roboto.ttf", 40, 0, 0);
  bool robo = true;
  Image img = LoadImage("icon.png");
  bool imo = true;

  SetWindowIcon(img);
  xmlInitParser();
  xmlDocPtr doc = xmlReadFile("dsc.xml", NULL, 0);
  shutup_end(odl, oel);
  while (!WindowShouldClose()) {
    UpdateMusicStream(music);
    if (!IsMusicStreamPlaying(music)) {
      PlayMusicStream(music);
    }
    BeginDrawing();
    ClearBackground(WHITE);
    if (doc == NULL) {
      fprintf(stderr, "Failed to parse XML\n");
      exit(1);
    }
    xmlNodePtr root = xmlDocGetRootElement(doc);
    int dayDex = 0;
    int stX = 50;
    int stY = 50;
    int colW = 400;
    int bloH = 40;

    for (xmlNodePtr node = root->children; node != NULL; node = node->next) {
      if (node->type == XML_ELEMENT_NODE) {
        int x = stX + (dayDex * colW);
        int y = stY;

        xmlChar *attr = xmlGetProp(node, (const xmlChar *)"num");
        if (attr != NULL) {
          char buf[256];
          snprintf(buf, sizeof(buf), "Day %s", attr);
          DrawTextEx(roboto, buf, (Vector2){x, y}, 30, 2, BLACK);
          y += 50;
          xmlFree(attr);
        }

        for (xmlNodePtr cnode = node->children; cnode != NULL;
             cnode = cnode->next) {
          if (cnode->type == XML_ELEMENT_NODE) {
            xmlChar *cattr = xmlGetProp(cnode, (const xmlChar *)"num");
            xmlChar *bcont = xmlNodeGetContent(cnode);
            xmlChar *times = xmlGetProp(cnode, (const xmlChar *)"ts");
            xmlChar *timee = xmlGetProp(cnode, (const xmlChar *)"te");
            if (cattr != NULL) {
              char bbuf[256];

              snprintf(bbuf, sizeof(bbuf),
                       "\t Block %s  -  Start: %s End: %s  -  %s", cattr, times,
                       timee, bcont);
              Color COLOUR =
                  is_time_in_range((const char *)times, (const char *)timee)
                      ? RED
                      : DARKGRAY;
              DrawTextEx(roboto, bbuf, (Vector2){x, y}, 20, 1, COLOUR);
              y += bloH;
              xmlFree(timee);
              xmlFree(bcont);
              xmlFree(cattr);
              xmlFree(times);
            } else if (strcasecmp((const char *)bcont, "Break") == 0 ||
                       strcasecmp((const char *)bcont, "Lunch") == 0) {
              char bbuf[256];
              Color COLOUR =
                  is_time_in_range((const char *)times, (const char *)timee)
                      ? RED
                      : DARKGRAY;

              snprintf(bbuf, sizeof(bbuf), "\t Start: %s End: %s  -  %s", times,
                       timee, bcont);
              DrawTextEx(roboto, bbuf, (Vector2){x, y}, 20, 1, COLOUR);
              y += bloH;
              xmlFree(timee);
              xmlFree(bcont);
              xmlFree(cattr);
              xmlFree(times);
            } else {
              xmlFree(timee);
              xmlFree(times);
              xmlFree(bcont);
              xmlFree(cattr);
            }
          }
        }

        dayDex++;
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
  xmlFreeDoc(doc);
  xmlCleanupParser();
  exit(0);
}
