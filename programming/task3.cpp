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
void del_node(list*& h, list*& t, list* r) {
    if (r == h && r == t) { 
        h = t = NULL;
    }
    else if (r == h) { 
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t) { 
        t = t->prev;
        t->next = NULL;
    }
    else { 
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }

    delete r;
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

    list* p = h;

    while (p) {
        int sum = 0;
        int count = 0;

        list* q = p->next;

        while (q) {
            sum += q->inf;
            count++;
            q = q->next;
        }

        list* nextNode = p->next;

        if (count > 0) {
            double sr = (double)sum / count;

            if (p->inf < sr) {
                del_node(h, t, p);
            }
        }

        p = nextNode;
    }

    print(h);

    del_list(h, t);

    return 0;
}