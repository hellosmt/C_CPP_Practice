/*
 * @Author: Cement
 * @Date: 2019-12-03 17:51:07
 * @LastEditors: Cement
 * @LastEditTime: 2019-12-04 21:16:06
 * @Description: 
 */
using namespace std;

//composite模式
#include <iostream>
#include <vector>
#include <iterator>

namespace test01
{
class Component
{
private:
    int value;

public:
    Component(int v) : value(v) {}
    virtual void add(Component *c) {}
    int getValue() const
    {
        return this->value;
    }
};

class Composite : public Component
{
private:
    vector<Component *> v;

public:
    Composite(int v) : Component(v) {}
    virtual void add(Component *c)
    {
        v.push_back(c);
    }
    void printVector() //这里加上const会报错 怎么改
    {
        for (vector<Component *>::iterator it = this->v.begin(); it < this->v.end(); it++)
        {
            cout << (*it)->getValue() << endl;
        }
    }
};

class Primitive : public Component
{

public:
    Primitive(int v) : Component(v) {}
};

void test_composite()
{
    Primitive p1 = Primitive(1);
    Composite c = Composite(2);
    Composite c1 = Composite(3);
    c.add(&p1);
    c.add(&c1);
    c.printVector();
}

} // namespace test01

//prototype模式
#include <iostream>
#include <vector>

namespace test02
{

enum imageType
{
    LandSat,
    Spot
};
class Image
{
private:
    //静态成员变量一定是在类内声明，类外进行初始化
    static Image *prototypes[10];
    static int _nextSlot;

protected:
    static void addPrototype(Image *image)
    {
        prototypes[_nextSlot++] = image;
    }

public:
    virtual Image *clone() = 0;
    virtual void draw() = 0;
    virtual imageType returnType() const = 0;
    static Image *findAndClone(imageType type)
    {
        for (int i = 0; i < _nextSlot; i++)
        {
            if (prototypes[i]->returnType() == type)
            {
                return prototypes[i]->clone();
            }
        }
    }
};
//类外初始化，可不加static
Image* Image::prototypes[];
int Image::_nextSlot;

class LandSatImage : public Image
{
private:
    int id;
    static int count;
    static LandSatImage lsi;

    //这个构造函数是编一阶段时静态成员变量lsi在初始化时使用的
    //并把自己添加到原型数组中
    LandSatImage()
    {
        addPrototype(this);
    }

    //这个构造函数是是在使用原型进行copy时调用的构造函数
    //使用占位参数来和上一个进行区分
    LandSatImage(int dummy)
    {
        this->id = count++;
    }

public:
    Image *clone()
    {
        return new LandSatImage(1);
    }

    void draw()
    {
        cout << "LandSatImage::" << this->id << endl;
    }

    imageType returnType() const
    {
        return LandSat;
    }
};
LandSatImage LandSatImage:: lsi;
int LandSatImage::count;

class SpotImage : public Image
{
private:
    int id;
    static int count;
    static SpotImage si;

    SpotImage()
    {
        addPrototype(this);
    }

    SpotImage(int dummy)
    {
        this->id = count++;
    }

public:
    Image *clone()
    {
        return new SpotImage(1);
    }

    void draw()
    {
        cout << "SpotImage::" << this->id << endl;
    }

    imageType returnType() const
    {
        return Spot;
    }
};
SpotImage SpotImage:: si;
int SpotImage::count;

const int IMAGE_NUM = 5;
imageType input[IMAGE_NUM]={LandSat, Spot, LandSat, Spot, LandSat};

void test_prototype()
{
    Image* images[IMAGE_NUM];
    for (int i = 0; i < IMAGE_NUM; i++)
    {
        images[i] = Image::findAndClone(input[i]);
    }
    for (int i = 0; i < IMAGE_NUM; i++)
    {
        images[i]->draw();
    }
    //释放内存
    for (int i = 0; i < IMAGE_NUM; i++)
    {
        delete images[i];
    }
    
}
} // namespace test02

int main()
{
    //test01::test_composite();
    test02::test_prototype();
}