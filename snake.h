#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH  20
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[100];
    int length;
    char direction; // 'w', 'a', 's', 'd'
} Snake;

void init_snake(Snake *snake);
void draw(const Snake *snake, const Point *food);
void move_snake(Snake *snake);
int check_collision(const Snake *snake);
int eat_food(Snake *snake, Point *food);

#endif
