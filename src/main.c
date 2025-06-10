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
#include <raylib.h>
int main() {
  InitWindow(800, 600, "MyCal");
  SetTargetFPS(60);
  Rectangle scbutton = {350, 280, 100, 50};
  Color scbuttoncol = BLACK;
  Font roboto = LoadFontEx("Roboto.ttf", 40, 0, 0);
  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);

    if (CheckCollisionPointRec(GetMousePosition(), scbutton)){
      scbuttoncol = DARKGRAY;
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
	sched();
      }
    } else {
      scbuttoncol = BLACK;
    }

    DrawRectangleRec(scbutton, scbuttoncol);
    DrawTextEx(roboto, "Schedule", (Vector2){scbutton.x + 12, scbutton.y + 15}, 20, 1, WHITE);

    EndDrawing();
  }
  UnloadFont(roboto);
  CloseWindow();
  return 0;
}
