#pragma once
#include "../Utils/Singleton.h"
#include "../Utils/SceneManager.h"
#include "../Resource/ResorceHolder.h"

using namespace sf;

class Framework : public Singleton<Framework>
{
private:
    static Vector2i resolution;
    static RenderWindow window;

    View mainView;
    View uiView;

    TextureHolder textureHolder;
    FontHolder fontHolder;
    SoundHolder soundHolder;
    SceneManager sceneManager;

    Clock clock;

public:
    static RenderWindow& Getwindow();

    static const Vector2i& GetResolution();

    static const View& GetMainView();

    static const View& GetUIView();

    void Init();

    int Run();
};