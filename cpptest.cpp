//12��
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



// 13��
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



//14��
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
//     void print(); // show()�Լ��� �̿��Ͽ� vec�� ����� ��� Student ��ü ���� ���
// };
// void Manager::run()
// {
//     cout << ">> ���Ϳ� �л� �����͸� �����մϴ�." << endl;
//     input2save();
//     cout << ">> ���Ϳ� ����� ��� �л� �����͸� ����մϴ�." << endl;
//     print();
// }
// void Manager::input2save()
// {
//     // Student ��ü�� ���õ� ������ �Է� �޾� vec�� ����
    
//     string name;
//     int id;

//     cout << "�л� �����͸� �Է��ϼ���. (�Է� ����� quit)" << endl;

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


//15��
// #include <iostream>
// #include <string>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// using namespace std;

// class Nation
// {
//     string nation;  //�����̸�
//     string capital; //����
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
//         Nation("�̱�", "������"), Nation("����", "����"), Nation("������", "�ĸ�"), Nation("�߱�", "����¡"), Nation("�Ϻ�", "����"), Nation("���þ�", "��ũ��"), Nation("�����", "���������"), Nation("����", "������"), Nation("�߽���", "�߽��ڽ�Ƽ")};
//     for (int i = 0; i < 9; i++)
//         v.emplace_back(n[i]); // v.push_back(n[i]);
//     srand((unsigned)time(0)); //������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
// }
// void NationGame::run()
// {
//     cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****" << endl;
//     while (true)
//     {
//         int cmd;
//         cout << "\n1(���� �Է�), 2(����), 3(����) : ";
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
//         cout << v[index].getNation() << "�� ������? ";

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

//     cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
//     cout << "\n������ ������ �Է��ϼ���(quit quit�̸� �Է� ����)" << endl;
    
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





//7�� 12��
// #include <iostream>
// #include <string>
// using namespace std;

// class ArrayUtil {
// public:
//     //s1�� s2�� ������ ���ο� �迭�� ���� �����Ͽ� ����
//     static int* concat(int s1[], int size1, int s2[], int size2, int&retSize);
   
//     //s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
//     static int* remove(int s1[], int size1, int s2[], int size2, int&retSize);
// };

//concat() �����մϴ�.
//remove() �����մϴ�.



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
//     int *p = new int[size1]; //��ġ�ϴ� ���� �ϳ��� ��� �ִ� ũ��� size1�� ���� �����Ƿ�
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
//         if(j == size2){ //s2�迭�� ������ ã�Ҵµ�, not found
//             p[len] = s1[i]; //s2�迭�� �����Ƿ� s1[i]�� ������ p�迭�� ����
//             len++; //p�迭�� �ε����� �ϳ� �������� ���� s1[i]��° �����͸� �˻�
//         }
//     }

//     retSize = len; // �ߺ����� �ʴ� �������� ������ len
//     if(len == 0) return NULL;

//     int *q = new int[retSize]; //������ retSize�� ���� �迭 �ٽ� �Ҵ�
//     if(!q){
//         retSize = 0;
//         return NULL;
//     }

//     for(int i=0; i< retSize; i++){
//         q[i] = p[i]; // p[] �迭�� q[] �迭�� ����
//     }

//     delete[] p; //�����迭 ��ȯ
//     return q; //���� �迭 ��ȯ
// }


// int main() {
//     int xcount = 0, ycount = 0;
//     int *x, *y;

//     while(xcount < 1 || xcount > 5){
//         cout << "x�迭�� ����(1~5)�� �� �� ? ";
//         cin >> xcount;
//     }

//     x = new int[xcount];

//     cout << "x�迭�� ������ ���� �Է� : ";
//     for(int i=0; i<xcount; i++){
//         cin >> x[i];
//     } 

//     while(ycount < 1 || ycount > 5){
//         cout << "x�迭�� ����(1~5)�� �� �� ? ";
//         cin >> ycount;
//     }

//     y = new int[ycount];

//     cout << "x�迭�� ������ ���� �Է� : ";
//     for(int i=0; i<ycount; i++){
//         cin >> y[i];
//     }
    
//     int retsize = 0;

//     int *conarr = ArrayUtil::concat(x, xcount, y, ycount, retsize);
//     cout << "\nx�迭�� y�迭�� ������ �迭�� ";
//     for (int i = 0; i < retsize; i++) cout << conarr[i] << ' ';
//     cout << endl;

//     int *remarr = ArrayUtil::remove(x, xcount, y, ycount, retsize);  
//     cout << "\nx�迭���� y�迭�� ���Ҹ� ������ ���, x�迭�� ������ " << retsize << "��, ";
//     for (int i = 0; i < retsize; i++) cout << remarr[i] << ' ';
//     cout << endl;

//     //���� �Ҵ�� ��� ������ ���� �Ѵ�. 
    
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
