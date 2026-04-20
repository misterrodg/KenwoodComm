#include "runtime/session.h"
#include "ui/console_ui.h"
#include "ui/setup.h"

#include <string>

int main(int argc, char** argv) {
    bool localMode = false;
    bool safeMode = false;
    std::string requestedProfile;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "local") {
            localMode = true;
        } else if (arg == "safe") {
            safeMode = true;
        } else if (arg.rfind("profile=", 0) == 0 && arg.size() > 8) {
            requestedProfile = arg.substr(8);
        }
    }

    auto config = ui::RunSetup(requestedProfile);
    auto modelNumber = ui::ResolveModelNumber(config);

    Session session(safeMode, localMode, modelNumber);
    ui::RunSessionLoop(session);

    return 0;
}
