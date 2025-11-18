#include "raylib.h"
#include <iostream>

using namespace std;
// create a class Ball:
class Ball{
    public:
    float x , y; int speed_x , speed_y; int radius; 
    void draw()
    {
         DrawCircle(x , y , 20, WHITE);
    }
    // for the movement of the ball
    void update()
    {
        x+=speed_x;
        y+=speed_y;
        if(y+radius >=GetScreenHeight() || y-radius<=0)
        {
            speed_y*=-1;
        }
        if(x+radius >=GetScreenWidth() || x-radius<=0){
            speed_x*=-1;
        }
    }
};
Ball ball;

int main()
{
     Color background={20 , 170 , 133 , 255};
    const int screen_width=1280;
    const int screen_length=800;
    InitWindow(screen_width , screen_length , "My ping pong game");
    SetTargetFPS(60);
    ball.x=screen_width/2;
    ball.y=screen_length/2;
    ball.speed_x=7;
    ball.speed_y=7;

    while(!WindowShouldClose())
    {     
          
          BeginDrawing();
          ball.update();

          ClearBackground(background);
          DrawLine(screen_width/2 , 0 , screen_width/2 ,screen_length , WHITE);  
          ball.draw();
          DrawRectangle(10, (screen_length/2)-60, 25 , 120 , WHITE);
          DrawRectangle(screen_width-35, (screen_length/2)-60, 25 , 120 , WHITE);

          EndDrawing();
    }
    CloseWindow(); // To destroy the window 
}