#include <Point.hpp>
#include <Visualizer.hpp>
#include <iostream>

Point::Point(int x, int y) : x_(x), y_(y) {

    circlePtr = new sf::CircleShape(static_cast<float>(Visualizer::GetPointRadius()));
    circlePtr->setPosition(static_cast<float>(x) - circlePtr->getRadius(),
                           static_cast<float>(y) - circlePtr->getRadius());
    circlePtr->setFillColor(Visualizer::GetPointColor());
    circlePtr->setOutlineColor(Visualizer::GetPointOutlineColor());
    circlePtr->setOutlineThickness(static_cast<float>(Visualizer::GetOutlineThickness()));

}


Point::~Point(){

    delete circlePtr;

}


int Point::getX() const {
    return x_;
}

int Point::getY() const {
    return y_;
}


void Point::changeX(int x) {
    x_ = x;
}

void Point::changeY(int y) {
    y_ = y;
}

void Point::changePos(sf::Vector2i &pos) {
    x_ = pos.x;
    y_ = pos.y;
    circlePtr->setPosition(static_cast<float>(pos.x) - circlePtr->getRadius(),
                           static_cast<float>(pos.y) - circlePtr->getRadius());
}

sf::CircleShape *Point::getCirclePtr() {
    return circlePtr;
}

Point Point::operator+(const Point& other) const {
    return Point(x_ + other.x_, y_ + other.y_);
}

Point Point::operator-(const Point& other) const {
    return Point(x_ - other.x_, y_ - other.y_);
}

Point& Point::operator+=(const Point& other) {
    x_ += other.x_;
    y_ += other.y_;
    return *this;
}

Point& Point::operator-=(const Point& other) {
    x_ -= other.x_;
    y_ -= other.y_;
    return *this;
}