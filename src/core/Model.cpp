#include <Model.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

Model::Model() {

    bezier = new BezierCurve(&points);

}

Model::~Model() {

    for (Point* point: points) {

        delete point;

    }

}       


void Model::updateBezierCurve() {

    bezier->CalculateCurvePoints();

}

void Model::createPoint(sf::Vector2i &pointVec) {
    
    Point* ptr = new Point(pointVec.x, pointVec.y);
    this->points.push_back(ptr);
    updateBezierCurve();

}

void Model::deletePoint(std::vector<Point*>::iterator &pointIter) {

    Point* pointPtr = *pointIter;
    points.erase(pointIter);
    delete pointPtr;
    updateBezierCurve();

}

void Model::changePointPos(Point &point, sf::Vector2i &pos) {

    point.changePos(pos);

}

