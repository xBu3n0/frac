#include "Mesh.hpp"
#include "Shader.hpp"
#include <GL/gl.h>

namespace mesh
{
    Mesh::Mesh()
    {
    	VAO = 0;
    	VBO = 0;
    }

    void Mesh::CreateMeshWOIBO(GLfloat *vertices, uint numOfVertices, const char* vShader, const char* fShader)
    {
        arraySize = numOfVertices;

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, numOfVertices, vertices, GL_STATIC_DRAW);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
                glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        shader = new shader::Shader();
        shader->CreateFromFiles(vShader, fShader);
    }

    void Mesh::RenderMesh()
    {//Vincula os dados para fazer o desenho, depois de desenhado, desvincula eles. 
        rMeshWOIBO();
    }

    void Mesh::rMeshWOIBO()
    {
        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, arraySize);
        glBindVertexArray(0);

        glUseProgram(0);
    }

    void Mesh::ClearMesh()
    {// Descructor
    	if(VBO != 0)
    	{
    		glDeleteBuffers(1, &VBO);
    		VBO = 0;
    	}

    	if(VAO != 0)
    	{
    		glDeleteVertexArrays(1, &VAO);
    		VAO = 0;
    	}

        shader->ClearShader();
    }


    Mesh::~Mesh()
    {
    	ClearMesh();
    }
}