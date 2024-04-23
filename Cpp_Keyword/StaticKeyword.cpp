#include<iostream>


using namespace std;
static int count = 0;


// c++ static example
void incrementCount() {
    count++;
}

void incrementLocalStaticCount() {
    static int count = 0;
    count++;
    printf("int static count : %d \n", count);
}

class Test {
    public:
      Test() {
        count++;
       }
      int getCount() {
        return count;
      }
};


int main () {

    printf(" static count vale %d\n", count);

    incrementCount();
    
    printf(" static count vale %d\n", count);

    incrementCount();

     printf(" static count vale %d\n", count);

     incrementLocalStaticCount();
     incrementLocalStaticCount();
     incrementLocalStaticCount();

     Test test1;
     Test test2;
     Test test3;
     cout<<" static count :"<<test1.getCount()<<endl;
     cout<< "Static count :"<<test2.getCount()<<endl;

    return 0;
}
