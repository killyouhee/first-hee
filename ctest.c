#include <iostream>
using namespace std;

class Person { //Person Ŭ���� ����
    char *name; 
    int id;
public:
    Person(const Person& p); // ���� ������
};

Person::Person(const Person& p){
    this -> name = p. name;
    this -> id = p.id;
}


14��, 15��
#include <iostream>
#include <string>
using namespace std;
    
void find2replace(string &fstr, string &fhas, string &fre, bool &fsuccess){
    int i = 0;

    while((i=fstr.find(fhas)) != -1){
        fstr.replace(i, fre.length(), fre);
        fsuccess = true;
    }
}
        
int main() {
    std::string str = "C++ programming";
    std::string has = "+";
    string replace = "p";
    bool result = false;
    
    cout << "���� �� ���ڿ� = " << str << endl;
    
    find2replace(str, has, replace, result);
    
    if (result == true) 
        cout << "���� �� ���ڿ� = " << str << endl;  
    else 
        cout << str << "���� " << has << "�� �߰����� ����." << endl;   
    return 0;
}



16��
#include <iostream>
using namespace std;

class Accumulator {
    int value;
public:
    Accumulator(int val) : value{val} { };
    Accumulator &add(int n);
    int get() { return value; }
};
//add() �Լ��� �ۼ��մϴ�. //

Accumulator& Accumulator:: add(int n){
    value += n;
    return *this;  //���ڱ� �ڽ� �ּ��� �� ����
}

int main() {
    Accumulator acc(10);
    cout << acc.get() << endl; //10 ���
    
    acc.add(1).add(2).add(3); //acc ��ü�� value�� 16�� ��. cout << acc.get() << endl; //15 ���
    cout << acc.get() << endl;

}


17��
#include <iostream>
using namespace std;

class Account {
    int balance; //�ܾ�
public:
    Account(int deposit) : balance(deposit) { };
    int getBalance() { return balance; }
    void setBalance(int deposit) { this-> balance = deposit; }
    void show() {
        cout << "�ܾ��� " << balance << "�� �Դϴ�." << endl;
    }
};


//
//increaseBy() �Լ��� �ۼ��մϴ�. //
void increaseBy(Account &acc , int in){
    acc.setBalance(acc.getBalance() + in);
}


int main() {
    Account acc(500);
    cout << "�Ա� �� "; acc.show();
    
    int in;
    cout << "�Աݾ� : "; cin >> in;
    
    increaseBy(acc, in);
    cout << "�Ա� �� "; acc.show();
}




18��
#include <iostream>
#include <string>
using namespace std;


void message_print(string&& msg){
    cout << "massage = " << msg << endl; 
}


int main() {
    string stra = "apple";
    string strb = "banana";
    
    message_print(move(stra)); //rvalue
    message_print(stra + strb);
    
    return 0;
}




19��
#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
public:
    Person() = default;
    Person(string n) : name {n} { cout << "������ ����" << endl; }; 
    Person(const Person &person); //���� ������
    Person(Person&& p); //�̵� ������
    ~Person() { cout << "�Ҹ��� ����" << endl; };
    void show(string obj) { cout << obj << " name = "<< name << endl; }
};


Person::Person(const Person &person) : name(person.name){
    cout << "��������� ����"<<endl;
} 

Person::Person(Person&& p){
    cout << "�̵������� ����"<< endl;
    this -> name = p.name;
    p.name.clear();
    
} 

int main() {
    cout << "-1----------" << endl;
    Person dan("daniel");
    Person ben = Person("benny");
    
    cout << "-2----------" << endl;
    Person mvdan = move(dan);
 
    cout << "-3----------" << endl;
    Person cpben = ben;
    Person cpmvdan(mvdan);
    
    cout << "-4----------" << endl;
    dan.show("dan");
    ben.show("ben");
    mvdan.show("mvdan");
    cpben.show("cpben");
    cpmvdan.show("cpmvdan");
 
    return 0;
}




20��
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char* name;
public:
    Person() = default;
    Person(const char *n); 
    Person(const Person &person); //���� ������
    Person(Person&& p) ; //�̵� ������
    ~Person();
    void show(string obj);
};

Person::Person(const char *n){
    cout << "������ ����"<<endl;
    int len = strlen(n); 
    this->name = new char[len+1]; 
    strcpy(this->name, n);
}

