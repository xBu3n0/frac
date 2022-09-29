#include "createMandelbrot.hpp"

// Vertex Shader
const char* vShaderMandelbrot = "Shaders/shader.vert";

// Fragment Shader
const char* fShaderMandelbrot = "Shaders/shader.frag";

void createMandelbrot(app::App& f, int width, int height)
{
    std::vector<GLfloat> frame;

    std::vector<GLfloat> start_position = {0, 0};

    for(int i = -width/2; i < width/2; ++i)
    {
        for(int j = -height/2; j < height/2; ++j)
        {
            frame.push_back(start_position[0] + 2 * (GLfloat(i)/(GLfloat(width))));
            frame.push_back(start_position[1] + 2 * (GLfloat(j)/(GLfloat(height))));
            frame.push_back(0);
        }
    }

    f.addMeshWOIBO(frame.data(), frame.size() * sizeof(GLfloat), vShaderMandelbrot, fShaderMandelbrot);
}