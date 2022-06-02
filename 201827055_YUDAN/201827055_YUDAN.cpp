// 201827055_YUDAN.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include "GameManager.hpp"
#include "GameLoop.hpp"
#include "vec.hpp"



#pragma comment(lib, "opengl32.lib")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

Player* p = new Player(0.1f,0.9f,0.9f ,STRIKERS_YUHAN::vec3(1.0f,0.0f,0.0f));
GameLoop* game;





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
    }







int main(void)
{
        
    

    
    
        GLFWwindow* window;

        glfwSetErrorCallback(error_callback);
        glfwSetKeyCallback(window, key_callback);//키 

        if (!glfwInit())
            exit(EXIT_FAILURE); //GLFW 라이브러리 초기화


        window = glfwCreateWindow(800, 1280, "STRIKERS YUHAN", NULL, NULL);//9:16 비율 


        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }


        glfwMakeContextCurrent(window);
        //윈도우 창 생성
        glfwSetKeyCallback(window, key_callback);



        while (!glfwWindowShouldClose(window))
        {
            float ratio;
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);
            ratio = width / (float)height;


            glClearColor(0.2f, 0.2f, 1, 1); //창 배경색 버퍼
            glClear(GL_COLOR_BUFFER_BIT);//인자로 받은 창 버퍼로 교체

            
            p->Render();
            
            
            

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
        delete(p);

    }







// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
