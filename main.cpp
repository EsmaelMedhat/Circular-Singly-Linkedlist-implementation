#include <iostream>
using namespace std;
template <class type>
class Node {
private:
  type data;
  Node* next;
public:
  Node() : next(NULL) {}

  void set_data(type data) {
    this->data = data;
  }

  void set_next(Node* next) {
    this->next = next;
  }

  Node* get_next() {
    return next;
  }

  type get_data() {
    return data;
  }
};
template <class type>
class CircularSinglyLinkedlist {
private:
  Node<type>* tail;
public:
int count=0;
  CircularSinglyLinkedlist() : tail(NULL) {}
  bool is_empty() // o(1)
  {
    return tail == NULL;
  }
  void insert_first(type val) // o(1)
   {
    Node<type>* newnode = new Node<type>;
    newnode->set_data(val);
    if (!is_empty()) {
      newnode->set_next(tail->get_next());
      tail->set_next(newnode);
    } else {
      tail = newnode;
      newnode->set_next(newnode); // Handle single element case (circular)
    }
  count++;
  }
  void insert_end(type val) // o(1)
   {
    if (is_empty()) {
      insert_first(val);
    } else {
      Node<type>* newnode = new Node<type>;
      newnode->set_data(val);
      newnode->set_next(tail->get_next());
      tail->set_next(newnode);
      tail = newnode;
    }
  count++;
  }
 void delete_first() // o(1)
 {
 Node<type>*temp=tail->get_next();
 tail->set_next(temp->get_next());
delete temp;
count--;
 }
void delete_end() // o(N)
{
Node<type>* temp = tail->get_next();
Node<type>* prev;
while(temp->get_data()!=tail->get_data())
{prev=temp;
temp=temp->get_next();
}
prev->set_next(tail->get_next());
tail=prev;
delete temp;
count--;
}
void insert_after(type item,type newitem) // o(N)
{
Node<type>*temp=tail->get_next();
do
{
if(temp->get_data()==item)
 {
Node<type>*newelement=new Node<type>;
newelement->set_data(newitem);
newelement->set_next(temp->get_next());
temp->set_next(newelement);
count++;
break;
}
else{
temp=temp->get_next();
}
}while(temp!=tail->get_next());
}
void insert_before(type item,type newitem) // o(N)
{
 Node<type>* current = tail->get_next();
 Node<type>* previous = nullptr;
do
{
if(current->get_data()==item)
 {
previous->set_data(newitem);
previous->set_next(current);
 count++;
 break;
 }
previous=current;
current=current->get_next();
}while(current->get_next()!=tail->get_next());
}
void delete_before(type item ) // o(N)
{
  Node<type>*temp=tail->get_next();
  Node<type>*current=temp->get_next();
  current=current->get_next();
  Node<type>*cur;
do{
 if(item==current->get_data())
 {cur=temp->get_next();
  temp->set_next(current);
  delete cur;
 count--;
 break;
 }
current=current->get_next();
temp=temp->get_next();
}while(temp!=tail->get_next());
}
void delete_after(type item) // o(N)
{
  Node<type>*temp=tail->get_next();
  Node<type>*current=temp->get_next();
  current=current->get_next();
  Node<type>*cur;
do{
 if(item==temp->get_data())
 {cur=temp->get_next();
   temp->set_next(current);
 delete cur;
 count--;
 break;
 }
current=current->get_next();
temp=temp->get_next();
}while(temp!=tail->get_next());
}
  void display() // o(N)
  {
  int n=1;
    cout << "*******  all elements ********\n\n";
    if (is_empty()) {
      cout << "List is empty\n";
      return;
    }

    Node<type>* temp = tail->get_next();
    do {
      cout<<"item "<<n<<":"<<temp->get_data()<<endl;
 n++;
      temp = temp->get_next();
    } while (temp != tail->get_next());
  }
bool isfind(type item) // o(N)
{
Node<type>*temp=tail->get_next();
do{
if(item==temp->get_data())
return true;

temp=temp->get_next();
}while(temp!=tail->get_next());
return false;
}
void replace(type old_item,type new_item) // o(N)
{
Node<type>*temp=tail->get_next();
bool exist=false;
do{
if(old_item==temp->get_data())
{
 exist=true;
 temp->set_data(new_item);
break;
}
temp=temp->get_next();
}while(temp!=tail->get_next());
if(exist==false)
cout<<"NOT found";}
void displaybyrecursion() // o(N)
{
static Node<type>*temp=tail->get_next();
static int n=1;
if (is_empty()) {
      cout << "List is empty\n";
      return;
 }
if(n==1){
cout<<"item "<<n<<":"<<temp->get_data()<<endl;
temp=temp->get_next();}
if(temp==tail->get_next())
return ;
else{
n++;
 cout<<"item "<<n<<":"<<temp->get_data()<<endl;
  temp=temp->get_next();
displaybyrecursion();
}
}
int size() //o(1)
{
return count;
}
};
int main() {
  CircularSinglyLinkedlist<int> numbers;
  for (int i = 0; i < 10; i++) {
    numbers.insert_first(i);
  }
  numbers.insert_end(100);
numbers.replace(1,10001);
numbers.display();

cout<<"\n size :"<<numbers.size();

 return 0;
}

