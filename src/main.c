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
#include <stdbool.h>
  
int rlmain() {
  InitWindow(800, 600, "MyCal");
  InitAudioDevice();
  Music music = LoadMusicStream("PixelPeekerPolka-faster.mp3");
  bool mlo = true;
  PlayMusicStream(music);
  SetTargetFPS(60);
  Rectangle glbutton = {343, 220, 120, 50};
  Rectangle scbutton = {350, 280, 100, 50};
  Color scbuttoncol = BLACK;
  Color glbuttoncol = BLACK;
  Font roboto = LoadFontEx("Roboto.ttf", 40, 0, 0);
  bool rbl = true;
  bool wino = true;
  Image img = LoadImage("icon.png");
  bool imo = true;
  Rectangle ascbutton = {343, 345, 120, 50};
  Color ascbuttoncol = BLACK;
  
  SetWindowIcon(img);
  
  while (!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(WHITE);
    UpdateMusicStream(music);
    if (!IsMusicStreamPlaying(music)){
      PlayMusicStream(music);
    }
    
    if (CheckCollisionPointRec(GetMousePosition(), glbutton)){
      glbuttoncol = DARKGRAY;
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
	  if (rbl == true){UnloadFont(roboto); rbl = false;}
          if (wino == true){CloseWindow(); wino = false;}
          if (imo == true) {UnloadImage(img); imo = false;}
	  if (mlo == true) {StopMusicStream(music); UnloadMusicStream(music); CloseAudioDevice(); mlo = false;}
	  launcher(0);
          break;
      }
    } else {
      glbuttoncol = BLACK;
    }
    
    if (CheckCollisionPointRec(GetMousePosition(), scbutton)){
      scbuttoncol = DARKGRAY;
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
	      if (rbl == true){UnloadFont(roboto); rbl = false;}
	      if (wino == true){CloseWindow(); wino = false;}
        if (imo == true) {UnloadImage(img); imo = false;}
	if (mlo == true) {StopMusicStream(music); UnloadMusicStream(music); CloseAudioDevice(); mlo = false;}
	      sched();
	      break;
      }
    } else {
      scbuttoncol = BLACK;
    }
    
    if (CheckCollisionPointRec(GetMousePosition(), ascbutton)){
      ascbuttoncol = DARKGRAY;
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
	      if (rbl == true){UnloadFont(roboto); rbl = false;}
	      if (wino == true){CloseWindow(); wino = false;}
        if (imo == true) {UnloadImage(img); imo = false;}
	if (mlo == true) {StopMusicStream(music); UnloadMusicStream(music); CloseAudioDevice(); mlo = false;}
	      assched();
	      break;
      }
    } else {
      ascbuttoncol = BLACK;
    }

    DrawRectangleRec(glbutton, glbuttoncol);
    DrawTextEx(roboto, "GLauncher", (Vector2){glbutton.x + 10, glbutton.y+ 15}, 20, 1, WHITE);
    
    DrawRectangleRec(ascbutton, ascbuttoncol);
    DrawTextEx(roboto, "AS Schedule", (Vector2){ascbutton.x + 10, ascbutton.y+ 15}, 20, 1, WHITE);
    
    
    DrawRectangleRec(scbutton, scbuttoncol);
    DrawTextEx(roboto, "Schedule", (Vector2){scbutton.x + 12, scbutton.y + 15}, 20, 1, WHITE);
    
    EndDrawing();
  }
  if (rbl == true){UnloadFont(roboto);}
  if (wino == true){CloseWindow();}
  if (imo == true) {UnloadImage(img); imo = false;}
  if (mlo == true) {StopMusicStream(music); UnloadMusicStream(music); CloseAudioDevice(); mlo = false;}
  return 0;
}
int main() {
  rlmain();
  return 0;
}