Person::Person(const Person &person){
    cout << "��������� ����"<<endl;
    int len = strlen(person.name); 
    this->name = new char[len+1]; 
    strcpy(this->name, person.name);
}

Person::Person(Person&& p){
    cout << "�̵������� ����"<< endl;
    int len = strlen(p.name); 
    this->name = new char[len+1]; 
    strcpy(this->name, p.name);
}

void Person::show(string obj){
    if(this->name == nullptr){
        cout << obj << "name = "<<endl;
    }
    else{
        cout << obj << "name = " << this -> name << endl;
    }
}

Person::~Person(){
    cout << "�Ҹ��� ����" << endl;
}


int main() {
    cout << "-1----------" << endl;
    Person dan("daniel");
    Person ben = Person("benny");
    
    cout << "-2----------" << endl;
    Person mvdan = move(dan);
 
    cout << "-3----------" << endl;
    Person cpben = ben;
    Person cpmvdan(mvdan);
    
    cout << "-4----------" << endl;
    dan.show("dan");
    ben.show("ben");
    mvdan.show("mvdan");
    cpben.show("cpben");
    cpmvdan.show("cpmvdan");
    
    return 0;
}











9��
#include <iostream>
#include <string>
using namespace std;


class Person {
    int id;
    double weight;
    string name;
public:
    Person(int id = 1, string name = "Grace", double weight = 20.5){
        this -> id = id;
        this -> weight = weight;
        this -> name = name;
    }

    void show() {
        cout << id << ' '<< weight << ' ' << name << endl; 
    }

};

int main() {
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}




10��
#include <iostream>
#include <string>
using namespace std;

int big(int a, int b, int c = 100){
    // if(a < b)
    //     a = b;  //a�� b���� ������ a=b, a�� ��µǾ�� �ϱ� ����

    // if(a > c)
    //     a = c; //a�� 100���� ũ�� a = c, c�� �ִ밪�̱� ����
    
    // return a;



    if(a > c || b > c) //a,b�� c���� ũ�� ����Ʈ�� 100�� ���
        return c; 

    else{ 
        if(a >= b){ 
            if(a > c) 
                return c;
            else
                return a;
        }
        else{
            if(b > c)
                return c;
            else
                return b;
        }
    }
}


int main() {
    int x = big(3, 5); //3�� 5�� ū �� 5�� �ִ밪 100���� �����Ƿ�, 5 ����
    int y = big(300, 60); //300�� 60�� ū �� 300�� �ִ밪 100���� ũ�Ƿ�, 100 ����
    int z = big(30, 60, 50); // 30�� 60 �� ū �� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
    cout << x << ' ' << y << ' ' << z << endl;
}




11��
#include <iostream>
#include <string>
using namespace std;



int add(int a[], int cnt, int b[] = 0){
    int sum = 0;

    for(int i=0; i < cnt; i++){
        sum += a[i];
        
        if(b != 0){
            sum += b[i];
        }
    } 
    return sum;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9, 10};

    int c = add(a, sizeof(a)/sizeof(int)); 
    int d = add(a, sizeof(a)/sizeof(int), b);
   
    cout << c << endl; // 15 ���
    cout << d << endl; // 55 ���
}




12��
#include <iostream>
#include <string>
using namespace std;

class ArrayUtil {
public:
    //s1�� s2�� ������ ���ο� �迭�� ���� �����Ͽ� ����
    static int* concat(int s1[], int size1, int s2[], int size2, int&retSize);
   
    //s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
    static int* remove(int s1[], int size1, int s2[], int size2, int&retSize);
};

//concat() �����մϴ�.
//remove() �����մϴ�.

int* ArrayUtil::concat(int s1[], int size1, int s2[], int size2, int&retSize){
    retSize = size1 + size2;
    int *p = new int[retSize];
    
    for(int i=0; i<size1; i++){
        p[i] = s1[i];
        p[i+size1] = s2[i];           
    }

    for(int j=size1; j<size2; j++){
            p[j] = s2[j];
    }  
    

    return p;
}

int* ArrayUtil::remove(int s1[], int size1, int s2[], int size2, int&retSize){
    int cnt = 0;
    int index = 0;
    int *q = new int[cnt];

    for(int i=0; i<size1; i++){
        for(int j=0; j<size2; j++){
            if(s1[i] == s2[j]) 
                break;
            else
                cnt++;
        }
        if(cnt == size2)
            q[index++] = s1[i];
        cnt++;
    }

    retSize = index;
    delete [] q;
    return q;
}

