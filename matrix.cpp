#include <iostream>
#include <cassert>

class Matrix
{
	int** m_matrix = 0;
        int m_size = 0;
        void initialize();
public:
        void print() const;
        inline int get_size() const { return m_size; }
        Matrix(int size = 0);
        Matrix(const Matrix& x);
       	Matrix& operator=(const Matrix&);
    	Matrix operator+(const Matrix&);
    	Matrix operator-(const Matrix&);
    	Matrix operator*(const Matrix&);
    	Matrix operator*(const int);
        ~Matrix();
};
Matrix::Matrix(int n): m_matrix(0), m_size(n){
        std::cout << "Constructor n = " << n << std::endl;
        assert(n >= 0);
        if (n == 0) {
                return;
        }
        m_matrix = new int*[n];
        for (int i = 0; i < n; i++) {
                m_matrix[i] = new int[n];
        }
        assert(0 != m_matrix);
        assert(n == m_size);
        initialize();
}
Matrix::Matrix(const Matrix& other):m_size(other.m_size){
    std::cout << "Copy constructor\n";
    m_matrix = new int*[m_size];
    if(0 == m_matrix){
        std::cout << "Could not allocate memory\n";
        exit(1);
    }
    for (int i=0; i<m_size; i++){
        m_matrix[i] = new int[m_size];
        if(0 == m_matrix){
            std::cout << "Could not allocate memory\n";
            exit(1);
        }
    }
    for(int i=0; i<m_size; i++){
        for(int j=0; j<m_size; j++){
           m_matrix[i][j] = other.m_matrix[i][j]; 
        }
    }
}
void Matrix::initialize(){
    for (int i=0; i<m_size; i++){
        for (int j=0; j<i; j++){ 
            m_matrix[i][j]=1;
        }
        m_matrix[i][i]=2;
        for (int j=i+1; j<m_size; j++){
    		m_matrix[i][j]=0;
        }
    }
}
Matrix& Matrix::operator=(const Matrix& other)
{
    m_size = other.m_size;
    m_matrix = new int*[m_size];
    if(0 == m_matrix){
        std::cout << "Could not allocate memory\n";
    }
    for (int i=0; i<m_size; i++)
    {
        m_matrix[i] = new int [m_size];
        if(0 == m_matrix)
        {
            std::cout << "Could not allocate memory\n";
            exit(1);
        }
    }
    for(int i = 0; i < m_size; i++)
        for(int j = 0; j < m_size; j++)
            m_matrix[i][j] = other.m_matrix[i][j];
    return *this;
}
void Matrix::print() const{
        if (0 == m_size) {
          //      assert(0 == m_matrix);
                std::cout << "No Matrix" << std::endl;
                return;
        }
        for (int i = 0; i < m_size; i++) {
                for (int j = 0; j < m_size; j++) {
                        std::cout << m_matrix[i][j] << " ";
                }
                std::cout << std::endl;
        }
        std::cout << std::endl;
}
Matrix Matrix::operator+(const Matrix& other){
    assert(m_size == other.m_size);
    for(int i = 0;i<m_size;i++){
        for(int j=0;j<m_size;j++){
            this->m_matrix[i][j]=m_matrix[i][j]+other.m_matrix[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator-(const Matrix& other){
    assert(m_size == other.m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++){
            temp.m_matrix[i][j]=m_matrix[i][j]-other.m_matrix[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator*(const Matrix& other){
    assert(m_size == other.m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++){
            temp.m_matrix[i][j] = 0;
            for(int k = 0; k < m_size; k++){
                temp.m_matrix[i][j] += m_matrix[i][k] * other.m_matrix[k][j];
            }
        }
    }
    return temp;
}

Matrix Matrix::operator*(const int n){
   // assert( 0 != m_size);
    Matrix temp(m_size);
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++){
            temp.m_matrix[i][j] = m_matrix[i][j]*n;
        }
    }
    return temp;
}
Matrix::~Matrix(){
        std::cout << "Destructor" << std::endl;
        if (0 == m_size) {
           //     assert(0 == m_matrix);
                return;
        }
        for(int i = 0; i < m_size; ++i) {
                delete[] m_matrix[i];
        }
        delete[] m_matrix;
        m_matrix = 0;
        m_size = 0;
}
int main()
{
        std::cout << "Enter matrix size:";
        int n = 0;
        std::cin >> n;
        if (n <= 0) {
                std::cout << "Wrong input" << std::endl;
                return 1;
        }
        Matrix a;
        a.print();
        Matrix e;
	Matrix t;
	t=e*5;
	t.print();
	e.print();
        Matrix k = e;
	k.print();
        Matrix m(n);
        m.print();
        Matrix g;
        g = m;  
        g.print();
}


