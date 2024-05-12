#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Forward declaration of observer interface
class Observer;

// // Subject interface
class Subject {

    public : 
      virtual void registerObserver(Observer* mObserver) = 0;
      virtual void removeObserver(Observer* mObserver) = 0;
      virtual void notifyObservers() = 0;
      virtual ~Subject() {}
};

// Observer interface
class Observer {
    public:
      virtual void update(Subject* mSubject) = 0;
      virtual ~Observer() {}

};


// Concreate Subject class
class ConcreateSubject : public Subject {
    private:
      int mState;
      vector<Observer*> mObservers;
      public:

       void registerObserver(Observer* mObservetr) override {
        mObservers.push_back(mObservetr);
       }

       void removeObserver(Observer* mObserver) override {
         auto itr = find(mObservers.begin(), mObservers.end(), mObserver);
         if(itr != mObservers.end()) {
          mObservers.erase(itr);
         }
       }

       void notifyObservers() override {
        for(auto observer : mObservers) {
           observer->update(this);
           }
       }

       void setState(int state) {
           mState = state;
           notifyObservers(); //Notify observers when state changes
       }

       int getState() {
         return mState;
       }
};

//Concrete observer class
class ConcreteObserver : public Observer {
  private:
   ConcreateSubject* mSubject;

   public:
     ConcreteObserver(ConcreateSubject* subject) : mSubject(subject){
       mSubject -> registerObserver(this);
     }

     ~ConcreteObserver()  override {
      mSubject->removeObserver(this);
     }

     void update(Subject* subject) override {
      if(subject == mSubject) {
        // Get the updated state from the subject
        int state = mSubject->getState();
        // Print the updated state
        std::cout << "Observer received update. New state: " <<state<< std::endl;
      }
     }
};

int main() {

  //create subject
  //ConcreateSubject* subject = new ConcreateSubject();
  ConcreateSubject msubject;

  // create observers
  //ConcreteObserver* obs1 = new ConcreteObserver(subject);
  //ConcreteObserver* obs2 = new ConcreteObserver(subject);

  ConcreteObserver observer1(&msubject);
  ConcreteObserver observer2(&msubject);

  //updae state and notify observers
  msubject.setState(10);


  return 0;
}


