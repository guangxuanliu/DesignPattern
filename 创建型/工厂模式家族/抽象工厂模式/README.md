## 模式名
抽象工厂模式，Abstract Factory Pattern

## 工厂方法和抽象工厂的区别

| 模式     | 一句话总结                    |
| ------ | ------------------------ |
| 工厂方法模式 | 一个工厂只生产**一个产品**。         |
| 抽象工厂模式 | 一个工厂可以生产**一组相关产品**（产品族）。 |



工厂方法：
```
Creator —— createProduct() → Product
 ↑                      ↑
ConcreteCreator    ConcreteProduct
```

抽象工厂：
```
AbstractFactory —— createA() → ProductA
                 —— createB() → ProductB
        ↑                             ↑
ConcreteFactory1             ProductA1, ProductB1
ConcreteFactory2             ProductA2, ProductB2

```
