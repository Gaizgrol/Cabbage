#include <chrono>
#include <iostream>
#include "Application.hpp"

auto main() -> int {
    using namespace cbg;
    using namespace std;

    Application app{};

    auto win1 = app.createWindow("Janela 1", 320, 240);
    auto win2 = app.createWindow("Janela 2", 320, 240);

    
    app.getWindow(win1)->addListener(RESIZE, [](WindowEvent e) {
        cout << "Janela " << e.window->id << " foi redimensionada!" << endl;
    });

    app.getWindow(win2)->addListener(RESIZE, [](WindowEvent e) {
        auto& [width, height] = std::get<WindowResizeEvent>(e.details);
        cout << "Tamanho da janela " << e.window->id << ": " << width << " x " << height << endl;
    });


    while (true) {
        auto start = chrono::high_resolution_clock::now();
        app.main();
        cout <<
            chrono::duration_cast<chrono::milliseconds>(
                chrono::high_resolution_clock::now() - start
            )
        << endl;
    }

    return 0;
}
