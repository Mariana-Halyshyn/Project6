#include "ElectronicDevice.h"
#include <iomanip>

ElectronicDevice::ElectronicDevice() : name(""), interface(""), powerConsumption(0), weight(0) {}

ElectronicDevice::ElectronicDevice(const std::string& name, const std::string& intf, double power, double w)
    : name(name), interface(intf), powerConsumption(power), weight(w) {}

// Гетери та сетери
std::string ElectronicDevice::getName() const { return name; }
std::string ElectronicDevice::getInterface() const { return interface; }
double ElectronicDevice::getPowerConsumption() const { return powerConsumption; }
double ElectronicDevice::getWeight() const { return weight; }

void ElectronicDevice::setName(const std::string& name) { this->name = name; }
void ElectronicDevice::setInterface(const std::string& intf) { interface = intf; }
void ElectronicDevice::setPowerConsumption(double power) { powerConsumption = power; }
void ElectronicDevice::setWeight(double w) { weight = w; }

std::string ElectronicDevice::getSpecification() const {
    return "Power: " + std::to_string(powerConsumption) + "W";
}

std::ostream& operator<<(std::ostream& os, const ElectronicDevice& device) {
    os << "Name: " << device.name << ", Interface: " << device.interface
        << ", Power: " << device.powerConsumption << "W, Weight: " << device.weight << "kg";
    return os;
}

std::istream& operator>>(std::istream& is, ElectronicDevice& device) {
    is >> device.name >> device.interface >> device.powerConsumption >> device.weight;
    return is;
}