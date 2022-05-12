#include "./Framework.h"
#include "../Utils/InputManager.h"

Vector2i Framework::resolution(1920, 1080);
RenderWindow Framework::window(VideoMode(resolution.x, resolution.y), "Helltaker", Style::Default, sf::ContextSettings(24, 8, 4));

RenderWindow& Framework::Getwindow()
{
    return window;
}

const Vector2i& Framework::GetResolution()
{
    return resolution;
}

const View& Framework::GetMainView()
{
    return Instance()->mainView;
}

void Framework::Init()
{
    mainView.reset(FloatRect(0, 0, resolution.x, resolution.y));

    InputManager::Init();
    AnimationHolder::Init();
    sceneManager.Init();
}

int Framework::Run()
{
    while (window.isOpen())
    {
        Time dt = clock.restart();

        Event event;

        InputManager::ClearInput();

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::Resized)
            {
                window.setSize(Vector2u(event.size.width, event.size.width*9/16));
            }

            InputManager::ProcessInput(event);
        }

        sceneManager.Update(dt);

        window.clear();
        sceneManager.Render();
        window.display();
    }

    return 0;
}