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

    TextureHolder textureHolder;
    FontHolder fontHolder;
    SoundHolder soundHolder;
    SceneManager sceneManager;
    AnimationHolder animationholder;

    Clock clock;

public:
    static RenderWindow& Getwindow();

    static const Vector2i& GetResolution();
    //const delete
    static View& GetMainView();

    void Init();

    int Run();
};