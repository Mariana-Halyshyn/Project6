#ifndef DISPLAYDEVICE_H
#define DISPLAYDEVICE_H

#include "ElectronicDevice.h"

class DisplayDevice : public ElectronicDevice {
private:
    double diagonal;
    int resolution;
    std::string description;

public:
    DisplayDevice();
    DisplayDevice(const std::string& name, const std::string& intf, double power, double w,
        double diag, int res, const std::string& desc);

    double getDiagonal() const;
    int getResolution() const;
    std::string getDescription() const;

    void setDiagonal(double diag);
    void setResolution(int res);
    void setDescription(const std::string& desc);

    std::string getSpecification() const override;  // override тут (в оголошенні)

    friend std::ostream& operator<<(std::ostream& os, const DisplayDevice& device);
    friend std::istream& operator>>(std::istream& is, DisplayDevice& device);
};

#endif // DISPLAYDEVICE_H
