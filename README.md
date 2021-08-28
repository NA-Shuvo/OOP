# Object Oriented Programming

<br/>

<img src="https://github.com/NA-Shuvo/OOP/blob/main/images/what_is_it.jpg" alt="What is it"/>
<br/>

*"Object Oriented Programming is like the image above. You can inspect it from many different angles."*

<br/>

*"I think Object Oriented Programming is a capitalist idea! If you have problem with
capitalism I can assure you that all people including socialists, communists and GOD himself think the whole
universe in an object oriented way."*

<br/>

*"Each pattern describes a problem which occurs over
and over again in our environment, and then describes the core of the solution
to that problem, in such a way that you can use this solution a million times
over, without ever doing it the same way twice" - Christopher Alexander.*

*"Object-oriented programming is an exceptionally bad idea which could only have originated in California." - Edsger W. Dijkstra*

# Table of Contents

* [Introduction](#chapter0)
* [Class](#chapter1)
* [Defining our own class](#chapter2)
* [Boilerplate of a class](#chapter3)
* [&#39;struct vs class&#39; and little about access controlling](#chapter4)
* [Class again!](#chapter5)
* [Encapsulation](#chapter6)
* [Interfaces](#interface)
* [Abstract Data Type in a nutshell](#adt)
* [Constructors, destructors and others](#cdo)
  * [Constructors](#constructors)
    * [new and delete](#nd) 
  * [Destructors](#chapter7.3)
  * [Others: copy, move](#chapter7.4)
* [Inheritance](#inheritance)
* [Polymorphism](#polymorph)
* [Credits](#credits)
* [Message](#message)


<h2 id = "chapter0"> Introduction </h2>

**Object Oriented Programming** (later in this text I will always refer it as **OOP**) is
a programming paradigm where we define our own data types and give them a **reasonable**,
NOT preferable name. By preferable I mean the use of **foo** or **bar** as varibale name instead of some reasonable name
that can give you some hints about the data. For example in OOP if we want to represent time as our data we
will NOT code it like bellow:

```cpp

int foo; // foo is for hour
int bar; // bar is for minute
foo = 5;
bar = 30; 

printf("Time: %d:%d", foo, bar); // This will print "Time 5:30"

```

In OOP we can code it like bellow:

```cpp

Time T(5, 30); // T will be defined in such a way that it can easily represent hour and minute
T.print(); // This will print "Time: 5:30"

```

So, how can we define time in such a way? OOP provides a way of definig everything in such a way.
Yes, everything, because **everything is object** (or atleast we can think everything as an object.)

<h2 id = "chapter1"> Class </h2>

**A class is a data type. An object is an instance of class.** Let me give you an analogy. When we declare
a variable(let say x) of integer data type with keyword **'int'** our computer allocates a memory that
can hold an integer type data. Now let's think we have our Time data type. Class allows us to define
Time such as we declare an integer variable. A variable of Time data type is an instance of Time class
like x is an instance of int data type.

```cpp
int x; 

// When computer executes the above statement it will allocate a memory that can hold an integer.

Time t; 

// When computer executes the above statement it will allocate a memory block that can hold
// at least two integers representing the hour and minute.

```

**So a class is the definition of a data type or simply a type and an object of this class is a variable of it. Remember, class doesn't hold any physical memory, it is just an abstract definition of a type, but object holds physical memory.**

And always remember [Dough Mcllory&#39;s](https://www.cs.dartmouth.edu/~doug/) quote- **"Those types are not “abstract”; they are as real as int and float."**

<br/>

<h2 id = "chapter2"> Defining our own class </h2>

Suppose we want to define our own Time class. Then how can we define it? Let's think we represent
our time object with only two data- hour and minute. Then in C++ we can define it by the following
way:

```cpp

class Time
{
    int hour;
    int minute;

};

```

Now we can use this definition in the main function. Well, **Never forget to put a ';' after class definition.**

```cpp

class Time
{
    int hour;
    int minute;

};

int main()
{
    Time t;
    return 0;
}

```

Now, observe the code very carefully. The **Time t;** statement allocates the memory for the object
variable **t**. We don't need to care about the memory allocation of the data **hour** and **minute**
explicitly within main function. They are automatically allocated implicitly. This is one of the main
features of OOP.

**hour** and **minute** are called **member data/attributes** of the object **t**. We can access to the
member data by using **.** symbol.

```cpp

#include <stdio.h>

class Time
{
    int hour;
    int minute;

};

int main()
{
    Time t;
    t.hour = 5;
    t.minute = 30;

    printf("Time: %d:%d\n", t.hour, t.minute);

    return 0;

}

```

The above code will print **"Time: 5:30"**. We can declare more Time type objects and we can access their
member data differently by using **.** symbol after object variable name.

```cpp

#include <stdio.h>

class Time
{
    int hour;
    int minute;

};

int main()
{
    Time t1, t2;

    t1.hour = 5;
    t1.minute = 30;

    t2.hour = 6;
    t2.minute = 45;

    printf("Time t1: %d:%d\n", t1.hour, t1.minute);
    printf("Time t2: %d:%d\n", t2.hour, t2.minute);

    return 0;

}

```

The object t1 and t2 are of same type (namely Time) BUT they are different objects. They hold different
memory. **Objects of the same class type never hold same memory.** They belong to same class but
their memory addresses are different. It's like we human beings are all human beings BUT we all are different than each other.
[Jeff Erickson](https://jeffe.cs.illinois.edu/) and [Thomas H. Coreman](https://www.cs.dartmouth.edu/~thc/) are different people BUT both of them are human beings. <br/>

Now we can write our own class type. So far our objects only consist of data. But an object is
NOT only a collections of data. An object can behave or it can accomplish some functionalities.
For example lets think of a different type of object 'car'. We need a car object for a video game
where a car has an id, a fuel tank. It starts a race with 100 litres oil. The player
needs to know information about speed, travelled distance, volume of existing fuel.
These are obviously member attributes for a particular car. We need some memory to store them. <br/>

But the value of these attributes can be changed. The video game player can move for 5 seconds with
current speed. This movement certainly change the value of travelled distance. Again movement causes
fuel consumption. Thus the value of existing fuel certainly will decrease. The game player can brake his
car. This causes the current speed falls down to zero. <br/>

So, the behaviors or the functionalities of the car change the values of its attributes. To perform
the change operation we need to define the logic of how the attributes are going to be changed
with the particular behavior. <br/>

To do so, we need to define these functionalities within the class. We can define a functionality or
behavior by defining a function. These functions within the class are called **member functions or methods**.

Let's have a look at the class definition of Car.

```cpp

class Car
{
    //data member
    int id;
    int existing_fuel = 100;
    int current_speed = 0;
    int fuel_cost_per_hour = 1;
    int travelled_distance = 0;
  
    //methods

    void move(int t)
    {
        travelled_distance += t * current_speed;
        existing_fuel -= t * fuel_cost_per_hour; 
      
    }

    void accelerate(int v)
    {
        current_speed = v;
    }

    void brake()
    {
        current_speed = 0;
    }

    void refueling(int ammount)
    {
        existing_fule += ammount;
    }

    void show_meter()
    {
        printf("Existing fuel : %d", existing_fuel);
        printf("Current speed : %d", current_speed);
        printf("Travelled distance : %d", travelled_distance);
    }


};

```

We can access to a member function same with the **'.'** symbol. Let's have a look at the main function.

```cpp

int main()
{
    // Declaration of 2 car objects
    Car car1, car2;

    // Set the ids of the cars
    car1.id = 1;
    car2.id = 2;

    // Now check the meter before start racing
    car1.show_meter();
    car2.show_meter();

    // Speed up car1 to 2 m/s. This sets car1.current_speed = 2
    car1.accelerate(2);

    // Speed up car2 to 3 m/s. This sets car2.current_speed = 3
    car2.accelerate(3);

    // Move car1 for 5 seconds. It sets car1.travelled_distance = 10 m and car1.existing_fuel = 95 litre
    car1.move(5);

    // Shows the updated meter information
    car1.show_meter();
    car2.show_meter();

    return 0;

}

```

<h2 id = 'chapter3'> Boilerplate of a class </h2>

From the above discussion we can say that a class definition provides a way to create our own data type. The instance
of the class data type is called object. A object has some member attributes or data and member functions or methods.
We simply use the word **members** to refer both of them. So when we want to define a class all we need to
declare and define it's members. So, the simplest boilerplate should look like this:

```cpp

class class_name
{
    //declare data members

    //declare (and define) methods
};

```

In C++ we can define class methods within as well as outside of the class definition. If we define methods of the Car class
it would look like this:

```cpp

class Car
{
    //data 
  
    int id;
    int existing_fuel = 100;
    int current_speed = 0;
    int fuel_cost_per_hour = 1;
    int travelled_distance = 0;
  
    //methods
    void move(int t);
    void accelerate(int v);
    void brake();
    void refueling(int ammount);
    void show_meter();

};

  
void Car::move(int t)
{
    travelled_distance += t * current_speed;
    existing_fuel -= t * fuel_cost_per_hour; 
  
}

void Car::accelerate(int v)
{
    current_speed = v;
}

void Car::brake()
{
    current_speed = 0;
}

void Car::refueling(int ammount)
{
    existing_fule += ammount;
}

void Car::show_meter()
{
    printf("Existing fuel : %d", existing_fuel);
    printf("Current speed : %d", current_speed);
    printf("Travelled distance : %d", travelled_distance);
}

```

Observe the code above carefully. We move definitions of all class methods outside of the class definition. We use the name of the class
with **double colon(::)** to specify the attachment of the class with the method. This is because we might have two methods with same
name from different classes. In that case we must specify which method definition belongs to which class. <br/>

**I like to define methods within the class.**

<h2 id = "chapter4"> 'struct vs class' and little about access controlling </h2>

In C++, strcuture and class are almost same thing. **So, we don't need to use struct to define a structure. We can always use class.**. But
before abandoning struct forever, we need to know the similarities and dissimilarities between them. A structure by default is a class.
Class is a more general idea. To recognize the difference we need to know data access control mechanism in OOP.

One of the important features of OOP is it provides a very CONTROLLED reuseability of classes. You can write your own class and use it in different many programs or you can put it in to the internet. Then a lot of users can reuse it. Now, when you design a class, you may NOT want to reassign any attribute value from outside of the class by accidentally. So you need to have a access control mechanism. OOP comes with an access control mechanism. C++ provides three types of member accessibility modifiers - public, private, protected. Public members can be accessed from everywhere. Private members can be accessed within the class by other public and private members(mostly by methods) and we will learn proteced accessibility later in this course. <br/>

So, let's update our notion of class members with member accessibility. Public members can be accessible from anywhere. But when
it comes to private members we need some other public members to work with them. For example if we want to update a private data
value we must need a public method to access it. Thus public methods can be treated like **interfaces**. An user use interface to
interact with the private members. Private members basically provide the **implementation details**. We don't need all implementation
details. Or sometimes we dont need to know how the class is implemented at all. So, we don't need to access those members at all.

For our Car class we can group members into public and private catagory. Car ids should not be changed frequently or accidentally.
So, it should be a private data. If we don't want to change it ever we can make it private by using **private** keyword.
But we may need to know the value of id for some particular instance. So to access that data, we can just define another
member method say **get_id**. This method will return the value of id of the car. BUT we must define this method with
public accessibility. <br/>

Next we can talk about fuel_cost_per_hour. An object has some core, hardly changeable qualities. Like a car fuel
consumption rate is a hardly changeable quality. This type of data should not be changed accidentally. So, We can define
this type of data as private one. And to work with this data we can define public methods. Thus, to update their values
an user must need to **consciously** use the method as interface. Thus the possibility of accidental modification of private data
is reduced! In this example we can define a public method to update . <br/>

Let's have a loot at the updated version of Car class with access modifiers.

```cpp

class Car
{
    //data member
    private:
    int id;
    int existing_fuel = 100;
    int current_speed = 0;
    int fuel_cost_per_hour = 1;

    public:
    int travelled_distance = 0;
  
    //methods
    public:

    void move(int t)
    {
        travelled_distance += t * current_speed;
        existing_fuel -= t * fuel_cost_per_hour; 
      
    }

    void accelerate(int v)
    {
        current_speed = v;
    }

    void brake()
    {
        current_speed = 0;
    }

    void refueling(int ammount)
    {
        existing_fule += ammount;
    }

    void show_meter()
    {
        printf("Existing fuel : %d", existing_fuel);
        printf("Current speed : %d", current_speed);
        printf("Travelled distance : %d", travelled_distance);
    }

    void update_fuel_consumtion_rate(int value)
    {
        fuel_cost_per_hour = value;
    }

    int set_id(int x):
    {
        id = x;
    }

    int get_id()
    {
        return id;
    }


};

```

Observe the above code carefully. We can't access id of a car object without consciously use set_id methods.
This is the main purpose of data access modifier.
Now, a struct is a class where all the members are by default public. So, don't use struct if you want some private
members. <br/> My advice is **don't use struct at all.** <br/>

<h2 id = 'chapter5'> Class again! </h2>

Let's talk about class again! Let's talk about it without codes. So far,
Class is a definition of our own data type. Wait, is it 'data type' or only 'type'?
Well, this is a good observation to be noted. We can surely define a class without any
data at all. We just define some member methods and that is all. So, sometimes class
can be thought of as a package of methods. For example we can define our own calculator
class consists of only basic methods for calculations like addition, subtraction,
multiplication, division etc. We pass all the data as arguments of the methods.
This type of classes are somtimes called **utility classes**. There is no data but only
some related methods. At this point we need to expand our ideas on object.
An object can be anything which has physical attributes or conceptual attributes.
We will consider a concept as an object. So concepts are objects too. No matter a
physical object or a concept, we always can define classes for them until we can
map their attributes and behavior to data and methods.

One last thing I want to add. Think about any real world physical object. You
can realize any object is a constitution of related attributes and behaviors. Think about
a vehicle. Any vehicle. We may define a vehicle class with a number_of_wheel attribute.
And we may define get_number_of_wheel() method which returns the number of wheel of the
vehicle. We may need to store the diameter of the wheel as an attribute.
If there is a wheel there we may need to work with its diameter. But shoud we define a
Student class with wheel or diameter of wheel? No. We should not. Technically we can code a
Student class with member like number_of_wheel and move method but they may not be
appropriate at all(unless we try to code in superman class or any superhero character from marvel).

**So class is all about relatedness and it should be defined appropriately with related members.**

<h2 id = 'chapter6'> Encapsulation </h2>

So far we have seen that class binds related data and methods all together. Generally methods
manipulate associated object data. This binding is called encapsulation. Encapsulation has another aspect though.
A good reader can easily understand that encapsulation enables access control to the data members. In
C++, class and access control modifiers implement encapsulation. Is there anything more about encapsulation?
No. But you can find many resource where it is stated that encapsulation provides modularity which is true.
But, the idea of modularity doesn't necessarily depend on encapsulation of data and methods. So, **modularity
is not unique implication of encapsulation.**

<h2 id = 'interface'> Interfaces </h2>

<br/>

*Keyboards, switchboards (and all boards) are great, so are the interfaces!!*
<br/>

*If you really want to be a developer, you need to learn how to use interfaces. They are easy.*
<br/> 

One of the most important conceptual aspects of modularity is about **interfaces**. You can easily remember that public
members, specially the methods are called interfaces. Now why they are called interfaces? What is actually an interface?
Well, interface is a medium of interaction. Do you completely know how electricity makes your fan moving or do you 
know the whole typing mechanism in a computer? The most probable answer is NO. BUT, we all can operate our fan by switching 
it ON or OFF on a switch-board without even a little caring about what is happening behind the board. The same thing is applicable
for typing mechanism. We DON'T need to know anything about how a keyboard works, how it is connected to computer and how keyboard
commands are transffered and processed. We just need to know how to stroke of the keys. Here keyboard and switchboard are simple
examples of interfaces. We use them to interact with the computer systems and the electricity system as users. 

Software developement is higly dependent on 
the efficient and correct use of those of interfaces. Interfacing with the various pre developed classes is in the centre of a developer's world. A programmer or 
a developer doesn't always need to understand the whole class definition like we don't need to know the behind scenario 
of the switchboard. He just need tp understand those public methods of a class/module written in the library documentation. Public methods interface the programmer with the classes. That's why they are called interfaces. 

**Encapsulation is a mechanism of separating the interfaces from complex implementation details.** Not all developers need to know all about implementational
details. For example, we just need to know how to call the move function, i.e the parameter list, the return values and dependencies(if any),
we don't need to understand the implementational details at all.


**How to use interfaces:**

*   Step 1: Go to the document website or related blogs or tutorial site for the module.
*   Step 2: Download and install the module
*   Step 3: Read the document carefully
*   Step 4: Import or include the specific class from the module.
*   Step 5: Create an object
*   Step 6: Read the document to use a specific interface. Carefully read: 
    *   1.  The must needed arguments
    *   2.  The return values
    *   3.  Error cases
    *   4.  Dependences(like you are not permitted to call an interface before calling another specific interface etc)
*   Step 7: Check if it works. If so, you are all done, if not, carefully read the error message. Then try to remove it. Discuss about it in community blog. 



<h2 id = 'adt'> Abstract Data Type in a nutshell </h2>


<br/>

*The purpose of abstraction is not to be vague, but to create a new semantic level in which one can be absolutely precise. - [Edsger Dijkstra](https://www.cs.utexas.edu/users/EWD/)* <br/>


ADT is the mathematical model of a data type. Now, what is a mathematical
model? Before talking about **mathematical** model let's talk about
**model** first. The word model comes with the **design** of a system.
But model is not only the design. It also describes the functinalities,
operational boudaries i.e constraints and limitations. These are called
behavior or **semantics** of a system. So, model is the **design** along
with the **semantics** of a system. When the design of a system is
logically correct and coherent with the **environment** and it comes with
a mathematically defined semantics, we call it a mathematical model. One of
the most frequently used mathematical models is the model of real number
system. There is a name for this model. It's called real algebraic field.
Real algebraic field restricts us from deviding a real number by zero. This
is one of the semantics of the real number system. We all have been using
this model since our childhood without knowing it formally.
<br/>
When we try to define our own data type, the first thing we need is to model
it mathematically. This model is called ADT, the abstract model of the data type.
It's not real data type/structure we are going to implement. It's only a list of
functions or methods or more specifically interfaces that describes the semantics
of the data type.
<br/>

One of our most frequently used data structures is Stack. The Stack ADT describes
the semantics of a Stack data structure.

```
Stack ADT:

push(item) : pushes "item" on the top of the stack.
pop() : pops the top item of the stack.
is_empty() : checks if the stack is empty.
pick() : returns the top item from the stack(but not pops it from the stack)  
```

Observe the Stack ADT carefully. It's a list of interfaces with parameter list and return values.
An ADT is all about it. It doesn't care about how the stack would be implemented.

ADT is not Data Structure rather it only describes the semantics of the data structure.
Sometimes to differentiate a data structure from abstract data types we call it concrete data
structure.<br/>

Sometimes, we can confuse class with ADT. Class is NOT ADT. Class is a mechanism to implement
ADT. Classes are dependent on the programming language, ADTs are not. They are independent of
any implementational process.


**How to implement your own data type/structures?**

*   Step 1: Construct an ADT for the data structure.
*   Step 2: Select a preferable object oriented language.
*   Step 3: Choose efficient algorithms to define the interfaces. You may also need some additional data structures.
*   Step 4: Implement it with class.


**Note: ADTs roughly are the list of interfaces of a class in simple English or any other language.**

<h2 id = 'cdo'> Constructors, destructors and others </h2>

*Ignorance more frequently begets confidence than does knowledge.– [Charles Darwin](https://en.wikipedia.org/wiki/Charles_Darwin)*
<br/>

*creation + initialisation = construction !*
<br/><br/>

**Desclaimer : This chapter is highly motivated by chapter 17 of Stroustrup's book The C++ Programming Language. It is a highly technical chapter. But this section is only an easy vesion.**

<h2 id = 'constructors'> Constructors </h2>

A **constructor** is a (so special) method with the same name of the class. But this is NOT obviously the defintion of constructor. This is just a naming rule. The truth is you can't define a constructor from outside of the constructor body. A constructor is anything like a method. It is self defining. You can define it like almost anyother method. You just need to remember that you **can't return** anything out of it.


Now, if constructor is a method then why we need to make it so special? There are some reasons. First of all, a constructor creates an object and initializes each and every **resources** necessary for an object. By **resources** memory, socket, thread, lock, file etc are meant. These resources are required to be free(or get back to heap as free resources) when they are no longer be needed. 

Constructors are very important to implement ADTs. Why? Almost all ADTs require some type of resources(mostly memories). Now, memories are the pre-requisite for an object in real. Constructors acquire the memory/resources from the very inception of the object and initializes them to some values if required. Let's define our own Stack [ADT](#adt) defined above. 

A stack is a container where items are pushed and popped in a LIFO order. What is a LIFO order? LIFO means **Last In First Out**. So, a stack only can pop out the last element pushed. Now, how can we implement this? 
The straight forward idea is to use an array to hold the items. The intresting thing is that, if we declare this array as a public member then the user directly use it and the purpose of a stack will be violated. So,
we need to make it private. In that case an user can't directly access into the array. This is the most important implication of encapsulation. Before going to the final implimentation let's have a look on two 
important c++ key-words: **new** and **delete**. 

<h3 id = 'nd'> new and delete </h3>

The c++ **new** keyword is used to allocate
memory dynamically and **delete** is used to release that memory. Generally dynamically allocated memories reside in heap portion of the memory. **new** and **delete** allocate and release memories from heap respectively. Remember new and delete comes in a pair. And technically constructors and destructors also
comes in pair. These are very core mechanism of c++ memory(broadly resource) management system.

```cpp
// Declare a pointer that will point the memory. Better initializing it to NULL 
int *p = NULL;
p = new int

// Or we can do the same thing in single instruction
int *q = new q;

// Now how to initialize ?
*p = 10;
*q = 15;

// We can intialize in declaration time.
int *r = new int(20);

// Now how to declare a block of memory or array?
int *arr = new int[10];

// Initializing the array
arr[0] = 5
arr[1] = 6

// How to release the memory
delete p;
delete q;
delete r;
delete [] arr

// Can we allocate memory for an object? yes.
Car *c = new Car();

// And we can delete it in the same way.
delete c;
```

Now we are ready to go for the full implementation of our Stack ADT.


**The key idea:**

*   Step 1: We will define an integer pointer that will point the array when a stack object will be created. For this we will use constructor function. Let's fix the array size to 100. If the size is exceeded, an error message will be displayed. To do so, we will use notthorw keyword with new. This will return NULL to the pointer in case of memory overflow. 
*   Step 2: We will define the interfaces.
*   Step 3: We will define a destructor function. It will handle the delete operation.


```cpp

class Stack
{
    private:
    int *arr = nullptr;
    int *top = nullptr;
    int *last = nullptr;
    int sz = 5;

    public:

    Stack()
    {
        arr = new(nothrow) int[sz];
        last = &arr[sz -1];

    }

    void push(int item)
    {

        if (top == nullptr)
            top = arr;
        else
            top++;

        if( top == last){
            cout << "Stack memory overflow" << endl;
            return;
        }

        *top = item;

    }

    int pop()
    {
        int result = -1;

        if (top == nullptr)
        {
            cout << "Stack memory underflow" << endl;
        }
        else
        {

            result = *top;

            if(top == arr)
                top = nullptr;
            else
                top--;

        }

        return result;

    }

    int pick()
    {
        return *top;
    }

    bool is_empty()
    {
        bool result = false;

        if(top == nullptr)
            result = true;

        return result;
    }

    ~Stack()
    {
        delete [] arr, top, last;
    }


};
```

<h2 id = 'inheritance'> Inheritance </h2>

*Inheritance is all about less coding.*

Inheritance is the process of obtaining the members from one class to another class. It establishes the relationship among two or 
more classes. The class from which the members are inherited is called base class and to which they are inherited is called derived
class. A derived class can be inherited from multiple base classes. In that case it is called multiple inheritance. Inherited members
need not to be re-written inm derived class. They will be just be called as if they were explicitly coded in the derived class. This
is the magic of inheritance. 


**How to inherit members from a single base class?**

*   Step 1: Define base class.
*   Step 2: Define derived class and inherit members from the base class by using ':' operator with access modifiers following the class name.**class derived_class_name : access_modifiers base_class_name {required definitions};**
*   Step 3: Choose preferable constructor name if there are one or more non-default constructors.

<br/>

```cpp

// Base class

class Person
{
    public:
    string name;
    int age;

    Person(string Name, int Age)
    {
        name = Name;
        age = Age;
    }

    void show_details()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

};

// Derived class

class Student : public Person
{
    public:
    int id;

    Student(string Name, int Age, int Id) : Person(Name, Age)
    {
        id = Id;
    }

    void show_details()
    {
        Person::show_details();
        cout << "Id: " << id << endl;
    }

};

```


**How to inherit members from multiple base classes?**

*   Step 1: Define base classes.
*   Step 2: Define derived class and inherit members from the base class by using ':' operator with access modifiers following the class names. Use comma(,) between base classes to mention them separately.
        **class derived_class_name : access_modifiers1 base_class_name1, access_modifiers2 base_class_name2, ..... {required definitions};**
*   Step 3: Choose preferable constructor name if there are one or more non-default constructors. If different constructors from different base classes are needed, mention all of them with comma(,) separation.
*   Step 4: In case of function name ambiguity, override the function. In case of mentioning any specific base class use scope operator(::) to mention it.

<br/>


```cpp

// Base class 1

class Person
{
    public:
    string name;
    int age;

    Person(string Name, int Age)
    {
        name = Name;
        age = Age;
    }

    void show_details()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

};

// Base class 2

class Student : public Person
{
    public:
    int id;

    Student(string Name, int Age, int Id) : Person(Name, Age)
    {
        id = Id;
    }

    void show_details()
    {
        Person::show_details();
        cout << "Id: " << id << endl;
    }

};


// Derived class

class CR : public Person, public Student
{
    public:
    bool is_CR;
    string mobile;

    CR(string Name, int Age, int Id, string Mobile): Student(Name, Age, Id), Person(Name, Age)
    {
        is_CR = true;
        mobile = Mobile;
    }

    void show_details()
    {
        Student::show_details();
        cout << "Mobile: " << mobile << endl;
    }
};


```

<h2 id = 'polymorph'> Polymorphism </h2>

*Best actors are those who can act in different roles.*

When the same entity (function or object) behaves differently in different scenarios, it is known as Polymorphism in C++. We have
already learn a portion of polymorphism in the name of function overriding. Overriding is rewriting the method with same name in different class. On the otherhand, overloading is multiple definitions of methods with same name(but obviously with different parameters or return type or both) within the same class. We can also overload some operators that means we can define the outputs of operation with operators on our own.
Both type of overloading happen in compile time. Let's observe some overloading.


```cpp

class Operation
{
    public:
    int sum(int a, int b)
    {
        return a + b;
    }

    string sum( string a, string b)
    {
        return a + ' ' + b;
    }

    double sum(double a, double b)
    {
        return a + b;
    }

};


```
The sum method takes different arguments and process them accordingly. Operator overloading is sometimes more
interesting. Let's add two complex number like integer addition.

```cpp

class Complex
{
    public:
    int a,b;

    Complex(int A, int B)
    {
        a = A;
        b = B;
    }

    Complex operator+(Complex other)
    {
        Complex result = Complex(a + other.a, b + other.b);
        return result;

    }

    show()
    {
        cout << a << "+" << b << "j" << endl;
    }
};


```



<h2 id = 'credits'> Credits </h2>

I am trying to follow the writing style of [Jeff Erickson](https://jeffe.cs.illinois.edu/)
BUT yes obviously this attempt is a failure. `<br/>`

To prepare this lecture I read some chapters from [Stroustrup&#39;s](https://www.stroustrup.com/) famous book [The C++ Programming Language](https://www.stroustrup.com/4th.html). BTW, this book is availabe in various versions in internet. If you want to learn OOP (and C++) really, you should read it.

For sections like [ADTs], [Interfaces] and Coding implementations I read some chapters from A First Course on Data Structures (in Python) by 
Donald R. sheehy. You can read it.  

All image credits must go to internet. But, motivation for the first photo was Stroustrup's [this](https://www.youtube.com/watch?v=86xWVb4XIyE) lecture. You can watch this lecture. It's an important video.

<h2 id = 'message'> Message </h2>

This note is a part of CSE313: Object Oriented Programming lecture notes for my students of summer 21. But anyone can use it and
reproduce it.

Ahh, wait, in this corona pandemic many people here in Bangladesh have become jobless, (homeless, and foodless).
I am trying to raise a personal fund to help few of those people(as much as I can). You can contribute to
that fund. If you are in Bangladesh you can bKash money to **+8801716338388**. If you really contribute, please update
[this](https://docs.google.com/spreadsheets/d/1N0gs5iwlseRnGKadSHgVEJivJ3b9hinEjhDlSWhBOnQ/edit?usp=sharing) form. And, for my students, you don't need to contribute to this fund. Try to save by yourself and help other!
