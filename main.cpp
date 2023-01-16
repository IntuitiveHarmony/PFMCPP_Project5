/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/


/*
 copied UDT 1:
 */
#include <iostream>
struct Tree
{ 
    float height = {0.0f};
    int age = {0};
    std::string type = {""};
    std::string location = {""};
    int numberOfBranches = {0};

    Tree();
    ~Tree();
    struct Fruit
    {
        std::string name = {""};
        std::string color = {""};
        bool readyToEat = {false};
        int numberOfSeeds = {0};
        
        Fruit();
        ~Fruit();

        void produceSeeds();
        void fallFromTree();
        void inspireTheoryOfGravity();
        void sweeten(int water);
    };

    void grow(int water);
    Fruit produceFruit(int grow = 7);
    int photosynthesize(int sunLight = 5, int water = 3, int unkonwnFactor = 7);
};

Tree::Tree()
{
    std::cout << "Tree being constructed!" << std::endl;
}

Tree::Fruit::Fruit()
{
    std::cout << "Fruit being constructed! \nRight now it has " << numberOfSeeds << " seeds." << std::endl;
}

void Tree::grow(int water)
{
    std::cout << "All is well in the shade of the apple tree" << std::endl;
    for(int i = 0; i < water; ++i)
    {
        height += 0.1f;
        numberOfBranches += 3;
    }
}

Tree::Fruit Tree::produceFruit(int grow)
{
    Tree::Fruit fruit;
    
    if (grow > 0)
    {
        fruit.readyToEat = true;    
    }
    else 
    {      
        fruit.readyToEat = false;
    }
    
    return fruit;
}

int Tree::photosynthesize(int sunLight, int water, int unkonwnFactor)
{
    return (sunLight > 0) ? water * unkonwnFactor : 0;
}

void Tree::Fruit::produceSeeds()
{
    srand(1);
    numberOfSeeds = rand() % 10;
}

void Tree::Fruit::fallFromTree()
{
    std::cout << "yum!" << std::endl;
}

void Tree::Fruit::inspireTheoryOfGravity()
{
    std::cout << "Eureka!" << std::endl;
}

void Tree::Fruit::sweeten(int water)
{
    float sweetness = 0.0f;
    for(int i = 0; i < water; ++i)
    {
       sweetness += 0.3f;     
    }
    std::cout << "The fruit has " << sweetness << " units of sweetness! \n";
}

Tree::~Tree()
{
    std::cout << "Destroying Tree \n";
}

Tree::Fruit::~Fruit()
{
    std::cout << "Destroying Fruit \n";
}
/*
 copied UDT 2:
 */
struct PersonTwo
{
    float height = {0.0f};
    int age = {0};
    int numberOfSiblings = {0};
    std::string job = {""};
    std::string address = {""};

    PersonTwo();
    ~PersonTwo();

    struct Eye
    {
        std::string color = {""};
        bool needsGlasses = {false};
        bool hasCataracts = {false};
        std::string typeOfColorBlindness = {""};
        std::string vision = {""};

        Eye();
        ~Eye();

        bool open(bool awake = true);
        bool close(bool awake = true);
        void see();
        void blink(float dust);
    };

    bool run(int speed = 7);
    int jump(int crouch = 9, int energy = 4);
    bool playPiano(bool memoryRecal = true, int nerves = 11);
    void printFace(int numOfHeads);
};

PersonTwo::PersonTwo()
{
    std::cout << "PersonTwo being constructed!" << std::endl; 
}

PersonTwo::Eye::Eye()
{
    std::cout << "The eye is being constructed!" << std::endl;
}

bool PersonTwo::run(int speed)
{
    return (speed > 5) ? true : false;
}

int PersonTwo::jump(int crouch, int energy)
{
    return crouch * energy;
}

bool PersonTwo::playPiano(bool memoryRecal, int nerves)
{
    return memoryRecal && nerves > 10 ? true : false; 
}

void PersonTwo::printFace(int numOfHeads)
{
    for(int i = 0; i < numOfHeads; ++i)
    {
        std::cout << "(o_*) ";
    }
    std::cout << "\n";
}

bool PersonTwo::Eye::open(bool awake)
{
    return awake ? true : false;
}

bool PersonTwo::Eye::close(bool awake)
{
    return awake == false ? true : false;
}

void PersonTwo::Eye::see()
{
    needsGlasses = vision == "20/20" ? false : true;
}

void PersonTwo::Eye::blink(float dust)
{
    std::cout << "I've got something in my eye! \n";
    while(dust >= 0.0f)
    {
        dust -= 0.3f; 
        std::cout << "*blink, \n"; 
        if(dust <= 0.0f)
        {
            std::cout << "*blink. \n";
            std::cout << "That got it. \n\n";
        }    
    }
     
}

