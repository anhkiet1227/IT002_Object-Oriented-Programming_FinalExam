#include <iostream>

using namespace std;

class bac1 {
private:
    long long a;
    long long b;
public:
    bac1() {};
    bac1(long long a, long long b) {
        this->a = a;
        this->b = b;
    }
    ~bac1() {};
    friend long long fxo(bac1 f, long long xo);    
    friend long long fx(bac1 f);	
    friend bac1 operator+(bac1 f1, bac1 f2);
    
};
long long fxo(bac1 f, long long xo)
{
    return f.a * xo + f.b;
}

long long fx(bac1 f)
{
    return -f.b / f.a;
}

bac1 operator+(bac1 f1, bac1 f2) {
    bac1 res(f1.a + f2.a, f1.b + f2.b);
    return res;
}
int main()
{
    cout << "Hello World!\n";
	return 0;
}