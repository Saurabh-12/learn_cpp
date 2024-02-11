Note that Because dynamic_cast does some consistency checking at runtime 
(to ensure the conversion can be made), use of dynamic_cast does incur a performance penalty.

Also note that there are several cases where downcasting using dynamic_cast will not work:
1) With protected or private inheritance.
2) For classes that do not declare or inherit any virtual functions (and thus don’t have a virtual table).
3) In certain cases involving virtual base classes

dynamic_cast vs static_cast
use static_cast unless you’re downcasting, in which case dynamic_cast is usually a better choice. 
However, you should also consider avoiding casting altogether and just using virtual functions.

Downcasting vs virtual functions
There are some developers who believe dynamic_cast is evil and indicative of a bad class design. 
Instead, these programmers say you should use virtual functions.

In general, using a virtual function should be preferred over downcasting. 
However, there are times when downcasting is the better choice:

When you can not modify the base class to add a virtual function 
(e.g. because the base class is part of the standard library)
When you need access to something that is derived-class specific 
(e.g. an access function that only exists in the derived class)
When adding a virtual function to your base class doesn’t make sense 
(e.g. there is no appropriate value for the base class to return). 
Using a pure virtual function may be an option here if you don’t need to instantiate the base class.
