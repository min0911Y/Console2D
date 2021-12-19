#include "CONSOLE2D.h"
int Console2D::initWorld(int width, int height)
{
    if (width <= 0 || height <= 0)
    {
        return -1;
    }
    if (width > 100 || height > 100)
    {
        return -1;
    }
    this->width = width;
    this->height = height;
    this->Map[sx][sy] = -1; //-1代表sprite的初始位置
    return 0;
}
void Console2D::Move(int x1)
{
    this->Map[x][y] = 0;
    if (x1 == direction::LEFT)
    {
        if (y > 0 && Map[x][y - 1] != 50)
        {
            y--;
        }
    }
    if (x1 == direction::RIGHT)
    {
        if (y < height - 1 && Map[x][y + 1] != 50)
        {
            y++;
        }
    }
    if (x1 == direction::UP)
    {
        if (x > 0 && Map[x - 1][y] != 50)
        {
            x--;
        }
    }
    if (x1 == direction::DOWN)
    {
        if (x < width - 1 && Map[x + 1][y] != 50)
        {
            x++;
        }
    }
    this->Map[x][y] = -1;
}
void Console2D::initsprite(string str)
{
    this->sprite = str;
}
void Console2D::initspritexy(int sx, int sy)
{
    this->sx = sx;
    this->sy = sy;
    this->x = sx;
    this->y = sy;
}
void Console2D::gotoxy(int x, int y)
{
    //将光标移动到指定位置
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Console2D::BodyCollisionDetection(int x, int y)
{
    if (this->Map[x][y] != 50)
    {
        this->Map[x][y] = 50;
    }
}
void Console2D::CreateBlock(int x, int y, string str)
{
    this->blockMap[x][y] = count;
    this->block[count] = str;
    this->Map[x][y] = 1;
    count++;
}
void Console2D::view_map()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (Map[i][j] == -1)
            {
                cout << sprite;
                continue;
            }
            if (blockMap[i][j] != 0)
            {
                cout << block[blockMap[i][j]];
                continue;
            }
            if (Map[i][j] == 0)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void Console2D::game()
{
    this->start();
    while (1)
    {
        this->update();
        gotoxy(0, 0);
    }
}
void Console2D::clearall()
{
    //Map
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (Map[i][j] == -1)
            {
                continue;
            }
            Map[i][j] = 0;
        }
    }
    //blockMap
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            blockMap[i][j] = 0;
        }
    }
    count = 1;
    //block
    for (int i = 0; i < 100 * 100; i++)
    {
        block[i] = "\0";
    }
    worldcount++;
}
void Console2D::outputFlashingstring(int x1, int y1, string str1)
{
    for (int i = 0; i < 5; i++)
    {
        gotoxy(x1, y1);
        cout << str1;
        Sleep(500);
        gotoxy(x1, y1);
        for(int j=0;j<str1.length();j++)
        {
            cout << " ";
        }
        Sleep(500);
    }
}
