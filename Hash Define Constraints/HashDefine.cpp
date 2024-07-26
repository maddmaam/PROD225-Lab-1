#include <iostream>
#include <conio.h>
#include <winerror.h>

#define LEFTKEY 75
#define RIGHTKEY 77
#define UPKEY 72
#define DOWNKEY 80

int main() 
{
    unsigned char KeyPressed = '\0';
    do
    {
        KeyPressed = _getch();
        if (KeyPressed == 224)
        {
            char ArrowKey = _getch();
            switch (ArrowKey)
            {
            case LEFTKEY:
                std::cout << "Left" << std::endl;
                break;
            case RIGHTKEY:
                std::cout << "Right" << std::endl;
                break;
            case UPKEY:
                std::cout << "Up" << std::endl;
                break;
            case DOWNKEY:
                std::cout << "Down" << std::endl;
                break;
            default:
                break;
            }
        }
    } 
    while (KeyPressed != 'q' && KeyPressed != 'Q');

    return ERROR_SUCCESS;
}