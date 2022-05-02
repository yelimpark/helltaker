#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include "./Singleton.h"

#define DURATION 0.5f;

using namespace sf;
using namespace std;

class InputManager : public Singleton<InputManager> 
{
private:
	static list<Keyboard::Key> downKeys;
	static map<Keyboard::Key, float> ingKeys;
	static list<Keyboard::Key> upKeys;

	static list<Mouse::Button> downButtons;
	static list<Mouse::Button> ingButtons;
	static list<Mouse::Button> upButtons;

public:
	static void Init();

	static void ProcessInput(const Event& event);

	static void Update(float dt);

	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);

	static bool GetMouseButttonDown(Mouse::Button button);
	static bool GetMouseButton(Mouse::Button button);
	static bool GetMouseButtonUp(Mouse::Button button);

	static void ClearInput();
};