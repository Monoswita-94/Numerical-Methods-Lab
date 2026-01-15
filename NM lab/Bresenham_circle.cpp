#include<iostream>
#include<graphics.h>
void drawCirclePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, YELLOW);
    putpixel(xc - x, yc + y, YELLOW);
    putpixel(xc + x, yc - y, YELLOW);
    putpixel(xc - x, yc - y, YELLOW);
    putpixel(xc + y, yc + x, YELLOW);
    putpixel(xc - y, yc + x, YELLOW);
    putpixel(xc + y, yc - x, YELLOW);
    putpixel(xc - y, yc - x, YELLOW);
}
void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    drawCirclePoints(xc, yc, x, y);

    while (x <= y) {
        x++;
        if (d < 0) {
            d += 4 * x + 6;
        } else {
            y--;
            d += 4 * (x - y) + 10;
        }
        drawCirclePoints(xc, yc, x, y);
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int xc, yc, r;
    std::cout << "Enter center of the circle (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter radius of the circle: ";
    std::cin >> r;

    bresenhamCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}


