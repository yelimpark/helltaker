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
    static View playerView;

    TextureHolder textureHolder;
    FontHolder fontHolder;
    SoundHolder soundHolder;
    AnimationHolder animationholder;

    SceneManager sceneManager;

    Clock clock;

public:
    static RenderWindow& Getwindow();

    static const Vector2i& GetResolution();

    const static View& GetMainView();

    static View& GetPlayerView();

    void Init();

    int Run();
};