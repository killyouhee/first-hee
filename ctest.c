#include <iostream>
using namespace std;

class Person { //Person 클래스 선언
    char *name; 
    int id;
public:
    Person(const Person& p); // 복사 생성자
};

Person::Person(const Person& p){
    this -> name = p. name;
    this -> id = p.id;
}


14번, 15번
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
    
    cout << "변경 전 문자열 = " << str << endl;
    
    find2replace(str, has, replace, result);
    
    if (result == true) 
        cout << "변경 후 문자열 = " << str << endl;  
    else 
        cout << str << "에서 " << has << "를 발견하지 못함." << endl;   
    return 0;
}



16번
#include <iostream>
using namespace std;

class Accumulator {
    int value;
public:
    Accumulator(int val) : value{val} { };
    Accumulator &add(int n);
    int get() { return value; }
};
//add() 함수를 작성합니다. //

Accumulator& Accumulator:: add(int n){
    value += n;
    return *this;  //★자기 자신 주소의 값 리턴
}

int main() {
    Accumulator acc(10);
    cout << acc.get() << endl; //10 출력
    
    acc.add(1).add(2).add(3); //acc 객체의 value는 16이 됨. cout << acc.get() << endl; //15 출력
    cout << acc.get() << endl;

}


17번
#include <iostream>
using namespace std;

class Account {
    int balance; //잔액
public:
    Account(int deposit) : balance(deposit) { };
    int getBalance() { return balance; }
    void setBalance(int deposit) { this-> balance = deposit; }
    void show() {
        cout << "잔액은 " << balance << "원 입니다." << endl;
    }
};


//
//increaseBy() 함수를 작성합니다. //
void increaseBy(Account &acc , int in){
    acc.setBalance(acc.getBalance() + in);
}


int main() {
    Account acc(500);
    cout << "입금 전 "; acc.show();
    
    int in;
    cout << "입금액 : "; cin >> in;
    
    increaseBy(acc, in);
    cout << "입금 후 "; acc.show();
}




18번
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




19번
#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
public:
    Person() = default;
    Person(string n) : name {n} { cout << "생성자 실행" << endl; }; 
    Person(const Person &person); //복사 생성자
    Person(Person&& p); //이동 생성자
    ~Person() { cout << "소멸자 실행" << endl; };
    void show(string obj) { cout << obj << " name = "<< name << endl; }
};


Person::Person(const Person &person) : name(person.name){
    cout << "복사생성자 실행"<<endl;
} 

Person::Person(Person&& p){
    cout << "이동생성자 실행"<< endl;
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




20번
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char* name;
public:
    Person() = default;
    Person(const char *n); 
    Person(const Person &person); //복사 생성자
    Person(Person&& p) ; //이동 생성자
    ~Person();
    void show(string obj);
};

Person::Person(const char *n){
    cout << "생성자 실행"<<endl;
    int len = strlen(n); 
    this->name = new char[len+1]; 
    strcpy(this->name, n);
}

Person::Person(const Person &person){
    cout << "복사생성자 실행"<<endl;
    int len = strlen(person.name); 
    this->name = new char[len+1]; 
    strcpy(this->name, person.name);
}

Person::Person(Person&& p){
    cout << "이동생성자 실행"<< endl;
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
    cout << "소멸자 실행" << endl;
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











9번
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




10번
#include <iostream>
#include <string>
using namespace std;

int big(int a, int b, int c = 100){
    // if(a < b)
    //     a = b;  //a가 b보다 작으면 a=b, a가 출력되어야 하기 때문

    // if(a > c)
    //     a = c; //a가 100보다 크면 a = c, c가 최대값이기 때문
    
    // return a;



    if(a > c || b > c) //a,b가 c보다 크면 디폴트값 100을 출력
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
    int x = big(3, 5); //3과 5중 큰 값 5는 최대값 100보다 작으므로, 5 리턴
    int y = big(300, 60); //300과 60중 큰 값 300이 최대값 100보다 크므로, 100 리턴
    int z = big(30, 60, 50); // 30과 60 중 큰 값 60이 최대값 50보다 크므로, 50 리턴
    cout << x << ' ' << y << ' ' << z << endl;
}




11번
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
   
    cout << c << endl; // 15 출력
    cout << d << endl; // 55 출력
}




