#include <iostream>
#include <list>

int main()
{
    std::list<int> l = {1, 2, 3, 4, 5};

    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    // 逆序遍历
    for (std::list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); rit++)
    {
        std::cout << *rit << std::endl;
    }

    // 只遍历奇数
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        if (*it % 2 == 0)
        {
            continue;
        }
        std::cout << *it << std::endl;
    }

    return 0;
}