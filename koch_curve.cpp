#include <iostream>
#include <vector>
#include <math.h>

#include <GLFW/glfw3.h>
#include <GL/gl.h>

#define WIDTH 1000
#define HEIGHT 600

#define PI -3.1415926

struct point
{
    double x;
    double y;
};

int main()
{		
    glfwInit();
    GLFWwindow * window = glfwCreateWindow(WIDTH, HEIGHT, "Koch curve", NULL, NULL);

    if(!window)
        return -1;

    glfwMakeContextCurrent(window);

    glOrtho(0, WIDTH, 0, HEIGHT, -1.0, 1.0);

    std::vector<point> koch;

    koch.push_back({.x = 20, .y = HEIGHT/2.-100});
    koch.push_back({.x = WIDTH-20, .y = HEIGHT/2.-100});

    for(int i = 0; i < 6; ++i)
    {
        std::vector<point> aux;

        for(int i = 0; i < koch.size()-1; ++i)
        {
            point start_point = koch[i], end_point = koch[i+1];

            point diff = {.x = (end_point.x - start_point.x)/3, .y = (end_point.y - start_point.y)/3};

            aux.push_back(start_point);
            aux.push_back({.x = start_point.x + diff.x, .y = start_point.y + diff.y});
            aux.push_back({.x = start_point.x + diff.x + (diff.y * sin(PI/3) + diff.x * cos(PI/3)), .y = start_point.y + diff.y + (-diff.x * sin(PI/3) + diff.y * cos(PI/3))});
            aux.push_back({.x = start_point.x + 2 * diff.x, .y = start_point.y + 2 * diff.y});
            aux.push_back(end_point);
        }

        koch = aux;
    }

    while(glfwWindowShouldClose(window) == GL_FALSE)
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);

        glVertex2f(koch[0].x, koch[0].y);
        
        for(int i = 1; i < koch.size() - 1; i++)
        {
                glVertex2f(koch[i].x, koch[i].y);
                glVertex2f(koch[i].x, koch[i].y);
        }
        
        glVertex2f(koch[koch.size()-1].x, koch[koch.size()-1].y);


        glEnd();
        glfwSwapBuffers(window);
    }

    return 0;
}