#ifndef PROB1_H
#define PROB1_H
#include <iostream>
using namespace std;

class Employee {
public:
    Employee(string, int, string);

    string getName() const {
        return name;
    }

    int getNum() const {
        return num;
    }

    string getdate() const {
        return date;
    }
protected:
    string name;
    int num;
    string date;
};

class ProductionWorker : public Employee {
private:
    int shift; //1=day, 2=night
    float pyrt; //hourly pay rate
public:
    ProductionWorker(string, int, string, int, float);

    void setShift(int shift) {
        this->shift = shift;
    }

    void setRt(float pyrt) {
        this->pyrt = pyrt;
    }

    int getShift() const {
        return shift;
    }

    float getRt() const {
        return pyrt;
    }
    friend ostream &operator<<(ostream &, const ProductionWorker &);

};

class ShiftSupervisor : public Employee {
public:
    ShiftSupervisor(string, int, string, float);
    friend ostream &operator<<(ostream &, const ShiftSupervisor &);
private:
    float annual;
    float bonus;
};

#endif /* PROB1_H */
