#pragma once
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "vec.hpp"
#include "Player.hpp"

#pragma comment(lib, "OpenGL32")

Player* p = new Player(0.1f, 0.9f, 0.9f, STRIKERS_YUHAN::vec3(1.0f, 0.0f, 0.0f));


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        p->MoveUp(0.01f);
    if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
        p->MoveUp(0.0f);
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        p->MoveUp(-0.01f);
    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE)
        p->MoveUp(0.0f);
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        p->MoveRight(0.01f);
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        p->MoveRight(-0.01f);
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
        p->MoveRight(0.0f);
    if (key == GLFW_KEY_Z && action == GLFW_PRESS)
        p->MoveRight(-0.00f);
    if (key == GLFW_KEY_Z && action == GLFW_RELEASE)
        p->MoveRight(0.0f);


}





namespace STRIKERS_YUHAN {
    class Window_Render
    {
        GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    public void CreatWindow() {
        if (!glfwInit())
            exit(EXIT_FAILURE); //GLFW ���̺귯�� �ʱ�ȭ
        window = glfwCreateWindow(800, 1280, "STRIKERS YUHAN", NULL, NULL);//9:16 ���� 
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);//������ â ����


        glfwSetKeyCallback(window, key_callback);//Ű �Է�

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.2f, 0.2f, 1, 1); //â ���� ����
        glClear(GL_COLOR_BUFFER_BIT);//���ڷ� ���� â ���۷� ��ü



    }


            
    void PlayerRender(STRIKERS_YUHAN::vec3 col)
    {
        color = col;
        quad[0] = quad[0] + coord;
        quad[1] = quad[1] + coord;
        quad[2] = quad[2] + coord;
        quad[3] = quad[3] + coord;

        glBegin(GL_TRIANGLES);
        glColor4f(color.x, color.y, color.z, 0.5f);
        glVertex3f(quad[0].x, quad[0].y, 0.0f);
        glVertex3f(quad[1].x, quad[1].y, 0.0f);
        glVertex3f(quad[2].x, quad[2].y, 0.0f);

        glEnd();
    }
               
      

        void SwapButter() {
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        void WindowEnd() {
            glfwDestroyWindow(window);
            glfwTerminate();//�Ҵ�� ��� �޸� ���� ������ ������ ȣ��
        }

       // exit(EXIT_SUCCESS);//�׳� ����
    };
}