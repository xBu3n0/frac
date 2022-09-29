#include "App.hpp"
#include "Shader.hpp"
#include <GLFW/glfw3.h>

namespace app
{
    App::App()
    {// Inicializa a aplicação sem nome.
        window = new win::Window("without title", 800, 600, false);
    }

    App::App(const char* screenName, int width, int height, bool fullscreen)
    {// Inicia a aplicação com nome, tamanho e se é fullscreen.
        window = new win::Window(screenName, width, height, fullscreen);
    }

    void App::addMeshWIBO(GLfloat *vertices, uint *indices, uint numOfVertices, uint numOfIndices, const char* vShader, const char* fShader)
    {// Adiciona uma mesh ao app que utiliza de IBO
        mesh::Mesh *obj = new mesh::Mesh();
        obj->CreateMeshWOIBO(vertices, numOfVertices, vShader, fShader);
        meshList.push_back(obj);

        return;
    }

    void App::addMeshWOIBO(GLfloat *vertices, uint numOfVertices, const char* vShader, const char* fShader)
    {// Adiciona uma mesh ao app que não utiliza de IBO
        mesh::Mesh *obj = new mesh::Mesh();
        obj->CreateMeshWOIBO(vertices, numOfVertices, vShader, fShader);
        meshList.push_back(obj);

        return;
    }

    void App::run()
    {
        float x = 0, y = 0, z = 1;
        GLfloat deltaTime = 0, lastTime = 0;

        GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;
        
        while (!window->getShouldClose())
        {
            GLfloat now = glfwGetTime();
            deltaTime = now - lastTime;
            lastTime = now;

            // Get + Handle User Input
            glfwPollEvents();

            bool *keys = window->getsKeys();

            if(keys[GLFW_KEY_UP])
                y += 0.2/z;
            if(keys[GLFW_KEY_DOWN])
                y -= 0.2/z;
            if(keys[GLFW_KEY_LEFT])
                x -= 0.2/z;
            if(keys[GLFW_KEY_RIGHT])
                x += 0.2/z;
            if(keys[GLFW_KEY_EQUAL])
                z *= 1.2;
            if(keys[GLFW_KEY_MINUS])
                z /= 1.2;

            // Limpa a janela
            glClearColor(0.1f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            for(int i = 0; i < meshList.size(); ++i)
            {
                meshList[i]->shader->UseShader();
                glUniform3f(meshList[i]->shader->uniformDeslocamento, x, y, z);
                meshList[i]->RenderMesh();
            }

            window->swapBuffers();
        }
    }
}