#include <iostream>
#include <vector>
#include <math.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#define WIDTH 1000
#define HEIGHT 600

#define PI 3.1415926

struct point
{
    GLfloat x;
    GLfloat y;
};

point rotate(point p, float degree)
{
    return {.x = GLfloat(cos(PI/180 * degree)) * p.x + GLfloat(sin(PI/180 * degree)) * p.y, .y = -GLfloat(sin(PI/180 * degree)) * p.x + GLfloat(cos(PI/180 * degree)) * p.y};
}

int main()
{		
    glfwInit();
    GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "sierpinski curve", NULL, NULL);

    if(!window)
        return -1;

    glfwMakeContextCurrent(window);

    glOrtho(0, WIDTH, 0, HEIGHT, -1.0, 1.0);

    std::vector<point> sierpinski;
    std::vector<point> memo;


    sierpinski.push_back({.x = WIDTH/2.0, .y = HEIGHT/2.-300});
    sierpinski.push_back({.x = WIDTH/2.0, .y = HEIGHT/2.-100});

    int next = 0;

    for(int i = 0; i < 10; ++i)
    {
        int init = next;
        int size = sierpinski.size();

        for(int i = init; i < size; i += 2)
        {
            point start_point = sierpinski[i], end_point = sierpinski[i+1];
            point diff = {.x = (end_point.x - start_point.x)/2, .y = (end_point.y - start_point.y)/2};

            sierpinski.push_back(end_point);
            sierpinski.push_back({.x = end_point.x + diff.x, .y = end_point.y + diff.y});

            point aux = rotate(diff, 120);

            sierpinski.push_back(end_point);
            sierpinski.push_back({.x = end_point.x + aux.x, .y = end_point.y + aux.y});

            aux = rotate(diff, -120);

            sierpinski.push_back(end_point);
            sierpinski.push_back({.x = end_point.x + aux.x, .y = end_point.y + aux.y});
        }
        
        next = size;
    }

    while(glfwWindowShouldClose(window) == GL_FALSE)
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        
        for(int i = 0; i < sierpinski.size(); i += 2)
        {
            glVertex2f(sierpinski[i].x, sierpinski[i].y);
            glVertex2f(sierpinski[i+1].x, sierpinski[i+1].y);
        }


        glEnd();
        glfwSwapBuffers(window);
    }

    return 0;
}