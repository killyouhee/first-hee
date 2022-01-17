//12번
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main(){

//     auto method = [](int size, int *arr){
//     sort(arr, arr+size);
//     };
    
 
 
//     int iarr[] = {4, 7, 2, 67, 4, 13, 6};
//     method(sizeof(iarr)/sizeof(int), iarr);
    
//     for(auto value : iarr){
//         cout<<value<<" ";
//     }
    
//     cout<<endl;
//     return 0;
// }



// 13번
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>
// using namespace std;


// template <typename T>
// void swap(T &a, T &b){
//     T temp = a;
//     a = b;
//     b = temp;
// }

// template <typename T>
// void reverse(T arr[], int size){
//     for(int i=0; i<size/2; i++){
//         swap(arr[i], arr[size-1-i]);
//     }
// }

// template <typename T>
// void print(string title, T arr[], int size)
// {
//     cout << title << " : ";
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int arr1[] = {3, 7, 2, 12, 14, 1};
//     double arr2[] = {22.7, 14.2, 3.8, 12.23, 11.2};
//     char arr3[] = {'C', 'a', 'B', 'E', 'N', 'Q'};
//     string arr4[] = {"John", "Lu", "Mary", "Su"};

//     print("Original array", arr1, sizeof(arr1) / sizeof(int));
//     reverse(arr1, sizeof(arr1) / sizeof(int));
//     print("Reversed array", arr1, sizeof(arr1) / sizeof(int));
//     cout << endl;

//     print("Original array", arr2, sizeof(arr2) / sizeof(double));
//     reverse(arr2, sizeof(arr2) / sizeof(double));
//     print("Reversed array", arr2, sizeof(arr2) / sizeof(double));
//     cout << endl;

//     print("Original array", arr3, sizeof(arr3) / sizeof(char));
//     reverse(arr3, sizeof(arr3) / sizeof(char));
//     print("Reversed array", arr3, sizeof(arr3) / sizeof(char));
//     cout << endl;

//     print("Original array", arr4, sizeof(arr4) / sizeof(string));
//     reverse(arr4, sizeof(arr4) / sizeof(string));
//     print("Reversed array", arr4, sizeof(arr4) / sizeof(string));
//     cout << endl;

//     return 0;
// }



//14번
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Student
// {
//     string name;
//     int id;

// public:
//     Student() = default;
//     Student(string name, int id) : name(name), id(id){};
//     ~Student() = default;
//     void show() { cout << "name: " << name << ", id: " << id << endl; }
// };
// class Manager
// {
//     vector<Student> vec;

// public:
//     void run();
//     void input2save();
//     void print(); // show()함수를 이용하여 vec에 저장된 모든 Student 객체 정보 출력
// };
// void Manager::run()
// {
//     cout << ">> 벡터에 학생 데이터를 저장합니다." << endl;
//     input2save();
//     cout << ">> 벡터에 저장된 모든 학생 데이터를 출력합니다." << endl;
//     print();
// }
// void Manager::input2save()
// {
//     // Student 객체와 관련된 정보를 입력 받아 vec에 저장
    
//     string name;
//     int id;

//     cout << "학생 데이터를 입력하세요. (입력 종료는 quit)" << endl;

//     while(true){
//         cout << "name : ";
//         getline(cin, name);
//         if(name == "quit") break;

//         cout << "id : ";
//         cin >> id;
//         cin.ignore();


//         vec.emplace_back(name, id);

        
//     }

// }
// void Manager::print()
// {
//     for(auto &v : vec){
//         v.show();
//     }
// }
// int main()
// {
//     Manager man;
//     man.run();
// }


//15번
// #include <iostream>
// #include <string>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// using namespace std;

// class Nation
// {
//     string nation;  //나라이름
//     string capital; //수도
// public:
//     Nation(string nation, string capital)
//     {
//         this->nation = nation;
//         this->capital = capital;
//     }
//     string getCapital() { return capital; }
//     string getNation() { return nation; }
//     void show()
//     {
//         cout << '(' << nation << ',' << capital << ')';
//     }
  
// };
// class NationGame
// {
//     vector<Nation> v;
//     void input();
//     void list();
//     void quiz();
//     bool exist(string nation);

// public:
//     NationGame();
//     void run();
// };
// NationGame::NationGame()
// {
//     Nation n[] = {
//         Nation("미국", "워싱턴"), Nation("영국", "런던"), Nation("프랑스", "파리"), Nation("중국", "베이징"), Nation("일본", "도쿄"), Nation("러시아", "모스크바"), Nation("브라질", "브라질리아"), Nation("독일", "베를린"), Nation("멕시코", "멕시코시티")};
//     for (int i = 0; i < 9; i++)
//         v.emplace_back(n[i]); // v.push_back(n[i]);
//     srand((unsigned)time(0)); //시작할 때마다, 다른 랜덤수를 발생시키기 위한 seed 설정
// }
// void NationGame::run()
// {
//     cout << "***** 국가의 수도 맞추기 게임을 시작합니다. *****" << endl;
//     while (true)
//     {
//         int cmd;
//         cout << "\n1(정보 입력), 2(퀴즈), 3(종료) : ";
//         cin >> cmd;
//         switch (cmd)
//         {
//         case 1:
//             input();
//             break;
//         case 2:
//             quiz();
//             break;
//         case 3:
//             return;
//         }
//     }
// }
// void NationGame::quiz()
// {
//     while (true)
//     {
//         int index = rand() % v.size(); 
//         cout << v[index].getNation() << "의 수도는? ";

//         string capital;
//         cin >> capital;

//         if(capital == "quit") break;

//         if(v[index].getCapital() == capital)
//             cout << "Correct !!" << endl;
//         else
//             cout << "NO !!" << endl;
//     }
// }

// void NationGame::input()
// {
    
//     string nation,
//             capital;

//     cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
//     cout << "\n국가와 수도를 입력하세요(quit quit이면 입력 종료)" << endl;
    
//     while (true)
//     {
    

//     }
// }

// bool NationGame::exist(string nation)
// {
// }
// int main()
// {
//     NationGame game;
//     game.run();
// }





//7강 12번
// #include <iostream>
// #include <string>
// using namespace std;

// class ArrayUtil {
// public:
//     //s1과 s2를 연결한 새로운 배열을 동적 생성하여 리턴
//     static int* concat(int s1[], int size1, int s2[], int size2, int&retSize);
   
//     //s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
//     static int* remove(int s1[], int size1, int s2[], int size2, int&retSize);
// };

//concat() 구현합니다.
//remove() 구현합니다.



// int* ArrayUtil::concat(int s1[], int size1, int s2[], int size2, int&retSize){
//     retSize = size1 + size2;
//     int *p = new int[retSize];
    
//     for(int i=0; i<size1; i++){
//         p[i] = s1[i];
//         p[i+size1] = s2[i];           
//     }

//     for(int j=size1; j<size2; j++){
//             p[j] = s2[j];
//     }  

//     return p;
// }

// int* ArrayUtil::remove(int s1[], int size1, int s2[], int size2, int&retSize){
//     int *p = new int[size1]; //일치하는 것이 하나도 없어도 최대 크기는 size1을 넘지 않으므로
//     if(!p){
//         retSize = 0;
//         return NULL;
//     }

//     int len = 0;
//     for(int i = 0; i< size1; i++){
//         int j;
//         for(j=0; j<size2; j++){
//             if(s1[i] == s2[j]) break;
//         }
//         if(j == size2){ //s2배열의 끝까지 찾았는데, not found
//             p[len] = s1[i]; //s2배열에 없으므로 s1[i]의 내용을 p배열에 저장
//             len++; //p배열의 인덱스를 하나 증가시켜 다음 s1[i]번째 데이터를 검사
//         }
//     }

//     retSize = len; // 중복되지 않는 내요으이 개수는 len
//     if(len == 0) return NULL;

//     int *q = new int[retSize]; //결정된 retSize로 동적 배열 다시 할당
//     if(!q){
//         retSize = 0;
//         return NULL;
//     }

//     for(int i=0; i< retSize; i++){
//         q[i] = p[i]; // p[] 배열을 q[] 배열에 복사
//     }

//     delete[] p; //독적배열 반환
//     return q; //동적 배열 반환
// }


// int main() {
//     int xcount = 0, ycount = 0;
//     int *x, *y;

//     while(xcount < 1 || xcount > 5){
//         cout << "x배열의 원소(1~5)는 몇 개 ? ";
//         cin >> xcount;
//     }

//     x = new int[xcount];

//     cout << "x배열에 저장할 정수 입력 : ";
//     for(int i=0; i<xcount; i++){
//         cin >> x[i];
//     } 

//     while(ycount < 1 || ycount > 5){
//         cout << "x배열의 원소(1~5)는 몇 개 ? ";
//         cin >> ycount;
//     }

//     y = new int[ycount];

//     cout << "x배열에 저장할 정수 입력 : ";
//     for(int i=0; i<ycount; i++){
//         cin >> y[i];
//     }
    
//     int retsize = 0;

//     int *conarr = ArrayUtil::concat(x, xcount, y, ycount, retsize);
//     cout << "\nx배열과 y배열을 연결한 배열은 ";
//     for (int i = 0; i < retsize; i++) cout << conarr[i] << ' ';
//     cout << endl;

//     int *remarr = ArrayUtil::remove(x, xcount, y, ycount, retsize);  
//     cout << "\nx배열에서 y배열의 원소를 삭제한 결과, x배열의 개수는 " << retsize << "개, ";
//     for (int i = 0; i < retsize; i++) cout << remarr[i] << ' ';
//     cout << endl;

//     //동적 할당된 모든 변수를 해제 한다. 
    
// }



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
