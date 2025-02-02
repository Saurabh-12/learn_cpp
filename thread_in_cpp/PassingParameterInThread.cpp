#include<iostream>
#include<thread>

void function1(int num)
{
    
    for(int i = 0; i < num; i++)
    {
        std::cout<<"i = "<<i<<'\n';
    }
    

}

class MyClassFunction
{
    int m_n;
    public:

    MyClassFunction(int n):m_n(n)
    {
        std::cout << "MyClassFunction constructore "<<m_n <<std::endl;
    }

    void ClassFunction(int num)
    {
        std::cout<<"MyClassFunction1 "+num<<'\n';
    }
};

auto MyLambda = [](const int &a, const int &b)
{
    std::cout<<"a+b = "<<a+b<<'\n';
    return a+b;
};


int main()
{
    std::thread myThread1(&function1, 5);

    std::thread myThread2(MyLambda, 9,5);
    myThread1.join();
    myThread2.join();

    int kk = MyLambda(9,7);
    printf("MyLambda KK: %d", kk);

    MyClassFunction obj(9);
  // std::thread myThread3(obj);
  // myThread3.join();
    
    return 0;
}