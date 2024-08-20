#include <Application.hpp>
#include <iostream>

Application::Application() {

    videoMode.width = WINDOW_WIDTH;
    videoMode.height = WINDOW_HEIGHT;
    

    sf::ContextSettings settings;
    settings.antialiasingLevel = 9;
    window = new sf::RenderWindow(videoMode, "BezierVisualizer",
                                  sf::Style::Titlebar | sf::Style::Close, settings);
    window->setFramerateLimit(60);

    model = new Model();
    visualizer = new Visualizer(*model, *window);
    controller = new Controller(event, *window, *model, *visualizer);

    isRunning = false;

}

Application::~Application() {
    
    delete controller;
    delete visualizer;
    delete window;
    delete model;

}

void Application::UpdateBezierCurve() {

    model->updateBezierCurve();

}

void Application::UpdateSelectedPoint()
{

    auto accessor = Controller::SelectedPointAccessor();
    auto selectedPointPtr = controller->getSelectedPointPtr(accessor);
    if (selectedPointPtr != nullptr) {
        
        model->changePointPos(*selectedPointPtr, sf::Mouse::getPosition(*window));
        UpdateBezierCurve();

    }
}

void Application::Update() {

    controller->pollEvents();
    if (!this->IsRunning()) return;
    UpdateSelectedPoint();


}

void Application::Render() {

    visualizer->Render();

}

bool Application::IsRunning() const {

    return window->isOpen();

}


void Application::Run() {

    while (this->IsRunning()) {

        this->Update();
        this->Render();        

    }

}

