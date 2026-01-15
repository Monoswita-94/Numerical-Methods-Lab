#include<iostream>
#include<graphics.h>
int H[7][5] = {
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 }
};

void drawBitmapH(int x, int y) {
    int size = 10;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            if (H[i][j] == 1) {
                bar(x + j * size, y + i * size, x + (j + 1) * size, y + (i + 1) * size);
            }
        }
    }
}

void drawOutlineH(int x, int y) {
    line(x, y, x, y + 60);
    line(x + 40, y, x + 40, y + 60);
    line(x, y + 30, x + 40, y + 30);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawBitmapH(50, 50);
    drawOutlineH(150, 50);

    getch();
    closegraph();
    return 0;
}


