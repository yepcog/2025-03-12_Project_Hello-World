#define DEVELOPMENT_BUILD

#define DEFINE_INT int MyInt{4};

//preprocessor definition can span multiple lines, by using a "\" as a line break
//we added white spaces to distinguish our C++ code from preprocessor code, but it's not required
#define DEFINE_GREET			\
void Greet(){					\
	cout << "\nHello There";	\
};

// - function-like macros
//macros can also accept arguments to use within their replacement text (makes them behave somewhat like functions)
//following version accepts two arguments to be used in the replacement
#define DEFINE_ARG_GREET(Greeting, Name)	\
void argGreet() {	\
	cout << '\n' << Greeting << ", I am " << Name	\
		<< "\nNice to meet you!\n";	\
};

#include <iostream>
using namespace std; //should get rid of it, though don't know where exacly everywhere is, for using "std::" instead

// Numeric Variables and Arithmetics
int LargeNumber{ 100'000'000 };
int Level{ (1 + 2) * 3 };
int StartingHealth{ 500 };
int Lost{ 100 };

int Health{ StartingHealth - Lost + Lost };
int HealthModifier{ -10 };

float MaxHealth{ 500.5 };

// Constant Expression - something that can be evaluated at built time
float Armor{ 0.2 }; // converting double to float in this case possible because compile can determine at build time if 0.2 (double) can be stored as 0.2f (float) so allows it

// True & False Logic
bool IsLevel100{ Level == 100 };
bool IsLevel101{ Level != 101 };
int TargetLevel{ 100 };
bool IsTargetLevel{ Level == TargetLevel };
bool IsAboveLevel100{ Level > 100 }; // False
bool IsAtLeastLevel100{ Level >= 100 }; // True
bool IsHealthy{ Health > 300.0 }; // Floats are ok to use w int
bool IsAbove50Percent{ Health / MaxHealth > 0.5 };

bool IsAlive{ true };
bool IsDead{ !IsAlive }; // Not anymore
bool IsLevel100Or200AndAlive{
	(Level == 100 || Level == 200) && IsAlive // True, () to group checked things
};

// Types and Literals

// Functions

void TakeDamage() {
	cout << "\n- TakingDamage function starting";
	Health -= 50;
	cout << "\n- TakingDamage function complete";
}

// Conditional Logic
void TakeDamage2() {
	Health -= 50;
	if (Health <= 0) {
		IsDead = true;
		Health = 0; // Add that line to ensure health not gonna be negative in any circumstances
	};
}
void DropLoot() {
	cout << "\nYou can aquire some loot";
}
void Attack() {
	cout << "\nPerforming an attack";
}
void RunAway() {
	cout << "\nBetter run, better run, yeah, I'm comin' after you~";
}
void Heal() {
	cout << "\nPulse Cell!";
}
bool HasLoot{ false };
bool ShouldAwardExperience{ true };
bool CanHeal{ true };
bool CanSeePlayer{ false };
bool IsHostile{ true };
void CastHealingSpell() {
	cout << "\nHoly Nova!";
}
void AwardExperience() {
	cout << "\nYou gained some exp";
}
void PatrolArea() {
	cout << "\nMust've been my imagination, back to patrol";
}

// Switch Statements
int Day{ 6 };

// Function "return" Statements
int CalculateLevel() {
	return 9;
}
int TakeDamage1() {
	Health -= 50;
	return 50;
}
int Score{ 0 };
int HealthReturn{ 100 };
int TakeDamageReturn() {
	HealthReturn -= 50;
	return 50;
}
int TakeDamage3() {
	if (IsDead) {
		return 0;
	}
	else {
		Health -= 50;
		return 50;
	}
}
int TakeDamage4() {
	if (IsDead) return 0; // Since "return" stops function from execution further "else" is don`t necessary
	Health -= 50;
	return 50;
}

// Implicit Conversions, Narrowing Casts
// better to return exact type that function declares, so don't do that
bool IsDead0() {
	return 0;
}
bool IsDead42() {
	return 42;
}
int NumberToFalse() {
	return false; // converts the other way around as well, results in 0
}
bool GetHealth() {
	return 50; // this function converts to true
}
int IntegerPlusBool{ 5 + true };

float GetPiFloat() { return 3.14; }

// Function Arguments and Parameters
void TakeDamage20250326(int Damage20250326) {
	cout << "\nInflicting " << Damage20250326 << " damage ";
	Health -= Damage20250326;
	cout << "Health: " << Health;
}
int AddNumbers(int x, int y, int z) { // functions can have multiple parameteres separated by ","
	return x + y + z;
}
void MagicalDamage(int Damage, bool IsMagical) {// parameters can be of different types and don`t need to match return type of function (void in this case)
	Health -= IsMagical ? Damage * 2 : Damage;
}
int IntMagicalDamage(
int Damage, bool IsMagical = false // giving parameter default value makes it optional (meaning we don`t have to provide it, if else we just updating it in argument)
) {
	return Health -= IsMagical ? Damage * 2 : Damage;
}
void MultipleOptionalParameter( // we can have any number of optional parameters
	int Damage,
	bool IsPhysicalDamage = true,
	bool IsLethalDamage = true // however, we can`t have any required parameter after optional
) {
	// body here
}
int Add(int x = 1, int y = 2, int z = 3) { // DOESN`T WORK we can explicitly use default parameter by passing set of braces {}, in needed position (i change it to return what i need)
	if (x == 0) {
		x = 1;
	}
	if (y == 0) {
		y = 2;
	}
	if (z == 0) {
		z = 3;
	}
	return x + y + z;
}
int CalculateDamage() {
	return 25;
}

// Scope
int x{ 42 }; // variable declared in the global/file scope can be accessed from anywhere within file
void Log() { cout << "\nx is " << x; }
	// function parameters are scoped to block of their function alike variables

// Forward Declarations
void HandlePositive(int); // forward declaration typically put near files that use them, but might be anywhere but before functions are used
void HandleNegative(int); // function: definitions ARE ALSO declarations, declarations MAY or MAY NOT be definitions, prototype - DECLARATION WITHOUT DEFENITION

void HandlePositive(int = x) { // circular dependencies occur when two or more parts of code reference each other in a circle
	if (x < 0) HandleNegative(x);
}
void HandleNegative(int = x) {
	if (x >= 0) HandlePositive(x);
}
int Add(int x, int y) {
	return x + y;
}
int Add(int x, int y); // prototype of a function: return type (int), function name (Add), parameter types (int, int), parameter names are optional, so prototype can be valid like this
int Add(int, int); // but for better understanding including names helps anyone reading prototype. Prototype relate closely to the concept of interface in software design, interface sometimes relate as API
//API - application programming interface

// Loops
void LoopReturn() {
	for (int i{ 1 }; i <= 10; ++i) {
		if (i == 5) {
			cout << i << ".";
		}
		if (i == 5) return; // RETURN statement ENDS the EXECUTION OF the FUNCTION where loop is running, ALSO implicitly ENDS LOOP (as if we called break)
		cout << i << ", ";
	}
	cout << "\nGoodbye."; // never would be said, unreachable code (changes by replacing return with break)
}

// Modulus operator
int Quotient{ 5 / 3 }; // (/) operator lets get quotient (1)
int Reminder{ 5 % 3 }; // to get the reminder we using modulus operator (%), 2 (5/3=1 1*3=1 5-3=2 -> 5%3=2 2 - remainder)
bool IsEven(int Number) { // common use is to check if a number is even or odd
	return Number % 2 == 0; // after being devided by 2: even will have a remainder of 0 (no leftovers), odd - 1
} // in modular arithmetics "divisible by" used to refer to a scenario where modulo operator (%) returns 0, here - divisible by 2

bool IsDivisibleBy(int x, int y) { // can I write the code that can tell which numbers an x number can be divisible by
	cout << '\n';
	y = x;
	bool z{ true };
	while (z != 0) {
		for (y; y <= x; --y) {
			if (x % y == 0) {
				cout << y;
			}
			if (y == 1) {
				cout << ".";
				break; }
			if (x % y == 0) {
				cout << ", ";
			}
		}
		if (y == 1) break;
	}
	return 0;
}

int SmallerDividedByBigger{ 5 % 6 }; // when smaller number divided by larger number, reminder - smaller number itself, as it cannot be divided further

// Abstraction and Classes
class Monster { // class is the main way to create custom user-defined type (abstract category of thing that are similar in some way, things within category - objects), class is like blueprint
public: // variables/functions should be placed below public: within class
	// class code here (includes description of what variables and functions all objects have)
	int Health{ 150 }; // variables and functions belonged to a class sometimes referred to as class members (variables: data member, field, property; functions: method, member function) 
	void TakeDamage(int Damage) {
		Health -= Damage;
		if (Health < 0) { // we can attempt to set (Health never negative) invariant by providing a function that implements this rule
			Health = 0; 
		} 
	}
	void MagicDamage(int Damage); // we can use forward declaration, if need to, by providing prototype for our class function
};

void Monster::MagicDamage(int Damage) { // ClassName::FunctionName to provide definition elsewhere in our code (doesn't need to be within the class and even the same file)
	Health -= (Damage * 2);
}

// Encapsulation and Access Specifiers
class Enemy { // encapsulation - process of bundling data and functions within a class and controlling how they are accessed and modified
public: // access specifier, code inside can be accessed through external code
	void TakeDamage(int Damage) {
		Health -= Damage;
		if (Health < 0) { // we can attempt to set (Health never negative) invariant by providing a function that implements this rule (rules like this sometimes referred to as a class invariant)
			Health = 0;
		}
	}
	void SetHealth(int IncomingHealth) { // setter function - allows outside code to update variables (in a way that we can control the process)
		if (IncomingHealth < 0) { // for example: provide a setter for variable, but in a way that maintains the invariant that variable will never be negative
			Health = 0;
		}
		else {
			Health = IncomingHealth;
		}
	}
	int GetHealth() { // getter function - allowing external code to access our private members (READ access only, allows to see curent values), but outside code still can't change private variables
		return Health; // some languages offer a dedicated syntax for this, but in C++ we create a function in the normal way
	}
private: // access specifier, parts of our code that we don't want anyone to messing up with
	int Health{ 150 }; // private members of a class can still be modified by functions, but code outside of our class will no longer have access to it
};
class MyClass { // class can have as many access specifiers as we want
	int VariableA; // private - if there are no proceeding specifiers

public: // variables and function have the access level of the nearest proceeding specifier
	int VariableB; // public 
	int VariableC; // public

private:
	int VariableD; // private

public:
	int VariableE; // public
};

// Constructors and Destructors
class DefaultFoe { // classes are provided with basic default constructor as standart, however, we can replace it
public: 
	// basic example of a default constructor (default constructor - takes no arguments, used when we don't need to specify any initial values for created objects)
	// btw, constructors and destructors - functions (special functions of a class) :/
	DefaultFoe() { // to allow objects to be created without arguments we can reimplement default constructor, we do this by providing a constructor that takes no arguments
		// ...
	}
private:
	string mName; // (m) in mName stands for member (according no member naming convention, to prevent confusion, etc.)(can also have underscores: _name, Name_)
};

