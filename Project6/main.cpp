#include <iostream>
#include <memory>
#include <locale>
#include "ElectronicDevice.h"
#include "DisplayDevice.h"
#include "DeviceContainer.h"

void demonstratePolymorphism(ElectronicDevice* device) {
    std::cout << "Device specification: " << device->getSpecification() << std::endl;
}

int main() {
    // Налаштування локалі для підтримки української мови
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());

    DeviceContainer container;

    try {
        // Завантаження пристроїв з файлу
        container.loadFromFile("info.txt");

        std::cout << "All devices in container:\n";
        for (auto it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << "\n\n";
        }

        // Демонстрація поліморфізму
        std::cout << "\nDemonstrating polymorphism:\n";
        DisplayDevice displayDevice("Тест", "HDMI", 50, 1.5, 24, 1920, "Тестовий пристрій");
        ElectronicDevice* basePtr = &displayDevice;
        demonstratePolymorphism(basePtr);

        int choice;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Add new device\n";
            std::cout << "2. Edit existing device\n";
            std::cout << "3. Delete device\n";
            std::cout << "4. View all devices\n";
            std::cout << "5. Save changes and exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                std::string name, interface, description;
                double power, weight, diagonal;
                int resolution;

                std::cout << "Enter device name: ";
                std::cin >> name;
                std::cout << "Enter interface: ";
                std::cin >> interface;
                std::cout << "Enter power consumption (W): ";
                std::cin >> power;
                std::cout << "Enter weight (kg): ";
                std::cin >> weight;
                std::cout << "Enter diagonal (inches): ";
                std::cin >> diagonal;
                std::cout << "Enter resolution (px): ";
                std::cin >> resolution;
                std::cout << "Enter description: ";
                std::cin.ignore();
                std::getline(std::cin, description);

                container.addDevice(DisplayDevice(name, interface, power, weight, diagonal, resolution, description));
                std::cout << "Device added successfully!\n";
                break;
            }
            case 2: {
                size_t index;
                std::cout << "Enter device index to edit (0-" << container.size() - 1 << "): ";
                std::cin >> index;

                if (index >= container.size()) {
                    std::cout << "Invalid index!\n";
                    break;
                }

                DisplayDevice& device = container.getDevice(index);
                std::cout << "Current device:\n" << device << "\n";

                std::string name, interface, description;
                double power, weight, diagonal;
                int resolution;

                std::cout << "Enter new name (current: " << device.getName() << "): ";
                std::cin >> name;
                std::cout << "Enter new interface (current: " << device.getInterface() << "): ";
                std::cin >> interface;
                std::cout << "Enter new power consumption (W) (current: " << device.getPowerConsumption() << "): ";
                std::cin >> power;
                std::cout << "Enter new weight (kg) (current: " << device.getWeight() << "): ";
                std::cin >> weight;
                std::cout << "Enter new diagonal (inches) (current: " << device.getDiagonal() << "): ";
                std::cin >> diagonal;
                std::cout << "Enter new resolution (px) (current: " << device.getResolution() << "): ";
                std::cin >> resolution;
                std::cout << "Enter new description (current: " << device.getDescription() << "): ";
                std::cin.ignore();
                std::getline(std::cin, description);

                device.setName(name);
                device.setInterface(interface);
                device.setPowerConsumption(power);
                device.setWeight(weight);
                device.setDiagonal(diagonal);
                device.setResolution(resolution);
                device.setDescription(description);

                std::cout << "Device updated successfully!\n";
                break;
            }
            case 3: {
                size_t index;
                std::cout << "Enter device index to delete (0-" << container.size() - 1 << "): ";
                std::cin >> index;

                if (index >= container.size()) {
                    std::cout << "Invalid index!\n";
                    break;
                }

                container.removeDevice(index);
                std::cout << "Device deleted successfully!\n";
                break;
            }
            case 4: {
                std::cout << "\nAll devices:\n";
                for (size_t i = 0; i < container.size(); ++i) {
                    std::cout << i << ":\n" << container.getDevice(i) << "\n\n";
                }
                break;
            }
            case 5: {
                container.saveToFile("info.txt");
                std::cout << "Changes saved to info.txt. Exiting...\n";
                break;
            }
            default:
                std::cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 5);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}