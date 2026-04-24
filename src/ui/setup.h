#ifndef SETUP_H
#define SETUP_H

#include "config/config_manager.h"
#include "core/radio.h"
#include <string>

namespace ui {

// Loads config, prompts the user for any missing values (callsign, model,
// serial port), persists the results, and returns the ready ConfigManager.
ConfigManager RunSetup(const std::string& requestedProfile);

// Reads the model number out of a fully-initialized ConfigManager.
// Prints a structured error and returns an UNRECOGNIZED model on failure.
Radios ResolveRadioModel(const ConfigManager& config);

} // namespace ui

#endif
