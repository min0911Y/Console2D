#  Console2D 一个控制台2D游戏框架
## 版本1.0
# 使用教程
## 1. initworld函数介绍
+ 函数原型：int initWorld(int width, int height);

+ 作用：根据所填的高度 宽度 init地图
## 2. CreateBlock函数介绍
+ 函数原型：void CreateBlock(int x, int y, string str);
+ 作用：创建一个方块（无碰撞检测）
## 3. initsprite函数介绍
+ 函数原型：void initsprite(string str);
+ 作用：制定主角的样貌
## 4. Move函数介绍
+ 函数原型：void Move(int x1);
+ 用法：通过direction这个枚举指定方向 
+ 作用：让主角移动
## 5. gotoxy函数介绍
+ 函数原型：void gotoxy(int x, int y);
+ 作用：移动光标到指定位置
## 6. initspritexy函数介绍
+ 函数原型：void initspritexy(int sx, int sy);
+ 作用：设定主角的位置
## 7. BodyCollisionDetection函数介绍
+ 函数原型：void BodyCollisionDetection(int x, int y);
+ 作用：在指定位置添加一个方块碰撞检测
## 8. view_map函数介绍
+ 函数原型：void view_map();
+ 作用：显示地图
## 9. get系列函数介绍
+ 简单来说 get_x函数 就是获取主角的x坐标
+ get_width函数 就是获取地图的宽度
+ 其他的也以此类推
## 10. start函数介绍
+ 函数原型：void start();
+ 这个函数你将会在main.cpp中编写
+ 可以在这里添加一些游戏的初始化代码
+ 这个函数会在游戏开始的时候被调用
## 11. update函数介绍
+ 函数原型：void update();
+ 这个函数你将会在main.cpp中编写
+ 可以在这里添加游戏的一些代码
+ 这个函数会在游戏运行时无限循环调用
+ 可以理解为unity脚本的update函数
## 12. clearall函数介绍
+ 函数原型：void clearall();
+ 作用：清除所有方块 worldcount变量自增
## 13. PlayerChedaceRtainPOS函数介绍
+ 函数原型：bool PlayerChedaceRtainPOS(int x, int y);
+ 作用：检测主角是否在指定位置 并返回一个bool值
## 14. set系列函数介绍
+ 简单来说 set_sprite_x_y函数 就是设置主角的位置
+ set_sprite就是设置主角的样貌
## 15. outputFlashingstring函数介绍
+ 函数原型：void outputFlashingstring(int x1, int y1, string str1)
+ 作用：在指定位置输出一个闪烁的字符串