#pragma once
#include <unordered_map>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace cbg {
	class Application {
	public:
		Application();
		~Application();

		auto closeWindow(WindowID id) -> bool;
		auto createWindow(std::string name, int width, int height) -> WindowID;
		auto getWindow(WindowID id) -> Window*;
		auto main() -> void;
	private:
		std::unordered_map<WindowID, Window*> _windows;
	};
}