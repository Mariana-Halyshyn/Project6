#include "DeviceContainer.h"
#include <fstream>
#include <sstream>
#include <iostream>

void DeviceContainer::addDevice(const DisplayDevice& device) {
    devices.push_back(device);
}

void DeviceContainer::removeDevice(size_t index) {
    if (index >= devices.size()) {
        throw std::out_of_range("Index out of range");
    }
    devices.erase(devices.begin() + index);
}

DisplayDevice& DeviceContainer::getDevice(size_t index) {
    if (index >= devices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return devices[index];
}

size_t DeviceContainer::size() const {
    return devices.size();
}

void DeviceContainer::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file for writing");
    }

    for (const auto& device : devices) {
        file << device.getName() << " " << device.getInterface() << " "
            << device.getPowerConsumption() << " " << device.getWeight() << " "
            << device.getDiagonal() << " " << device.getResolution() << " "
            << device.getDescription() << "\n";
    }
}

void DeviceContainer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Cannot open file for reading");
    }

    devices.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        DisplayDevice device;
        if (iss >> device) {
            devices.push_back(device);
        }
        else {
            std::cerr << "Warning: Failed to parse line: " << line << std::endl;
        }
    }
    std::cout << "Loaded " << devices.size() << " devices from file." << std::endl;
}

// Ðåàë³çàö³ÿ Iterator
DeviceContainer::Iterator::Iterator(std::vector<DisplayDevice>::iterator iterator) : it(iterator) {}

DeviceContainer::Iterator& DeviceContainer::Iterator::operator++() {
    ++it;
    return *this;
}

DeviceContainer::Iterator DeviceContainer::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++it;
    return tmp;
}

bool DeviceContainer::Iterator::operator!=(const Iterator& other) const {
    return it != other.it;
}

DisplayDevice& DeviceContainer::Iterator::operator*() {
    return *it;
}

DeviceContainer::Iterator DeviceContainer::begin() {
    return Iterator(devices.begin());
}

DeviceContainer::Iterator DeviceContainer::end() {
    return Iterator(devices.end());
}