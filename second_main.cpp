#include "raylib.h"
#include <iostream>

using namespace std;
int player_score=0;
int cpu_score=0;
Color green=Color{38 , 185 , 154 , 255};
Color dark_green=Color{38 , 185 , 154 , 255};
Color light_green=Color{38 , 185 , 154 , 255};
Color yellow=Color{243 , 213 , 91 , 255};
// create a class Ball:
class Ball{
    public:
    float x , y; int speed_x , speed_y; int radius; 
    void draw()
    {
         DrawCircle(x , y , 20, yellow);
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
        if(x+radius>=GetScreenWidth())
        {
         cpu_score++;
        }
        if(x-radius<=0)
        {
            player_score++;
        }
    }
};
class Paddle{
    public:
    float x , y; float width , height; int speed;
    void Draw()
    {
         DrawRectangleRounded(Rectangle{x , y ,width , height} , 0.8 , 0 , WHITE);
    }
    void update()
    {   if(IsKeyDown(KEY_DOWN))
        {
            y+=speed;
        }
        if(IsKeyDown(KEY_UP))
        {
            y=y-speed;
        }
        if(y+(height)/2 >=GetScreenHeight()-60 || y-(height/2) <=-60)
        {
            speed*=-1;
        }
    }
};
class CPU_PADDLE: public Paddle{
public: 

 void update(int ball_x)
 {
   // If y position of ball is greater than y position of paddle move it up other wise down 
   if(y+(height)/2 > ball_x)
   {
    y=y-speed;
   }
   if(y+(height)/2 <= ball_x)
   {
    y=y+speed;
   }
 }
};
Ball ball;
Paddle player;
CPU_PADDLE cpu_paddle;
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
    player.height=120;
    player.width=25;
    player.x=screen_width-25-10;
    player.y=(screen_length)/2 -60;
    player.speed=7;
    cpu_paddle.height=120;
    cpu_paddle.width=25;
    cpu_paddle.x=10;
    cpu_paddle.y=(screen_length)/2-60;
    cpu_paddle.speed=7;

    while(!WindowShouldClose())
    {     
          
          BeginDrawing();
          ball.update();
          player.update();
          cpu_paddle.update(ball.y);
          if(CheckCollisionCircleRec(Vector2{ball.x, ball.y} , ball.radius , Rectangle{player.x , player.y , player.width , player.height}))
          {
            ball.speed_x*=-1; 
          }
           if(CheckCollisionCircleRec(Vector2{ball.x, ball.y} , ball.radius , Rectangle{cpu_paddle.x , cpu_paddle.y , cpu_paddle.width , cpu_paddle.height}))
          {
            ball.speed_x*=-1;
          }

          
        

          ClearBackground(background);
          DrawLine(screen_width/2 , 0 , screen_width/2 ,screen_length , WHITE); 
          DrawRectangle(screen_width/2, 0 , screen_width/2 , screen_length , dark_green); 
          DrawCircle(screen_width/2 , screen_length/2 , 100 , light_green);
          ball.draw();
          cpu_paddle.Draw();
          player.Draw();
          DrawText(TextFormat("%i" , cpu_score) , screen_width/4-20  , 20 , 80 ,WHITE);
            DrawText(TextFormat("%i" , player_score) , 3*  screen_width/4-20 , 20 , 80 ,WHITE);
          EndDrawing();
    }
    CloseWindow(); // To destroy the window 
}