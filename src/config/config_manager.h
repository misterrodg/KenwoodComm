#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <map>
#include <string>

class ConfigManager {
public:
    bool load(const std::string& inFilePath);
    void setProfile(const std::string& profile);
    std::string get(const std::string& key) const;
    std::string getFromSection(const std::string& section,
                               const std::string& key) const;
    std::string getCurrentProfile() const;
    void set(const std::string& key, const std::string& value);
    void setInSection(const std::string& section, const std::string& key,
                      const std::string& value);
    bool save();
    bool saveAs(const std::string& inPath);

private:
    std::string filePath;
    std::string currentProfile = "DEFAULT";
    std::map<std::string, std::map<std::string, std::string>> profiles;
    bool profilesChanged = false;
};

#endif
