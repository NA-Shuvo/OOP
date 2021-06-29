
#   Object Oriented Programming
<br/>



<img src="https://github.com/NA-Shuvo/OOP/blob/main/images/what_is_it.jpg" alt="What is it"/>

**Object Oriented Programming is like the image above. [Bjarne Stroustrup](https://www.stroustrup.com/) used it in his slide. It was meant to
demonstrate the diverse perspectives of C++. To me it is also true for Object Oriented Programming."
<br/> <br/>
*"I think Object Oriented Programming is a capitalist idea! If you have problem with 
capitalism I can assure you that all people including socialists, communists and GOD himself think the whole 
universe in an object oriented way."*
<br/> <br/>
*"Each pattern describes a problem which occurs over
and over again in our environment, and then describes the core of the solution
to that problem, in such a way that you can use this solution a million times
over, without ever doing it the same way twice" - Christopher Alexander.*
<br/><br/> 
 
    
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


##   Contents

*   [Class](#chapter1)
*   [Defining our own class](#chapter2)
*   [Boilerplate of a class](#chapter3)
*   [Stucture vs Class](#chapter4)
*   [Class again!](#chapter5)



<h2 id = "chapter1"> Class </h2>

A class is a data type. An object is an instance of class. Let me give an analogy. When we declare 
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

And always remember Dough Mcllory's quote- **"Those types are not “abstract”; they are as real as int and float."**

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
features of OOP. <br/>

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
    int fuel_cost_per_second = 1;
    int travelled_distance = 0;
    
    //methods

    void move(int t)
    {
        travelled_distance += t * current_speed;
        existing_fuel -= t * fuel_cost_per_second; 
        
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
    int fuel_cost_per_second = 1;
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
    existing_fuel -= t * fuel_cost_per_second; 
    
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


<h2 id = "chapter4"> Stucture vs Class </h2>

In C++, strcuture and class are same thing. **So, we don't need to use struct to define a structure. We can always use class.**. But 
before abandoning struct forever, we need to know the similarities and dissimilarities between them. A structure by default is a class.
Class is a more general idea. To recognize the difference we need to know data access control mechanism in OOP.

One of the important features of OOP is it provides a very CONTROLLED reuseability of classes. You can write your own class and use it in different many programs or you can put it in to the internet. Then a lot of users can reuse it. Now, when you design a class, you may NOT want to reassign any attribute value from outside of the class by accidentally. So you need to have a access control mechanism. OOP comes with an access control mechanism. C++ provides three types of data accessibility- public, private, protected. Public members can be accessed from everywhere. Private members can be accessed within the class by other public and private members(mostly by methods) and we will learn proteced accessibility later in this course.<br/>

So, let's update out notion of class members with member accessibility. Public members can be accessible from anywhere. But when
it comes to private members we need some other public members to work with them. For example if we want to update a private data 
value we must need a public method to access it. Thus public methods can be treated like **interfaces**. An user use interface to
interact with the private members. Private members basically provide the **implementation details**. We don't need all implementation
details. Or sometimes we dont need to know how the class is implemented at all. So, we don't need to access those members at all. 

For our Car class we can group members into public and private catagory. Car ids should not be changed frequently or accidentally.
So, it should be a private data. If we don't want to change it ever we can make it private by using **private** keyword.
But we may need to know the value of id for some particular instance. So to access that data, we can just define another
member method say **get_id**. This method will return the value of id of the car. BUT we must define this method with
public accessibility. <br/>

Next we can talk about fuel_cost_per_second. An object has some core, hardly changeable qualities. Like a car fuel 
consumption rate is a hardly changeable quality. This type of data should not be changed accidentally. So, We can define 
this type of data as private one. And to work with this data we can define public methods. Thus, to update their values
an user must need to **consciously** use the method as interface. Thus the possibility of accidental modification of private data
is reduced! In this example we can define a public method to update fuel_cost_per_second. <br/>

Let's have a loot at the updated version of Car class with access modifiers.

```cpp

class Car
{
    //data member
    private:
    int id;
    int existing_fuel = 100;
    int current_speed = 0;
    int fuel_cost_per_second = 1;

    public:
    int travelled_distance = 0;
    
    //methods
    public:

    void move(int t)
    {
        travelled_distance += t * current_speed;
        existing_fuel -= t * fuel_cost_per_second; 
        
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
        fuel_cost_per_second = value;
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
members. My advice is **Don't use struct at all.**
<br/>

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

So class should be defined appropriately with related members.   








