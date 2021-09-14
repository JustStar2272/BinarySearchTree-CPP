#include<iostream>
#include<Windows.h>
using namespace std;


struct Derev {
	int value;
	Derev* left;
	Derev* right;
};

struct List {
	Derev* data;
	List* next;
};

void sozdan(List  *&root, Derev *&node) {
	List* tmp = new List;
	tmp->data = node;
	tmp->next = NULL;
	root = tmp;
}

void dob(List *&root, Derev *&node) {
	List* tmp = new List;
	List* p = root;
	while (p->next != NULL) {
		p = p->next;
	}
	tmp->next = p->next;
	tmp->data = node;
	p->next = tmp;
}


void vvod(Derev *&root, int value) {
	Derev* tmp = new Derev;
	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	root = tmp;
}

void sozdNode(Derev* root, int value) {
	if (root != NULL && root->value != value) {
		Derev* node = new Derev;
		Derev* copyRoot = root;
		if (value > root->value && root->right == NULL) {
			node->left = NULL;
			node->right = NULL;
			node->value = value;
			root->right = node;
		}
		else if (value < root->value && root->left == NULL) {
			node->left = NULL;
			node->right = NULL;
			node->value = value;
			root->left = node;
		}
		else if (value > root->value && root->right != NULL) {
			sozdNode(root->right, value);
		}
		else if (value < root->value && root->left != NULL) {
			sozdNode(root->left, value);
		}
	}
	else cout << "����� ������� ��� ����." << endl;
}

void del(Derev*& root, int value) {
	if (root->right == NULL && root->left == NULL) root = NULL;
	else if (root->left != NULL && root->right == NULL) {
		Derev* node = root;
		root = root->left;
		delete node;
	}
	else if (root->left == NULL && root->right != NULL) {
		Derev* node = root;
		root = root->right;
		delete node;
	}
	else if (root->left != NULL && root->right != NULL) {
		if (root->right->left == NULL && root->right->right == NULL || root->right->left == NULL && root->right->right != NULL) {
			Derev* node = root;
			root->right->left = root->left;
			root = root->right;
			delete node;
		}
		else if (root->right->left != NULL && root->right->right == NULL || root->right->left != NULL && root->right->right != NULL) {
			Derev* copyNode = root->right;
			while (copyNode->left->left != NULL) {
				copyNode = copyNode->left;
			}
			if (copyNode->left->right == NULL) {
				Derev* node = root;
				copyNode->left->left = root->left;
				copyNode->left->right = root->right;
				root = copyNode->left;
				copyNode->left = NULL;
				delete node;
			}
			else {
				Derev* node = root;
				Derev* nodeRight = copyNode->left->right;
				copyNode->left->left = root->left;
				copyNode->left->right = root->right;
				root = copyNode->left;
				copyNode->left = nodeRight;
				copyNode->left = copyNode->left->right;
				delete node;
			}
		}
	}
}

void deleteDerev(Derev *&root, int value) {
	int num = 0;
	if (root == NULL) return;
	else if (value > root->value && root->right != NULL) {
		if (root->right->value == value) {
			num++;
			del(root->right, value);
		}
		else deleteDerev(root->right, value);
	}
	else if (value < root->value && root->left != NULL) {
		if (root->left->value == value) {
			num++;
			del(root->left, value);
		}
		else deleteDerev(root->left, value);
	}
	else if (root->value == value) {
		num++;
		del(root, value);
	}
	if (num == 0) cout << "��� ������ ��������" << endl;
}