class Foe {
public:
	Foe(string Name, int Health = 150) { // constructors can have optional parameters, so previous code can and should be simplified to this
		mName = Name;
		mHealth = Health;
		cout << mName << " Ready for Battle!"
			<< "\nHealth: " << mHealth;
	}
private:
	string mName;
	int mHealth;
};

class DestructorFoe {
public:
	DestructorFoe() {
		cout << "Monster Created\n";
	}
	// destructor function (called automatically when an object is deleted
	~DestructorFoe() { // syntax similar to constructor, but with (~) prefix
		// ...
		cout << "Monster Destroyed\n";
	}
	// seems like? when program is executed and exited (returns 0) all objects, apparently, get destroyed
private:

};
void SomeFunction() { // for now we can note scenario: objects will get destroyed is when the scope they where created in gets destroyed (function ends - scope ends)
	DestructorFoe Deadman;
}

class InvalidFoe {
public:
	InvalidFoe(int Level) { mLevel = Level;  } // when defining multiple constructors we need to ensure that they don't "overlap"
  //InvalidFoe(int Health) { mHealth = Health; } // any time we creating an object, there must be only one constructor that supports the argument list that was provided
	// this is invalid because, if someone tries to initiate the class with a single int argument, compiler has no way of knowing what constructor is supposed to be used
private:
	int mLevel;
  //int mHealth;
};

class DefaultMonster {
public:
	// if we don't need to provide any implementation to this, we can use (= default) to restore the original default constructor
	DefaultMonster() = default;
	
	// classes can define multiple constructors, allowing objects to be created with a variety of different argument lists
	// once we define a custom constructor, the default is automatically deleted
	DefaultMonster(string Name, int Health) { // constructor that takes a string argument, granting the ability for name to bes set at creation time, can have multiple parameters, separated by a (,)
		mName = Name; // this is an example of where confusion can take place, w parameter of a constructor (function) and class members
		mHealth = Health;
		cout << mName << " Ready for Battle!"
			<< "\nHealth: " << mHealth;
	}
private:
	string mName;
	int mHealth;
};

class PrototypeFoe {
public:
	// the prototype
	PrototypeFoe(int Health); // similar to other functions we can define and declare constructors in different locations using prototypes
private:
	int mHealth{ 150 };
};
// the definition
PrototypeFoe::PrototypeFoe(int Health) { 
	mHealth = Health;
}

// Structs and Aggregate Initialization
struct Vector3 { // structure - similiar to class, stores coordinates for our objects
	// Vector3 (sometimes Vec3) one of the most fundamental types within graphic applications
	// VECTOR: represents position and direction within simulated space, 3: 3-dimensional vector, positions in 3D environment
	float x;
	float y;
	float z;
	// members of structs are PUBLIC by default (only difference w classes, TECHNICALLY they're almost identical)
	// structs also can have functions, constructors, destructors, and more.
	// structs or classes sentiment: structs are for creating simpler types, whilst classes are for creating more powerful types (in Unreal structs have legitimate technical limitations)
	// structs: passive objects that carry data, without complex behaviors and functionalities
	Vector3 operator+ (Vector3 Other) { // when overloading an operator as a member function - function called within the context of left operand - no need of providing left operand
		return Vector3{
			x + Other.x,
			y + Other.y,
			z + Other.z
		};
	}
	Vector3 operator-() { // when overloading unary (uno - one) operator as a member function - no parameters needed
		return Vector3{ -x, -y, -z};
	}
	// binary operator: standalone function - 2 parameters, member function - 1 parameter; unary operator: standalone - 1 parameter, member - no parameters ()
};

// Operator Overloading

// operators are simply functions that have a specific name and parameter list
// operator overloading: operators implemented with a specific naming convention using the word "operator"
//void operator+(Vector3 a, Vector3 b); // function prototype that allows two of our Vector3 objects to use + operator

// more specific definition of what we expect after using our operator
Vector3 operator-(Vector3& a, Vector3& b) { // passing by value: that way operands are being copied into function body - which is unnecessary; pass by reference: can be changed to by appending an ampersand (&)
	return Vector3{
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	};
} // sometimes reffered to as free functions (not implemented as member within relevant class/struct)
//int * Vector3
Vector3 operator*(int num, Vector3 vec) { //C++: A * B and B * A are not the same, so to give Vector3 abillity to be multiplied by int - two variations needed
	return Vector3{
		vec.x * num, vec.y * num, vec.z * num
	};
}
//Vector3 * int
Vector3 operator*(Vector3 vec, int num) { // if operation is commutative (order doesn't change output) - we can implement one function in terms of the other (when called - we defer to the int * Vector3)
	return num * vec;
}
//operators can be defined and declared in different locations, like any other function

// Structured Binding
class StructBindTest {
public:
	string Name;
	float Health;
	float Stamina;
};

// Inheritance
// Inheritance allows to orginize classes into hierarchies (as I understand creating higher by hierarchy classes (parent) where we define functions that multiple classes may need to have (eg. "Render()")
// term examples: Actor (class w abillity to render) - PARENT, ANCESTOR of Goblin class; Goblin - CHILD, DESCENDANT of Actor; 
// other terms: Goblin - SUB-CLASS of Actor; Goblin - DERIVES from Actor; Actor - BASE CLASS of Goblin
class Actor {
public:
	void Render() {};
};
//syntax for inheritance "class Child : public Parent { // public: code... };"
class Character : public Actor { // by default inheritance is private, so here we set it to public (not overruling an access, if something was private in parent class - it will be private in child class)
public:
	int GetLevel() { return 5; }
public:
	void Move() {}
	void Attack() {}
	void DropLoot() {}
	int GetHealth() { return mHealth; }
	// initializing health can be written using a member initializer: (initializer list is placed between constructor name and body, separated by (:); "Constructor() : initializer list { body }"
	Character() : //we can add parameters, to make our initializer lists support
		mHealth{ 150 },  //initialize multiple class variables by adding those to the list, separeted by commas (,)
		mLevel{ GetLevel() } { //any expression that results in a value of correct type can be used ( GeteLevel() or 125 + 25 for mHealth )
		// body here...
	};
protected:
	int mHealth{ 100 };
	int mLevel;
public:
	Character(int Health, int Level) : //with member initializer list we can set our constructor up to support arguments like this:
		mHealth{ Health },
		mLevel{ Level } {

	};
};
// since multiple classes of enemies might have same functions (attack, move, drop loot), it's better to have multi layers of inheritance
// so it makes sense to create class Character, that holds those functions, and left Goblin and Dragon classes w functions that specified only for their objects
class Goblin : public Character {
public:
	void Enrage() {}
};
class Dragon : public Character {
public:
	void Fly() {}
};
// when class is not designed to ever have a child class we can add "final" specifier to the class heading:
class Demon final {
public:

};
class Vampire final : public Character{ // final classes still have an abillity to inherit from base classes
public:

};
// class Archer : public Demon {}; // as a result of attempting to inherit from a final class: E1904 a 'final' class type cannot be used as a base class

// Protected Class Members
// "protected:" - access level in between private and public, can't be accessed by outside functions, but still can be accessed by code in child classes
class Healer : public Character {
public:
	void Heal(int Amount) { mHealth += Amount; } // since mHealth now not private but protected in base class, we can access it from derived class
};
// "public:", "protected:", "private:" - all three fundamental access specifiers: private - within same class they're defined, protected - same class + subclasses (child classes), public - from anywhere

// Member Initializer List
//why use member initializer list over code in constructor? performance (using initializer list is faster and that optimizes process of creation by reducing the number of required operations);
//code readability (makes the initialization intent explicit); it's sometimes required (necessary for correct class functionality in some scenarios)

//Working with Inherited Members
class Monsters {
public:
	Monsters() {
		cout << "\nDefault constructing Monsters";
	}
	Monsters(int Health) : mHealth{Health}{
		cout << "\nConstructing Monsters with an int";
	}
	int GetHealth() { return mHealth; }
public:
	Monsters(int x, int y) {
		std::cout << "\nTwo integers";
	}
	Monsters(int x, int y, int z) {
		std::cout << "\nThree integers";
	}
protected:
	int mHealth{ 100 };
	int mDamage{ 10 };
public:
	void Attack() { cout << "\nMonsters Attacking"; }
	int PerformAttack() { return mDamage; }
	void ExtendedAttack() {
		cout << "\nMonsters Attacking";
		cout << "\nPlaying Animation";
		cout << "\nPlaying Sound";
		cout << "\nUpdating UI";
		cout << "\nEven More Stuff";
	}
	int PerformBigAttack(int Damage) {
		mDamage = Damage;
		return mDamage;
	}
};

class Shapeshifter : public Monsters {
public:
	// to allow sub-classes to use base-class constructor (class inherit it's parent's constructors) we use syntax:
	using Monsters::Monsters; // where "using NameOfTheBaseClass::NameOfTheBaseClassConstructor" (same name anyway)
	//sub-class now have it's own (int, int, int) constructor, so code above will inherit only (int, int) constructor (instruction prioritizes the more derived version)
	Shapeshifter(int x, int y, int z) {
		std::cout << "\nI'll handle this one!";
	}
public:
	//ONLY place for calling an inherited constructor - within member initializer list - SubClassDefaultConstructor() : BaseClass{}{ some code... } - calling base-class default constructor explicitly
	//if inherited class doesn't have a default constructor (and we don't specify alternatives) we won't be able to create any objects (C2512 - 'BaseClass': no appropriate default constructor available)
	//if we've removed base-class default constructor and replacing it with constructor that accepts int - then we can pass that int within member initializer list of sub-class
	Shapeshifter() : Monsters{150} {
		cout << "\nDefault constructing Shapeshifter";
	}
	//we free to use expressions in this process, so if we also remove default sub-class constructor (replacing it with an int one), we can forward that int to base-class constructor through member initializer list
	Shapeshifter(int Health) : Monsters{ Health } {
		cout << "\nConstructing Shapeshifter with an int";
	}
protected:
	int mDamage{ 10 }; //ALWAYS initialize member variable, so that's now interfering a little with previos examples, but in case of learning that's bearable, just a warnings... (initialized w 10 anyway)
public:
	//if u feeling like your class member initializer lists are not complicated enough - there's a way to make them "slightly" more complex:
	Shapeshifter(int Health, int Damage) :
		Monsters{ Health }, //forwards to base-class constructor to set inherited Health
		mDamage{ Damage } { //sets mDamage, variable specific to sub-class type
		cout << "\nConstructing Shapeshifter with two ints";
	}
	int GetDamage() { return mDamage; }
};
class Shapeshuffler : public Monsters {
public:
	//in order to change some inherited variable values while there's no inherited constructor to let us set it directly - we can update it in sub-class constructor (if inherited variables are: public or protected)
	Shapeshuffler() {
		mHealth = 220;
	}
	//this example is possible because of the order in which constructors are called in inheritance scenarios: base-class constructors - first (for example: Actor - Character - Shapeshifter)
	//(meaning: within constructors of the more derived classes - the base will have already be completed and all inherited variables are set up)
public:
	//common mistake: shadowing inherited variable (and as a result: if we call getter which is defined within inherited class we will get returned variable value from base-class scope)
	//int mHealth{ 220 };
public:
	//shadowing inherited functions: specific implementation of inherited function, allowing to implement subtype-specific behaviors
	void Attack() { cout << "\nShapeshuffler Attacking"; }
	int PerformAttack() {
		return isBuffed ? mDamage * 2 : mDamage;
	} //returns sub-class function (while function we shadowing still exists on the base class)
	
