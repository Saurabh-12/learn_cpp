C++ does not compile the template function directly. 
Instead, at compile time, when the compiler encounters a call to a template function, 
it replicates the template function and replaces the template type parameters with actual types. 
The function with actual types is called a function template instance.

Template classes are ideal for implementing container classes, 
because it is highly desirable to have containers work across a wide variety of data types, 
and templates allow you to do so without duplicating code.
 Although the syntax is ugly, and the error messages can be cryptic, 
 template classes are truly one of C++’s best and most useful features.

 Template non-type parameters
 A template non-type parameter is a special type of parameter that does not substitute for a type, 
 but is instead replaced by a value. A non-type parameter can be any of the following:
         ** A value that has an integral type or enumeration
         ** A pointer or reference to a class object
         ** A pointer or reference to a function
         ** A pointer or reference to a class member function
         ** std::nullptr_t

#Class template specialization
1. Class template specialization allows us to specialize a template class for a particular data type 
   (or data types, if there are multiple template parameters). 

2. Class template specializations are treated as completely independent classes, 
   even though they are allocated in the same way as the templated class. 

3. This means that we can change anything and everything about our specialization class, 
   including the way it’s implemented and even the functions it makes public
