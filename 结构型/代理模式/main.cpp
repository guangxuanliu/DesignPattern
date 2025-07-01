#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

// --- 1. Subject (抽象主题) ---
// 定义了图片操作的共同接口
class Image
{
public:
    virtual ~Image() = default;
    virtual void display() = 0;
};

// --- 2. Real Subject (真实主题) ---
// 实际的图片类，加载和显示图片是一个耗时操作
class RealImage : public Image
{
private:
    std::string filename;

    // 模拟图片从磁盘加载的耗时操作
    void loadImageFromDisk()
    {
        std::cout << "Loading " << filename << " from disk... (This takes time)" << std::endl;
        // 实际应用中可能包含文件I/O操作
    }

public:
    RealImage(const std::string &filename) : filename(filename)
    {
        // 在真实对象创建时就加载图片，这可能导致性能问题
        // loadImageFromDisk(); // 真实场景中，这里可能会立即加载，我们希望代理来延迟
    }

    void display() override
    {
        std::cout << "Displaying " << filename << std::endl;
    }
};

// --- 3. Proxy (代理) ---
// 图片代理类，控制对RealImage的访问，实现延迟加载
class ProxyImage : public Image
{
private:
    std::unique_ptr<RealImage> realImage; // 指向真实图片对象的指针
    std::string filename;
    bool isLoaded; // 标记图片是否已加载

public:
    ProxyImage(const std::string &filename)
        : filename(filename), isLoaded(false)
    {
        std::cout << "Proxy created for " << filename << ". Image not loaded yet." << std::endl;
    }

    void display() override
    {
        if (!isLoaded)
        {
            // 只有当display()方法被调用时才真正创建并加载RealImage对象
            realImage = std::make_unique<RealImage>(filename);
            // 模拟加载操作 (这里RealImage的构造函数不再加载，我们通过代理来控制)
            std::cout << "Actually loading " << filename << " through proxy..." << std::endl;
            // 模拟真实加载（如果RealImage构造函数不负责加载，则在此处调用）
            // realImage->loadImageFromDisk(); // 如果RealImage有公开的加载方法
            isLoaded = true;
        }
        realImage->display(); // 调用真实图片的显示方法
    }
};

// --- 客户端代码 (Client) ---
void clientCode()
{
    std::cout << "Client: Creating image proxies." << std::endl;

    // 创建代理对象，此时真实图片并未加载
    std::unique_ptr<Image> image1 = std::make_unique<ProxyImage>("photo_gallery_thumbnail_1.jpg");
    std::unique_ptr<Image> image2 = std::make_unique<ProxyImage>("photo_gallery_thumbnail_2.jpg");
    std::unique_ptr<Image> image3 = std::make_unique<ProxyImage>("photo_gallery_thumbnail_3.jpg");

    std::cout << "\nClient: Displaying first image." << std::endl;
    // 第一次调用 display()，真实图片才会被加载
    image1->display();

    std::cout << "\nClient: Displaying first image again." << std::endl;
    // 第二次调用 display()，图片已经加载，不再重复加载
    image1->display();

    std::cout << "\nClient: Displaying second image." << std::endl;
    // 加载并显示第二张图片
    image2->display();

    std::cout << "\nClient: Image 3 proxy exists, but never displayed." << std::endl;
    // image3 永远不会被加载，因为 display() 从未被调用
}

int main()
{
    clientCode();
    return 0;
}