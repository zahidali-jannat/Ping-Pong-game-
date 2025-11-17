#include "raylib.h"

int main() {
    InitWindow(1000 , 1000  ,"My First game ");
    SetTargetFPS(60);
    int ballX = 500;
    int ballY = 500;
    int ballRadius = 20;
    Color ballColor = WHITE;
    Color background={20 , 170 , 133 , 255};

     
    while (!WindowShouldClose())
    {
        
        ballX+=3;
        
        BeginDrawing();
        ClearBackground(background);
        DrawCircle(ballX, ballY, ballRadius, ballColor);
        EndDrawing();
    }
    
    CloseWindow();
  return 0;
}