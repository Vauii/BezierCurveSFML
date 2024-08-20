#pragma once
#include <SFML/Graphics.hpp>

class Point {

    private:
        int x_;
        int y_;
        sf::CircleShape* circlePtr;

    public:
        Point(int x, int y);
        ~Point();

        int getX() const;
        int getY() const;
        
        void changeX(int x);
        void changeY(int y);
        void changePos(sf::Vector2i &pos);

        sf::CircleShape* getCirclePtr();

        Point operator+(const Point& other) const;
        Point operator-(const Point& other) const;
        Point& operator+=(const Point& other);
        Point& operator-=(const Point& other);


};
