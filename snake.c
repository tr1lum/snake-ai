#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_snake(Snake *snake) {
    snake->length = 3;
    snake->body[0] = (Point){WIDTH / 2, HEIGHT / 2};
    snake->body[1] = (Point){WIDTH / 2 - 1, HEIGHT / 2};
    snake->body[2] = (Point){WIDTH / 2 - 2, HEIGHT / 2};
    snake->direction = 'd';
}

void draw(const Snake *snake, const Point *food) {
    system("clear"); // or "cls" on Windows
    // 画边框
    for (int y = 0; y <= HEIGHT; y++) {
        for (int x = 0; x <= WIDTH; x++) {
            int is_body = 0;
            for (int i = 0; i < snake->length; i++) {
                if (snake->body[i].x == x && snake->body[i].y == y) {
                    is_body = 1;
                    break;
                }
            }
            if (x == 0 || x == WIDTH || y == 0 || y == HEIGHT)
                printf("#");
            else if (is_body)
                printf("O");
            else if (food->x == x && food->y == y)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void move_snake(Snake *snake) {
    // 身体跟头走
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }
    // 改变头的位置
    switch (snake->direction) {
        case 'w': snake->body[0].y--; break;
        case 's': snake->body[0].y++; break;
        case 'a': snake->body[0].x--; break;
        case 'd': snake->body[0].x++; break;
    }
}

int check_collision(const Snake *snake) {
    Point head = snake->body[0];
    // 撞墙
    if (head.x <= 0 || head.x >= WIDTH || head.y <= 0 || head.y >= HEIGHT)
        return 1;
    // 撞自己
    for (int i = 1; i < snake->length; i++)
        if (snake->body[i].x == head.x && snake->body[i].y == head.y)
            return 1;
    return 0;
}

int eat_food(Snake *snake, Point *food) {
    if (snake->body[0].x == food->x && snake->body[0].y == food->y) {
        snake->length++;
        food->x = rand() % (WIDTH - 2) + 1;
        food->y = rand() % (HEIGHT - 2) + 1;
        return 1;
    }
    return 0;
}
