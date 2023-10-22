#pragma once
#include "../vector.h"
#include "../Container.h"

class Collider
{
    Vector2<float, float> size;
    Vector2<float, float> position;
    bool Trigger;

    Collider(Vector2<float, float> colliderSize, Vector2<float, float> colliderPosition, bool trigger = false)
    {
        size = colliderSize;
        position = colliderPosition;
        Trigger = trigger;
    }

    // Check for collisions with another collider
    bool CheckCollision(Collider otherCollider)
    {
        // Calculate the boundaries of the current collider
        float left1 = position.x - size.x / 2;
        float right1 = position.x + size.x / 2;
        float top1 = position.y + size.y / 2;
        float bottom1 = position.y - size.y / 2;

        // Calculate the boundaries of the other collider
        float left2 = otherCollider.position.x - otherCollider.size.x / 2;
        float right2 = otherCollider.position.x + otherCollider.size.x / 2;
        float top2 = otherCollider.position.y;
    }
};

class GameObject
{
    Vector2<float, float> position;
    Collider collider;


    GameObject(Vector2<float, float> initialPosition)
    {
        position = initialPosition;
        collider = new Collider();

    }
};