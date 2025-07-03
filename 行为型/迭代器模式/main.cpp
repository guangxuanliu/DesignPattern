#include <iostream>
#include <memory>
#include <vector>

// ========== 迭代器接口 ==========
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

// ========== 聚合接口 ==========
class Iterable
{
public:
    virtual ~Iterable() = default;
    virtual std::unique_ptr<Iterator> createIterator() = 0;
};

// ========== 具体容器 ==========
class IntArray : public Iterable
{
public:
    void add(int value)
    {
        data.push_back(value);
    }

    std::unique_ptr<Iterator> createIterator() override;

    int get(size_t index) const
    {
        return data.at(index);
    }

    size_t size() const
    {
        return data.size();
    }

private:
    std::vector<int> data;

    // 嵌套迭代器类
    // 此处不一定非得是嵌套类，但为了简化代码结构，使用嵌套类来实现迭代器
    class IntArrayIterator : public Iterator
    {
    public:
        IntArrayIterator(const IntArray &arr) : array(arr), index(0) {}

        bool hasNext() override
        {
            return index < array.size();
        }

        int next() override
        {
            return array.get(index++);
        }

    private:
        const IntArray &array;
        size_t index;
    };

    friend class IntArrayIterator;
};

// ========== 创建迭代器 ==========
std::unique_ptr<Iterator> IntArray::createIterator()
{
    return std::make_unique<IntArrayIterator>(*this);
}

// ========== 客户端 ==========
int main()
{
    IntArray arr;
    arr.add(10);
    arr.add(20);
    arr.add(30);

    std::unique_ptr<Iterator> it = arr.createIterator();
    while (it->hasNext())
    {
        std::cout << it->next() << " ";
    }
    std::cout << std::endl;
    return 0;
}
