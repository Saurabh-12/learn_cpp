#include<iostream>
#include <cstdint> // for fixed width integers

class Average
{
    private:
    int32_t m_sum  = 0;
    int8_t m_count = 0;

    public:
    Average()
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Average &average)
    {
        // Our average is the sum of the numbers we've seen divided by the count of the numbers we've seen
		// We need to remember to do a floating point division here, not an integer division
        out<<static_cast<double>(average.m_sum)/average.m_count;
        return out;
    }

// Because operator+= modifies its left operand, we'll write it as a member
    Average& operator+=(int num)
    {
        // Increment our total by the new number
        m_sum += num;
        // And increase the count by 1
        ++m_count;
        // return *this in case someone wants to chain +='s together
        return *this;
    }
};

int main()
{
	Average avg;
	
	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4
	
	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';
 
	return 0;
}