#include <iostream>
#include <string>
using namespace std;

struct node
{
    char c;
    node *prev;
    node *next;
    node(char s = '\0', node *p = NULL, node *n = NULL)
    {
        c = s;
        prev = p;
        next = n;
    }
};

class list
{
  private:
    node *head, *tail;

  public:
    list();
    ~list();
    void append(char ch);
    void insert(int n, char ch);
    bool adjust(node *p);
    bool remove(node *p);
    void print();
};

list::list()
{
    head = new node();
    tail = new node();
    head->next = tail;
    tail->prev = head;
}

list::~list()
{
}

void list::append(char ch)
{
    node *p = tail->prev, *q;
    q = new node(ch, p, tail);

    if (q == NULL)
    {
        exit(1);
    }

    p->next = q;
    tail->prev = p->next;
    adjust(q);
}

void list::insert(int n, char ch)
{
    node *p = head;
    while (n--)
    {
        p = p->next;
    }
    node *q = p->next;
    p->next = new node(ch, p, q);
    q->prev = p->next;
    adjust(p->next);
}

bool list::adjust(node *p)
{

    if (p == head)
        return true;

    char ch = p->c;
    int num = 1;

    while (ch == p->next->c)
    {
        p = p->next;
    }

    while (ch == p->prev->c)
    {
        p = p->prev;
        num++;
    }
    p = p->prev;

    while (num >= 3)
    {
        remove(p);
        num -= 3;
    }

    if (num == 0)
    {
        adjust(p);
    }
    return true;
}

bool list::remove(node *p)
{
    // p = p->prev;
    node *q = p->next;
    node *r = q->next;
    node *o = r->next;
    node *s = o->next;
    p->next = s;
    s->prev = p;
    delete (q);
    delete (r);
    delete (o);
    return true;
}

void list::print()
{
    node *p = head->next;

    if (p == tail)
    {
        cout << '-' << endl;
        return;
    }

    while (p != tail)
    {
        cout << p->c;
        p = p->next;
    }
    cout << endl;
    return;
}

int main(int argc, char const *argv[])
{
    // freopen("zuma.txt", "r", stdin);
    char ch;
    string s;
    list l;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        ch = s[i];
        if (!((ch >= 'A') && (ch <= 'Z')))
        {
            continue;
        }
        l.append(ch);
    }

    int N;
    cin >> N;
    int r;
    for (int i = 0; i < N; i++)
    {
        cin >> r >> ch;
        if (!((ch >= 'A') && (ch <= 'Z')))
        {
            break;
        }
        l.insert(r, ch);
        l.print();
    }

    return 0;
}