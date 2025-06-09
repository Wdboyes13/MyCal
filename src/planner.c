#include <stdio.h>
#include <raylib.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <stdlib.h>
#include "stuff.h"
#include <string.h>
void sched() {
  InitWindow(800, 600, "Planner");
  Font roboto = LoadFontEx("Roboto.ttf", 40, 0, 0);
  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);
    xmlInitParser();
    xmlDocPtr doc = xmlReadFile("dsc.xml", NULL, 0);
    if (doc == NULL){
      fprintf(stderr, "Failed to parse XML\n");
      exit(1);
    }
    xmlNodePtr root = xmlDocGetRootElement(doc);
    int dayDex = 0;
    int stX = 50;
    int stY = 50;
    int colW = 250;
    int bloH = 40;

    for (xmlNodePtr node = root->children; node != NULL; node = node->next){
      if (node->type == XML_ELEMENT_NODE) {
	int x = stX + (dayDex * colW);
	int y = stY;
	
	xmlChar* attr = xmlGetProp(node, (const xmlChar*)"num");
	if (attr != NULL){
	  char buf[256];
	  snprintf(buf, sizeof(buf), "Day %s", attr);
	  DrawTextEx(roboto, buf, (Vector2){x, y}, 30, 2, BLACK);  
	  y +=50;
	  xmlFree(attr);
	}
	
	for (xmlNodePtr cnode = node->children; cnode != NULL; cnode = cnode->next){
	  if (cnode->type == XML_ELEMENT_NODE){
	    xmlChar* cattr = xmlGetProp(cnode, (const xmlChar*)"num");
	    if (cattr != NULL){
	      xmlChar* bcont = xmlNodeGetContent(cnode);
	      char bbuf[256];
	      snprintf(bbuf, sizeof(bbuf), "\t Block %s : %s", cattr, bcont);
	      DrawTextEx(roboto, bbuf, (Vector2){x, y}, 20, 1, DARKGRAY);
	      y += bloH;
	      xmlFree(bcont);
	      xmlFree(cattr);
	    }
	  }
	}

	dayDex++;
      }
    }
    EndDrawing();
    xmlCleanupParser();
    xmlFreeDoc(doc);
  }
  CloseWindow();
  UnloadFont(roboto);
  exit(0);
}
