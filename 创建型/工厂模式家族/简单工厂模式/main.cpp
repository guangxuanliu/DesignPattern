#include <iostream>
#include <memory>
#include <string>

// 产品接口
class Shape
{
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// 具体产品：圆形
class Circle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a Circle.\n";
    }
};

// 具体产品：矩形
class Rectangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a Rectangle.\n";
    }
};

// 简单工厂
class ShapeFactory
{
public:
    static std::unique_ptr<Shape> createShape(const std::string &type)
    {
        if (type == "circle")
        {
            return std::make_unique<Circle>();
        }
        else if (type == "rectangle")
        {
            return std::make_unique<Rectangle>();
        }
        else
        {
            return nullptr;
        }
    }
};

// 客户端代码
int main()
{
    auto shape1 = ShapeFactory::createShape("circle");
    if (shape1)
    {
        shape1->draw();
    }

    auto shape2 = ShapeFactory::createShape("rectangle");
    if (shape2)
    {
        shape2->draw();
    }

    auto shape3 = ShapeFactory::createShape("triangle"); // 不支持的类型
    if (shape3)
    {
        shape3->draw();
    }
    else
    {
        std::cout << "Unknown shape type.\n";
    }

    return 0;
}