	//inherited functions might be quite complex and we may want the version of that function in our subclass to do all those things, too - we just want it to do something extra
	void ExtendedAttack() {
		//when shadowing inherited function we can call inherited version: "BaseClassName::InheritedFunction();" ( :: - scope resolution operator)
		//also, we can call inherited version at any time
		cout << "\nSome initial Shapeshuffler things";
		Monsters::ExtendedAttack(); 
		cout << "\nand now some Shapeshuffler things";
	}
		//and we can forward or calculate arguments as needed
	void BigAttack(int Damage) {
		if (isBigAttackReady) {
			Monsters::PerformBigAttack(Damage * 2);
			isBigAttackReady = false;
		}
		else {
			cout << "\nNot ready!";
		}
	}
protected:
	bool isBuffed{ true };
	bool isBigAttackReady{ true };
};

// References
class Characters {
public:
	int Health{ 200 };
};
// when functions are called, our arguments are copied - this behavior is called "passed by value" (used by default w all variable types in C++)
void Combat(Characters Hero, Characters Enemy) {
	Hero.Health -= 50;
	Enemy.Health -= 50;
}
// variable can be implicitly converted to a reference to a variable of that same type
// int& reference to int, float& to float, Character& to Character; "&" syntax: to update function's parameter to be passed by reference
void Increment(int& x) { x++; }
// with that, modifications to the reference w Increment() function now are reflected in original variable
int ReferenceNumber{ 1 };
// same for Combat() function, updating our Characters types to be references
void ReferenceCombat(Characters& Hero, Characters& Enemy) {
	Hero.Health -= 50;
	Enemy.Health -= 50;
}
// caller can pass a value to function as a reference, function can modify it and then caller can inspect it after function ends
int fatalAttack(bool& wasFatal) {
	wasFatal = true;
	return 50; //while return is the main way of function to communicate information back to the caller - but with references we have another way
}
//parameter used for that feature sometimes referred to as - output parameter (rarely recommended)
struct fatalAttackResult {
	int fatalDamageResult;
	bool wasFatalResult;
};
//previos example can be written in a more friendly way - by returning a new type (caller can understand what function returns just by looking at type, can unpack its values using structured binding)
fatalAttackResult AttackResult() {
	return fatalAttackResult{ 50, true };
}
//when setting function up to receive reference, function expects to be called w a variable from which to create that reference - as such we can no longer pass a simple literal
void SomeOtherFunction(int& x) {}; //"int main() { SomeFunction(5); }" - cannot convert argument 1 from 'int' to 'int&' 
//(literals are temporary values and references meant to refer to something more permanent, like a variable - so that changes can be made to that variable)
//however, ability to modify a reference in a way that affects variables within the calling code - deneraly not desirable - for this reason, we can mark references as constant ("const")
void SomeFunction(const Characters& PlayerConstant) {
	//can do this w constant reference
	cout << '\n' << PlayerConstant.Health;

	//can't do this
	//PlayerConstant.Health -= 50;

	//"const" can be used in many situations - all relating to the idea of defining data that cannot be modified (can read data, but not change it)
	//constant references get us performance benefits of passing by reference, whilst also letting the caller know we're not going to modify their argument
}
//copying cost: for "int", "float", "bool" - negligible - so they tend to be passed by value
//when dealing with objects that contain other objects - user-defined types created from class that defines multiple mvariables; strings) - as such, passing them by const reference is generally preferred
// if - using an output parameter intentionally: pass by reference
// else if - parameter cheap to copy: pass by value
// else if - want to modify object within function and don't want changes to affect caller: pass by value
// else - pass by constant reference (in real use cases: 2, 4 by far most common)
class Weapon {
public:
	string Name;
};
//reference within a user - defined type
class ArmedCharacter {
public:
	//below, our ArmedCharacter objects have mSword, which is reference to a Weapon
	ArmedCharacter(Weapon& Sword) : mSword(Sword) {} //references in classes - MUST be initialized within a member initializer list
	Weapon GetWeapon() { return mSword; } //in this example function returns the weapon by value, not by reference
private:
	Weapon& mSword;
};
//(functions can return references, but we need to be carefull here - since reference linked to an underlying object, we need to ensure that the object has not automatically been deleted)
class refCharacter {
public:
	string Name;
};
refCharacter& refGetPlayer() { //note for myself: NEVER initialize anyhing through this, results in crashes
	refCharacter refPlayer{ "Anna" };
	return refPlayer;
}

// Pointers
//and we can pass pointers to functions
void HandlePointer(int* Pointer) {
	// ...
}
//to access the value that a pointer points to, we first need to visit the memory address the pointer if pointing at, and get the value stored there
//this process is reffered to as: Dereferencing the pointer - and done using "*" operator
//"*" operator returns an objects of the underlying type; dereferencing and "int*" (a pointer to an int) will return "int" (a simple int value)
void HandleThatPointer(int* Pointer) {
	int Dereferenced{ *Pointer };
	cout << "\nDereferenced: " << Dereferenced;
}
//"&" operator: with data type int& - work w reference; with variable &Variable - work w pointer
//"*" operator: with data type int* - work w pointer; with pointer variable *PointerVariable - dereferencing PointerVariable
//dereferenciating as i understand it: weird pointing int* after *Dereferenciation returns simple int that was pointed at, and that int is underlying type
void GetPrecedence(string* Precedence) {
	string ToPrecedence(*Precedence);
	cout << "\nLink to precedence of all operators:\n\n" << ToPrecedence << '\n';
}
string Precedence{ "https://en.cppreference.com/w/cpp/language/operator_precedence" };
// Increment function that we implemented using reference - now w pointers:
void referIncrement(int& Number) {
	Number++;
}
void pointIncrement(int* Number) {
	(*Number)++;
}
//differences:
// - as an argument function now expects pointer instead of an int
// - because Number is now pointer function needs to dereference it first before accessing/modifying underlying value
// - no longer can just pass an int into function expecting compiler to convert it to correct data type automatically (we need to be more explicit w pointers and use & )
//however:
// - references easier to work w
// - restrictions put on references are w good reason (additional work of managing pointers can get a lot more complex)
// - when possible it's better to prefer references (should only use pointers when references are unusable because of restrictions for the specific problem at hand)

//when working w pointers to custom types - we should dereference the pointer first before we access one of it's members
class someWeapon;
class someMonster {
public:
	int someTakeDamage(int Damage) {
		return mHealth -= Damage;
	}
	int mHealth{ 200 };
	someMonster() = default;
public:
	//to make a pointer point to nothing (representing the absence of a value) we use "nullptr" keyword
	someWeapon* mWeapon{ nullptr };
	someMonster(string Name) : mName{ Name } {
		//it bothers me that i can tell that this is a constructor when it's shorten to one line
	}
	void SetsomeEnemy(someMonster* Enemy) {
		mEnemy = Enemy;
	}
	void LogsomeEnemy() {
		if (mEnemy) {
			cout << "\nEnemy: " << mEnemy->mName;
		}
		else {
			cout << "\nI don't have an enemy";
		}
	}
public:
	someMonster* mEnemy{ nullptr };
	string mName;
};
class someWeapon {
public:
	string mName{ "Iron Sword" };
};
void CombatArt(someMonster* someEnemy) {
	// member access operator "." has higher precedence, so we need to use brackets "(*someEnemy).someTakeDamage(50);"
	//C++ provides alternative syntax for this - arrow operator "->" (we can think of it as a combined "*" and "." operators)
	someEnemy->someTakeDamage(50);
	//note: we only use arrow operator -> w pointers to an object
	//when we have: the actual object by value, or a reference to it - "." still used to access its members 
}

// The "this" Pointer
//within our member functions we have acces to specific keyford - "this"
struct someType {
public:
	//inside the body of a function "this" would contain a pointer to the object tha function was called on
	void someFunction() {
		cout << this; // for example: "someThing.someFunction();" - will log out a pointer to "someThing"
	}
};
// we can use "this" like any other pointer, also we can dereference it using "*" operator to access the object itself
struct someOtherType {
	someOtherType* Pointer() { return this; } //returns pointer to the current object
	someOtherType& Reference() { return *this; } //returns a reference to the current object
	someOtherType Copy() { return *this; } //returns a copy of the current object
};
class thisCharacter {
private:
	string mName;
	int mLevel{ 1 };
public:
	thisCharacter(string Name) : mName{ Name } {}
	thisCharacter(int Level) : mLevel{ Level } {}
	thisCharacter(string Name, int Level) :
		mName{ Name },
		mLevel{ Level } {
	}
	
	//we have a thisCharacter class, where objects can attack each other, when a character is attacked they will likely want to know ho attacked them (to react accordingly)
	//"this" pointer can help achieve that
	void Attack(thisCharacter& Target) {
		Target.TakeDamage(*this);
	}
	void TakeDamage(thisCharacter& Attacker) {
		cout << '\n' << Attacker.mName
			<< " has attacked me!";
	}
	//we might want to use "this" to return the object that the method was called on
	thisCharacter& SetName(string Name) {
		mName = Name;
		return *this;
	}
	thisCharacter& SetLevel(int Level) {
		mLevel = Level;
		return *this;
	}
	thisCharacter& Log() {
		cout << "\nI am a " << mName
			<< " and I am level " << mLevel;
		return *this;
	} //allows to create APIs where member functions can be chained together (we generate these by dereferencing the "this" pointer using the "*" operator)
	//chained member function call looks like this in the main() {
	//thisEnemy
		//.SetName("Name")
		//.SetLevel(int)
		//.Log();
	//}
public:	
	thisCharacter() = default;
};
//overloading incremention and multiplivation operators w "this"
struct thisVector3 {
	float x;
	float y;
	float z;
	//by overloading these we can be able to chain operators like: "(++thisVector) *= int;"
	thisVector3& operator++() {
		++x;
		++y;
		++z;
		return *this;
	}
	thisVector3& operator*=(int Multiplier) {
		x *= Multiplier;
		y *= Multiplier;
		z *= Multiplier;
		return *this;
	}
	//overloading the posfix operator using a member function: (to do this, we typically have three steps)
	thisVector3 operator++(int) { 
		thisVector3 temp{ *this }; // - create a copy of the object w it's current value
		//++x; // - modify the object to increment it
		//++y;
		//++z;
		//since we already have prefix operator we can simplify postfix overloading
		++(*this); //here we applying our already overloaded prefix operator to our "temp" value (which is stored in "this" and dereferenced by "*")
		//now it started to make some sense actually
		return temp; // return the original copy
	}
};
//to get equivalent behavior as we did using "this" pointer through free functions: operators need to receive operand by reference and return that same reference
//code below works and I'm really proud of it (since I am hardly proccessing latest lessons), but I don't want it to interfere w function operator overloaders
//thisVector3& operator++(thisVector3& vec) {
	//++vec.x;
	//++vec.y;
	//++vec.z;
	//return vec;
