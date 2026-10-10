#pragma once
#include <iostream>


class Q {
private:
    int *D;
    int count;
public:
    Q();
    Q(const Q& other);
    ~Q();
    Q& operator= (const Q& other);
    
    int size() const {return count;}
    bool poos() const {return count == 0;}
    
    void push(int v);  // конец
    int pop(); // начало
    
    Q operator+ (const Q& other) const;
    Q& operator+= (const Q& other) ;
    
    
    bool operator== (const Q& other) const;
    bool operator!= (const Q& other) const;
    bool operator< (const Q& other) const;
    bool operator<= (const Q& other) const;
    bool operator> (const Q& other) const;
    bool operator>= (const Q& other) const;
    
    Q& operator<< (int v);
    
    Q& operator>> (int& v);
    
    friend std:: istream& operator>> (std::istream& in, Q& q);
    friend std:: ostream& operator<< (std::ostream& out,const Q& q);
};












