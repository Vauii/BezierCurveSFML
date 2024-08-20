#include <Visualizer.hpp>
#include <iostream>

sf::Color Visualizer::pointColor = sf::Color(63, 156, 125);
sf::Color Visualizer::pointSelectedColor = sf::Color(132, 210, 171);
sf::Color Visualizer::backgroundColor = sf::Color(196, 228, 245);
sf::Color Visualizer::pointOutlineColor = sf::Color(46, 46, 46);
sf::Color Visualizer::curveColor = sf::Color(201, 87, 141);


void Visualizer::InitObjectPointers(Model &appModel, sf::RenderWindow &appWindow) {

    model = &appModel;
    window = &appWindow;

}

Visualizer::Visualizer(Model &appModel, sf::RenderWindow &appWindow) {
   
    InitObjectPointers(appModel, appWindow);
}

void Visualizer::DrawPoints() {

    for (auto * point: model->points) {

        window->draw(*point->getCirclePtr());

    }

}

void Visualizer::ReconstructBezierCurve() {

    bezierCurveLines.clear();
    border.clear();
    if (!model->bezier->CurveDoesExist()) {

        return;

    }

    const std::vector<sf::Vertex> & curve = model->bezier->GetCurve();
    
    
    bezierCurveLines.push_back(curve[0]);
    for (int i = 1; i < curve.size() - 1; ++i) {

        bezierCurveLines.push_back(curve[i]);
        bezierCurveLines.push_back(curve[i]);

    }
    bezierCurveLines.push_back(curve.back());


    for (const auto *point: model->points) {  

        float x = static_cast<float>(point->getX());
        float y = static_cast<float>(point->getY());
        border.emplace_back(sf::Vector2f(x, y));

    }
    border.push_back(border.front());
}

void Visualizer::DrawBezierCurve() {

    ReconstructBezierCurve();
    if (bezierCurveLines.size() < 2) return;
    thickLines = CreateThickLines(bezierCurveLines, LINE_THICKNESS, curveColor);
    for (const auto &thicLine : thickLines) {

        window->draw(thicLine);

    }
}

void Visualizer::DrawBorder() {

    if (bezierCurveLines.size() < 2) return;
    window->draw(border.data(), border.size(), sf::LinesStrip);

}

void Visualizer::Draw() {

    DrawBezierCurve();
    DrawBorder();
    DrawPoints();

}

void Visualizer::Render()
{

    window->clear(backgroundColor);
    Draw();
    window->display();

}

std::vector<sf::RectangleShape> Visualizer::CreateThickLines(const std::vector<sf::Vertex> &lineVertices, const float thickness, sf::Color lineColor)
{
    std::vector<sf::RectangleShape> thickLines;
        
        if (lineVertices.size() % 2 != 0) {
            return thickLines;
        }
        
        for (size_t i = 0; i < lineVertices.size(); i += 2) {
            const sf::Vector2f& start = lineVertices[i].position;
            const sf::Vector2f& end = lineVertices[i + 1].position;
            
            sf::Vector2f direction = end - start;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            float angle = std::atan2(direction.y, direction.x) * 180 / 3.14159265f;
            
            sf::RectangleShape rectangle(sf::Vector2f(length, thickness));
            rectangle.setPosition(start);
            rectangle.setRotation(angle);
            rectangle.setFillColor(lineColor);
            thickLines.push_back(rectangle);
        }
        
        return thickLines;
}

int Visualizer::GetPointRadius()
{

    return POINT_RADIUS;
}

int Visualizer::GetOutlineThickness() {
    
    return OUTLINE_THICKNESS;

}

sf::Color Visualizer::GetPointColor() {
    
    return pointColor;

}

sf::Color Visualizer::GetPointSelectedColor() {

    return pointSelectedColor;

}

sf::Color Visualizer::GetPointOutlineColor()
{
    return pointOutlineColor;
}
