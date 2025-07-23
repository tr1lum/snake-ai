#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // Windows下用，Linux下请用termios实现getch()

int main() {
    Snake snake;
    Point food;
    int gameover = 0;

    srand((unsigned)time(NULL));
    init_snake(&snake);
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;

    while (!gameover) {
        draw(&snake, &food);

        // 非阻塞读取键盘方向
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
                snake.direction = ch;
        }

        move_snake(&snake);

        if (check_collision(&snake)) {
            printf("Game Over!\n");
            break;
        }
        eat_food(&snake, &food);
        _sleep(100); // Windows下，Linux可用usleep
    }
    return 0;
}
