class Rupee
{
    private:
    int m_rupee;

    public:
    Rupee( int rupee = 0)
    {
        m_rupee = rupee;
    }

    int getRupee() const{return m_rupee; }
};

// Need to explicitly provide prototype for operator+ so uses of operator+ 
//in other files know this overload exists
Rupee operator+(const Rupee &r1, const Rupee &r2);