12번
#include <iostream>
#include <string>
using namespace std;

class ArrayUtil {
public:
    //s1과 s2를 연결한 새로운 배열을 동적 생성하여 리턴
    static int* concat(int s1[], int size1, int s2[], int size2, int&retSize);
   
    //s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
    static int* remove(int s1[], int size1, int s2[], int size2, int&retSize);
};

//concat() 구현합니다.
//remove() 구현합니다.

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
        cout << "x배열의 원소(1~5)는 몇 개 ? ";
        cin >> xcount;
    }

    x = new int[xcount];

    cout << "x배열에 저장할 정수 입력 : ";
    for(int i=0; i<xcount; i++){
        cin >> x[i];
    } 
////////////////////////////////////////////////////////
    while(ycount < 1 || ycount > 5){
        cout << "x배열의 원소(1~5)는 몇 개 ? ";
        cin >> ycount;
    }

    y = new int[ycount];

    cout << "x배열에 저장할 정수 입력 : ";
    for(int i=0; i<ycount; i++){
        cin >> y[i];
    }
///////////////////////////////////////////////////////////
    
    int retsize = 0;

    int *conarr = ArrayUtil::concat(x, xcount, y, ycount, retsize);
    cout << "\nx배열과 y배열을 연결한 배열은 ";
    for (int i = 0; i < retsize; i++) cout << conarr[i] << ' ';
    cout << endl;

    int *remarr = ArrayUtil::remove(x, xcount, y, ycount, retsize);  
    cout << "\nx배열에서 y배열의 원소를 삭제한 결과, x배열의 개수는 " << retsize << "개, ";
    for (int i = 0; i < retsize; i++) cout << remarr[i] << ' ';
    cout << endl;

    //동적 할당된 모든 변수를 해제 한다. 
    
}





8강=======================================================================
4번
#include <iostream>
using namespace std;

class Power { //에너지를 표현하는 파워 클래스
    int kick; //발로 차는 힘
     int punch; //주먹으로 치는 힘
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






5번
#include <iostream>
#include <cmath>
using namespace std;

class Power { //에너지를 표현하는 파워 클래스
    int kick; //발로 차는 힘
    int punch; //주먹으로 치는 힘
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











6번
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
    }//title 반환

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
    Book a("청춘", 20000), b("미래", 30000);
   
    a += 500; //책 a의 가격 500원 증가
    b -= 500; //책 b의 가격 500원 감소   
    a.show("a"); 
    b.show("b");
   
    Book c("명품 C++", 30000), d("고품 C++", 30000);
   
    if (c == 30000) cout << "명품 C++ 정가 30000원" << endl; //price 비교
    if (c == "명품 C++") cout << "명품 C++ 입니다." << endl; //책 title 비교
    if (c == d) cout << "두 책이 같은 책입니다." << endl; // title, price 모두 비교 
    else cout << "두 책이 다른 책입니다." << endl;
}




7번

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
        cout << ar[i] << ' ' ; // x[] 출력
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
    a >> x; // a의 각 원소를 배열 x에 복사. 
    b << y; // 배열 y의 원소 값을 b의 각 원소에 설정
    
    cout << "x = { ";
    for (int i = 0; i < 4; i++)
        cout << x[i] << ' '; // x[] 출력
    cout << "}" << endl;
    
    b.show("b");
}



8번
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

Circle& Circle::operator++(){ //전위
    radius++;
    return *this;
}

Circle Circle::operator++(int x){ //후위
    Circle test = *this; //증가 이전 객체 상태 저장
    radius++;
    return test; //증가 이전 객체 상태 리턴
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
 
    ++a; // 반지름을 1 증가 시킨다. a.show("a");
    a.show("a");

    b = a++; // 반지름을 1 증가 시킨다. a.show("a");
    a.show("a");
    b.show("b");
    
    b = a + 3; // b의 반지름을 a의 반지름에 3을 더한 것으로 변경
    b.show("b");
}


