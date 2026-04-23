#include "st.h"

ST::ST() : CommandSwitch(CommandPrefix::CommandPrefixEnum::ST) {
}

bool ST::supportsSet() const {
    return true;
}