//}
//thisVector3& operator*=(thisVector3& vec, int Multiplier) {
	//vec.x *= Multiplier;
	//vec.y *= Multiplier;
	//vec.z *= Multiplier;
	//return vec;
//}
//to overload postfix operator syntax is a little different (and also "inelegant", looks dumb for me + requires an additional parameter)
//to override the posfix operator as a free function:
//thisVector3 operator++(thisVector3 Vec, int) {
	//// code
//}
//postfix vs prefix:
// - performance: copying our object to support expected postfix behavior has a performance overhead, therefore - ++SomeObject generally faster then SomeObject++
// - if we don't care about the return value of the expression (specific reasons), we should default to using the prefix variations

//Dangling Poiners and References
int* GetPointerNumber() {
	int Number{ 1 };
	return &Number;
}
//example w a destructor in custom type function
struct SomeType {
	int Value{ 1 };
	~SomeType() {
		cout << "\nDestroying"; //oooh, that's because our int is already destroyed after function end, then how did I catch it w previous example
	}
};
SomeType* GetSomeObject() {
	SomeType SomeObject;
	return &SomeObject;
}
//dangling pointers/dangling references - when we have a pointer or a reference to an object, and that object is then deleted, the pointer is no longer usefull
//if we attempt to use this dangling pointer or reference - our program's behavior becomes undefined (often leads to unpredictable results and crashes or other serious issues)
// - this is becuase the memory our objects was using is freed up for other purposes (meaning: we no longer know what'll be stored there by the time we use our opinter/reference)
//pointers return memory address (which might refer to a memory location that about to be freed) while returned by value objects from function creating a copy of a variable, and returning that copy

//storage duration - concept: objects in C++ have a different lifetime depending on how they're created
// - automatic storage duration: what local variables we've been using in functions have, they automatically created (when function is called) and destroyed (when it ends)
// - static storage duration: objects exist for the entire run of the program
// - thread storage duration: each thread has its own copy of the object (red thread of destiny)
// - dynamic storage duration: programmer controls when objects are created or destroyed
//options to make objects last longer then a single function call:
// - create it in the global scope (though this should be used sparingly)
// - create it inside the main() function (that's what I did to save a variable from example)
// - make it a part of a longer-lived object

// Function Overloading
//polymorphism - same expressions can have multiple forms, based on contex or data types it is used w, manifests mainly in three forms:
// - overloading: operator overloading; function overloading (multiple functions w same name but different parameter lists)
// - templates: allows to define recipes for blocks of code, compiler then can generate functions or entire classes that adapts for our needs
// - run time polymorphism: allows dynamic behavior w/out introducing excessive complexity

//overload functions: define functions w the same name, w/int the same scope, but have a different parameter list
struct Rectangle {
	float Width;
	float Height;
};
float CalculateArea(const Rectangle& R) { //rectangle requires width and height
	return R.Width * R.Height;
}
//defined Rectangle and Circle types; alongside each class we provide standalone functions (same name, different parameter lists)
struct Circle {
	float Radius;
};
float CalculateArea(const Circle& C) { //while circle expecting only radius argument
	return 3.14 * C.Radius * C.Radius;
}
//when these functions both available they considered - overloaded

//member function can be overloaded the same way as a free functions
class OverloadWeapon {};
class OverloadShield {};
class OverloadCharacter {
public:
	void Equip(OverloadWeapon* Weapon) {
		mWeapon = Weapon;
	}
	void Equip(OverloadShield* Shield) {
		mShield = Shield;
	}

private:
	OverloadWeapon* mWeapon{ nullptr };
	OverloadShield* mShield{ nullptr };
};
//when working w overloaded functions we might get compiler report errors claiming our function calls are ambiguous (in this scenarios we need to be more explicit about our types)
void Func(int Arg) {}
void Func(float Arg) {}
//when we call "Func(1.5)" we're getting a compiler error because: numbers like "1.5" is interpreted as a "double", rather than a "float", float literals append w "f" ("1.5f")
//since doubles can be implicitly converted not only to floats but also to integers as well, which causes a problem in this context; w/out "f" our code is ambiguous

// Static Casting
//type casting (or just casting) - explicit conversions (like int to float, for example)
//casting can be: static (done at build time) or dynamic (done at run time)
//usefull properties of a static casting: min performance impact (or often none at all), compiler check if the cast is possible and throws an error if not (preventing us from introducing bugs)

double CastingFunction() { return 1.0; }

int AddMyInt(int x, int y) { return x + y; }

// Virtual Functions and Overrides
//run time polymorphism can be achieved w techniques: inheritance, references and pointers, virtual functions
//for related to the lesson examples may use rtp prefix (run time polymorphism), building combat system as an example
class rtpCharacter {
public:
	//anytime we want our char to do somethin, we'll call Act() function and we'll pass a pointer to the target that our char interact w
	virtual void rtpAct(rtpCharacter* Target) {
		//marking Character version of this function as "virtual"
		cout << "\nCharacter Acting";
	}
	//introducing a concept of chars being alive/dead
	bool rtpGetIsAlive() {
		return isAlive;
	}
protected:
	bool isAlive{ true };
};
//then every type of object that we'll create will inherit from this base class
class rtpGoblin : public rtpCharacter {
	//our user defined subclasses may have different approach to Act() function, so we may override it using the prototype from Character base class, then we need to mark Character version as "virtual"
public:
	void rtpAct(rtpCharacter* Target) final { //accidently left a pointer to orig Character, so that led to mistakes in output
		cout << "\nGoblin Acting!";
	}
};
class rtpDragon : public rtpCharacter {
public:
	//when a class function is supplanting a virtual method on a base class in this way - it is considered an override (and when this happening we should be explicit by marking function w "override" keyword)
	void rtpAct(rtpCharacter* Target) override {
		//this's not required, but has it's benefits (so we should use it where applicable):
		// - informs other devs reading our function that it is an override
		// - compiler ensures that our function is overriding something - ensures there is a virtual function on a base class w same prototype
		//when we later change our base class function parameters, any sub-class that was overriding it no longer will be, and by adding "override" specifier, compiler will detect that issue and alert us
		//"override" provides both clarity and a compiler check
		cout << "\nDragon Acting!";
	}
};
//we can add breadth by adding more enemy types, w our types inheriting from Character (types don't always need to inherit from Character directly) and override functions as needed
class rtpFireDragon : public rtpDragon{};
class rtpFrostDragon : public rtpDragon{};
class rtpStormDragon : public rtpDragon{};
//this pattern keeps our project orginized and manageable; source code file might get a lil large but we can split our project across multiple files (keep types in dedicated files: Dragon.cpp or Goblin.cpp)

//represent combat system as simple void function called rtpBattle
void rtpBattle(rtpCharacter* A, rtpCharacter* B) {
	//w introducing flive#dead abillity, no Battle() continue until one of combatants is dead (and since they don't have any HP - forever, for now)
	//while (A->rtpGetIsAlive() && B->rtpGetIsAlive()) {
		//receives two character pointers and has them Act() upon each other
		A->rtpAct(B);
		B->rtpAct(A);
	//}
}
//w everithing in place, now we've achieved run-time polymorphism (w/out changing any code in our Battle() function, its behavior now is - dynamic)
//we can add depth by expanding Character base class and Battle() function whilst keeping the complexity under control (w this basic system in place)

//Inclusion of the "virtual" keyword in class function changes calls to this function from being - statically bound to being - dynamically bound

//by default, C++ binds function calls to the function definitions in our code at compile time ("static binding" or "early binding")
//static binding: compiler sees an expression like A->Act(), investigates type of A, in our Battle(): A - Character, so compiler associates this call to the Act() as defined within Character

//by adding "virtual" specifier, we're asking the compiler to take different approach: compiler determines what specific type of object our pointer is pointing at, then calls version of Act() within that type
//(if that type doesn't define it - we search up the inheritance tree until we find the nearest ancestor that does)
//this needs to be done at a run time, so is reffered to as - dynamic binding or late binding (has small performance impact at a run time, so it's not used by default, we'll have to to explicitly opt it in, w "virtual")
//"virtual" specifier: when function is called - compiler will use the "most derived" version of function

//when our code encouters virtual function, the proccess of traversing inheritance tree to find most derived override effectively treats all intermediate functions as virtual too (whether they marked "virtual" or not)
//in some scenarios, we may need to design our class in such a way that subtypes should not be able to override a function
//in those cases, we can mark the function as - "final"
//class rtpGoblin : public rtpCharacter { public: void rtpAct() final {} };
class rtpGoblinWarrior : public rtpGoblin {
public:
	//void rtpAct(rtpCharacter* Target) override {} //E1850: cannot override 'final' function "..." (declared at line ...)
};
//"final" specifier: prevents further overriding of a function in derived classes

//this form of a run-time polymorphism works only when we're passing our objects by reference or pointer
//any object of a subtype can be copied to an object of a base type:
class slcGoblin : public rtpCharacter {
public:
	int Damage{ 10 };
};
void slcBattle(rtpCharacter Enemy) {
	//Enemy is always a basic Character
}
//within Battle() function Enemy is no longer a Goblin, it is a basic Character
//any subtype specific variables, such as Damage int in this case, are simply discarded, living us w plain old Character
//this scenario is sometimes referred to as - slicing (there are legitimate use cases where we may want to do this, but it's frequently a bug)
//slicing - phenomenon where a derived class object is treated as a base class object, leading to the potential loss of derived class information

// Downcasting
//using dwnc prefix for clarity
class dwncCharacter {
public:
	dwncCharacter(string Name) : mName{ Name } {}
	string dwncGetName() { return mName; }

public:
	//to use dynamic_cast our type MUST be polymorphic (type w at least one "virtual" function)
	//if our type doesn't require any virtual functions, but we still want to use dynamic_cast - by convention we make the destructor virtual (wow)
	virtual ~dwncCharacter() = default;

private:
	string mName;
};
class dwncGoblin : public dwncCharacter {
public:
	dwncGoblin(string Name) : dwncCharacter{ Name } {}
	
