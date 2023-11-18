#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int width = 20, height = 20;
int gameover, score;
int x, y, fruitX, fruitY, flag;

int tailX[100], tailY[100];
int countTail = 0;

void setup()
{
    gameover = 0;
    x = width / 2;
    y = height / 2;

    label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
        goto label1;

    label2:
    fruitY = rand() % 20;
    if (fruitY == 0)
        goto label2;

    score = 0;
}

void draw()
{
    system("cls");
    int i, j;
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("O");
                else if (i == fruitX && j == fruitY)
                    printf("F");
                else
                {
                    int printTail = 0;
                    for (int k = 0; k < countTail; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            printTail = 1;
                        }
                    }
                    if (!printTail)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Score: %d", score);
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            flag = 1;
            break;
        case 'd':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 's':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < countTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
        gameover = 1;

    for (int i = 0; i < countTail; i++)
    {
        if (x == tailX[i] && y == tailY[i])
            gameover = 1;
    }

    if (x == fruitX && y == fruitY)
    {
        label3:
        fruitX = rand() % 20;
        if (fruitX == 0)
            goto label3;

        label4:
        fruitY = rand() % 20;
        if (fruitY == 0)
            goto label4;

        score += 10;
        countTail++;
    }
}

int main()
{
    int m, n;
    char c;
    label5:
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
        Sleep(10); // Sleep for 10 milliseconds
    }
    printf("\n\nGame Over!\n");
    printf("Press 'Y' to play again or any other key to exit: ");
    scanf(" %c", &c);
    if (c == 'Y' || c == 'y')
        goto label5;
    return 0;
}
