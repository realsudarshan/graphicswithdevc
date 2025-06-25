#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawBox(int left, int top, int right, int bottom, int depth, int color, char* label) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar3d(left, top, right, bottom, depth, 1);  // last 1 = top on, 0 = off
    outtextxy(left, top - 20, label);
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int left, top, right, bottom, depth;
    int tx, ty;             // translation factors
    float sx, sy;           // scaling factors

    // ----- Input box parameters -----
    printf("Enter left, top, right, bottom coordinates of the box: ");
    scanf("%d%d%d%d", &left, &top, &right, &bottom);

    printf("Enter depth of the 3D box (e.g. 20): ");
    scanf("%d", &depth);

    printf("Enter translation values (tx ty): ");
    scanf("%d%d", &tx, &ty);

    printf("Enter scaling factors (sx sy): ");
    scanf("%f%f", &sx, &sy);

    // ----- Draw Original Box -----
    cleardevice();
    drawBox(left, top, right, bottom, depth, WHITE, "Original Box");
    getch();

    // ----- Apply Translation -----
    int leftT = left + tx;
    int topT = top + ty;
    int rightT = right + tx;
    int bottomT = bottom + ty;

    cleardevice();
    drawBox(leftT, topT, rightT, bottomT, depth, YELLOW, "Translated Box");
    getch();

    // ----- Apply Scaling -----
    int width = rightT - leftT;
    int height = bottomT - topT;

    int leftS = leftT;
    int topS = topT;
    int rightS = leftT + (int)(width * sx);
    int bottomS = topT + (int)(height * sy);

    cleardevice();
    drawBox(leftS, topS, rightS, bottomS, depth, GREEN, "Scaled Box");
    getch();

    closegraph();
}

