#include "CONSOLE2D.h"
Console2D console;
void createBlock(int x, int y, string str);
void createstringblock(int startx, int starty, string str);
int main()
{

    //console.func();
    console.initsprite("O");
    console.initspritexy(0, 0);
    console.initWorld(20, 20);
    createstringblock(10, 5, "hello world!");

    console.game();

    return 0;
}
void createBlock(int x, int y, string str)
{
    console.CreateBlock(x, y, str);
    console.BodyCollisionDetection(x, y);
}
void createstringblock(int startx, int starty, string str)
{
    for (int i = 0, j = 0, k = starty; i < str.length(); i++, j++)
    {
        char ch[20];
        ch[0] = str[i];
        console.CreateBlock(startx, starty + j, ch);
        console.BodyCollisionDetection(startx, starty + j);
        if (j + k == console.get_width() - 1)
        {
            starty = 0;
            startx++;
            j = 0;
            k = 0;
        }
    }
}
void Console2D::start()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    system("cls");
    outputFlashingstring(10, 10, "Game Start!");
    system("cls");
}
void Console2D::update()
{

    view_map();
    //键盘移动
    if (_kbhit())
    {
        int x1 = _getch();
        //调用移动函数
        if (x1 == 'w' || x1 == 'W')
        {
            Move(direction::UP);
        }
        if (x1 == 's' || x1 == 'S')
        {
            Move(direction::DOWN);
        }
        if (x1 == 'a' || x1 == 'A')
        {
            Move(direction::LEFT);
        }
        if (x1 == 'd' || x1 == 'D')
        {
            Move(direction::RIGHT);
        }
    }
    if (PlayerChedaceRtainPOS(10, 4) && console.get_worldcount() == 0)
    {
        clearall();
        console.CreateBlock(0,console.get_worldcount(), "J");
        Sleep(500);
    }
    this->gotoxy(30, 0);
    cout << "test game 1.0";
    this->gotoxy(30, 1);
    cout << "x=" << x << "      ";
    this->gotoxy(30, 2);
    cout << "y=" << y << "      ";
}