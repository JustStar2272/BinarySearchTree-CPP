
#include <iostream>
using namespace std;
struct Stek
{
    int num;
};
struct List
{
    Stek d;
    List* next;
};

void dobaBlenue(int*& arr, int& i, int& n, const int& pt)
{
    if (i % pt == 0)
    {
        n++;
    }
    int* stackm = new int[pt * n];
    for (int L = 0; L < i; L++) {
        stackm[L] = arr[L];
    }
    cout << "������� �����." << endl;
    cin >> stackm[i];
    delete[] arr;
    arr = stackm;
    i++;
}
//�������� ��� ����� ����� ������
void remove(int*& arr, int& i, int& n, const int& pt)
{
    if (i >= 1)
    {
        int* stackm = new int[pt * n];

        for (int L = 0; L < i; L++) {
            stackm[L] = arr[L];
        }
        arr[i] = 0;
        i--;
    }
    else
    {
        cout << "� ������� �� ������." << endl;
    }
}
//����� ������� ��� ����� � ������
void print(int*& arr, int& i)
{
    if (i >= 1)
    {
        for (int y = 0; y < i; y++)
            cout << arr[y] << " ";
        cout << endl;
    }
    else
    {
        cout << "������ ��������." << endl;
    }
}
void Berh(int*& arr, int& i)
{
    if (i >= 1)
    {
        cout << arr[i - 1] << endl;
    }
    else
    {
        cout << "���� ����" << endl;
    }
}
void clean(int*& arr, int& i, int& n, int& l)
{
    if (i >= 1)
    {
        for (int L = 0; L < i; L++) {
            arr[L] = 0;
        }
        i = 0;
        n = 1;
        l = 0;
    }
    else
    {
        cout << "���� � ��� ����" << endl;
    }
}
void pysto(int& i)
{
    if (i >= 1)
    {
        cout << "�� �����" << endl;
    }
    else
    {
        cout << "�������" << endl;
    }
}
//������� ��� ������ �� ����
void clean1(int*& arr, int& i, int& n, int& l)
{
    if (i >= 1)
    {
        for (int L = 0; L < i; L++) {
            arr[L] = 0;
        }
        i = 0;
        n = 1;
        l = 0;
    }
}
//�������� ��� ������� ����� ������
void ydalsnachala(int*& arr, int& i, int& n, const int& pt, int& l)
{
    if (i >= 1)
    {
        int* stackm = new int[pt * n];

        for (int L = 0; L < i; L++) {
            stackm[L] = arr[L];
        }
        arr[l] = 0;
        l++;
    }
    else
    {
        cout << "� ������� �� ������." << endl;
    }
}
//������� ��� ����� � ������� �� ��������
void printList(List* u)
{
    List* p = u;
    if (p == NULL)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        while (p)
        {
            cout << p->d.num << " ";
            p = p->next;
        }
        cout << endl;
    }
}
void addtobeginoflist(List** u)
{
    List* t = new List;
    cin >> t->d.num;
    t->next = *u;
    *u = t;
}
void addtoendoflist(List** u)
{
    List* p = *u;
    List* L = new List;
    cin >> L->d.num;
    L->next = NULL;
    if (p == NULL)
    {
        *u = L;
    }
    else
    {
        while (1)
        {
            if (!p->next)
            {
                p->next = L;
                break;
            }
            p = p->next;
        }
    }
}
void Berxlist(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        cout << p->d.num << endl;
    }
}
void delstek(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        p = p->next;
        *u = p;
    }
}
void ocher(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        p = p->next;
        *u = p;
    }
}
void pystolist(List* u)
{
    List* p = u;
    if (p == NULL)
    {
        cout << "�������" << endl;
    }
    else
    {
        cout << "�� �����" << endl;
    }
}
void cleanstek(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }

    }
}
void cleanstek1(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }
    }
}
void cleanocher(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }

    }
}
void cleanocher1(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }

    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    int i = 0;//��������� ������ �������
    int n = 1;//����� ������� ����� ����������� ���� �������������� ���������
    const int pt = 5;
    int* arr = new int[0];
    int f;
    int l = 0;
    int pos = 0;//�������
    int sst = 0;
    List* u = NULL;
    do
    {
        cout << "1.���� ����� ������" << endl << "2.���� �������" << endl << "3.������� ����� ������" << endl << "4.������� �������" << endl;
        cin >> f;
        if ((f >= 1) && (f <= 4))
        {
            switch (f)
            {
            case 1:
                //������ ����
                do
                {
                    cout << "1.��������(� �����)" << endl << "2.�������(�� �����)" << endl <<

                    "3.�����������" << endl << "4.�������� �������" << endl << "5.��������" << endl << "6.��������� ����� ��" << endl << "7.����� �� ������" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        dobaBlenue(arr, i, n, pt);
                        break;
                    case 2:
                        remove(arr, i, n, pt);
                        break;
                    case 3:
                        print(arr, i);
                        break;
                    case 4:
                        Berh(arr, i);
                        break;
                    case 5:
                        clean(arr, i, n, l);
                        break;
                    case 6:
                        pysto(i);
                        break;
                    case 7:
                        clean1(arr, i, n, l);
                        break;
                    }
                } while (f != 7);
            case 2:
                //���� �������
                do
                {
                    cout << "1.��������(� ������)" << endl << "2.�������(� ������)" << endl << "3.�����������" << endl << "4.�������� �������" << endl << "5.�������� ����" << endl << "6.��������� ����� ��" << endl << "7.����� �� ������" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        addtobeginoflist(&u);
                        break;
                    case 2:
                        delstek(&u);
                        break;
                    case 3:
                        printList(u);
                        break;
                    case 4:
                        Berxlist(&u);
                        break;
                    case 5:
                        cleanstek(&u);
                        break;
                    case 6:
                        pystolist(u);
                        break;
                    case 7:
                        //exit
                        cleanstek1(&u);
                        break;
                    }
                } while (f != 7);
                break;
            case 3:
                do
                {
                    //������ �������
                    cout << "1.��������(� �����)" << endl << "2.�������(�� ������)" << endl << "3.�����������" << endl << "4.�������� �������" << endl << "5.��������" << endl << "6.��������� ����� ��" << endl << "7.����� �� ������" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        dobaBlenue(arr, i, n, pt);
                        break;
                    case 2:
                        ydalsnachala(arr, i, n, pt, l);
                        break;
                    case 3:
                        print(arr, i);
                        break;
                    case 4:
                        Berh(arr, i);
                        break;
                    case 5:
                        clean(arr, i, n, l);
                        break;
                    case 6:
                        pysto(i);
                        break;
                    case 7:
                        clean1(arr, i, n, l);
                        break;
                    }
                } while (f != 7);
            case 4:
                //������� �������
                do
                {
                    cout << "1.��������(� �����)" << endl << "2.�������(�� ������)" << endl << "3.�����������" << endl << "4.�������� �������" << endl << "5.��������" << endl << "6.��������� ����� ��" << endl << "7.����� �� ������" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        addtoendoflist(&u);
                        break;
                    case 2:
                        ocher(&u);
                        break;
                    case 3:
                        printList(u);
                        break;
                    case 4:
                        Berxlist(&u);
                        break;
                    case 5:
                        cleanocher(&u);
                        break;
                    case 6:
                        pystolist(u);
                        break;
                    case 7:
                        //exit
                        cleanocher1(&u);
                        break;
                    }
                } while (f != 7);
                break;
            }
        }
        else
        {
            cout << "������ ���� � ������� ������� �� ���������";
        }
    } while (1);
}