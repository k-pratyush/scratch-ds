#include<iostream>

using namespace std;

struct Stack {
    int size;
    int top;
    int *s;
};

//stack init
void create(Stack *st) {
    cout << "Size? ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void display(Stack st) {
    for(int i = st.top; i >= 0; i--) {
        cout << st.s[i] << " ";
    }
}

void push(Stack *st, int x) {
    if(st->top == st->size) {
        cout << "Stack overflow";
    } else {
        st->top++;
        st->s[st->top] = x;
    }
}

void pop(Stack *st) {
    if(st->top == -1) {
        cout << "Stack underflow";
    } else {
        st->top--;
    }
}

int peek(Stack st, int index) {
    int x = -1;
    if(st.top - index == 0) {
        cout << "Invalid index";
    } else {
        x = st.s[st.top - index + 1];
    }
    return x;
}

bool isEmpty(Stack *st) {
    return st -> top == -1;
}

bool isFull(Stack *st) {
    return st -> top == st->size - 1;
}


int main() {
    Stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    cout << peek(st, 1) << " ";
    display(st);
}
