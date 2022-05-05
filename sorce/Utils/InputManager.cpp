#include "./InputManager.h"
#include <iostream>

list<Keyboard::Key> InputManager::downKeys;
map<Keyboard::Key, float> InputManager::ingKeys;
list<Keyboard::Key> InputManager::upKeys;

list<Mouse::Button> InputManager::downButtons;
list<Mouse::Button> InputManager::ingButtons;
list<Mouse::Button> InputManager::upButtons;

void InputManager::Init()
{
    downKeys.clear();
    ingKeys.clear();
    upKeys.clear();

    downButtons.clear();
    ingButtons.clear();
    downKeys.clear();
}

void InputManager::ProcessInput(const Event& event)
{
    switch (event.type)
    {
    case Event::KeyPressed:
        if (ingKeys.find(event.key.code) == ingKeys.end())
        {
            downKeys.push_back(event.key.code);
            ingKeys[event.key.code] = DURATION;
        }
        break;

    case Event::KeyReleased:
        ingKeys.erase(event.key.code);
        upKeys.push_back(event.key.code);
        break;

    case Event::MouseButtonPressed:
        downButtons.push_back(event.mouseButton.button);
        ingButtons.push_back(event.mouseButton.button);
        break;

    case Event::MouseButtonReleased:
        ingButtons.remove(event.mouseButton.button);
        upButtons.push_back(event.mouseButton.button);
        break;

    default:
        break;
    }
}

void InputManager::Update(float dt)
{
    for (auto key : ingKeys) {
        key.second -= dt;
        if (key.second < 0) {
            key.second = 0;
        }
    }
}

bool InputManager::GetKeyDown(Keyboard::Key key)
{
    auto it = find(downKeys.begin(), downKeys.end(), key);
    return it != downKeys.end();
}

bool InputManager::GetKey(Keyboard::Key key)
{
    auto it = ingKeys.find(key);
    if (it != ingKeys.end() && ingKeys[key] <= 0.f) {
        return true;
    }
    return false;
}

bool InputManager::GetKeyUp(Keyboard::Key key)
{
    auto it = find(upKeys.begin(), upKeys.end(), key);
    return it != upKeys.end();
}

bool InputManager::GetMouseButttonDown(Mouse::Button button)
{
    auto it = find(downButtons.begin(), downButtons.end(), button);
    return it != downButtons.end();
}

bool InputManager::GetMouseButton(Mouse::Button button)
{
    auto it = find(ingButtons.begin(), ingButtons.end(), button);
    return it != ingButtons.end();
}

bool InputManager::GetMouseButtonUp(Mouse::Button button)
{
    auto it = find(upButtons.begin(), upButtons.end(), button);
    return it != upButtons.end();
}

void InputManager::ClearInput()
{
    downKeys.clear();
    upKeys.clear();
    downButtons.clear();
    upButtons.clear();
}
