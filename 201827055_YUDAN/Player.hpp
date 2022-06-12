#pragma once
#include <GLFW/glfw3.h>
class Player {
public:
    STRIKERS_YUHAN:: vec2 coord;
    STRIKERS_YUHAN::vec2 quad[4];
    float size;
    STRIKERS_YUHAN::vec3 color;

    Player(float size_, float x_, float y_)
    {
        coord = STRIKERS_YUHAN::vec2(0, 0);
        size = 0.2;
        
        quad[0] = STRIKERS_YUHAN::vec2(-size, size);
        quad[1] = STRIKERS_YUHAN::vec2(size, size);
        quad[2] = STRIKERS_YUHAN::vec2(-size, -size);
        quad[3] = STRIKERS_YUHAN::vec2(size, -size);
    }
    ~Player()
    {

    }

    void MoveUp(float distance)
    {
        coord.y = distance;
    }

    void MoveRight(float distance)
    {
        coord.x = distance;
    }

    void shot() {

    }

};
