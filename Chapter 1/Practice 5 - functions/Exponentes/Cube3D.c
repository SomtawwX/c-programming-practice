#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40
#define SCALE 20
#define PERSPECTIVE 10
#define ROT_SPEED 0.05

typedef struct { float x, y, z; } Vertex;
typedef struct { int a, b; } Edge;

Edge edges[] = { {0,1}, {1,2}, {2,3}, {3,0},
                 {4,5}, {5,6}, {6,7}, {7,4},
                 {0,4}, {1,5}, {2,6}, {3,7} };
Vertex vertices[8] = {
    {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
    {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}
};

void rotate(Vertex *v, float ax, float ay, float az) {
    // Rotate around X-axis
    float temp = v->y;
    v->y = v->y * cos(ax) - v->z * sin(ax);
    v->z = temp * sin(ax) + v->z * cos(ax);
    
    // Rotate around Y-axis
    temp = v->x;
    v->x = v->x * cos(ay) + v->z * sin(ay);
    v->z = -temp * sin(ay) + v->z * cos(ay);
    
    // Rotate around Z-axis
    temp = v->x;
    v->x = v->x * cos(az) - v->y * sin(az);
    v->y = temp * sin(az) + v->y * cos(az);
}

void project(Vertex v, int *x, int *y) {
    float factor = PERSPECTIVE / (PERSPECTIVE + v.z);
    *x = (int)(v.x * factor * SCALE) + WIDTH / 2;
    *y = (int)(v.y * factor * SCALE) + HEIGHT / 2;
}

void drawLine(char buffer[HEIGHT][WIDTH], int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;
    
    while (1) {
        if (x0 >= 0 && x0 < WIDTH && y0 >= 0 && y0 < HEIGHT)
            buffer[y0][x0] = '#';
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

int main() {
    char buffer[HEIGHT][WIDTH];
    float ax = 0, ay = 0, az = 0;
    
    while (1) {
        // Clear buffer
        for (int y = 0; y < HEIGHT; y++)
            for (int x = 0; x < WIDTH; x++)
                buffer[y][x] = ' ';
        
        // Rotate and project vertices
        int projX[8], projY[8];
        for (int i = 0; i < 8; i++) {
            Vertex v = vertices[i];
            rotate(&v, ax, ay, az);
            project(v, &projX[i], &projY[i]);
        }
        
        // Draw edges
        for (int i = 0; i < 12; i++)
            drawLine(buffer, projX[edges[i].a], projY[edges[i].a], projX[edges[i].b], projY[edges[i].b]);
        
        // Display buffer
        system("cls || clear");
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++)
                putchar(buffer[y][x]);
            putchar('\n');
        }
        
        // Update rotation angles
        ax += ROT_SPEED;
        ay += ROT_SPEED;
        az += ROT_SPEED;
        
        // Delay to control animation speed
        clock_t end = clock() + 0.1 * CLOCKS_PER_SEC;
        while (clock() < end);
    }
    
    return 0;
}