#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

// ---------- 共享状态 ----------
struct CarSharedState {
    std::string brand;
    std::string model;
    std::string color;

    CarSharedState(std::string b, std::string m, std::string c)
        : brand(std::move(b)), model(std::move(m)), color(std::move(c)) {}

    friend std::ostream& operator<<(std::ostream& os, const CarSharedState& s) {
        return os << "[Brand: " << s.brand << ", Model: " << s.model << ", Color: " << s.color << "]";
    }
};

// ---------- 非共享实体类 ----------
class Car {
public:
    Car(std::string owner, std::string plate, std::string registerPlace,
        std::shared_ptr<CarSharedState> shared)
        : owner_(std::move(owner)), plate_(std::move(plate)),
          registerPlace_(std::move(registerPlace)), shared_(std::move(shared)) {}

    void Display() const {
        std::cout << "Car: " << *shared_ << " | Owner: " << owner_
                  << ", Plate: " << plate_ << ", Place: " << registerPlace_ << "\n";
    }

private:
    std::string owner_;
    std::string plate_;
    std::string registerPlace_;

    std::shared_ptr<CarSharedState> shared_;  // 持久化的共享状态
};

// ---------- 享元工厂 ----------
class CarSharedStateFactory {
public:
    std::shared_ptr<CarSharedState> Get(const std::string& brand,
                                        const std::string& model,
                                        const std::string& color) {
        std::string key = brand + "_" + model + "_" + color;
        if (cache_.count(key) == 0) {
            std::cout << "[Factory] Creating new shared state: " << key << "\n";
            cache_[key] = std::make_shared<CarSharedState>(brand, model, color);
        } else {
            std::cout << "[Factory] Reusing shared state: " << key << "\n";
        }
        return cache_[key];
    }

    void ListSharedStates() const {
        std::cout << "\nFactory has " << cache_.size() << " shared car types:\n";
        for (const auto& [k, v] : cache_) {
            std::cout << "  - " << k << "\n";
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<CarSharedState>> cache_;
};

// ---------- 客户端 ----------
int main() {
    CarSharedStateFactory factory;

    std::vector<Car> cars;

    cars.emplace_back("Alice", "A1234", "Shanghai", factory.Get("BMW", "X5", "Black"));
    cars.emplace_back("Bob", "B5678", "Beijing", factory.Get("BMW", "X5", "Black")); // 复用共享
    cars.emplace_back("Charlie", "C9012", "Shenzhen", factory.Get("Tesla", "Model Y", "White"));

    for (const auto& car : cars) {
        car.Display();
    }

    factory.ListSharedStates();

    return 0;
}