void poisk(Derev *&root, int value) {
	int num = 0;
	if (root == NULL) return;
	else if (value > root->value && root->right != NULL) {
		if (root->right->value == value) {
			num++;
			cout << "����: " << root->right->value << endl;
			cout << "��������: " << root->value << endl;
			cout << "����� �������: ";
			if (root->right->left != NULL) {
				cout << root->right->left->value << endl;
			}
			else cout << "���" << endl;
			cout << "������ �������: ";
			if (root->right->right != NULL) {
				cout << root->right->right->value << endl;
			}
			else cout << "���" << endl;
		}
		else poisk(root->right, value);
	}
	else if (value < root->value  && root->left != NULL) {
		if (root->left->value == value) {
			num++;
			cout << "����: " << root->left->value << endl;
			cout << "��������: " << root->value << endl;;
			cout << "����� �������: ";
			if (root->left->left != NULL) {
				cout << root->left->left->value << endl;
			}
			else cout << "���" << endl;
			cout << "������ �������: ";
			if (root->left->right != NULL) {
				cout << root->left->right->value << endl;
			}
			else cout << "���" << endl;
		}
		else poisk(root->left, value);
	}
	else if (root != NULL && root->value == value) {
		num++;
		cout << "����: " << root->value << endl;
		cout << "����� �������: ";
		if (root->left != NULL) {
			cout << root->left->value << endl;
		}
		else cout << "���" << endl;
		cout << "������ �������: ";
		if (root->right != NULL) {
			cout << root->right->value << endl;
		}
		else cout << "���" << endl;
	}
	if (num == 0) cout << "��� ������ ��������" << endl;
}

void pram(Derev* root)
{
	if (root == NULL) return;
	cout << root->value << " ";
	pram(root->left);
	pram(root->right);
}

void simetr(Derev* root)
{
	if (root == NULL)
	{
		return;
	}
	simetr(root->left);
	cout << root->value << " ";
	simetr(root->right);
}

void obratn(Derev* root)
{
	if (root == NULL) return;
	obratn(root->left);
	obratn(root->right);
	cout << root->value << " ";
}

void vshir(Derev* root, List *&list) {
	sozdan(list, root);
	List* copyList = list;
	Derev* copyRoot = root;
	do
	{
		cout << copyList->data->value << " ";
		if (copyList->data->left != NULL) {
			dob(list, copyList->data->left);
		}
		if (copyList->data->right != NULL) {
			dob(list, copyList->data->right);
		}
		copyList = copyList->next;
	} while (copyList != NULL);
}

void srznach(Derev* root, int &number, int &sum) {
	if (root == NULL) return;
	srznach(root->left, number, sum);
	srznach(root->right, number, sum);
	sum += root->value;
	number++;
}

int main() {
	setlocale(LC_ALL, "ru");
	Derev* root = NULL;
	List* list = NULL;
	while (1)
	{
		cout << "�������� ����� ����:" << endl;
		cout << "1. �������� ��������" << endl;
		cout << "2. ����� ����" << endl;
		cout << "3. ������� �������� ����" << endl;
		cout << "4. ��������� ������� �������������� ���� ��������� ������" << endl;
		cout << "5. ����������� ��� �������� � ������" << endl;
		cout << "6. �����" << endl;
		char num;
		cin >> num;
		switch (num) {
		case '1': {
			cout << "������� ��������:" << endl;
			int value;
			cin >> value;
			if (root == NULL) {
				vvod(root, value);
			}
			else sozdNode(root, value);
			break;
		}
		case '2': {
			if (root != NULL) {
				cout << "������� ��������: " << endl;
				int value;
				cin >> value;
				poisk(root, value);
			}
			else cout << "������ ������" << endl;
			break;
		}
		case '3': {
			if (root != NULL) {
				cout << "������� ��������: ";
				int value;
				cin >> value;
				deleteDerev(root, value);
			}
			else cout << "������ ������" << endl;
			break;
		}
		case '4': {
			int number = 0;
			int sum = 0;
			srznach(root, number, sum);
			cout << "������� ��������������: " << sum / number << endl;
			break;
		}
		case '5': {
			if (root != NULL) {
				cout << "������ �����: ";
				pram(root);
				cout << endl << "����������� �����: ";
				simetr(root);
				cout << endl << "�������� �����: ";
				obratn(root);
				cout << endl << "����� � ������: ";
				vshir(root, list);
				cout << endl;
			}
			else cout << "������ ������" << endl;
			break;
		}
		case '6': {
			system("pause");
			return 0;
			break;
		}
		default:
			cout << "������" << endl;
			break;
		}

	}
}