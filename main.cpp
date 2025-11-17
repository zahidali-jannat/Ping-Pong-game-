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
        
        //  ballX+=3; // This will increase the ball x position by 3 pixels at every loop which run 60 in one second 
        // but we want keyboard controls into the program 
        if(IsKeyDown(KEY_RIGHT))
        {
            ballX+=3;
        }
        else if(IsKeyDown(KEY_LEFT))
        {
            ballX-=3;
        }
        else if(IsKeyDown(KEY_UP))
        {
            ballY-=3;
        }
        else if(IsKeyDown(KEY_DOWN))
        {
            ballY+=3;
        }
        
        BeginDrawing();
        ClearBackground(background);
        DrawCircle(ballX, ballY, ballRadius, ballColor);
        EndDrawing();
    }
    
    CloseWindow();
  return 0;
}