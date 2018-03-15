# learn-cplusplus

- SmartPointer - To demonstrate the ideal behind smart pointer to manage dynamically allocate memory.
  - move semantics (move constructor and move operator)
  - code doesn't compile for disabling copy constructor and assignment

- Inheritance
  - based class and derived classes
  - Polymorphism
  - using std::shared_ptr and std::make_shared

- LinkedList (single linked)
  - using struct and raw pointer
  - traversal and print the list
  - delete a given node from the list
  - reverse the list

- Constructor
  - to demonstrate the order of the constructors within a inheritance tree being called
    - first it calls its parent class constructor (top-down)
    - then initialise its own member variables
    - finally call its own constructor


To-do:

- Write sample code to using std::unique_ptr and std::share_ptr
