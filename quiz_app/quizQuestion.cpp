# include<iostream>

double getDoubleNumber(std::string type){
 std::cout << "Enter"+type+"double value: "<<std::endl;
    double x;
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter one of the following: +, -, *, or / "<<std::endl;
    char op;
    std::cin >> op;
    return op;
}
 void printResult(double x, char op, double y)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << x + y << '\n';
    else if (op == '-')
        std::cout << x << " - " << y << " is " << x - y << '\n';
    else if (op == '*')
        std::cout << x << " * " << y << " is " << x * y << '\n';
    else if (op == '/')
        std::cout << x << " / " << y << " is " << x / y << '\n';
}

int main()
{
    double d1 = getDoubleNumber(" first ");
    double d2 = getDoubleNumber(" second ");

  char op = getOperator();
 
    printResult(d1, op, d2);


return 0;
}