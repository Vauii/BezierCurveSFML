#pragma once
#include <Visualizer.hpp>
#include <Model.hpp>
#include <Point.hpp>
#include <iostream>

class Controller {

    private:

        Model *model;
        Visualizer *visualizer;
        sf::Event *event;
        sf::RenderWindow *window;
        Point *selectedPoint;

    public:

        class SelectedPointAccessor {

            friend class Application;
            SelectedPointAccessor() = default;

        };

        Controller(sf::Event &appEvent, sf::RenderWindow& appWindow, 
                   Model& appModel, Visualizer& appVisualizer);

        
        Point* getSelectedPointPtr(SelectedPointAccessor accessor) const;
        void pollEvents();
         
    
};
