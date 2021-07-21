#include<iostream>

using namespace std;
template <typename T>
class Vector{
public:
    Vector();
    Vector(size_t size);
    Vector(const Vector<T> & rhs);      
    ~Vector();

    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    void push_back(const T & value); 
    void pop_back();
    void reserve(size_t capacity);      
    void shrink_to_fit();

    T & operator[](unsigned int index);  
    Vector& operator=(const Vector<T>& rhs);
 private:
    size_t  m_size;
    size_t m_capacity;
    T * ptr;
};

template<typename T>
Vector<T>::Vector(){
    m_capacity = 1;
    m_size = 0;
    ptr = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T> & rhs){
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    T*ptr = new T[m_capacity];  
    for (size_t i = 0; i < m_size; i++)
        ptr[i] = rhs.ptr[i];  
}

template<typename T>
Vector<T>::Vector(size_t size):m_size(size),m_capacity(size){
    ptr = new T[size];
}

template<typename T>
Vector<T>& Vector<T>::operator = (const Vector<T> & rhs){
    delete[ ] ptr;
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;
    ptr = new T [m_capacity];
    for (size_t i = 0; i < m_size; i++)
        ptr[i] = rhs.ptr[i];
    return *this;
}

template<typename T>
void Vector<T>::push_back(const T & v){
    if (m_size >= m_capacity)
	m_capacity*=2;
        reserve(m_capacity);
    ptr[m_size++] = v;
}

template<typename T>
void Vector<T>::pop_back(){
    m_size--;
}

template<typename T>
void Vector<T>::reserve(size_t capacity){
    if(ptr == 0){
        m_size = 0;
        m_capacity = 0;
    }    
    T * ptr1 = new T [capacity];
      for (size_t i = 0; i < m_size; i++)
        ptr1[i] = ptr[i];

    m_capacity = capacity;
    delete[] ptr;
    ptr = ptr1;
}
template <typename T>
void Vector <T>::shrink_to_fit(){
    if(m_capacity == m_size)
        return;
    T* temp = new T[m_size];
    for (size_t i=0; i < m_size; i++){
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    m_capacity = m_size;
}

template<typename T>
size_t Vector<T>::size()const{
    return m_size;
}

template<typename T>
T& Vector<T>::operator[](unsigned int index){
    return ptr[index];
}  

template<typename T>
size_t Vector<T>::capacity()const{
    return m_capacity;
}

template<typename T>
Vector<T>::~Vector(){
    delete[ ] ptr;
}
int main(){
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(73);
    v.push_back(74);
    for(int i=0 ; i<v.size(); i++){
	cout<<v[i]<<" ";
    }
    cout << "Vector size : " << v.size() << endl;
    cout << "Vector capacity : " << v.capacity() << endl;
    v.pop_back();
    for (int i =0; i<v.size(); i++){
	cout<<v[i]<<" ";
    }
    cout << "size-"<< v.size() << endl;
    cout << "Vector capacity : "
         << v.capacity() << endl;
   

        return 0;
}
