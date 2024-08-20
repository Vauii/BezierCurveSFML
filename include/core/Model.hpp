#pragma once
#include <vector>
#include <Point.hpp>
#include <BezierCurve.hpp>

class Model {

    friend class Visualizer;
    friend class Controller;

    private:
        
        BezierCurve *bezier;
        std::vector<Point*> points;

    public:
        Model();        
        ~Model();

        void createPoint(sf::Vector2i &pointVec);
        void deletePoint(std::vector<Point*>::iterator &pointIter);
        void changePointPos(Point &point, sf::Vector2i &pos);
        void updateBezierCurve();
    
};
