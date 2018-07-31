
#include "EngineInput.h"

#include "EngineWindow.h"

EngineInput* EngineInput::Input;

void GLOBAL_KeyCB(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	EngineInput::Input->KeyCallback(key, mods, action);
}

void EngineInput::KeyCallback(int key, int mods, int action)
{
	std::pair<int, int> code(key, mods);
	auto it = KeyCodes.find(code);
	if(it == KeyCodes.end())
	{
		return;
	}

	std::string name = it->second;
	if(Down[name])
	{
		if(action == GLFW_RELEASE)
		{
			Down[name] = false;
			Released[name] = true;
		}
	}
	else
	{
		if(action == GLFW_PRESS)
		{
			Down[name] = true;
			Pressed[name] = true;
		}
	}
}

void GLOBAL_CharCB(GLFWwindow* window, unsigned int codepoint)
{
	EngineInput::Input->CharCallback(codepoint);
}

void EngineInput::CharCallback(unsigned int codepoint)
{
	textInput += (unsigned char) codepoint;
}
	
void EngineInput::BindToWindow(EngineWindow* window)
{
	glfwSetKeyCallback(window->GetRaw(), GLOBAL_KeyCB);
	glfwSetCharCallback(window->GetRaw(), GLOBAL_CharCB);
}

void EngineInput::AddBinding(std::string KeyName, std::pair<int,int> KeyCode)
{
	auto prev = KeyBinds.find(KeyName);
	bool exists = false;
	if(prev != KeyBinds.end())
	{
		KeyCodes.erase(prev->second);
		exists = true;
	}
	KeyBinds[KeyName] = KeyCode;
	KeyCodes[KeyCode] = KeyName;

	if(!exists)
	{
		Down[KeyName] = false;
		Pressed[KeyName] = false;
		Released[KeyName] = false;
	}
}

void EngineInput::Serialize(std::ostream output)
{
	// TODO: Serialize settings
}

void EngineInput::Deserialize(std::istream input)
{
	// TODO: Deserialize settings
}

void EngineInput::PollEvents()
{
	for(auto it : Pressed)
	{
		Pressed[it.first] = false;
	}

	for(auto it : Released)
	{
		Released[it.first] = false;
	}

	glfwPollEvents();
}

