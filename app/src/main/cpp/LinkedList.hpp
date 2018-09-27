//
// Created by yanzhiwen on 9/3/2018.
//

#ifndef NDK34_LINKEDLIST_HPP
#define NDK34_LINKEDLIST_HPP

#include <assert.h>

//单链表节点
template<class E>

struct Node {
    Node<E> *next;
    E value;

public:
    Node(E value, Node<E> *next) {
        this->next = next;
        this->value = value;
    }
};

template<class E>
class LinkedList {

public:

    //头指针
    Node<E> *head = NULL;


    int len = 0;

    //尾节点
    Node<E> *last = NULL;

    /**
     * 添加数据
     * @param e 元素
     */
    void push(E e);

    /**
     * 集合的大小
     * @return
     */
    int size();

    E get(int index);


    void insert(int index, E e);

    void remove(int index);

    ~LinkedList();

    Node<E> *node(int i);
};

template<class E>
void LinkedList<E>::push(E e) {
    //添加一个数据
    Node<E> *new_node = new Node<E>(e, NULL);
    if (head) {
        // head->next = new_node;
        //找到尾巴节点，有一个特点就是next 是为空
        /* Node<E> *h = head;
         while (h) {
             if (h->next == NULL) {
                 break;
             }
             h = h->next;
         }
         h->next = new_node;
         */
        //每次node(len-1)的时间复杂O(n)
        //如何优化？？？
        //记录last节点 尾节点 时间复杂度变成O(1)
        // Node<E> *last = node(len - 1);
        last->next = new_node;
    } else {
        head = new_node;
        last = new_node;
    }
    last = new_node;
    len++;
}

template<class E>

int LinkedList<E>::size() {
    return len;
}

template<class E>
E LinkedList<E>::get(int index) {
    //下一个断言
    assert(index >= 0 && index < len);
    return node(index)->value;
}

template<class E>
Node<E> *LinkedList<E>::node(int index) {
    Node<E> *h = head;
    for (int i = 0; i < index; ++i) {
        h = h->next;
    }
    return h;
}


template<class E>
void LinkedList<E>::insert(int index, E e) {
    assert(index >= 0 && index <= len);
    //考虑边界问题index=0的情况
    Node<E> *new_node = new Node<E>(e, NULL);
    if (index == 0) {
        Node<E> *h = head;
        head = new_node;
        new_node->next = h;
    } else {
        Node<E> *prev = node(index - 1);
        //prev->next 当前节点
        Node<E> *next = prev->next;
        prev->next = new_node;
        new_node->next = next;
    }
    len++;

}

template<class E>
void LinkedList<E>::remove(int index) {
    assert(index >= 0 && index < len);
    //考虑边界问题 0 len mid
    if (index == 0) {
        Node<E> *h = head;
        head = h->next;
        //释放
        delete h;
    } else {
        Node<E> *prev = node(index - 1);
        //当前节点
        Node<E> *cur = prev->next;
        //前一个节点的next指向当前节点的next
        prev->next = cur->next;

        delete cur;
    }
    len--;

}

template<class E>
LinkedList<E>::~LinkedList() {
    // 析构释放内存 ？
}

#endif //NDK34_LINKEDLIST_HPP
