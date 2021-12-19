#define CONSOL2D_H
#ifdef CONSOL2D_H
#include "ALLHEADER.h"
class Console2D
{
public:
    int initWorld(int width, int height);
    void initsprite(string str);
    void initspritexy(int sx, int sy);
    void Move(int x1);
    void gotoxy(int x, int y);
    void CreateBlock(int x, int y, string str);
    void BodyCollisionDetection(int x, int y);
    void view_map();
    void start();
    void update();
    void game();
    void clearall();
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
    int get_width(){
        return width;
    }
    int get_height(){
        return height;
    }
    int get_worldcount(){
        return worldcount;
    }
    void outputFlashingstring(int x1, int y1, string str1);
    bool PlayerChedaceRtainPOS(int x, int y){
        if(this->x == x && this->y == y){
            return true;
        }
        return false;
    }
    void set_sprite_x_y(int x, int y){
        this->x = x;
        this->y = y;
    }
    void set_sprite(string str){
        this->sprite = str;
    }

private:
    int width;
    int height;
    int x;
    int y;
    int sx;
    int sy;
    int Map[100][100];
    int count = 1;
    int blockMap[100][100];
    string sprite;
    string block[100 * 100];
    int worldcount = 0; //图层数量
};

enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
#endif