PersonTwo::~PersonTwo()
{
    std::cout << "Destroying PersonTwo \n";
}

PersonTwo::Eye::~Eye()
{
    std::cout << "Destroying Eye \n";
}
/*
 copied UDT 3:
 */
struct Computer
{
    bool airplaneMode = {false};
    float storageAmount = {0};
    int RAMAmount = {0};
    std::string manufacturer = {""};
    float screenSize = {0.0f};
    int amountUSBPort = {0};
    
    Computer();
    ~Computer();

    bool connectToInternet(bool paidISP);
    bool save(std::string fileName, bool clickSaveButton);
    void runApp(std::string something);
    void runFizzBuzz(int max);
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl; 
}

bool Computer::connectToInternet(bool paidISP = true)
{
    return paidISP ? true : false;
}

bool Computer::save(std::string fileName, bool clickSaveButton)
{
    return fileName != "" && clickSaveButton ? true : false;
}

void Computer::runApp(std::string text)
{
    std::cout << text << " on " << RAMAmount << " GB of RAM" << std::endl;
}

void Computer::runFizzBuzz(int max)
{
    for(int i = 1; i <= max; ++i)
    {
        if(i % 3 == 0 && i % 5 ==0)
        {
            std::cout << "FizzBuzz" << std::endl;
        } 
        else if(i % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;
        } 
        else if(i % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;
        } 
        else
        {
            std::cout << i << std::endl;   
        }
        
    }
}

Computer::~Computer()
{
    std::cout << "Destroying Computer \n";
}

/*
 new UDT 4:
 with 2 member functions
 */
struct Room
{
    Computer knot;
    PersonTwo jason;
    Tree::Fruit apple;

    Room();
    ~Room();

    void setUpComputer();
    void runShortcut();
};

Room::Room()
{
    std::cout << "The room is being entered \n";
}

void Room::setUpComputer()
{
    knot.storageAmount = 30.31f;
    knot.RAMAmount = 16;
    knot.manufacturer = "Apple";
    knot.screenSize = 13.1f;
    knot.amountUSBPort = 2;
    std::cout << "The " << knot.manufacturer << " coputer is now set up. \n\n";
}

void Room::runShortcut()
{
    knot.runFizzBuzz(45);
}

Room::~Room()
{
    std::cout << "The room is now empty \n";
}

/*
 new UDT 5:
 with 2 member functions
 */
struct Luggage
{
    Computer knot;
    Tree::Fruit apple;

    Luggage();
    ~Luggage();

    void activateAirplaneMode();
    void eatApple();
};

Luggage::Luggage()
{
    std::cout << "Luggage Packed \n";
}

void Luggage::activateAirplaneMode()
{
    knot.airplaneMode = true;
}

void Luggage::eatApple()
{
    apple.fallFromTree();
}

Luggage::~Luggage()
{
    std::cout << "Luggage emptied \n";
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Tree tree;
    tree.grow(34);
    tree.produceFruit();
    tree.photosynthesize();
    std::cout << "The tree is " << tree.height << " feet tall and has " << tree.numberOfBranches << " branches! \n";

    Tree::Fruit fruit;
    fruit.produceSeeds();
    fruit.fallFromTree();
    fruit.inspireTheoryOfGravity();
    fruit.sweeten(345);
    std::cout << "Does the apple have more than 4 seeds? " << (fruit.numberOfSeeds > 4 ? "Yes, it has " : "No, it only has ") << fruit.numberOfSeeds << (fruit.numberOfSeeds == 1 ? " seed. \n\n" : " seeds. \n\n");

    PersonTwo personTwo;
    personTwo.run();
    personTwo.jump();
    personTwo.playPiano();
    personTwo.printFace(3);
    
    PersonTwo::Eye eye;
    eye.open();
    eye.close();
    eye.see();
    eye.blink(3.4f);
    std::cout << "Is the person awake? Will they play the Piano? " << (eye.open() ? "Yes" : "No") << " and " << (eye.open() && personTwo.playPiano() ? "Yes" : "No") << "\n\n";
    
    Computer computer;
    computer.connectToInternet();
    computer.save("Sweet Cat Video", true);
    computer.runApp("App is running");
    computer.runFizzBuzz(30);
    std::cout << "Is the RAM higher than 8? " << (computer.RAMAmount > 8 ? "Yes" : "No") << "\n\n";

    Room room;
    room.setUpComputer();
    room.runShortcut();

    Luggage luggage;
    luggage.activateAirplaneMode();
    luggage.eatApple();
    
    std::cout << "good to go!" << std::endl;
}
