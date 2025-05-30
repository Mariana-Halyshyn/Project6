#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include <string>
#include <iostream>

class ElectronicDevice {
protected:
    std::string name;
    std::string interface;
    double powerConsumption;
    double weight;

public:
    ElectronicDevice();
    ElectronicDevice(const std::string& name, const std::string& intf, double power, double w);
    virtual ~ElectronicDevice() = default;

    // Гетери та сетери
    std::string getName() const;
    std::string getInterface() const;
    double getPowerConsumption() const;
    double getWeight() const;

    void setName(const std::string& name);
    void setInterface(const std::string& intf);
    void setPowerConsumption(double power);
    void setWeight(double w);

    virtual std::string getSpecification() const;

    friend std::ostream& operator<<(std::ostream& os, const ElectronicDevice& device);
    friend std::istream& operator>>(std::istream& is, ElectronicDevice& device);
};

#endif // ELECTRONICDEVICE_H