	void dwncEnrage() {
		cout << "\nGetting Angry!";
		Damage += 5;
	}

private:
	int Damage{ 10 };
};
//having a Character* pointer we can call Character functions as expected
void dwncAct(dwncCharacter* Enemy) {
	cout << '\n' << Enemy->dwncGetName() << " Acting!";
	//inheritance rule doesn't work in the other direction (not all Characters are Goblins)
	//therefore if we have a variable of type Character* and we try to call function that is defined in the Goblin class - we get a compilation error
	//Enemy->dwncEnrage();

	//simplest form of the downcasting involves using the static_cast approach
	//in our Act() function we can use it to convert our Character* pointer to a Goblin* pointer
	dwncGoblin* dwncGoblinPtr{
		static_cast<dwncGoblin*>(Enemy)
	};
	//we can then Enrage() using our Goblin* pointer
	static_cast<dwncGoblin*>(Enemy)->dwncEnrage();

	//why not just use Goblin* pointer?
	//point of a run time polymorphism is that we want functions like Act() to work across a range of types
	//(if we updated our parameter to be a Goblin* instead, we could call goblin-specified function directly, but we then couldn't call Act() w anything except goblins

	//below our Act() function attempts to cast a Character* to a Goblin*
	//(this is theoretically possible - Character is a base class for Goblin, so Character* pointer "could" be pointing at a Goblin)
	//but in this specific case:
	//int main(){ dwncCharacter Dragon{"Dave"}; dwncAct(&Dragon); }
	//Act() function assumes that Character* always pointing at a Goblin - we have a bug, programm will behave unpredictably, likely crashing
}
//we have a pointer to a Character*, and we want to convert this to a pointer to a Goblin so we can access goblin-specific functionality
// downcasting - scenario, where we are casting a pointer down the inheritance tree to a more specific subtype is called

//downcasting can fail in one of two ways:
// - compile time error (impossible downcasts)
class dwncDragon : public dwncCharacter {};
void dwncAct(dwncGoblin* Enemy) {
	//casting a Goblin to a Dragon would never work (Goblin cannot possibly be a Dragon, as Dragon does not inherit from Goblin)
	//static_cast<dwncDragon*>(Enemy);
	//C2440: 'static_cast': cannot convert from '...*' to '...*'
	//this is one of the advantages of static_cast over C-style casting (C-style would let this error through, resulting in a bug)
	//(dwncDragon*)Enemy;
}
// - run time failure
// second, more common way a downcast will fail is when our convertion is possible in theory, but is simply not valid in this specific case

//for scenarios where an object may be or may not be a specific subtype (like calling Act() w Character* after downcasting a pointer to Goblin*), we need to use - dynamic casting
//often the specific subtypes our functions are dealing w on each invocation will be different, and they will depend on runtime conditions such as user decisions

//limitations af a static_cast: only checks if Character class is a base class of a Goblin (doesn't check whether this "specific" Character is a Goblin)
//static_cast: done at compile time, no performance overhead, and this is great if we KNOW the downcast will work (used Act() only w Goblin), however, in many scenarios, we can't be sure
//for this scenarios dynamic casting is better

//the way we invoke dynamic_cast follows the same pattern as static_cast:
void dwncHandle(dwncCharacter* Object) {
	dwncGoblin* dwncGoblinPtr{
		dynamic_cast<dwncGoblin*>(Object)
	};
	//key difference - dynamic_cast performs an additional run-time check to determine whether the pointer is actually pointing to the thing we're trying to cast it to
	//(this case: whether Object pointer really is pointing at a Goblin)

	//if the pointer was not pointing at the type we specified, dynamic_cast returns a nullptr
	//this allows us to react to cast failures, because null pointers can be detected using an if statements
	if (dwncGoblinPtr) {
		cout << "\nThat was a Goblin";
	}
	else {
		cout << "\nThat was NOT a Goblin";
	}
};

//slightly more complex example (polymorphic combat system)
class cdwncCharacter {
public:
	cdwncCharacter(string Name) : mName{ Name } {}
	void cdwncTakeDamage(int Damage) {
		cout << '\n' << mName << " Taking Damage";
		mHealth -= Damage;
	}

	virtual void cdwncAct(cdwncCharacter* Target) {
		Target->cdwncTakeDamage(50);
	}

protected:
	string mName;
	int mHealth{ 150 };
};
//two Character objects are passed to Battle() as pointers, and they both Act() upon each other
void cdwncBattle(cdwncCharacter* A, cdwncCharacter* B) {
	B->cdwncAct(A);
	A->cdwncAct(B);
}
//let's add more subclasses, below Vampire now has its own dedicated class, and also developed a weakness to wooden stakes (represented by vampire-specific Stake())
class cdwncVampire : public cdwncCharacter {
public:
	cdwncVampire(string Name) : cdwncCharacter{ Name }{}

	void cdwncStake() {
		cout << '\n' << mName << " Getting Staked";
		mHealth -= 0;
	}
};
//our player has become a VampireHunter which, for now, behaves in the same way as Character
class cdwncVampireHunter : public cdwncCharacter {
public:
	cdwncVampireHunter(string Name) : cdwncCharacter{ Name } {}
	
	//we'd like to update our VampireHunter w the ability to Stake() vampire enemies, but we still need to fight non-vampires, too
	//we can override Act() function and use dynamic_cast to determine whether or not we're fighting a Vampire
	void cdwncAct(cdwncCharacter* Target) override {
		cdwncVampire* cdwncVampirePtr{
			dynamic_cast<cdwncVampire*>(Target)
		};
		if (cdwncVampirePtr) {
			cdwncVampirePtr->cdwncStake();
		}
		else {
			cdwncCharacter::cdwncAct(Target);
		}
	}
};
//in this process we didn't need to change our combat system (contrive Battle() and Character class it uses)
//everything we needed was encapsulated away in our vampiric types
//w polymorphism our combat system gets richer and more dynamic (w/out its code needing to get more complex or even change at all)

// Preprocessor Definitions
//when we build our code it's not immediately compiled, it is first sent to - preprocessor (behind-the-scenes tool)
//preprocessor directives - special instructions we insert into our source file
//preprocessor modifies our code (not orig, temporary intermediate copy) based on preprocessor directives
//(modifications sometimes called translations, generated files - translation units
//once finished generating those copies, w all changes,they are send off for compilation

//preprocessor directives abilities:
// - different versions of a software from the sane source code
// - defining reusable code blocks
// - including code others have written, sometimes called library code, to let us build more advanced features quickly
// - keep project orginized by splitting between multiple files

// - setting preprocessor definition (such as DEVELOPMENT_BUILD) depends on our IDE
//in VS: from top menu bar: Project -> "ProjectName" Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions
//two configurations provided by default - "Debug", "Release"
//we can create more configurations as needed, each can have its own set of preprocessor definitions (+ other settings), and we can quickly switch between configurations through user interface

//"#ifdef" and "if" key difference:
//preprocessor directives "#ifdef" analyzed at build time, whilst "if" - at run time
//most things can only be checked at run time, so "if" statements are generally going to be much common and useful
//if something doesn't need to be checked at run time - should consider using preprocessor instead

//conditional inclusion two big benefits over "if":
// - performance: "#ifdef" directive evaluated one time (when we build software), "if" - everytime the function is called, by everyone who runs our soft
// - security: if we include "secret" functionality in the code for users, "if" won't keep it hidden (quite easy to reverse engineer and see those)
//w "#indef" instead - the code is entirely removed from what we release

//if we need to provide a preprocessor definition across our whole project, we typically do it through our build tools, but we don't have to
//we can just define things within our source files
//for example, we can define flag like this
//in files where this directive exists - effect equivalent to having set it through tooling
//#define DEVELOPMENT_BUILD

//thing to note about "#define":
// - things defined w this directive are typically called - "macros" (eg. DEVELOPMENT_BUILD)
// - to distinguish macros from other C++ code, we typically use all uppercase names w "_" as a separator
// - we do not end macros w semi-colons ";" - they're not C++ statements
// - macros typically defined at or near the top files (!macro is available from the line it was defined until the end of the file)

//text substitution macros allow us to "#define" bocks of code, end then easily insert those elsewhere in our project as needed
//(it's fairly uncommon that we need to create text replacement macros, just demonstration)
//#define DEFINE_INT int MyInt{4};
struct MyType {
	DEFINE_INT
	DEFINE_GREET
	DEFINE_ARG_GREET("Howdy", "a struct object")
};
//int main() { DEFINE_INT	//code...	}

//somewhere above we created macro for creating functions, then we use it to add a member function to our MyType strunct, as well as a free function defined above our main()
DEFINE_GREET
DEFINE_ARG_GREET("Hi there", "a free function")

// ! - unreal provides a lot of useful utilities in the form of macros, so you're likely using them quite heavily if you're writing C++ in that contex
//for example, loging into Unreal console is done using two function-like macros, "UE_LOG" and "TEXT"
//UE_LOG(LogTemp, Error, TEXT("Hello!"))


