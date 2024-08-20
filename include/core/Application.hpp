#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Model.hpp>
#include <Controller.hpp>
#include <Visualizer.hpp>

class Application {

    private:
        sf::Event event{};
        sf::VideoMode videoMode;
        sf::RenderWindow *window;
        Model *model;
        Controller *controller;
        Visualizer *visualizer;

        bool isRunning;
        
        constexpr static int WINDOW_WIDTH = 1400;
        constexpr static int WINDOW_HEIGHT = 900;

        void UpdateBezierCurve();
        void UpdateSelectedPoint();
        void Update();
        void Render();


    public:
        Application();
        ~Application();
        
        void Run();
        bool IsRunning() const;

};
