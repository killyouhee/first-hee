#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nation
{
    string nation;  //�����̸�
    string capital; //����
public:
    Nation(string nation, string capital)
    {
        this->nation = nation;
        this->capital = capital;
    }
    string getCapital() { return capital; }
    string getNation() { return nation; }
    void show()
    {
        cout << '(' << nation << ',' << capital << ')';
    }
  
};
class NationGame
{
    vector<Nation> v;
    void list();
    void quiz();
    bool exist(string nation);

public:
    NationGame();
    void run();
};
NationGame::NationGame()
{
    Nation n[] = {
        Nation("�̱�", "������"), Nation("����", "����"), Nation("������", "�ĸ�"), Nation("�߱�", "����¡"), Nation("�Ϻ�", "����"), Nation("���þ�", "��ũ��"), Nation("�����", "���������"), Nation("����", "������"), Nation("�߽���", "�߽��ڽ�Ƽ")};
    for (int i = 0; i < 9; i++)
        v.emplace_back(n[i]); // v.push_back(n[i]);
    srand((unsigned)time(0)); //������ ������, �ٸ� �������� �߻���Ű�� ���� seed ����
}
void NationGame::run()
{
    cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****" << endl;
    while (true)
    {
        int cmd;
        cout << "\n1(����), 2(����) : ";
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            quiz();
            break;
        case 2:
            return;
        }
    }
}
void NationGame::quiz()
{
    while (true)
    {
        int index = rand() % v.size(); 
        cout << v[index].getNation() << "�� ������? ";

        string capital;
        cin >> capital;

        if(capital == "quit") break;

        if(v[index].getCapital() == capital)
            cout << "Correct !!" << endl;
        else
            cout << "NO !!" << endl;
    }
}

bool NationGame::exist(string nation)
{
}
int main()
{
    NationGame game;
    game.run();
}