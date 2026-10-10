 #include "Queue.h"

Q :: Q() : D(nullptr), count (0){}

Q :: Q (const Q& other ) : D(nullptr), count(other.count) {
    if (count > 0){
        D = new int [count];
        for (int i = 0; i < count; i++){
            D[i] = other.D[i];
        }
    }
}

Q :: ~Q() {
    delete []D;
}

Q& Q :: operator= (const Q& other) {
    if (this == &other) return *this;
    delete []D;
    count = other.count;
    if (count > 0 ) {
        D = new int [count];
        for (int i = 0; i < count; i++){
            D[i] = other.D[i];
        }
    }
    else {
        D = nullptr;
    }
    return *this;
}

void Q :: push(int v) {
    int * nD = new int [count + 1];
    for (int i = 0; i < count ; i++){
        nD[i] = D[i];
    }
    nD[count] = v;
    delete [] D;
    D = nD;
    count++;
}


int Q :: pop() {
    int  v = D[0];
    int * nD = new int[count - 1];
    for (int i = 0 ; i < count; i++){
        nD [i-1] = D[i];
    }
    delete []D;
    D = nD;
    count--;
    return v;
}


Q Q :: operator+(const Q &other) const{
    Q r;
    for (int i = 0 ; i < count ; i ++){
        r.push(D[i]);
    }
    for (int i = 0 ; i < count; i ++){
      r.push(other.D[i]);
    }
    return r;
}

Q& Q :: operator+= (const Q& other) {
    for (int i = 0; i < other.count; i++){
        push(other.D[i]);
    }
    return *this;
}


bool Q :: operator==(const Q& other) const {
    if (count != other.count) return false;
    for (int i = 0 ; i < count; i ++){
        if (D[i] != other.D[i]) return false;
    }
    return true;
}


bool Q :: operator!=(const Q& other) const{
    return !(*this == other);
}

bool Q :: operator<(const Q& other) const{
    int n = count < other.count ? count : other.count;
    for (int i = 0 ; i < n; i ++){
        if (D[i] < other.D[i]) return true;
        if (D[i] > other.D[i]) return false;
    }

    return count < other.count;
}

bool Q :: operator<=(const Q& other) const{
    return (*this < other) || (*this == other);
}

bool Q :: operator> (const Q& other) const{
    return !(*this <= other);
}

bool Q :: operator>= (const Q& other) const{
    return !(*this < other);
}


Q& Q :: operator<< (int v){
    push(v);
    return *this;
}
Q& Q :: operator>> (int& v){
    v = pop();
    return *this;
}

std :: istream& operator>> (std :: istream& in, Q& q){
    int n;
    in >> n;
    delete [] q.D;
    q.D = nullptr;
    q.count = 0;
    for (int i = 0 ; i < n; i++){
        int v;
        in >> v;
        q.push(v);
    }
    return in;
}

std :: ostream& operator<< (std :: ostream& out, const Q& q){
    out << "[";
    for (int i = 0; i < q.count ; i ++){
        if (i > 0) out << ", ";
        out << q.D[i];
    }
    out << "]";
    return out;

}

















































