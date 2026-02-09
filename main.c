#include "game.h"

void menu() {
    printf("请选择：\n");
    printf("1.Start\n");
    printf("0.Exit\n");
}

void game()
{
    char realboard[ROWS][COLS] = { 0 };
    char showboard[ROWS][COLS] = { 0 };    
    //初始化雷地（二维数组）
    initboard(realboard, ROWS, COLS, '0');
    initboard(showboard, ROWS, COLS, '*');
    
    printboard(realboard, ROW, COL);
    printboard(showboard, ROW, COL);
    
    setboard(realboard, ROW, COL);
    printboard(realboard, ROW, COL);
    printboard(showboard, ROW, COL);
    
    exclude(realboard, showboard, ROW, COL);
    
}
void test()
{
    unsigned int selection = 0;
    do {
        menu();
        printf("Please select :");
        scanf("%d", &selection);
        switch(selection)
        {
        case 1: 
            game();
            break;
        case 0:
            printf("Exit the game\n");
            break;
        default:
            printf("error selection\n");
            break;
        }
        
    } while(selection);
}

int main()
{
    int a = 0;
    printf("中文测试\n");
    srand((unsigned)(time(NULL)));
    test();
    scanf("%d",&a);
}
















// #include <iostream>
// #include <vector>
// #include <string>
// int main()
// {
//     std::vector<std::string> msg{"hello", "C++", "in" , "Termux"};
//         for (const std::string& word : msg)
//         {
//             std::cout << word << " ";
//         }
//     std::cout << std::endl;
// }