int main() {
    int xcount = 0, ycount = 0;
    int *x, *y;

///////////////////////////////////////////////////////////
    while(xcount < 1 || xcount > 5){
        cout << "x�迭�� ����(1~5)�� �� �� ? ";
        cin >> xcount;
    }

    x = new int[xcount];

    cout << "x�迭�� ������ ���� �Է� : ";
    for(int i=0; i<xcount; i++){
        cin >> x[i];
    } 
////////////////////////////////////////////////////////
    while(ycount < 1 || ycount > 5){
        cout << "x�迭�� ����(1~5)�� �� �� ? ";
        cin >> ycount;
    }

    y = new int[ycount];

    cout << "x�迭�� ������ ���� �Է� : ";
    for(int i=0; i<ycount; i++){
        cin >> y[i];
    }
///////////////////////////////////////////////////////////
    
    int retsize = 0;

    int *conarr = ArrayUtil::concat(x, xcount, y, ycount, retsize);
    cout << "\nx�迭�� y�迭�� ������ �迭�� ";
    for (int i = 0; i < retsize; i++) cout << conarr[i] << ' ';
    cout << endl;

    int *remarr = ArrayUtil::remove(x, xcount, y, ycount, retsize);  
    cout << "\nx�迭���� y�迭�� ���Ҹ� ������ ���, x�迭�� ������ " << retsize << "��, ";
    for (int i = 0; i < retsize; i++) cout << remarr[i] << ' ';
    cout << endl;

    //���� �Ҵ�� ��� ������ ���� �Ѵ�. 
    
}





8��=======================================================================
4��
#include <iostream>
using namespace std;

class Power { //�������� ǥ���ϴ� �Ŀ� Ŭ����
    int kick; //�߷� ���� ��
     int punch; //�ָ����� ġ�� ��
public: 
    Power(int kick=0, int punch=0) { 
    this->kick = kick;
    this->punch = punch;
 }
    void show(string obj);
    Power operator*(const Power &op2);
};

void Power::show(string obj) {
    cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator*(const Power &op2){
    return Power(this->kick*op2.kick, this->punch*op2.punch);
}

int main(){
    Power a(3,5), b(4,6), c;
    c = a * b;
    a.show("a");
    b.show("b");
    c.show("c");
}






5��
#include <iostream>
#include <cmath>
using namespace std;

class Power { //�������� ǥ���ϴ� �Ŀ� Ŭ����
    int kick; //�߷� ���� ��
    int punch; //�ָ����� ġ�� ��
public: 
    Power(int kick=0, int punch=0) { 
    this->kick = kick;
    this->punch = punch;
 }
    void show(string obj);
    Power operator<<(int op2);
}; 

void Power::show(string obj) {
 cout << obj << ") kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator<<(int op2){
    kick = kick*pow(2, op2);
    punch = punch*pow(2, op2);
}

int main(){
    Power a(2,3);
    a << 3;
    a.show("a");

    Power b(1,5);
    b << 1;
    b.show("b");

}











6��
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int price;
public:
    Book(string title = "", int price = 0){
        this->title = title; this->price = price;
    }
    void show(string obj);
    string getTitle() { 
        return title; 
    }//title ��ȯ

    Book& operator+=(int op2);
    Book& operator-=(int op2);
    bool operator==(int price);
    bool operator==(string title);
    bool operator==(const Book& op2);
};

void Book::show(string obj){
    cout << obj << ") title = " << title << ", price= " << price << endl;
}

Book& Book::operator+=(int op2){
    price = price + op2;
    return *this;
}

Book& Book::operator-=(int op2){
    price = price - op2;
    return *this;
}

bool Book::operator==(int price) {
    if (this->price == price) 
        return true;
    else 
        return false;
}

bool Book::operator==(string title) {
    if (this->title == title) 
        return true;
    else 
        return false;
}

bool Book::operator==(const Book& op2) {
    if(title==op2.title && price==op2.price) 
        return true;
    else 
        return false;
}

