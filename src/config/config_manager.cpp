#include "config_manager.h"

#include <fstream>

static inline void trim(std::string& s) {
    s.erase(0, s.find_first_not_of(" \t\r\n"));
    s.erase(s.find_last_not_of(" \t\r\n") + 1);
}

bool ConfigManager::load(const std::string& inFilePath) {
    filePath = inFilePath;
    profiles.clear();
    profilesChanged = false;
    std::ifstream file(inFilePath);
    if (!file)
        return false;

    std::string line, section = "DEFAULT";
    while (std::getline(file, line)) {
        trim(line);
        if (line.empty() || line[0] == '#')
            continue;
        if (line.front() == '[' && line.back() == ']') {
            section = line.substr(1, line.size() - 2);
            trim(section);
            continue;
        }
        size_t eq = line.find('=');
        if (eq != std::string::npos) {
            std::string key = line.substr(0, eq), value = line.substr(eq + 1);
            trim(key);
            trim(value);
            profiles[section][key] = value;
        }
    }
    return true;
}

void ConfigManager::setProfile(const std::string& profile) {
    if (profiles.count(profile)) {
        currentProfile = profile;
    } else {
        currentProfile = "DEFAULT";
    }
}

std::string ConfigManager::getCurrentProfile() const {
    return currentProfile;
}

std::string ConfigManager::get(const std::string& key) const {
    auto profIt = profiles.find(currentProfile);
    if (profIt != profiles.end()) {
        auto keyIt = profIt->second.find(key);
        if (keyIt != profIt->second.end()) {
            return keyIt->second;
        }
    }
    auto defIt = profiles.find("DEFAULT");
    if (defIt != profiles.end()) {
        auto keyIt = defIt->second.find(key);
        if (keyIt != defIt->second.end()) {
            return keyIt->second;
        }
    }
    return "";
}

std::string ConfigManager::getFromSection(const std::string& section,
                                          const std::string& key) const {
    auto sectIt = profiles.find(section);
    if (sectIt != profiles.end()) {
        auto keyIt = sectIt->second.find(key);
        if (keyIt != sectIt->second.end()) {
            return keyIt->second;
        }
    }
    return "";
}

void ConfigManager::set(const std::string& key, const std::string& value) {
    profiles[currentProfile][key] = value;
    profilesChanged = true;
}

void ConfigManager::setInSection(const std::string& section,
                                 const std::string& key,
                                 const std::string& value) {
    profiles[section][key] = value;
    profilesChanged = true;
}

bool ConfigManager::save() {
    if (filePath.empty())
        return false;
    return saveAs(filePath);
}

bool ConfigManager::saveAs(const std::string& inPath) {
    std::ofstream file(inPath);
    if (!file)
        return false;

    bool firstSection = true;
    for (const auto& [section, keyValues] : profiles) {
        if (!firstSection) {
            file << "\n";
        }
        file << "[" << section << "]\n";
        for (auto& [key, value] : keyValues) {
            file << key << "=" << value << "\n";
        }
        firstSection = false;
    }
    file.close();
    profilesChanged = false;
    return true;
}
