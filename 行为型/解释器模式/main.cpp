#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

// ====== 抽象表达式接口 ======
class Expression
{
public:
    virtual ~Expression() = default;
    virtual bool interpret() const = 0;
};

// ====== 终结符表达式 ======
class Literal : public Expression
{
public:
    Literal(bool value) : value_(value) {}
    bool interpret() const override
    {
        return value_;
    }

private:
    bool value_;
};

// ====== 非终结符表达式 ======
class AndExpression : public Expression
{
public:
    AndExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left_(left), right_(right) {}

    bool interpret() const override
    {
        return left_->interpret() && right_->interpret();
    }

private:
    std::shared_ptr<Expression> left_, right_;
};

class OrExpression : public Expression
{
public:
    OrExpression(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left_(left), right_(right) {}

    bool interpret() const override
    {
        return left_->interpret() || right_->interpret();
    }

private:
    std::shared_ptr<Expression> left_, right_;
};

class NotExpression : public Expression
{
public:
    NotExpression(std::shared_ptr<Expression> expr)
        : expr_(expr) {}

    bool interpret() const override
    {
        return !expr_->interpret();
    }

private:
    std::shared_ptr<Expression> expr_;
};

// ====== 测试入口 ======
int main()
{
    // 表达式：(true AND false) OR (NOT false)
    auto expr = std::make_shared<OrExpression>(
        std::make_shared<AndExpression>(
            std::make_shared<Literal>(true),
            std::make_shared<Literal>(false)),
        std::make_shared<NotExpression>(
            std::make_shared<Literal>(false)));

    std::cout << std::boolalpha;
    std::cout << "Result: " << expr->interpret() << "\n"; // true

    return 0;
}
