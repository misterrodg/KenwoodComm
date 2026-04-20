#include "console_ui.h"

#include "session.h"

#include <iostream>
#include <string>

namespace ui {

void RunSessionLoop(Session& session) {
    std::string command;

    while (session.sessionOpen) {
        if (session.safeMode) {
            std::cout << "SAFE ";
        }
        std::cout << ":: ";
        std::getline(std::cin, command);
        session.CheckCommand(command);
    }
}

} // namespace ui