int main() {
    Book a("û��", 20000), b("�̷�", 30000);
   
    a += 500; //å a�� ���� 500�� ����
    b -= 500; //å b�� ���� 500�� ����   
    a.show("a"); 
    b.show("b");
   
    Book c("��ǰ C++", 30000), d("��ǰ C++", 30000);
   
    if (c == 30000) cout << "��ǰ C++ ���� 30000��" << endl; //price ��
    if (c == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; //å title ��
    if (c == d) cout << "�� å�� ���� å�Դϴ�." << endl; // title, price ��� �� 
    else cout << "�� å�� �ٸ� å�Դϴ�." << endl;
}




7��

#include <iostream>
using namespace std;

class Matrix {
    int ar[4];
public:
    Matrix(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0);
    void show(string name);

    Matrix operator+(Matrix a);
    Matrix& operator+=(Matrix b);
    Matrix& operator<<(int op2[]);
    Matrix& operator>>(int op2[]);
};

Matrix::Matrix(int a1 , int a2 , int b1 , int b2 ){
    ar[0] = a1;
    ar[1] = a2;
    ar[2] = b1;
    ar[3] = b2;
}

void Matrix::show(string name){
    cout << name << " = { " ;
    for (int i = 0; i < 4; i++){
        cout << ar[i] << ' ' ; // x[] ���
    }
    cout << "}" << endl;
}

Matrix Matrix::operator+(Matrix a) {
    Matrix tmp;
    for (int i = 0; i < 4; i++)
        tmp.ar[i] = this->ar[i] + a.ar[i];
    return tmp;
}

Matrix& Matrix::operator+=(Matrix b) {
    for (int i = 0; i < 4; i++)
        this->ar[i] += b.ar[i];
    return *this;
}

Matrix& Matrix::operator<<(int op2[]){
    for(int i=0; i<4; i++){
        this->ar[i] = op2[i];
    }
}

Matrix& Matrix::operator>>(int op2[]){
    for(int i=0; i<4; i++){
        op2[i] = this->ar[i];
    }
}

int main() {
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a.show("a");
    b.show("b");
    c.show("c");
    
    a += b;
    a.show("a");
    
    int x[4], y[4] = {5, 6, 7, 8};
    a >> x; // a�� �� ���Ҹ� �迭 x�� ����. 
    b << y; // �迭 y�� ���� ���� b�� �� ���ҿ� ����
    
    cout << "x = { ";
    for (int i = 0; i < 4; i++)
        cout << x[i] << ' '; // x[] ���
    cout << "}" << endl;
    
    b.show("b");
}



8��
#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0){ this-> radius = radius; }
    void show(string name){
        cout << "radius = "<< radius << endl;
    }

    Circle& operator++();
    Circle operator++(int x);
    Circle operator+(int op2);

};

Circle& Circle::operator++(){ //����
    radius++;
    return *this;
}

Circle Circle::operator++(int x){ //����
    Circle test = *this; //���� ���� ��ü ���� ����
    radius++;
    return test; //���� ���� ��ü ���� ����
}

Circle Circle::operator+(int op2){
    Circle tmp;
    tmp.radius = this->radius + op2;
    return tmp;
}

int main() {
    Circle a(5), b(4);
    a.show("a");
    b.show("b");
 
    ++a; // �������� 1 ���� ��Ų��. a.show("a");
    a.show("a");

    b = a++; // �������� 1 ���� ��Ų��. a.show("a");
    a.show("a");
    b.show("b");
    
    b = a + 3; // b�� �������� a�� �������� 3�� ���� ������ ����
    b.show("b");
}


9��
#include <iostream>
#include <utility>
#include <string>
using namespace std;

class Array {
    double *ptr;
    int size;
public:
    Array(int size);
    ~Array();
    void show(string name);
    //[] ������ �ߺ�
     //= ������ �ߺ�

    double& operator[](int index);
    Array& operator=(const Array &array);
    
};

Array::Array(int s) : size(s){
    ptr = new double[size];
}

Array::~Array(){
    delete [] ptr;
}

double& Array::operator[](int index){
    if(index<0 || index >= size){
        cout << "�ε��� ���� �ʰ� ����" << endl;
        exit(1);
    }
    return ptr[index];
}

Array& Array::operator=(const Array &array){
    // if(this == &array) return *this; //�ڱ��ڽ� arr=arr �϶� �������

    delete ptr;
    ptr = nullptr;

    size = array.size;
    ptr = new double[size];

    for(auto i=0; i<size; i++){
        this->ptr[i] = array.ptr[i];
    }
    return *this;
}

