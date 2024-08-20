#include <Controller.hpp>


Controller::Controller(sf::Event &appEvent, sf::RenderWindow& appWindow,
                       Model& appModel, Visualizer& appVisualizer) {

    event = &appEvent;
    window = &appWindow;
    model = &appModel;
    visualizer = &appVisualizer;
    selectedPoint = nullptr;

}

Point *Controller::getSelectedPointPtr(SelectedPointAccessor accessor) const
{
    return selectedPoint;
}

void Controller::pollEvents()
{

    while (window->pollEvent(*event)) {

        switch (event->type) {

            case sf::Event::Closed:

                window->close();
                break;
            
            case sf::Event::KeyPressed:

                if (event->key.code == sf::Keyboard::Escape) {

                    window->close();
                    break;

                }
                if (event->key.code == sf::Keyboard::BackSpace) {
                    
                    if (model->points.size() == 0) break;
                    model->deletePoint(model->points.end() - 1);
                    break;

                }

            case sf::Event::MouseButtonPressed:

                if (event->mouseButton.button == sf::Mouse::Left) {
                    
                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                    bool pointIsSelected = false;

                    for (auto* point : model->points) {
                        
                        

                        sf::CircleShape *circle = point->getCirclePtr();
                        if (circle->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            
                            circle->setFillColor(Visualizer::GetPointSelectedColor());
                            selectedPoint = point;
                            pointIsSelected = true;
                            break;

                        }

                    }

                    if (!pointIsSelected) {

                        model->createPoint(mousePos);

                    }

                }
                else if (event->mouseButton.button == sf::Mouse::Right) {

                    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

                    for (auto it = model->points.begin(); it != model->points.end(); ++it) {

                        sf::CircleShape *circle = (*it)->getCirclePtr();
                        if (circle->getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                            
                            model->deletePoint(it);
                            break;

                        }

                    }

                }
                break;
            
            case sf::Event::MouseButtonReleased:
                if (event->mouseButton.button == sf::Mouse::Left) {

                    if (selectedPoint != nullptr) {
                        
                        selectedPoint->getCirclePtr()->setFillColor(Visualizer::GetPointColor());
                        selectedPoint = nullptr;

                    }

                }
                break;

        }

    }
}
