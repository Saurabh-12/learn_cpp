class Cents
{
    private:
    int m_cent;

    public:
    Cents(int cent) {m_cent = cent;}
    const int getCent() const { return m_cent;}

};


// Need to explicitly provide prototype for operator+ so uses of operator+ 
//in other files know this overload exists
Cents operator+(const Cents &c1, const Cents &c2);