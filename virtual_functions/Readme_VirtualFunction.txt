Virtual function
the ability to structure your code in such a way that newly derived classes will automatically 
work with the old code without modification

Use of the virtual keyword
1. Only the most base class function needs to be tagged as virtual for all of the derived functions to work virtually.
2. However, having the keyword virtual on the derived functions does not hurt, and it serves as
 a useful reminder that the function is a virtual function rather than a normal one.the compiler also has to allocate an extra pointer for each class object that has one or more virtual functions
 
Note:- 
 Do not call virtual functions from constructors or destructors

 The downside of virtual functions
 1. Resolving a virtual function call takes longer than resolving a regular one
 2. the compiler also has to allocate an extra pointer for each class object that has one or more virtual functions.

Can we make Operator << virtual?
The short answer is no. There are a number of reasons for this.
First, only member functions can be virtualized -- this makes sense, since only classes can inherit from other classes, and there’s no way to 
override a function that lives outside of a class (you can overload non-member functions, but not override them)
Because we typically implement operator<< as a friend, and friends aren’t considered member functions, a friend version of operator<< is ineligible to be virtualized

Second, even if we could virtualize operator<< there’s the problem that the function parameters 
for Base::operator<< and Derived::operator<< differ (the Base version would take a Base parameter and 
the Derived version would take a Derived parameter). 
Consequently, the Derived version wouldn’t be considered an override of the Base version, 
and thus be ineligible for virtual function resolution.
