#include <iostream>
#include <string>
#include <locale>
// Базовый класс "Транспортные средства"
class TransportVehicle {
protected:
    std::string color;
    std::string brand;
    std::string model;
    int year;
    int horsepower;
    std::string engineType; // "электрический", "внутреннего сгорания" или "гибридный"

public:
    TransportVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType)
        : color(color), brand(brand), model(model), year(year), horsepower(horsepower), engineType(engineType) {}

    virtual void displayInfo() const {
        std::cout << "Цвет: " << color << "\n"
            << "Бренд: " << brand << "\n"
            << "Модель: " << model << "\n"
            << "Год выпуска: " << year << "\n"
            << "Лошадиные силы: " << horsepower << "\n"
            << "Тип двигателя: " << engineType << "\n";
    }
};

// Класс "Грузовые транспортные средства"
class CargoVehicle : public TransportVehicle {
private:
    double maxCargoWeight;

public:
    CargoVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double maxCargoWeight)
        : TransportVehicle(color, brand, model, year, horsepower, engineType), maxCargoWeight(maxCargoWeight) {}

    void displayInfo() const override {
        TransportVehicle::displayInfo();
        std::cout << "Максимальная масса груза: " << maxCargoWeight << " кг\n";
    }
};

// Класс "Пассажирские транспортные средства"
class PassengerVehicle : public TransportVehicle {
private:
    int passengerSeats;

public:
    PassengerVehicle(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, int passengerSeats)
        : TransportVehicle(color, brand, model, year, horsepower, engineType), passengerSeats(passengerSeats) {}

    void displayInfo() const override {
        TransportVehicle::displayInfo();
        std::cout << "Количество мест для пассажиров: " << passengerSeats << "\n";
    }
};

// Класс "Легковые транспортные средства"
class Car : public TransportVehicle {
private:
    double weight;
    int numberOfDoors;

public:
    Car(const std::string& color, const std::string& brand, const std::string& model,
        int year, int horsepower, const std::string& engineType, double weight, int numberOfDoors)
        : TransportVehicle(color, brand, model, year, horsepower, engineType), weight(weight), numberOfDoors(numberOfDoors) {}

    void displayInfo() const override {
        TransportVehicle::displayInfo();
        std::cout << "Масса автомобиля: " << weight << " кг\n"
            << "Количество дверей: " << numberOfDoors << "\n";
    }
};

int main() {
    system("chcp 1251");
    system("cls");
    CargoVehicle truck("Белый", "Volvo", "FH16", 2020, 750, "внутреннего сгорания", 25000);
    PassengerVehicle bus("Синий", "Mercedes-Benz", "Sprinter", 2019, 190, "дизельный", 20);
    Car sedan("Красный", "Toyota", "Camry", 2021, 301, "гибридный", 1500, 4);

    std::cout << "Информация о грузовом транспортном средстве:\n";
    truck.displayInfo();
    std::cout << "\nИнформация о пассажирском транспортном средстве:\n";
    bus.displayInfo();
    std::cout << "\nИнформация о легковом транспортном средстве:\n";
    sedan.displayInfo();

    return 0;
}
