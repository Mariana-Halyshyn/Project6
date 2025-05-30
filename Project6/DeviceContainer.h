#ifndef DEVICECONTAINER_H
#define DEVICECONTAINER_H

#include "DisplayDevice.h"
#include <vector>
#include <string>
#include <stdexcept>

class DeviceContainer {
private:
    std::vector<DisplayDevice> devices;

public:
    void addDevice(const DisplayDevice& device);
    void removeDevice(size_t index);
    DisplayDevice& getDevice(size_t index);
    size_t size() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    class Iterator {
    private:
        std::vector<DisplayDevice>::iterator it;

    public:
        explicit Iterator(std::vector<DisplayDevice>::iterator iterator);
        Iterator& operator++();
        Iterator operator++(int);
        bool operator!=(const Iterator& other) const;
        DisplayDevice& operator*();
    };

    Iterator begin();
    Iterator end();
};

#endif // DEVICECONTAINER_H