#include <stdexcept>

#include "Window.hpp"

using namespace cbg;

auto cbg::_resizeCallbackWrapper(GLFWwindow* window, int width, int height) -> void {
    auto windowInstance = ((Window*)glfwGetWindowUserPointer(window));
    auto& _callbacks = windowInstance->_callbacks;
    auto entry = _callbacks.find(RESIZE);
    if (entry == _callbacks.end()) {
        _callbacks.insert({ RESIZE, std::vector<WindowCallback>{} });
        entry = _callbacks.find(RESIZE);
    }
    for (const auto& cb : entry->second) {
        WindowEvent event{
            .id = RESIZE,
            .window = windowInstance,
            .details = WindowResizeEvent{
                .width = width,
                .height = height
            }
        };
        cb(event);
    }
}

WindowID Window::_nextWindowId{ 1 };
std::unordered_set<WindowEventId> Window::_windowEventIds{
    CLOSE, RESIZE
};

Window::Window(const Application* app, std::string name, int width, int height )
    : id{ Window::_nextWindowId++ }
    , _app{ app }
    , _callbacks{}
    , _width{width}
    , _height{height}
{
    _window = glfwCreateWindow(_width, _height, name.c_str(), NULL, NULL);
    if (!_window) {
        throw std::runtime_error("Failed to create GLFW window " + std::to_string(id));
    }
    glfwMakeContextCurrent(_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD on window " + std::to_string(id));
    }
    glfwSetWindowUserPointer(_window, this);
    glfwSetFramebufferSizeCallback(_window, _resizeCallbackWrapper);
    
    addListener(RESIZE, [](WindowEvent e) {
        auto& [width, height] = std::get<WindowResizeEvent>(e.details);
        glViewport(0, 0, width, height);
    });
}

Window::~Window() {
    glfwDestroyWindow(_window);
}

auto Window::addListener(WindowEventId eventId, WindowCallback callback) -> void {
    if (_windowEventIds.find(eventId) == _windowEventIds.end()) {
        throw std::range_error("Invalid WindowEventId: " + std::to_string(eventId));
    }

    auto entry = _callbacks.find(eventId);
    if (entry == _callbacks.end()) {
        _callbacks.insert({ eventId, std::vector<WindowCallback>{} });
        entry = _callbacks.find(eventId);
    }

    entry->second.push_back(callback);
}

auto Window::draw() -> void {
    glfwMakeContextCurrent(_window);
    glfwPollEvents();
    glClearColor(.6f, .8f, .3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(_window);
}

auto Window::height() const -> int {
    return _height;
};

auto Window::width() const -> int {
    return _width;
};