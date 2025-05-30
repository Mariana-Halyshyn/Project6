#include "DisplayDevice.h"
#include <sstream>

DisplayDevice::DisplayDevice() : ElectronicDevice(), diagonal(0), resolution(0), description("") {}

DisplayDevice::DisplayDevice(const std::string& name, const std::string& intf, double power, double w,
    double diag, int res, const std::string& desc)
    : ElectronicDevice(name, intf, power, w), diagonal(diag), resolution(res), description(desc) {}

// Гетери та сетери
double DisplayDevice::getDiagonal() const { return diagonal; }
int DisplayDevice::getResolution() const { return resolution; }
std::string DisplayDevice::getDescription() const { return description; }

void DisplayDevice::setDiagonal(double diag) { diagonal = diag; }
void DisplayDevice::setResolution(int res) { resolution = res; }
void DisplayDevice::setDescription(const std::string& desc) { description = desc; }

std::string DisplayDevice::getSpecification() const {  // БЕЗ override тут (у визначенні)
    return "Resolution: " + std::to_string(resolution) + "px, Diagonal: " + std::to_string(diagonal) + " inches";
}

std::ostream& operator<<(std::ostream& os, const DisplayDevice& device) {
    os << static_cast<const ElectronicDevice&>(device)
        << ", Diagonal: " << device.diagonal << " inches, Resolution: "
        << device.resolution << "px\nDescription: " << device.description;
    return os;
}

std::istream& operator>>(std::istream& is, DisplayDevice& device) {
    // Читаємо перші 6 полів
    is >> device.name >> device.interface >> device.powerConsumption
        >> device.weight >> device.diagonal >> device.resolution;

    // Читаємо решту рядка як опис
    std::getline(is >> std::ws, device.description);

    return is;
}