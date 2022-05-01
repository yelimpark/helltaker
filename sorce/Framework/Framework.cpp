#include "./Framework.h"
#include "../Utils/InputManager.h"

Vector2i Framework::resolution(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
RenderWindow Framework::window(VideoMode(resolution.x, resolution.y), "Template", Style::Default);

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

            InputManager::ProcessInput(event);
        }

        InputManager::Update(dt.asSeconds());
        sceneManager.Update(dt);

        window.clear();
        sceneManager.Render();
        window.display();
    }

    return 0;
}