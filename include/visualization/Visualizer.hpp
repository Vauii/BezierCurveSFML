#pragma once
#include <Model.hpp>
#include <Point.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <BezierCurve.hpp>

class Visualizer {

    private:

        Model *model;
        sf::RenderWindow *window;

        std::vector<sf::CircleShape> pointsPictures;
        std::vector<sf::Vertex> bezierCurveLines, border;
        std::vector<sf::RectangleShape> thickLines;

        constexpr static int OUTLINE_THICKNESS = 2;
        constexpr static int POINT_RADIUS = 7;
        constexpr static int LINE_THICKNESS = 5;
        static sf::Color pointColor;
        static sf::Color pointSelectedColor;
        static sf::Color backgroundColor;
        static sf::Color pointOutlineColor;
        static sf::Color curveColor;

        void InitObjectPointers(Model &appModel, sf::RenderWindow &appWindow);
        void DrawPoints();
        void ReconstructBezierCurve();
        void DrawBezierCurve();
        void DrawBorder();
        void Draw();

    public:
    
        Visualizer(Model &appModel, sf::RenderWindow &appWindow);

        
        void Render();

        static std::vector<sf::RectangleShape> CreateThickLines(const std::vector<sf::Vertex>& lineVertices,
                                                               const float thickness, 
                                                               sf::Color lineColor = sf::Color::White);
        static int GetPointRadius();
        static int GetOutlineThickness();
        static sf::Color GetPointColor();
        static sf::Color GetPointSelectedColor();
        static sf::Color GetPointOutlineColor();
        


};
