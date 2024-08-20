#pragma once
#include <SFML/Graphics.hpp>
#include <Point.hpp>

class BezierCurve {

    private:

        bool exist;
        std::vector<Point*> *points;

        constexpr static unsigned int NUM_SEGMENTS = 200;
        static float step;

        std::vector<sf::Vertex> curve;
        
        sf::Vertex deCasteljau(float t) const;

    public:

        BezierCurve(std::vector<Point*> *pointsVector);
        void CalculateCurvePoints();
        const std::vector<sf::Vertex> & GetCurve() const;

        bool CurveDoesExist();

        

};