int main() {
	Level = Level + 1;
	Level += 2;
	Level -= 7;
	Level *= 10;
	Level /= 5;
	Level *= Level;

	Health += HealthModifier;
	Health *= -1;
	Health *= -1;
	Health -= HealthModifier;

	MaxHealth = MaxHealth + 19.5;
	MaxHealth++;
	MaxHealth--;
	MaxHealth -= 20;
	MaxHealth *= 2;
	MaxHealth /= 2.5;
	MaxHealth += 100;

	cout << "\nCurrent level is " << Level;
	cout << "\nHP at the moment is " << Health;

	cout << "\n5 / 2 = " << 5 / 2;
	cout << "\n" << 5.0 / 2;
	cout << "\n" << 5 / 2.0;
	cout << "\n" << 5.0 / 2.0;

	cout << "\nMaximum health is " << MaxHealth; cout << "\n";

	Health -= Health;
	if (Health >= 0) {
		cout << "Guess I die...";
	}
	cout << "\n";
	if (IsDead >= false) { // Still needed > sign
		cout << "Revived!";
	}

	Health += 500;
	bool IsReady{ Level == 100 && IsAlive }; // AND operator Has to be in there (main, not wherevere higher par is :/ ) May be more than 2
	cout << "\n";
	if (IsReady >= true) {
		cout << "Show me everything you've got puppet of Geppetto!";
	}
	cout << "\n";

	Health -= Health;
	bool Ending{ Level == 999 || Health == 0 }; // OR operator At least one of requirement met Same as per && can be multiple requirements
	if (Ending == true) {
		cout << "You're just a useless puppet...";
	}
	Health += 500;
	cout << "\n";
	Ending = Level == 999 || Health == 0; // Damn that was smart of me, hd haven't thought that it would actyally work)) (switching {} to = removed contradictions
	if (Ending == true) {
		cout << "You're just a useless puppet...";
	}
	cout << "\n";
	if (Ending == false) { // Which now is
		cout << "Someone got BIG BRAIN right there :*";
	}

	// Types and Literals
	int8_t SmallNumber{ 100 }; // non-fixed version "short"
	int16_t MediumNumber{ 10'000 };
	int32_t LargeNumber{ 1'000'000'000 }; // non-fixed "long"
	int64_t HugeNumber{ 1'000'000'000'000'000'000 };

	int Number{ 2'000'000'000 };
	Number += 1'000'000'000; // OVERFLOW when value to big it wraps around to other side of width range (w - in that case)

	int8_t PositiveNumber{ 100 };
	int8_t NegativeNumber{ -100 };
	uint8_t BiggerNumber{ 200 }; // unsigned integer stores values from 0 to 255
	unsigned int BasicUnsignedInt{ 3'000'000'000 };
	std::cout << '\n';

	cout.precision(16);

	float A{ 1.1111111111111111 };
	std::cout << "Float precision: "
		<< A + A << '\n';

	double B{ 1.1111111111111111 };
	std::cout << "Double precision: "
		<< B + B;

	// Functions
	cout << "\nMain function starting";
	TakeDamage();
	cout << "\nWe are back in main";
	TakeDamage();
	cout << "\nMain function complete";

	// Conditional Logic
	Health += 100;
	if (IsDead) Health = 0;
	if (!IsDead) // PlayIdleAnimation();
		if (Level == 1) // StartTutorial();
			if (Level >= 10 && !IsDead) // StartQuest();

				if (IsDead) {
					Health = 0;
					// DropLoot();
					// PlayDeathAnimation;
					// AwardExpirience;
				}

	if (IsDead) {
		// DropLoot();
	}
	else {
		// Attack();
	}
	IsDead ? DropLoot() : Attack(); // Works, no visuals signs to check

	if (Health <= 0) {
		IsDead = true;
		DropLoot();
	}
	else if (Health <= 50) {
		RunAway();
	}
	else if (Health <= 100) {
		Heal();
	}
	else {
		Attack();
	}

	Health -= 500;
	HasLoot = !HasLoot;
	if (Health <= 0) {
		IsDead = true;
		if (HasLoot) {
			DropLoot();
		}
		if (ShouldAwardExperience) {
			AwardExperience();
		}
	}
	else if (Health <= 50) {
		CanHeal ? CastHealingSpell() : RunAway();
	}
	else if (IsHostile) {
		CanSeePlayer ? Attack() : PatrolArea();
	}
	Health += 500;

	Health <= 0
		? DropLoot()
		: Health <= 50
		? RunAway()
		: Attack(); // Contentious thing, better not nest terneries

	// Switch Statements
	switch (Day) {
	case 1: // Is day == 1?
		cout << "\nMonday"; // break needed to prevent fallthrough which is default to switch statements
		break;
	case 2:
		cout << "\nTuesday";
		break;
	case 3:
		cout << "\nWednesday";
		break;
	case 6:
	case 7:
		cout << "\nWeekend"; // 6 & 7 Fallthrough, often a source of bugs
		break;
	default:
		cout << "\nSomething else"; // Activates in any other scenario unles "break" from one of the "case" activates
	}

	// Function "return" Statements
	int Level = CalculateLevel();
	cout << "\nLevel: " << CalculateLevel();
	cout << "\nHealth: " << CalculateLevel() * 5;
	int DamageInflicted{ TakeDamage1() };
	Score += DamageInflicted;
	Score = TakeDamage1();
	cout << "\nScore: " << Score;

	IsDead = !IsDead;
	HealthReturn = TakeDamage4();
	cout << '\n' << HealthReturn;

	// Implicit Conversions, Narrowing Casts
	IsDead0();
	cout << '\n' << IsDead0(); // converting 0 bool results in false
	if (IsDead0()) {
		cout << " - true";
	}
	else {
		cout << " - false";
	}

	IsDead42();
	cout << '\n' << IsDead42(); // non-0 - true
	if (IsDead42()) {
		cout << " - true";
	}
	else {
		cout << " - false";
	}

	NumberToFalse();
	cout << "\nFalse is " << NumberToFalse();

	GetHealth();
	if (GetHealth()) {
		cout << "\n50 to true ";
	}
	int ConvertHealth{ GetHealth() }; // as a result of multiple convertion returns to integer - 1
	cout << "then to " << ConvertHealth;

	cout << "\n5 + true = " << IntegerPlusBool;

	int Pi = 3.14; // "=" syntax initialize narrowing cast but it can cause data loss and warning output in compilers, another reason to use uniform initialization (by "{ }")
	cout << "\nPi is equal to a float number, but as a result of narrowing cast we get " << Pi;

	GetPiFloat(); // converting a "float" to "int" will fail, a "double" to "int" - fail, "double" to "float" - fail
	double FloatToDouble{ GetPiFloat() }; // any "float" can be converted to "double" without data loss

	// Function Arguments and Parameters
	cout << '\n' << Health;
	TakeDamage20250326(20);
	TakeDamage20250326(50);
	TakeDamage20250326(100);

	cout << "\nCalling AddNumbers(1,2,3) function will result in " << AddNumbers(1, 2, 3);

	MagicalDamage(50, true);

	TakeDamage20250326(25.9f); // incorrect data type of an argument will trigger implicin conversion, 25.9 (float) - 25 (int)
	TakeDamage20250326(true); // true (bool) - 1 (int), (string) - error, () - error, we have to provide something if parameter proclaimed
	Health -= Health;
	Health += 500;
	cout << "\nHealth before IntMagicalDamage(50) - " << Health;
	cout << ", after - " << IntMagicalDamage(50);
	cout << "\nHealth before IntMagicalDamage(50, false) - " << Health;
	cout << ", after - " << IntMagicalDamage(50, false); // results in same output as if using (50) argument
	cout << "\nHealth before IntMagicalDamage(50, true) - " << Health;
	cout << ", after - " << IntMagicalDamage(50, true); // overrides default parameter

	cout << "\nAdd({}, {}, {}) will return: " << Add({}, {}, {}); // DOESN`T WORK (should be 6) because it returns fucking 0 and function takes it as int
	cout << "\nAdd({}, {}, 5) will return: " << Add({}, {}, 5);

	bool IsWizard{ true }; // we can use any expressin in argument if that result in a value of correct type for parameter
	cout << "\nHealth before IntMagicalDamage(25 * 2, IsWizard) - " << Health;
	cout << ", after - " << IntMagicalDamage(25 * 2, IsWizard); // this will be equivalent TakeDamage(50, true)
	cout << "\nHealth before IntMagicalDamage(CalculateDamage(), true) - " << Health; // arguments can alse be determined by calls to other functions
	cout << ", after - " << IntMagicalDamage(CalculateDamage(), true);
	cout << "\nIf we call function int AddNumbers(int x, int y, int z) as AddNumbers(1, 2, AddNumbers(3, 4, 5)); ";
	cout << "\nresult is going to be - " << AddNumbers(1, 2, AddNumbers(3, 4, 5)); // we can compose functions with themselves

	// Scopes
	Log();
	cout << "\nit's definitely " << x; // moving x variable into the bode of function main no longer going to be able to access it and resulting compilation error
	bool ShouldLog{ true };
	if (ShouldLog) { // if represents child scope nested within main's scope (parent scope)
		string Message{ "hello world!" }; // block scopes are inside {} like in functions, also if, else creating block scopes, making Message inaccessible
		cout << '\n' << Message; // this works though
	}
	{ string Message{ "hello world" }; } // uncommon, but creates block scope just like that
	int x{ 1 };
	{
		int x{ 2 }; // this x shadows outer x BETTER AVOID shadowing
		cout << "\nInner x: " << x;
	} // when block ends inner x goes out of scope and outer x becomes accessible
	cout << ", outer x: " << x;
	// Forward Declarations

	// Loops
	int NumberWhile{ 1 }; // variable increases in every iteration (term used to describe code that contains loops)
	cout << '\n';
	while (NumberWhile <= 9) {
		cout << NumberWhile << ", ";
		++NumberWhile;
	}
	cout << NumberWhile << ".\n";
	while (false) { // if condition provided is false from the beginning - code inside the block will not be executed even once
		cout << "\nCan't see me!";
	}
	int i{ 0 };
	while (i <= 5) {
		++i;
	}
	cout << "\ni ends at " << i;
		 // aplication loops runs untill someone explicitly tells it to stop, if application is a game, game loop

	int NumberDoWhile{ 1 };
	cout << '\n';
	do {
		cout << NumberDoWhile << ", ";
		++NumberDoWhile; // NEVER forget to update variable value, or u just end up with infinite loop D:
	} while (NumberDoWhile <= 9);
	cout << NumberDoWhile << ".\n";
	do {
		cout << "Hello World" << endl; // do while will always be executed at least once even if the boolean is initially false
	} while (false);

	int NumberFor{ 1 };
	for (int y{ 1 }; y <= 9; ++y) { // int NumberFor{ 1 } - initialize, statement will be executed a single time, before start of the loop
		++NumberFor;
		cout << y << ", "; // NumberFor <=10 - condition, boolean expression that indicates if loop should continue
	} // ++NumberFor - update, this code is executed at the end of each loop iteration, this component separeted by semicolon ;
	cout << NumberFor << ".\n";

	int NumberOptional{ 1 };
	for ( ; NumberOptional < 10; ) { // we can omit components, but it makes rather messy code, should just use while loop in that scenario
		cout << NumberOptional << ", ";
		++NumberOptional;
	}
	cout << NumberOptional << ".\n";

	int NumberInfinite{ 1 };
	for ( ; ; ) { // removing a conditional check from for loop not going to prevent compiling, but will create infinite loop
		cout << NumberInfinite << ", ";
		++NumberInfinite;
		break; // i just added break there, so i can leave code as an example
	}
	while (true) {
		int Number{ 1 }; // variable created inside a loop can't be accessible outside of it
		// and every iteration of a loup creates a new block of scope, so previous variable are no longer accessible once that iteration completes
		break;
	}
	
	int NumberNest{ 1 }; // within the block of a loop we can create variables, call functions, use conditional logic etc. 
	while (NumberNest <= 9) { // nesting conditionals
		if (NumberNest == 5) {
			cout << "Five" << ", "; // for treating one number differently we can add if statement inside a loop
		}
		else {
			cout << NumberNest << ", ";
		}
		++NumberNest;
	}
	cout << NumberNest << ".\n";
	int NumberContinue{ 0 }; // continue - loop will skip over the remaining code for this iteration, and continue onvards to the next iteration
	while (NumberContinue < 10) { // if the condition that controls the loop is no longer true - loop will instead end
		++NumberContinue;
		if (NumberContinue == 5) continue; // most typically used in a conditional block (if) within our loop (for skipping number 5 in that case)
		else if (NumberContinue == 10) { 
			cout << NumberContinue << ".\n";
			break; // BREAK - most useful within a conditional in our loop, to EXIT LOOP entirely and to STOP ITERATING
		}
		cout << NumberContinue << ", ";
	}
	int RemainingIterations{ 100 };
	while (true) { // break - to limit a loop to 100 iterations, regardless of whether the condition is true
		--RemainingIterations;
		if (RemainingIterations <= 0) break;
	}

	for (int Row{ 1 }; Row <= 4; ++Row) { // nested loops: outer loop iterates 4 times, each causing 4 iterations of the inner loop
		for (int Col{ 1 }; Col <= 4; ++Col) { // so the code within the inner loop invoked 16 times in total
			cout << "Row " << Row << ", "
				<< "Col " << Col << " | ";
		}
		cout << '\n';
	}

	LoopReturn();

	// Modulus operator
	IsEven(9);
	IsEven(12);
	IsDivisibleBy(6, {});
	IsDivisibleBy(16, {});
	IsDivisibleBy(9, {});

	cout << '\n' << 0 % 3 << ", " << 1 % 3 << ", " << 2 % 3; // cycle of modulus operator, length is determined by the right operand (3 - got a repeating pattern of 3 numbers)
	cout << '\n' << 3 % 3 << ", " << 4 % 3 << ", " << 5 % 3; // modulus arithmetics has a tendency to "wrap around" after reaching certain value, can be useful when paired with loops
	cout << '\n' << 6 % 3 << ", " << 7 % 3 << ", " << 8 % 3 << '\n';
	
	for (int i = 1; i <= 9; ++i) { // while incrementing i on every 3rd iteration of a loop modulus i % 3 will be 0
		cout << i << " ";
		if (i % 3 == 0) cout << '\n'; // this can be used to insert a line break on every  third iteration
	}

	// Abstractions and Classes
	Monster Bonker; // class grants the ability to create new objects of that class
	Monster Basher; // creating an object from a class is sometimes referred to as instantiating the class, objects created - instances
		// above - instantiate the Monster class to create Bonker and Basher - instances of the Monster class
	Basher.Health; // (.) member access operator - gives access to variables/functions from class
	cout << "Bonker Health: " << Bonker.Health << '\n'; 
	Bonker.TakeDamage(25);
	cout << "Bonker Health: " << Bonker.Health << '\n';
	Bonker.Health += 125; // Bonker.Health - int, so we can use it as any other int (pass it as an argument, copy value to new variable, -
	cout << "Bonker Health: " << Bonker.Health << '\n'; // - use ++ to increment, use != to compare it to another number, generating a bool result)
	Basher.Health = 200; // each object will have its own copy of that variable, so we specifying what the initial value of that variable will be for every new created object
	cout << "Basher Health: " << Basher.Health << '\n';
	
	// Encapsulation and Access Specifiers
	Monster Goblins;
	Goblins.Health -= 200; // our rule guaranteed if consumers only ever use a function, but they can bypassed our rule by setting Health directly
	cout << "Goblin Health: " << Goblins.Health << " :(" << '\n';
	Enemy Hobgoblin;
	Hobgoblin.TakeDamage(200);
	cout << "Hobgoblin Health: " << Hobgoblin.GetHealth() << '\n';

	Hobgoblin.SetHealth(150);
	cout << "Hobgoblin Health: " << Hobgoblin.GetHealth() << '\n';
	Hobgoblin.SetHealth(-50);
	cout << "Hobgoblin Health: " << Hobgoblin.GetHealth() << '\n';

	// Constructors and Destructors
	DefaultFoe Kobold;
	Foe Carcass{ "Cadaver", 150 }; // arguments also have to be comma-separate (,)
	cout << '\n';
	Foe Wolf{ "Wolf", 200 };
	cout << '\n';
	Foe Dog{ "Dog" };
	cout << '\n';
	cout << "Hello World!\n";
	SomeFunction();
	cout << "Goodbye!\n";

	// Structs and Aggregate Initialization
	// in typical scenario you would need to define a constructor to initialize this values
	Vector3 Position{ 1.9, 2.6, 0.3 }; // aggrigate initialization - alows to directly assign values to (x, y, z) when creating an instance (an option only when types are simple)
	
	// Operator Overloading
	Vector3 CurrentPosition{ 4.0, 5.0, 6.0 };
	Vector3 Movement{ 1.0, 2.0, 3.0 };
	Vector3 NewPosition{
		CurrentPosition + Movement // now we have it simple, convenient
	};
	std::cout // used for multiple lines?
		<< "x = " << NewPosition.x
		<< ", y = " << NewPosition.y
		<< ", z = " << NewPosition.z;
	Vector3 MultiPosition{
		NewPosition * 2
	};
	std::cout
		<< "\nx = " << MultiPosition.x
		<< ", y = " << MultiPosition.y
		<< ", z = " << MultiPosition.z;
	Vector3 otherMultiPosition{
		2 * NewPosition
	};
	std::cout
		<< "\nx = " << otherMultiPosition.x
		<< ", y = " << otherMultiPosition.y
		<< ", z = " << otherMultiPosition.z
		<< '\n';

	// Structured Binding
	Vector3 SomeVector{ 1.0, 2.0, 3.0 };
	float vecA{ SomeVector.x }; // often we'll want to exctract all members of a vector to standalone variables for further operations
	float vecB{ SomeVector.y }; 
	float vecC{ SomeVector.z };
	// C++ offers convinient shortcut to this - structured binding (allows to directly unpack public members of class/struct into the variables), syntax to use it looks like this:
	Vector3 BindingVector1{ 1.0, 2.0, 3.0 };
	// syntax: "auto [name we want to use for each variable]{object we want to use to initialize these variables}"
	auto [a, b, c]{BindingVector1}; // auto - automatically determine what type each of new variables will have (auto MUST be used)
	cout << "a = " << a
		<< ", b = " << b
		<< ", c = " << c;
	Vector3 BindingVector2{ 1.0, 2.0, 3.0 };
	Vector3 BindingVector3{ 1.0, 2.0, 3.0 };
	// any initialization syntax will work
	auto [d, e, f](BindingVector2); // created variables are mapped to the variables within the source object by position (code sets values to 1st, 2nd, 3rd members of {SourceObject} respectively)
	auto [g, h, j] = BindingVector3; // doesn't matter how they called within the struct or class definition - structure binding will have the same effect
	StructBindTest myCharacter{ "Puppet", 200, 150 };
	auto [myName, myHP, myStamina] {myCharacter}; // structure binding mostly used for simple data types, such as Vector3 struct
	cout << "\nCharacter name is: " << myName
		<< ", current stats: " << '\n'
		<< "HP: " << myHP << "\nStamina: " << myStamina;
	// limitations of structure binding: need to unpack every variable from an object, even if needed few; can't access all of types, some might be privat data members
	// those cases require traditional approach: accessing variables 1-by-1 or providing member function to support desired access pattern

	// Inheritance
	Goblin Smasher; // now when creating an object from Goblin class, that object will be both: Goblin and Actor
	Smasher.Attack(); // available because Smasher is Goblin
	Smasher.Render(); // available because Smasher is also an Actor
	Actor Rock; // child objects also parent objects, but parent objects may be not child objects
	Rock.Render(); // for example, Rock can't attack, becuse they're not a Goblin, obviosly, xd (parent class objects can't use child's class member functions)
	Dragon Dave;
	Dave.Render(); // now Dave can perform functions of all his parent classes
	Dave.Attack();
	Dave.Fly();

	// Protected Class Members
	Healer Player;
	cout << "\nHealth: " << Player.GetHealth();
	Player.Heal(25);
	cout << "\nHealth: " << Player.GetHealth();

	// Member Initializer list

	//Working with inherited Members !!!!
	cout << "\nInitializing (two int) Shapeshifter: ";
	Shapeshifter Dawg{ 1,2 }; //use Monsters (base-class) constructor
	cout << "\nInitializing (three int) Shapeshifter: ";
	Shapeshifter Woof{ 1,2,3 }; //use Shapeshifter (sub-class) constructor
	cout << "\nInitializing (default) Shapeshifter: ";
	Shapeshifter Catto;
	cout << "\nCatto Health: " << Catto.GetHealth();
	cout << "\nInitializing (Health argument) Shapeshifter: ";
	Shapeshifter Foks{ 200 };
	cout << "\nFoks Health: " << Foks.GetHealth();
	cout << "\nInitializing (Health, Damage argument) Shapeshifter: ";
	Shapeshifter Hofk{ 175, 15 };
	cout << "\nHofk Health: " << Hofk.GetHealth()
		<< "\nHofk Damage: " << Hofk.GetDamage();
	cout << "\ninitializing (updated Health) Shapeshuffler: ";
	Shapeshuffler Beir;
	cout << "\nBeir Health: " << Beir.GetHealth();
	Beir.Attack();
	cout << "\nBeir performing an attack inflicting: " << Beir.PerformAttack() << " damage";
	cout << "\nBeir performing an extended attack: "; 
	Beir.ExtendedAttack();

	// References
	Characters Hero;
	Characters Enemy;
	cout << "\nHero HP: " << Hero.Health; // 200
	cout << "\nEnemy HP: " << Enemy.Health; // 200
	Combat(Hero, Enemy);
	cout << "\nHero HP: " << Hero.Health; // 200
	cout << "\nEnemy HP: " << Enemy.Health; // 200

	cout << "\nNumber: " << ReferenceNumber; // 1
	Increment(ReferenceNumber);
	cout << "\nNumber: " << ReferenceNumber; // 2

	ReferenceCombat(Hero, Enemy);
	cout << "\nHero HP: " << Hero.Health; // 200
	cout << "\nEnemy HP: " << Enemy.Health; // 200

	bool wasFatal;
	int fatalDamage{ fatalAttack(wasFatal) };
	cout << "\nInflicted " << fatalDamage << " Damage";
	if (wasFatal) { cout << " (Fatal)"; }

	auto [DamageResult, wasFatalResult]{AttackResult()};
	cout << "\nInflicted " << DamageResult << " Damage";
	if (wasFatalResult) { cout << " (Fatal)"; }

	Characters PlayerConstant;
	SomeFunction(PlayerConstant);
	//we can use references at any time, below we simply create a reference like any other variable
	int refNumber{ 5 };
	int& Ref{ refNumber }; //our identifier "Ref" bound to "refNumber" variable - modifications to "Ref" affect "refNumber"
	Ref++;
	cout << "\nValue: " << refNumber;
	//references implement two restrictions that eliminate a large source of defects related to memory addresses (common source of bugs, references closely relate to idea of memory adresses)
	//references: must be Initialized
	int myRefNumber{ 5 };
	int& myRef{ myRefNumber }; //initialize it to point to the desired memory address - usually by assigning it to a variable ("int& myRef;" - results in a compilation error)
	//references: cannot be Reassigned
	//can't be updated to point to a different memory address (once reference created - always point to memory address it was initialized w)
	Weapon ClericWeapon{ "Mace" };
	ArmedCharacter Cleric{ ClericWeapon };
	cout << "\nCleric has a weapon: " << Cleric.GetWeapon().Name;
	//references within an object work the same way as they do anywhere else
	ClericWeapon.Name = "Blessed Mace"; //modified ClericWeapon and since ArmedCharacter holding that object by reference - changes will be reflected in Cleric.GetWeapon() return value
	cout << "\nCleric infused weapon to: " << Cleric.GetWeapon().Name;
	//if function returning reference then when function ends - refCharacter is Automatically deleted, breaking the reference
	//cout << "\nName: " << refGetPlayer().Name; // - our programm will likely output some gibberish and then crash (returns something other than 0)

	// Pointers
	int variableX{ 1 };
	// to log out the location of variableX in memory
	cout << '\n' << &variableX; //"&" operator allows to get the address of where a variable is stored in memory (reffered: "address-of operator")
	
	int& RefTovariableX{ variableX }; //when "&" used next to data type (like "int&" ) - means that we want to work w a REFERENCE to that data type
	&variableX; //when "&" used w a value (such as the name of a variable) that has an identifiable memory location - it's going to operate on that variable (will get its memory address)

	//pointer - is what's returned from address-of operator ("&"), it's a value lika any other, can be store in variables, as members of class, handed off to functions, etc.
	//pointer type includes: underlying type (type of data being pointed at) and a "*" suffix; pointer to an int - int*, bool - bool*, Character - Character*
	int* MyPointer{ &variableX }; //if we use "&" on a variable containing "int" - we'll get an "int*" - a pointer to an "int"
	
	int pointerToX{ 41 };
	HandlePointer(&pointerToX);
	HandleThatPointer(&pointerToX); //returns string message from function and dereferenced int* as a simple int
	
	//precedence for pointers
	//*MyPointer++; //should not compile, or if does, with "C6269: possibly incorrect order of operations" (incrementing operator ++ - higher precedence than dereferencing operator *)
	//*(MyPointer++); //this equivalent to the above
	(*MyPointer)++; //brackets will do the trick to ensure that dereferencing happens first (dereferencing operator has fairly low precedence in general)
	
	//silly code to get precedence order of all operators:
	GetPrecedence(&Precedence); //it's soo dumb, but me likey!

	int referNumber{ 23 };
	referIncrement(referNumber);
	int pointNumber{ 23 };
	pointIncrement(&pointNumber);

	//we use "." w objects
	someMonster someObject;
	someObject.someTakeDamage(50);
	//we use "." w references
	someMonster& someReference{ someObject };
	someReference.someTakeDamage(50);
	//we use "->" w pointers
	someMonster* somePointer{ &someObject }; //nice, membered how to implement all that complicated syntax
	somePointer->someTakeDamage(50);

	//we should never try to dereference a nullptr using the "*" or "->" operators
	//if we need to dereference a pointer, and we think it may be "nullptr" - we can first check for that condition using an if statement
	someWeapon Sword;
	if (!someObject.mWeapon) {
		cout << "\nI am unarmed";
	}
	//so we know that it is a nullptr
	someObject.mWeapon = &Sword;
	if (someObject.mWeapon) {
		cout << "\nNot anymore! Behold the power of my " << someObject.mWeapon->mName;
	}

	//more complex example with implemented "nullptr"
	someMonster somePlayer{ "Romeo" };
	somePlayer.LogsomeEnemy();
	
	someMonster someEnemy{ "Giant Axe Carcass" };
	somePlayer.SetsomeEnemy(&someEnemy);
	somePlayer.LogsomeEnemy();

	someMonster someotherEnemy{ "Stump Carcass" };
	somePlayer.SetsomeEnemy(&someotherEnemy);
	somePlayer.LogsomeEnemy();

	// The "this" Pointer
	someType someThing;
	cout << '\n' << &someThing << '\n';
	someThing.someFunction();

	thisCharacter thisPlayer{ "Player One" };
	thisCharacter thisMonster{ "Puppet" };
	thisPlayer.Attack(thisMonster); //that's kinda cute )

	thisCharacter thisEnemy;
	thisEnemy
		.SetName("Black Cat")
		.SetLevel(60)
		.Log();

	thisVector3 thisVector{ 1.0, 2.0, 3.0 };
	(++thisVector) *= 4; //don't know why we might need that but there it is
	cout << "\nx = " << thisVector.x // 8
		<< ", y = " << thisVector.y // 12
		<< ", z = " << thisVector.z; // 16

	//turns out that ++Number and Number++ are two different operators, the shock...
	// Number++ - POSTFIX increment operator
	// ++Number - PREFIX increment operator
	//difference is: value that is returned from each operator
	// - postfix - will return value BEFORE it is incremented
	int postfixX{ 4 };
	cout << "\nx++: " << postfixX++
		<< " (x is now " << postfixX << ")\n";
	// - prefix - will return value AFTER it is incremented
	int prefixY{ 4 };
	cout << "++y: " << ++prefixY
		<< " (y is now " << prefixY << ")";

	// Dangling Pointers and References
	//compiler should give us warning that we might have been doing something wrong on our "return" statement:
	//"Address of stack memory associated with local variable Number returned"
	int* WrongResult{ GetPointerNumber() };
	cout << "\nResult: " << *WrongResult;
	//but I can't even tell what's wrong with this one exactly...
	//within our call to "GetpointerNumber()" we are allocated the memory to store int we created;
	//then we returned that address to our main() function;
	//however, stack frames - automated form of memory management - when function ends - its stack frame, all the objects stored within - are destroyed

	
	int PointerResult{ *GetPointerNumber() }; //okay, fixed it, don't now how and it's still red in debug but returns correct number somehow
	cout << "\nResult: " << PointerResult;
	cout << "\nPointerResult address: " << &PointerResult;
	cout << "\nWrongResult address: " << &WrongResult;

	SomeType* SomeResult{ GetSomeObject() };
	cout << "\nResult: " << SomeResult->Value;

	// Function Overloading
	Circle MyCircle{ 2 };
	cout << "\nCircle Area: "
		<< CalculateArea(MyCircle);
	//from the perspective of the consumer it looks like they're calling a sinle polymorphic function (rather then 2 different ones)
	Rectangle MyRectangle{ 3, 4 };
	cout << "\nRectangle Area: "
		<< CalculateArea(MyRectangle);
	
	OverloadCharacter OverloadPlayer;
	OverloadWeapon WoodenSword;
	OverloadPlayer.Equip(&WoodenSword);
	OverloadShield WoodenShield;
	OverloadPlayer.Equip(&WoodenShield);

	//Func(1.5); //for now we can explicit it manually
	Func(1); //call Func(int)
	Func(1.5f); //call Func(float)

	//Static Casting
	//to convert an int 5 to float: "static_cast<SomeType>(SomeExpression)"
	static_cast<int>(20.0f);
	static_cast<int>(20.0);
	static_cast<int>(20.0 / 4);
	float SomeFloat{ 15.f };
	cout << "\nstatic_cast: "
		<< "\nSomeFloat = " << static_cast<int>(SomeFloat);
	bool SomeBoolean{ true };
	cout << "\nSomeBoolean = " << static_cast<int>(SomeBoolean ? 16 : 4.0);
	//double CastingFunction() { return 1.0; }
	cout << "\nCastingFunction = " << static_cast<int>(CastingFunction());

	//static_cast<int> returns an int and can be used anywhere that an integer is valid
	//saving the result to a variable:
	int MyInt1{ static_cast<int>(20.f) };
	int MyInt2{ static_cast<int>(25.0) / 5 };

	//int AddMyInt(int x, int y) { return x + y; }
	//passing the result to a function:
	cout << "\nAddMyInt function: "
		<< AddMyInt(
		static_cast<int>(1.f),
		static_cast<int>(2.0)
	);

	//static_cast can be used on any data type, including user-defined types (can also be used when working w pointers)
	//static_cast<Vector3>(142);
	//static_cast<Actor>(5);

	//C-style casting - has a slightly simpler syntax, but we should avoid using it for reasons
	(int)5.0;
	int SomeVariable{ 4 };
	(bool)SomeVariable;
	//(Character)SomeFunction();
	//c++ has multiple "named casts" (static_cast, dynamic_cast, reinterpret_cast) and each of them are covering a specific use case, they perform additional checks to ensure what we're doing makes sense for that use case
	//while c-style casting were inherited from c lang had only one form and doesn't perform any checks
	//cout << '\n' << (int)"Hi"; //as a results using c-style casting we may have unpredictable results after compilation (while c++ casting would've thrown an error and would not compile)

	// Virtual Functions and Overrides
	rtpGoblin rtpA;
	rtpDragon rtpB;
	rtpBattle(&rtpA, &rtpB); //A and B enter Battle() and both using Act() defined in basic class

	slcGoblin slcBonker;
	slcBattle(slcBonker);

	//Downcasting

	dwncGoblin dwncBonker{"Bonker"};
	//an object of a specific type has also the type of every ancestor class, here Bonker is Goblin and a Character as well, and can be passed to the Act() in the form of a Character*
	//we're then able to call the inherited GetName() function
	//dwncAct(&dwncBonker);
	//dwncCharacter Dragon{ "Dave" };
	//dwncAct(&Dragon); //execute code with that error was scary, haha

	//to check for nullptr within dynamic_cast in action, we first pass Handle() a Goblin, and then a basic Character
	dwncGoblin dwncEnemy{ "Enemy" };
	dwncHandle(&dwncEnemy); // That was a Goblin
	dwncCharacter dwncPlayer{ "Player" };
	dwncHandle(&dwncPlayer); // That was NOT a Goblin

	//slightly more complex example (polymorphic combat system)
	cout << '\n';
	cdwncCharacter cdwncPlayer{ "Player" };
	cdwncCharacter cdwncEnemyGoblin{ "Goblin" };
	cdwncBattle(&cdwncPlayer, &cdwncEnemyGoblin);
	cout << '\n';
	cdwncCharacter cdwncEnemyVampire{ "Vampire" };
	cdwncBattle(&cdwncPlayer, &cdwncEnemyVampire);
	cout << '\n';
	cdwncVampireHunter cdwncHunterPlayer{ "Vampire Hunter" };
	cdwncVampire cdwncOtherVampire{ "other Vampire" };
	cdwncBattle(&cdwncHunterPlayer, &cdwncOtherVampire);
	cout << '\n';

	// Preprocessor Definitions

	// - conditional inclusion (determine what code is included in the software we built, dev/user versions)
	//achieved through wrapping the code we want to conditionaly include between "#ifdef" and "#endif" directives:
	cout << "\nHello There!";
#ifdef DEVELOPMENT_BUILD
	cout << "\nThis is a developer build";
#endif
	//the opposite of "#ifdef" is "#ifndef" - will incude code if flag is NOT defined
#ifndef DEVELOPMENT_BUILD
	cout << "\nThis is a public build";
	//we can also use "#elif" and "#else"
#elif DEMO_BUILD
	cout << "\nThis is a demo build";
#else
	cout << "\nThis is an else public build";
#endif

	DEFINE_INT
		cout << "\nMyInt: " << MyInt;
	
	MyType MyObject;
	cout << "\nMyObject.MyInt: " << MyObject.MyInt;

	Greet();
	MyObject.Greet();

	argGreet();
	MyObject.argGreet();


	return 0; // Function w proclaimed return type should ALWAYS return somithing if else - code is invalid
}