void Array::show(string name){
    cout << name << " = { " ;
    for (int i = 0; i < size; i++){
        cout << ptr[i] << ' ' ; // x[] ���
    }
    cout << "}" << endl;
}


int main() {
    int size;
    cout << "array size ? ";
    cin >> size;
    
    Array arr(size), brr(size);
    
    for (int i = 0; i < size; i++) {
        cout << i << ") input >> ";
        cin >> arr[i];
    }

    arr.show("arr");
    
    brr = arr;
    brr.show("brr");
    
    brr[2] = 34.5;
    brr[4] = 56.3;
    arr.show("arr"); 
    brr.show("brr");
    
    return 0;
}



10��
#include <iostream>
using namespace std;

class SortedArray {
    int size; //���� �迭�� ũ��
    int *p; //���� �迭�� ���� ������
    void sort(); //���� �迭�� ������������ ����

public:
    SortedArray(); //p�� NULL�� size�� 0���� �ʱ�ȭ
    SortedArray(SortedArray &arr); //���� ������
    SortedArray(int arr[], int size); //������. ���� �迭�� ũ�⸦ ���޹���
    ~SortedArray(); //�Ҹ���
    SortedArray operator+(SortedArray &b);
    SortedArray &operator=(const SortedArray &b); //���� �迭�� b �迭�� ����  
    void show(string name);//�迭�� ���� ���
};

SortedArray::SortedArray(){
    size = 0;
    p = nullptr;
}

SortedArray::SortedArray(SortedArray& arr){
    this->size = arr.size;
    this->p = new int [this->size];
    for(int i=0; i<this->size; i++)
        this->p[i] = arr.p[i];
}

SortedArray::SortedArray(int p[], int size){
    this->p = new int [size];
    this->size = size;
    for(int i=0; i<size; i++)
        this->p[i] = p[i]; 
}

SortedArray& SortedArray::operator=(const SortedArray& op2){
    delete [] p;
    this->size = op2.size;
    this->p = new int [this->size]; 
    for(int i=0; i<this->size; i++){
        this->p[i] = op2.p[i];
    } 
    return *this;
}

SortedArray SortedArray::operator+(SortedArray &b){
    SortedArray tmp;
    tmp.size = this -> size + b.size;
    tmp.p = new int[tmp.size];

    for(int i=0; i<tmp.size; i++){
        if(i<this->size){
            tmp.p[i] = this->p[i];
        }
        else
            tmp.p[i] = b.p[i -(tmp.size - b.size)];
        
    }
    return tmp;
}

void SortedArray::show(string name) {
    sort();
    cout << name << " = { ";
    for(int i=0; i<size; i++)
        cout << p[i] << ' ';
    cout << "}" << endl;
}

void SortedArray::sort(){
    int swap;
    for(int i=0; i<size; i++){ //p[0] ~ p[size] sequential sort 
        for(int j=i; j<size; j++){
            if(p[i]<p[j] || p[i]==p[j]);
            else {
                swap = p[i];
                p[i] = p[j];
                p[j] = swap;
            }
        }
    }
}

SortedArray::~SortedArray() {
    
    delete [] p;
}
 


int main() {
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};

    SortedArray a(n, 3), b(m, 4), c;
    
    c = a + b;
    
    a.show("a");
    b.show("b");
    c.show("c");

    
}




9��==================================================
6��

#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "������ A " << endl; }
    A(int x) { cout << "������ A " << x << endl; }
};
class B : public A
{
public:
    B() { cout << "������ B " << endl; }
    B(int x) { cout << "������ B " << x << endl; }
    B(int x, int y) : A(x + y + 2){
        cout << "������ B " << x + y + 2 << endl; 
    } 
    
};

int main(){
    
    B b(10,20);
    
}



7��
#include <iostream>
using namespace std;

