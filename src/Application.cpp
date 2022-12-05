#include <stdexcept>

#include "Application.hpp"

using namespace cbg;

Application::Application()
    : _windows{}
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

Application::~Application() {
    for (const auto& entry: _windows) {
        closeWindow(entry.second->id);
    }
    glfwTerminate();
}

auto Application::createWindow(std::string name, int width, int height) -> WindowID {
    auto window = new Window(this, name, width, height);
    _windows[window->id] = window;
    return window->id;
}

auto Application::closeWindow(WindowID id) -> bool {
    auto result = _windows.find(id);
    if (result == _windows.end()) {
        return false;
    }

    auto& windowPtrRef = result->second;
    delete windowPtrRef;
    windowPtrRef = nullptr;

    result = _windows.erase(result);

    return true;
}

auto Application::getWindow(WindowID id) -> Window* {
    auto result = _windows.find(id);
    if (result == _windows.end()) {
        throw std::range_error("Invalid WindowID: " + std::to_string(id));
    }

    return result->second;
};

#include <iostream>

auto Application::main() -> void {
    for (const auto& entry : _windows) {
        auto window = entry.second;
        window->draw();
    }
}