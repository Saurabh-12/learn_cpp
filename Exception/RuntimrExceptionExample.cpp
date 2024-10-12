#include<iostream>
#include<stdexcept>
#include<exception>

using namespace std;

class DivError : public runtime_error {

    public:
     
     DivError(const string& msg):runtime_error(msg){}
};


int main() {

    cout<<"Example of Runtime Exception : Divide by Zero start"<<endl;
    cout<<"sum: "<<(144/12*100-200+500)<<endl;

    int num = 12;
    int dem = 0;
    try {
        if(dem == 0)
          throw "Divide by 0 Exceptrion";
        //throw DivError("Variable divisor is zero.");

        int result = num/dem;
        int num = -1;
        int *reserveInt = new int(num);
        delete[] reserveInt;
    } catch (string &e1){
        cout<<"Exception: "<<e1<<endl;
    } 
    catch(DivError &e0){
        cout<<"Exception: "<<e0.what()<<endl;

    } catch(std::bad_alloc &e) {
        cout<<"Exception: "<<e.what()<<endl;
    } catch (...) {
       cout<<"Runtime exception : Catch by all type exception"<<endl;
    }



    return 0;
}