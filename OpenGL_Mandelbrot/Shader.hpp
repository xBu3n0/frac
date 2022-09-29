#pragma once

#include <string>
#include <string.h>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace shader
{
    class Shader
    {
        public:
            Shader();

            // Cria o `Program` para ser utilizado quando for realizado o desenho. 
            void CreateFromString(const char* vertexCode, const char* fragmentCode);
            void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

            std::string ReadFile(const char* fileLocation);

            void UseShader();
            void ClearShader();

            ~Shader();

            GLuint uniformDeslocamento;
        private:
            GLuint shaderID;

            void CompileShader(const char* vertexCode, const char* fragmentCode);
            void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
    };
}