class BaseArray
{
    int capacity; //���� �Ҵ�� �޸��� �� �뷮
    int *mem;     //���� �Ҵ�� �޸�
protected:
    BaseArray(int capacity = 100)
    {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray
{
    int head; //�����͸� ���� ��ġ�� head
    int tail; //������ ������ ��ġ�� tail+1
    int size; //���� ť �ȿ� �ִ� �������� ����
public:
    MyQueue(int capacity); // capacity��ŭ BaseArray ����, head, tail, size �ʱ�ȭ
    void enqueue(int n);   //ť�� head ��ġ�� ������ �ֱ�
    int dequeue();         //ť�� tail+1 ��ġ���� �����͸� ������ ����
    int capacity();        //ť�� �� �뷮 ����
    int length();          //ť�� �ִ� �������� ���� ����
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity){
    head = 0;
    tail = -1;
    size = 0;
}

void MyQueue::enqueue(int n){
    put(head, n);
    head;
}

int MyQueue::dequeue(){
    head--;
    tail++;
    return get(tail);
}

int MyQueue::capacity(){
    return getCapacity();
}

int MyQueue::length(){
    return size;
}

int main()
{
    int capa;
    cout << "ť�� ��ü �뷮��? ";
    cin >> capa;
    MyQueue mq(capa);
    int cnt, n;
    cout << "ť�� ������ ���� ������? ";
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cout << i << ") ";
        cin >> n;
        mq.enqueue(n); //ť�� ������ �ֱ�
    }
    cout << "ť�� �뷮 = " << mq.capacity() << endl;
    cout << "ť�� ���� ũ�� = " << mq.length() << endl;
    cout << "ť�� ���Ҹ� ������� ���� ��� �ϸ�...";
    while (mq.length() != 0)
    {
        cout << mq.dequeue() << ' '; //ť���� ���� ���
    }
    cout << endl;
    cout << "ť�� �뷮 = " << mq.capacity() << endl;
    cout << "ť�� ���� ũ�� = " << mq.length() << endl;
}


�̰Ǹ���============================================================

#include <iostream>
using namespace std;

class SortedArray {
    int size; //���� �迭�� ũ��
    int *p; //���� �迭�� ���� ������
    void sort(); //���� �迭�� ������������ ����

public:
    SortedArray(); //p�� NULL�� size�� 0���� �ʱ�ȭ
    SortedArray(SortedArray &arr); //���� ������
    SortedArray(int arr[], int size); //������. ���� �迭�� ũ�⸦ ���޹���
    ~SortedArray(); //�Ҹ���
    SortedArray operator+(SortedArray &b);
    SortedArray &operator=(const SortedArray &b); //���� �迭�� b �迭�� ����  
    void show(string name);//�迭�� ���� ���
};

SortedArray::SortedArray(){
    size = 0;
    p = nullptr;
}

SortedArray::SortedArray(SortedArray& arr){
    this->size = arr.size;
    this->p = new int [this->size];
    for(int i=0; i<this->size; i++)
        this->p[i] = arr.p[i];
}

SortedArray::SortedArray(int p[], int size){
    this->p = new int [size];
    this->size = size;
    for(int i=0; i<size; i++)
        this->p[i] = p[i]; 
}

SortedArray& SortedArray::operator=(const SortedArray& op2){
    delete [] p;
    this->size = op2.size;
    this->p = new int [this->size]; 
    for(int i=0; i<this->size; i++){
        this->p[i] = op2.p[i];
    } 
    return *this;
}

SortedArray SortedArray::operator+(SortedArray &b){
    SortedArray tmp;
    tmp.size = this -> size + b.size;
    tmp.p = new int[tmp.size];

    for(int i=0; i<tmp.size; i++){
        if(i<this->size){
            tmp.p[i] = this->p[i];
        }
        else
            tmp.p[i] = b.p[i -(tmp.size - b.size)];
        
    }
    return tmp;
}

void SortedArray::show(string name) {
    sort();
    cout << name << " = { ";
    for(int i=0; i<size; i++)
        cout << p[i] << ' ';
    cout << "}" << endl;
}

void SortedArray::sort(){
    int swap;
    for(int i=0; i<size; i++){ //p[0] ~ p[size] sequential sort 
        for(int j=i; j<size; j++){
            if(p[i]<p[j] || p[i]==p[j]);
            else {
                swap = p[i];
                p[i] = p[j];
                p[j] = swap;
            }
        }
    }
}

SortedArray::~SortedArray() {
    
    delete [] p;
}
 


int main() {
    int n[] = {2, 20, 6};
    int m[] = {10, 7, 8, 30};

    SortedArray a(n, 3), b(m, 4), c;
    
    c = a + b;
    
    a.show("a");
    b.show("b");
    c.show("c");

}