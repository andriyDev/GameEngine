
#pragma once

#include <string>
#include <map>
#include <vector>

#include <iostream>

class EngineWindow;

class EngineInput
{
public:
	static EngineInput* Input;

	EngineInput() { Input = this; }

	void BindToWindow(EngineWindow* window);
	
	void AddBinding(std::string KeyName, std::pair<int, int> KeyCode);

	void Serialize(std::ostream output);
	void Deserialize(std::istream input);

	void PollEvents();

	bool IsKeyPressed(std::string KeyName) { return Pressed[KeyName]; }
	bool IsKeyDown(std::string KeyName) { return Down[KeyName]; }
	bool IsKeyReleased(std::string KeyName) { return Released[KeyName]; }

	std::string textInput;

	void KeyCallback(int key, int mods, int action);
	void CharCallback(unsigned int codepoint);

private:
	std::map<std::string, std::pair<int, int>> KeyBinds;
	std::map<std::pair<int, int>, std::string> KeyCodes;

	std::map<std::string, bool> Down;
	std::map<std::string, bool> Pressed;
	std::map<std::string, bool> Released;
};

