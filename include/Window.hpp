#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace cbg {
	class Application;
	class Window;

	using WindowID = uint32_t;

	enum WindowEventId {
		CLOSE, RESIZE
	};

	typedef struct WindowResizeEvent {
		int width;
		int height;
	} WindowResizeEvent;

	typedef struct WindowEvent {
		WindowEventId id;
		Window* window;
		std::variant<struct WindowResizeEvent> details;
	} WindowEvent;

	using WindowCallback = std::function<void(WindowEvent)>;


	class Window {
	public:
		friend class Application;
		friend auto _resizeCallbackWrapper(GLFWwindow* window, int width, int height) -> void;

		const WindowID id;

		Window(const Application* app, std::string name, int width, int height);
		~Window();
		auto addListener(WindowEventId eventId, WindowCallback callback) -> void;
		auto draw() -> void;
		auto height() const -> int;
		auto width() const -> int;

	private:
		static WindowID _nextWindowId;
		static std::unordered_set<WindowEventId> _windowEventIds;

		const Application* _app;
		int _width;
		int _height;
		std::unordered_map<WindowEventId, std::vector<WindowCallback>> _callbacks;
		GLFWwindow* _window;
	};
}