#include <iostream>
#include <algorithm>
template <typename t>
struct Node{
	Node<t>* m_next;
	t m_data;
	Node(){
	m_next = nullptr;
	}
	Node(t data1):m_data(data1),m_next(nullptr){}
};

template<typename t>
class Stack{
	Node<t>* m_top;
	size_t m_size1;
public:
	Stack();
	void Push(const t&);
	void Pop();
	bool Empty();
	size_t Size();
	t& Top();
	~Stack();
};

template<typename t>
Stack<t>::Stack(){
	m_top = nullptr;
	m_size1 = 0;
}

template<typename t>
void Stack<t>::Push(const t& value){
	Node<t> *ptr = new Node<t>(value);
	if(m_top == nullptr){
		m_top=ptr;
	}
	else {
		ptr->m_next=m_top;
		m_top=ptr;
	}
		m_size1++;
}
template<typename t>
bool Stack<t>::Empty(){
	return m_size1 == 0 ? true : false;
}
template<typename t>
size_t Stack<t>::Size(){
	return m_size1;
}
template<typename t>
t& Stack<t>::Top() {
	return m_top -> m_data;
}
template<typename t>
void Stack<t>::Pop(){
	Node<t>*tmp=m_top;
	m_top = m_top -> m_next;
	delete tmp;
	m_size1--;
}
template<typename t>
Stack<t>::~Stack() {
for(Node<t> *ptr = m_top; ptr!=nullptr;){
	m_top = m_top -> m_next;
	delete ptr;
}
}
int main() {
	Stack<int> my_stack;
	my_stack.Push(10);
	my_stack.Push(20);
	my_stack.Push(30);
	my_stack.Push(40);
	my_stack.Push(50);
	my_stack.Push(60);
	std::cout << my_stack.Size() << std::endl;
	while(!my_stack.Empty()){
		std::cout << my_stack.Top()<<" ";
		my_stack.Pop();
}
	std::cout << std::endl << my_stack.Size();
return 0;
}
