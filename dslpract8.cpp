#include <iostream>
using namespace std;

struct SLLNode {
    char data;
    struct SLLNode *next;
};

struct SLLNode *headU, *headA, *headB;

struct SLLNode* createSLL(int cnt, struct SLLNode *head);
void displaySLL(struct SLLNode *head);
void A_U_B();
void A_Int_B();
void A_Min_B();
void B_Min_A();
void U_Min_A_U_B();

int main() {
    int i, no;

    cout << "\n\n\tHow many Linked Lists: ";
    cin >> no;

    headU = headA = headB = NULL;

    for (i = 1; i <= no; i++) {
        if (i == 1) {
            cout << "\n\n\t Enter number of Students: ";
            headU = createSLL(10, headU);
            cout << "\n";
            displaySLL(headU);
        }
        if (i == 2) {
            cout << "\n\n\t Enter Students who like Vanilla Icecream:";
            headA = createSLL(3, headA);
            cout << "\n";
            displaySLL(headA);
        }
        if (i == 3) {
            cout << "\n\n\t Enter Students who like Butterscotch Icecream:";
            headB = createSLL(3, headB);
            cout << "\n";
            displaySLL(headB);
        }
    }

    cout << "\n\n Set 'U': ";
    displaySLL(headU);
    cout << "\n\n Set 'A': ";
    displaySLL(headA);
    cout << "\n\n Set 'B': ";
    displaySLL(headB);
    cout << "\n\n Output Sets: ";
    A_U_B();
    A_Int_B();
    A_Min_B();
    B_Min_A();
    U_Min_A_U_B();

    cout << "\n\n";
    return 0;
}

struct SLLNode* createSLL(int cnt, struct SLLNode *head) {
    int i;
    struct SLLNode *p, *newNode;

    for (i = 0; i < cnt; i++) {
        newNode = new SLLNode;
        cout << "\n\t Enter Student Initial: ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            p = head;
        } else {
            p->next = newNode;
            p = p->next;
        }
    }
    return head;
}

void displaySLL(struct SLLNode *head) {
    struct SLLNode *p = head;
    while (p != NULL) {
        cout << " " << p->data;
        p = p->next;
    }
}

void A_U_B() {
    int i = 0;
    char a[10];
    struct SLLNode *p = headA, *q = headB;

    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            a[i] = p->data;
            i++;
            p = p->next;
            q = q->next;
        } else {
            a[i] = p->data;
            i++;
            p = p->next;
        }
    }

    if (p == NULL) {
        while (q != NULL) {
            a[i] = q->data;
            i++;
            q = q->next;
        }
    }

    if (q == NULL) {
        while (p != NULL) {
            a[i] = p->data;
            i++;
            p = p->next;
        }
    }

    cout << "\n\n\t Set A U B: ";
    for (int j = 0; j < i; j++)
        cout << " " << a[j];
}

void A_Int_B() {
    int i = 0;
    char a[10];
    struct SLLNode *p = headA;

    while (p != NULL) {
        struct SLLNode *q = headB;
        while (q != NULL) {
            if (p->data == q->data) {
                a[i] = p->data;
                i++;
            }
            q = q->next;
        }
        p = p->next;
    }

    cout << "\n\n\t Set A ^ B: ";
    for (int j = 0; j < i; j++)
        cout << " " << a[j];
}

void A_Min_B() {
    int i = 0, flag;
    char a[10];
    struct SLLNode *p = headA;

    while (p != NULL) {
        struct SLLNode *q = headB;
        flag = 0;
        while (q != NULL) {
            if (p->data == q->data) {
                flag = 1;
                break;
            }
            q = q->next;
        }
        if (flag == 0) {
            a[i] = p->data;
            i++;
        }
        p = p->next;
    }

    cout << "\n\n\t Set A - B: ";
    for (int j = 0; j < i; j++)
        cout << " " << a[j];
}

void B_Min_A() {
    int i = 0, flag;
    char a[10];
    struct SLLNode *q = headB;

    while (q != NULL) {
        struct SLLNode *p = headA;
        flag = 0;
        while (p != NULL) {
            if (q->data == p->data) {
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (flag == 0) {
            a[i] = q->data;
            i++;
        }
        q = q->next;
    }

    cout << "\n\n\t Set B - A: ";
    for (int j = 0; j < i; j++)
        cout << " " << a[j];
}

void U_Min_A_U_B() {
    int i = 0, flag;
    char a[10];
    struct SLLNode *p = headU;

    while (p != NULL) {
        flag = 0;
        struct SLLNode *q = headA;
        while (q != NULL) {
            if (p->data == q->data) {
                flag = 1;
                break;
            }
            q = q->next;
        }

        struct SLLNode *r = headB;
        while (r != NULL) {
            if (p->data == r->data) {
                flag = 1;
                break;
            }
            r = r->next;
        }

        if (flag == 0) {
            a[i] = p->data;
            i++;
        }
        p = p->next;
    }

    cout << "\n\n\t Set U - (A U B): ";
    for (int j = 0; j < i; j++)
        cout << " " << a[j];
}
