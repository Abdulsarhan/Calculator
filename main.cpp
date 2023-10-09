#include <iostream>

double Add(double x, double y, double &result)
{
    result = x + y;
    return result;
}

double Subtract(double x, double y, double &result)
{
    result = x - y;
    return result;
}

double Multiply(double x, double y, double &result)
{
    result = x * y;
    return result;
}

double Divide(double x, double y, double &result)
{
    result = x / y;
    return result;
}

double Remainder(double &x, double y) 
{
    return x - (int)(x/y) * y;
}

double Remainder(double x, double y, double &result) 
{
   return result = x - (int)(x/y) * y;
}
void print_result(double x, double y, double &result, char operation)
{
    const char undefined[]= "undefined";

    if (operation == '/' && x == 0 | y == 0 )
    {
        std::cout << x << operation << y << "=" << undefined << "\n";
    }else
        std::cout << x << operation << y << "=" << result << "\n";
    
    /*if (Remainder(result, 2) == 0)
    {
        std::cout<< "this number is even \n";
    }else 
        std::cout << "this number is odd\n";
   */ 
}

double calculator(double x, double y, double &result, char operation)
{
    switch (operation)
    {
        case '+':
            Add(x,y, result);
            break;

        case '-':
            Subtract(x,y, result);
            break;

        case '*':
            Multiply(x,y, result);
            break;

        case '/':
            Divide(x,y, result);
            break;
        case '%':
            Remainder(x,y, result);
            break;
    }
    return result;
}

int main()
{
    double x;
    double y;
    double result;
    char operation;
    char yesorno;
    std::cout <<"Enter your first operand: ";
    std::cin >> x;
    std::cout <<"Enter your operation:\n";
    std::cout <<"+ = Add \n- = Subtract \n* = Multiply \n/ = Divide\n% = Remainder\n";
    std::cin >> operation;
    if (operation == '+' | operation == '-' | operation =='*'| operation =='/')
    {
        std::cout <<"Choose your second operand: ";
        std::cin >> y;
        calculator  (x, y, result, operation);
        print_result(x, y, result, operation);
        std::cout << "Wanna do another calculation? (y/n)";
        while (yesorno != y && yesorno != 'n')
        {
            std::cin >> yesorno;
            if(yesorno == 'y')
            {
                yesorno -= yesorno; 
                main();
            }else if (yesorno == 'n')
            {
                yesorno -= yesorno;
                return 0;
            }else
                yesorno -= yesorno;
                std::cout << "\nWanna do another calculation? (y/n)";
        }
        return 0;
    }   else
        std::cout << "invalid operation!\nRestarting...\n";
        operation -= operation;
        main();
}
