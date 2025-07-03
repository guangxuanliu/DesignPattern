#include <iostream>
#include <memory>
#include <string>

// ======= 抽象策略 =========
class CompressionStrategy
{
public:
    virtual ~CompressionStrategy() = default;
    virtual void compress(const std::string &inputFile, const std::string &outputFile) = 0;
};

// ======= 具体策略：ZIP =========
class ZipStrategy : public CompressionStrategy
{
public:
    void compress(const std::string &inputFile, const std::string &outputFile) override
    {
        std::cout << "Compressing '" << inputFile << "' to '" << outputFile << "' using ZIP.\n";
        // 模拟: system(("zip " + outputFile + " " + inputFile).c_str());
    }
};

// ======= 具体策略：GZIP =========
class GzipStrategy : public CompressionStrategy
{
public:
    void compress(const std::string &inputFile, const std::string &outputFile) override
    {
        std::cout << "Compressing '" << inputFile << "' to '" << outputFile << "' using GZIP.\n";
        // 模拟: system(("gzip -c " + inputFile + " > " + outputFile).c_str());
    }
};

// ======= 具体策略：TAR =========
class TarStrategy : public CompressionStrategy
{
public:
    void compress(const std::string &inputFile, const std::string &outputFile) override
    {
        std::cout << "Compressing '" << inputFile << "' to '" << outputFile << "' using TAR.\n";
        // 模拟: system(("tar -cf " + outputFile + " " + inputFile).c_str());
    }
};

// ======= 上下文类 =========
class Compressor
{
public:
    void setStrategy(std::shared_ptr<CompressionStrategy> strategy)
    {
        strategy_ = strategy;
    }

    void compressFile(const std::string &inputFile, const std::string &outputFile)
    {
        if (strategy_)
        {
            strategy_->compress(inputFile, outputFile);
        }
        else
        {
            std::cout << "[ERROR] No compression strategy set!\n";
        }
    }

private:
    std::shared_ptr<CompressionStrategy> strategy_;
};

// ======= 测试入口 =========
int main()
{
    Compressor compressor;

    compressor.setStrategy(std::make_shared<ZipStrategy>());
    compressor.compressFile("data.txt", "data.zip");

    compressor.setStrategy(std::make_shared<GzipStrategy>());
    compressor.compressFile("data.txt", "data.gz");

    compressor.setStrategy(std::make_shared<TarStrategy>());
    compressor.compressFile("data.txt", "data.tar");

    return 0;
}
