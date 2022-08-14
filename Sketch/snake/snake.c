#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int score = 0, direction = 1, running = 1;
int x, y, foodx, foody, snakeLength = 0;
int width = 30, height = 20;

int snake[200][2];

void init()
{
    x = width / 2;
    y = height / 2;

    snake[0][0] = x;
    snake[0][1] = y-1;
    snakeLength++;

    foodx = rand() % width;
    foody = rand() % height;
}

void update()
{
    int cell = 0;

    system("cls");
    for (int i = 0; i < width/2; i++)
        printf("   ");
    printf("SNAKE\tSCORE: %d\n", score);
    for (int i = 0; i < (width/2) + 20; i++)
        printf("#  ");
    printf("\n");
    
    for (int i = 0; i < height; i++)
    {
        printf("\n\t");
        for (int j = 0; j < width; j++)
        {
            cell = 0;
            if (i == x && j == y)
            {
                printf(" X ");
                cell = 1;
            }

            for (int snakeInd = 0; snakeInd < snakeLength; snakeInd++)
                if (i == snake[snakeInd][0] && j == snake[snakeInd][1])
                {   
                    printf(" O ");
                    cell = 1;
                }
            if (i == foody && j == foodx)
            {
                printf(" + ");
                cell = 1;
            }

            if (cell == 0)
                printf("   ");
        }
    }
    printf("\n");
}

void input()
{
    if (kbhit())
        switch (getch())
        {
            case 'a':
                direction = 1;
                break;
            case 's':
                direction = 2;
                break;
            case 'd':
                direction = 3;
                break;
            case 'w':
                direction = 4;
                break;
            case 'x': case 'c':
                running = 0;
                break;
        }   
}

void logic()
{
    if (x >= width)
        x = 0;
    if (x < 0)
        x = width;
    if (y >= height)
        y = 0;
    if (y < 0)
        y = height;

    switch (direction)
    {
        case 1:
            y--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y++;
            break;
        case 4:
            x--;
            break;
    }
}

int main ()
{
    time_t t;
    srand((unsigned) time(&t));

    init();

    while (running)
    {
        Sleep(100);
        input();
        logic();
        update();
    }
    return 0;
}
