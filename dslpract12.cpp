#include <iostream>
#include <queue>
using namespace std;

#define ROW 5
#define COL 2

class Person {
public:
    int age;
    float height;

    Person(int age, float height) : age(age), height(height) {}
};

bool operator<(const Person &p1, const Person &p2) {
    return p1.height <= p2.height;
}

int main() {
    priority_queue<Person> Q;
    float arr[ROW][COL] = {{29, 5.7}, {45, 6.5}, {23, 6.2}, {33, 6.1}, {18, 5.2}};

    for (int i = 0; i < ROW; ++i) {
        Q.push(Person(arr[i][0], arr[i][1]));
    }

    while (!Q.empty()) {
        Person p = Q.top();
        Q.pop();
        cout << p.age << " " << p.height << "\n";
    }

    return 0;
}