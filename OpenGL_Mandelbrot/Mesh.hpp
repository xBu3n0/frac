#pragma once

#include "Shader.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace mesh
{
    class Mesh
    {
        public:
            Mesh();
            shader::Shader *shader;
            // Cria a mesh + shader que será utilizado para essa mesh. 
            void CreateMeshWOIBO(GLfloat *vertices, uint numOfVertices, const char* vShader, const char* fShader);
            // Desenha a mesh
            void RenderMesh();
            void rMeshWOIBO();
            void ClearMesh();

            ~Mesh();

        private:
            GLuint VAO, VBO;
            GLsizei arraySize;
    };
}