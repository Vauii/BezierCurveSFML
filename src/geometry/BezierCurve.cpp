#include "BezierCurve.hpp"
#include <iostream>

float BezierCurve::step = 1 / NUM_SEGMENTS;



BezierCurve::BezierCurve(std::vector<Point *> *pointsVector) {

    points = pointsVector;
    exist = false;

}


sf::Vertex BezierCurve::deCasteljau(float t) const
{   
    size_t n = points->size();
    std::vector<sf::Vertex> coordinates;
    coordinates.reserve(n);
    for (const auto *point : *points) {
        
        float x = static_cast<float>(point->getX());
        float y = static_cast<float>(point->getY());

        coordinates.emplace_back(sf::Vector2f(x, y));

    }

    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < n - k; ++i) {
            
            coordinates[i].position.x = coordinates[i].position.x * (1.f - t) + coordinates[i + 1].position.x * t;
            coordinates[i].position.y = coordinates[i].position.y * (1.f - t) + coordinates[i + 1].position.y * t;

        }
    }
    return coordinates[0];
}


void BezierCurve::CalculateCurvePoints()
{

    if (points->size() <= 1) {

        exist = false;
        return;

    }

    exist = true;
    curve.clear();

    for (int i = 0; i <= NUM_SEGMENTS; ++i) {

        float t = static_cast<float>(i) / NUM_SEGMENTS; 
        curve.push_back(deCasteljau(t));

    }
}

const std::vector<sf::Vertex> & BezierCurve::GetCurve() const {

    return curve;

}

bool BezierCurve::CurveDoesExist()
{
    return exist;
}