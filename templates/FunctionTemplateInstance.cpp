#include<iostream>

template<typename T>
const T& max(const T &t1,  const T &t2)
{
    return (t1>t2)? t1:t2;
}

template<class T>
T average(T *array, int length)
{
    T sum = 0;
    for(int count=0; count < length; ++count)
    {
        sum += array[count];
    }

    sum /= length;
    return sum;
}



class Cents
{
    private:
    int m_cents;

    public:
    Cents(int cent) : m_cents(cent)
    {

    }

    const int getCents() const { return m_cents;}
     
    friend bool operator>(const Cents &c1, const Cents &c2)
    {
        return (c1.m_cents > c2.m_cents);
    }

    friend std::ostream& operator<< (std::ostream &out, const Cents &cents)
    {
        out << cents.m_cents << " cents ";
        return out;
    }
 
    Cents& operator+=(Cents cents)
    {
        m_cents += cents.m_cents;
        return *this;
    }
 
    Cents& operator/=(int value)
    {
        m_cents /= value;
        return *this;
    }
};

int main()
{
    Cents nickle(5);
    Cents dime(10);
 
    Cents bigger = max(nickle, dime);
    std::cout<<bigger.getCents()<<'\n';

    int array1[] = { 5, 3, 2, 1, 4 };
    std::cout << average(array1, 5) << '\n';
 
    double array2[] = { 3.12, 3.45, 9.23, 6.34 };
    std::cout << average(array2, 4) << '\n';

    Cents array3[] = { Cents(5), Cents(10), Cents(15), Cents(14) };
    std::cout << average(array3, 4) << '\n';

    return 0;
}