9번
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
    //[] 연산자 중복
     //= 연산자 중복

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
        cout << "인덱스 범위 초과 오류" << endl;
        exit(1);
    }
    return ptr[index];
}

Array& Array::operator=(const Array &array){
    // if(this == &array) return *this; //자기자신 arr=arr 일때 써줘야함

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
        cout << ptr[i] << ' ' ; // x[] 출력
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



10번
#include <iostream>
using namespace std;

class SortedArray {
    int size; //현재 배열의 크기
    int *p; //정수 배열에 대한 포인터
    void sort(); //정수 배열을 오름차순으로 정렬

public:
    SortedArray(); //p는 NULL로 size는 0으로 초기화
    SortedArray(SortedArray &arr); //복사 생성자
    SortedArray(int arr[], int size); //생성자. 정수 배열과 크기를 전달받음
    ~SortedArray(); //소멸자
    SortedArray operator+(SortedArray &b);
    SortedArray &operator=(const SortedArray &b); //현재 배열에 b 배열을 복사  
    void show(string name);//배열의 원소 출력
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




9강==================================================
6번

#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "생성자 A " << endl; }
    A(int x) { cout << "생성자 A " << x << endl; }
};
class B : public A
{
public:
    B() { cout << "생성자 B " << endl; }
    B(int x) { cout << "생성자 B " << x << endl; }
    B(int x, int y) : A(x + y + 2){
        cout << "생성자 B " << x + y + 2 << endl; 
    } 
    
};

int main(){
    
    B b(10,20);
    
}



7번
#include <iostream>
using namespace std;

class BaseArray
{
    int capacity; //동적 할당된 메모리의 총 용량
    int *mem;     //동적 할당된 메모리
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
    int head; //데이터를 넣을 위치는 head
    int tail; //데이터 꺼내는 위치는 tail+1
    int size; //현재 큐 안에 있는 데이터의 개수
public:
    MyQueue(int capacity); // capacity만큼 BaseArray 생성, head, tail, size 초기화
    void enqueue(int n);   //큐의 head 위치에 데이터 넣기
    int dequeue();         //큐의 tail+1 위치에서 데이터를 꺼내서 리턴
    int capacity();        //큐의 총 용량 리턴
    int length();          //큐에 있는 데이터의 개수 리턴
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
    cout << "큐의 전체 용량은? ";
    cin >> capa;
    MyQueue mq(capa);
    int cnt, n;
    cout << "큐에 저장할 정수 개수는? ";
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cout << i << ") ";
        cin >> n;
        mq.enqueue(n); //큐에 데이터 넣기
    }
    cout << "큐의 용량 = " << mq.capacity() << endl;
    cout << "큐의 현재 크기 = " << mq.length() << endl;
    cout << "큐의 원소를 순서대로 꺼내 출력 하면...";
    while (mq.length() != 0)
    {
        cout << mq.dequeue() << ' '; //큐에서 꺼내 출력
    }
    cout << endl;
    cout << "큐의 용량 = " << mq.capacity() << endl;
    cout << "큐의 현재 크기 = " << mq.length() << endl;
}


이건모지============================================================

#include <iostream>
using namespace std;

class SortedArray {
    int size; //현재 배열의 크기
    int *p; //정수 배열에 대한 포인터
    void sort(); //정수 배열을 오름차순으로 정렬

public:
    SortedArray(); //p는 NULL로 size는 0으로 초기화
    SortedArray(SortedArray &arr); //복사 생성자
    SortedArray(int arr[], int size); //생성자. 정수 배열과 크기를 전달받음
    ~SortedArray(); //소멸자
    SortedArray operator+(SortedArray &b);
    SortedArray &operator=(const SortedArray &b); //현재 배열에 b 배열을 복사  
    void show(string name);//배열의 원소 출력
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