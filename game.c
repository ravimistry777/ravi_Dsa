#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h>  // For Sleep()

#define WIDTH 30
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100

// Directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Struct to represent the position of the snake and food
typedef struct {
    int x;
    int y;
} Position;

// Struct to represent the snake
typedef struct {
    Position body[MAX_SNAKE_LENGTH];
    int length;
    int direction;
} Snake;

// Function prototypes
void drawBoard(Snake *snake, Position *food);
void updateSnake(Snake *snake);
void generateFood(Position *food);
int checkCollision(Snake *snake);
int checkFoodEaten(Snake *snake, Position *food);
void moveSnake(Snake *snake);

// Main function
int main() {
    Snake snake = {{ {10, 10} }, 1, RIGHT}; // Initial position of snake
    Position food = {15, 10}; // Initial position of food
    int score = 0;
    char input;

    generateFood(&food);

    while (1) {
        drawBoard(&snake, &food);

        if (_kbhit()) {
            input = _getch();  // Get user input
            if (input == 'w' && snake.direction != DOWN) {
                snake.direction = UP;
            }
            if (input == 's' && snake.direction != UP) {
                snake.direction = DOWN;
            }
            if (input == 'a' && snake.direction != RIGHT) {
                snake.direction = LEFT;
            }
            if (input == 'd' && snake.direction != LEFT) {
                snake.direction = RIGHT;
            }
        }

        moveSnake(&snake);

        if (checkCollision(&snake)) {
            printf("Game Over! Final Score: %d\n", score);
            break;
        }

        if (checkFoodEaten(&snake, &food)) {
            score++;
            snake.length++;
            generateFood(&food);
        }

        Sleep(100);  // Slow down the game loop
    }

    return 0;
}

// Function to draw the game board
void drawBoard(Snake *snake, Position *food) {
    system("cls");  // Clear the screen
    for (int i = 0; i < HEIGHT + 2; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            if (i == 0 || i == HEIGHT + 1 || j == 0 || j == WIDTH + 1) {
                printf("#");  // Border
            } else if (i == food->y && j == food->x) {
                printf("F");  // Food
            } else {
                int isSnakeBodyPart = 0;
                for (int k = 0; k < snake->length; k++) {
                    if (snake->body[k].x == j && snake->body[k].y == i) {
                        isSnakeBodyPart = 1;
                        break;
                    }
                }
                if (isSnakeBodyPart) {
                    printf("O");  // Snake body
                } else {
                    printf(" ");  // Empty space
                }
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", snake->length - 1);
}

// Function to move the snake
void moveSnake(Snake *snake) {
    Position newHead = snake->body[0];

    switch (snake->direction) {
        case UP:
            newHead.y--;
            break;
        case DOWN:
            newHead.y++;
            break;
        case LEFT:
            newHead.x--;
            break;
        case RIGHT:
            newHead.x++;
            break;
    }

    // Shift the snake's body
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = newHead;
}

// Function to check if the snake has collided with itself or the walls
int checkCollision(Snake *snake) {
    if (snake->body[0].x <= 0 || snake->body[0].x >= WIDTH + 1 || 
        snake->body[0].y <= 0 || snake->body[0].y >= HEIGHT + 1) {
        return 1;  // Collision with wall
    }
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y) {
            return 1;  // Collision with itself
        }
    }
    return 0;
}

// Function to check if the snake has eaten food
int checkFoodEaten(Snake *snake, Position *food) {
    if (snake->body[0].x == food->x && snake->body[0].y == food->y) {
        return 1;  // Food eaten
    }
    return 0;
}

// Function to generate a new food position
void generateFood(Position *food) {
    food->x = rand() % WIDTH + 1;
    food->y = rand() % HEIGHT + 1;
}
