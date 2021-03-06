//
// Created by Lenovo on 2019/1/30.
//

#include <iostream>
#include <limits>

#ifndef CPPCODES_CPPBLOGCODE_H
#define CPPCODES_CPPBLOGCODE_H

#endif //CPPCODES_CPPBLOGCODE_H
using std::cout;
using std::endl;

class Person {
public:
    int age;
    char name;
    char sex;
    int id;

    Person() {
        cout << "Person is being created without param" << endl;
    };

    ~Person() {
        cout << "Person is being deleted " << endl;
    };  // 这是析构函数声明

    Person(int age, int id) : age(age), id(id) {
        cout << "Person is being created with params" << endl;
        cout << "Person age is :" << Person::age << endl;
        cout << "Person  id is :" << Person::id << endl;
    }
};

class Box {
public:
    double length;         // 长度
    double breadth;        // 宽度
    double height;         // 高度

    friend void printBreadth(Box box) {// 请注意：printWidth() 不是任何类的成员函数
        /** 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
        cout << "breadth of box : " << box.breadth << endl;
    }

    int compare(Box box) {
        return this->getVolume() > box.getVolume();
    }

    double getVolume(void)  // 返回体积
    {
        return length * breadth * height;
    }

    double getLength() const {
        return length;
    }

    void setLength(double length) {
        Box::length = length;
    }

    double getBreadth() const {
        return breadth;
    }

    void setBreadth(double breadth) {
        Box::breadth = breadth;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        Box::height = height;
    }

    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box &b) {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
};

class Student {

    int grade;//在类里面不写是什么类型，默认是 private 的。
private:
    char classroom;
public:
    char name;
protected:
    char address;

public:
    char getClassroom() const {
        return classroom;
    }

    void setClassroom(char classroom) {
        Student::classroom = classroom;
    }
};

class LittleStudent : Student {

public:
    void setAddress(char addrs) {
        address = addrs;
    }

    char getAddress() {
        return address;
    }
};

class AllLife {
private:
    int *ptr;
public:
    AllLife(int len) {//构造函数
        cout << "using alllife  constructor" << endl;
        // 为指针分配内存
        ptr = new int;
        *ptr = len;
    };

    AllLife(const AllLife &obj) {
        cout << "using alllife copy constructor and location mem for pointer  ptr " << endl;
        ptr = new int;
        *ptr = *obj.ptr; // 拷贝值
    }

    ~AllLife() {//析构函数
        cout << "release ptr memory" << endl;
        delete (ptr);

    }

    int getLength() {
        return *ptr;
    }

    void printLength() {
        cout << "AllLife size is " << getLength() << endl;
    }
};

//基类
class Shape {
public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

public:
    Shape(int a = 0, int b = 0) {
        width = a;
        height = b;
    }

    virtual int getArea() {
        cout << "Parent class area :" << endl;
        return 0;
    }

protected:
    int width;
    int height;
};

// 基类 PaintCost
class PaintCost {
public:
    int getCost(int area) {
        return area * 12;
    }
};

// 派生类
class Rectangle : public Shape, public PaintCost {
public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

    int getArea() {
        cout << "Rectangle class area :" << (width * height) << endl;
        return (width * height);
    }
};

class Triangle : public Shape {
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}

    int getArea() {
        cout << "Triangle class area :" << (width * height / 2) << endl;
        return (width * height / 2);
    }
};

void print_basic_data_types();

void set_print_person();

void set_print_boxes();

void set_print_student();

void set_print_alllife();

void set_print_inherit();

void set_print_polymorphism();

void test_files();