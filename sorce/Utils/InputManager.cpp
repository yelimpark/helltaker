#include "./InputManager.h"

list<Keyboard::Key> InputManager::downKeys;
list<Keyboard::Key> InputManager::ingKeys;
list<Keyboard::Key> InputManager::upKeys;

list<Mouse::Button> InputManager::downButtons;
list<Mouse::Button> InputManager::ingButtons;
list<Mouse::Button> InputManager::upButtons;

void InputManager::Init()
{
}

void InputManager::ProcessInput(const Event& event)
{
    switch (event.type)
    {
    case Event::KeyPressed:
        if (!GetKey(event.key.code))
        {
            downKeys.push_back(event.key.code);
            ingKeys.push_back(event.key.code);
        }
        break;

    case Event::KeyReleased:
        ingKeys.remove(event.key.code);
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

}

bool InputManager::GetKeyDown(Keyboard::Key key)
{
    auto it = find(downKeys.begin(), downKeys.end(), key);
    return it != downKeys.end();
}

bool InputManager::GetKey(Keyboard::Key key)
{
    auto it = find(ingKeys.begin(), ingKeys.end(), key);
    return it != ingKeys.end();
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
