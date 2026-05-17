#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;

    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }

    t = r;
}

void print(list* h) {
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

void insert_after(list*& h, list*& t, list* r, int y) {
    list* p = new list;
    p->inf = y;

    if (r == t) {
        p->next = NULL;
        p->prev = r;
        r->next = p;
        t = p;
    }
    else {
        p->next = r->next;
        p->prev = r;
        r->next->prev = p;
        r->next = p;
    }
}


void del_list(list*& h, list*& t) {
    while (h) {
        list* p = h;
        h = h->next;
        delete p;
    }
    t = NULL;
}

int main() {
    list* h = NULL;
    list* t = NULL;

    int n, x;
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, t, x);
    }

    int mx = h->inf;
    int lastOdd = 0;
    bool hasOdd = false;

    list* p = h;

    while (p) {
        if (p->inf > mx)
            mx = p->inf;

        if (p->inf % 2 != 0) {
            lastOdd = p->inf;
            hasOdd = true;
        }

        p = p->next;
    }

    if (hasOdd) {
        p = h;

        while (p) {
            list* nextNode = p->next;

            if (p->inf == mx) {
                insert_after(h, t, p, lastOdd);
            }

            p = nextNode;
        }
    }

    print(h);

    del_list(h, t);

    return 0;
}