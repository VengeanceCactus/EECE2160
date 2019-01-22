#include <iostream>

struct Person {
  std::string name;
  int age;
};

void PrintPerson(struct Person *p) {
  std::cout << p->name << " is " << p->age << " years old.\n";
}

struct Node {
  struct Person *data;
  Node *next;
};

struct Node *head, *tail;

struct List {
   void  list()
    {
        head = NULL;
        tail = NULL;
    }

};

/**
 * Append a person to the end of the list.
 */
void ListAppend(struct List *list, struct Person *person) {
  Node *temp = new Node;
  temp -> data = person;
  temp -> next = NULL;
  if(head == NULL)
  {
      head = temp;
     // tail = temp;
      temp = NULL;
  }
  else
  {
      tail->next=temp;
      tail=temp;
  }
}

/**
 * Insert a new person at an index.
 */
void ListInsert(struct List *list, int index, struct Person *person) {
  Node *pre = new Node;
  Node *cur = new Node;
  Node *temp = new Node;
  cur = head;
  for (int i = 0; i < index; i++){
    pre = cur;
    cur = cur -> next;
  }
  temp -> data = person;
  pre -> next = temp;
  temp -> next = cur;
}

/**
 * Return the person at a certain index.
 */
struct Person *ListGet(struct List *list, int index) {
  Node *temp = head;
  Person *curPerson = temp -> data;
  std::string curName = curPerson -> name;
  int age = curPerson -> age;
  int i = 0;
  while (temp != NULL){
  if (i != index){
        temp = temp -> next;
        i++;
  }
  else{
      std::cout<<temp -> data ->name<<"\n";
      std::cout<<temp -> data ->age<<"\n\n";
      temp = temp -> next;
      i++;
}

  }
}

/**
 * Remove a certain person from the list by the index. The removed person is
 * returned.
 */
struct Person *ListRemove(struct List *list, int index) {
  Node *cur = new Node;
  Node *pre = new Node;
  cur = head;
  for (int i = 0; i < index; i++){
    pre = cur;
    cur = cur -> next;
  }
  pre -> next = cur -> next;
}

/**
 * Print all the people in the list
 */
void ListPrint(struct List *list) {
  Node *temp = head;
  Person *curPerson = temp -> data;
  std::string curName = curPerson -> name;
  int age = curPerson -> age;
  int i=0;
  while(temp != NULL)
  {
      std::cout<<"["<<i<<"] "<<temp -> data ->name<<" is "<<temp -> data ->age<<" years old.\n";
      temp = temp -> next;
      i++;
  }
  std::cout<<"\n";
}

/**
 * The global variable list
 */
struct List list;

/**
 * Initialize set the init value for the global variable list
 */
void Initialize() {
  /*
   * Implement the Initialize function here
   */
}

/**
 * Finalize frees all the memory that is not freed in the list
 */
void Finalize() {
  /*
   * Implement the Finalize function here
   */
}

int main() {
  // Since the main function is very similar to the main function of lab2, the
  // main function is implemented for you. Please do not modify the main
  // function.

  int input;

  Initialize();

  while (1) {
    std::cerr << "Main menu:\n\n"
                 "\t1. Append a person\n"
                 "\t2. Find a person\n"
                 "\t3. Remove a person\n"
                 "\t4. Insert a person\n"
                 "\t5. Print the list\n"
                 "\t6. Exit\n";
    std::cin >> input;

    switch (input) {
      case 1: {
        struct Person *p = new Person();
        std::cerr << "Enter the name: ";
        std::cin >> p->name;
        std::cerr << "Enter the age: ";
        std::cin >> p->age;
        ListAppend(&list, p);
        break;
      }
      case 2: {
        int index;
        struct Person *p;
        std::cerr << "Enter the index of the person: ";
        std::cin >> index;
        p = ListGet(&list, index);
        break;
      }
      case 3: {
        int index;
        struct Person *p;
        std::cerr << "Enter the index of the person to remove: ";
        std::cin >> index;
        p = ListRemove(&list, index);
        break;
      }
      case 4: {
        int index;
        struct Person *p = new Person();
        std::cerr << "Enter the index to insert to: ";
        std::cin >> index;
        std::cerr << "Enter the name: ";
        std::cin >> p->name;
        std::cerr << "Enter the age: ";
        std::cin >> p->age;
        ListInsert(&list, index, p);
        break;
      }
      case 5:
        ListPrint(&list);
        break;
      case 6:
        Finalize();
        return 0;
      default:
        std::cerr << "Unknown input.\n";
        break;
    }
  }

  Finalize();
  return 0;
}
