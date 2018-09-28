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
    Node<E> *prev;
    E value;

public:
    Node(E value, Node<E> *prev, Node<E> *next) {
        this->value = value;
        this->prev = prev;
        this->next = next;
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

    /**
     *
     * @param index
     * @return
     */
    E get(int index);


    /**
     *
     * @param index
     * @param e
     */
    void insert(int index, E e);

    /**
     *
     * @param index
     */
    E remove(int index);

    ~LinkedList();

    /**
     * 查找当前节点
     * @param i
     * @return
     */
    Node<E> *node(int i);

    /**
     *
     * @param e
     */
    void linkLast(E e);

    /**
     *
     * @param cur
     */
    void linkBefore(Node<E> *cur, E e);


    E unlink(Node<E> *cur);
};

template<class E>
void LinkedList<E>::push(E e) {
    //添加一个数据
    linkLast(e);
    len++;
    /*Node<E> *new_node = new Node<E>(e, NULL);
    if (head) {
        // head->next = new_node;
        //找到尾巴节点，有一个特点就是next 是为空
//        Node<E> *h = head;
//         while (h) {
//             if (h->next == NULL) {
//                 break;
//             }
//             h = h->next;
//         }
//         h->next = new_node;
//
        //每次node(len-1)的时间复杂O(n)
        //如何优化？？？
        //记录last节点 尾节点 时间复杂度变成O(1)
        // Node<E> *last = node(len - 1);
        last->next = new_node;
    } else {
        head = new_node;
    }
    last = new_node;
    len++;*/

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
    //时间复杂度是O(n)级别
    /*   Node<E> *h = head;
       for (int i = 0; i < index; ++i) {
           h = h->next;
       }


       return h;*/
    //时间复杂度是O(n/2)级别
    if (index < len >> 1) {
        // 从前往后变量
        Node<E> *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur;
    } else {
        // 从后往前遍历
        Node<E> *cur = last;
        for (int i = len - 1; i > index; i--) {
            cur = cur->prev;
        }
        return cur;
    }
}


template<class E>
void LinkedList<E>::insert(int index, E e) {
    assert(index >= 0 && index <= len);
    //考虑边界问题index=0的情况
    // 考虑边界
    if (index == len) {
        linkLast(e);
    } else {
        linkBefore(node(index), e);
    }
    len++;

/*    Node<E> *new_node = new Node<E>(e, NULL);
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
*/
}

template<class E>
E LinkedList<E>::remove(int index) {
    assert(index >= 0 && index < len);
    return unlink(node(index));

    //考虑边界问题 0 len mid
/*    if (index == 0) {
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
    }*/

}


template<class E>
void LinkedList<E>::linkLast(E e) {
    Node<E> *l = last;
    Node<E> *new_node = new Node<E>(e, l, NULL);
    last = new_node;
    if (head) {
        l->next = new_node;
    } else {
        head = new_node;
    }

}

template<class E>
LinkedList<E>::~LinkedList() {
    // 析构释放内存 ？
    Node<E> *h;
    h = head;
    while (h) {
        Node<E> *next = h->next;
        delete h;
        h = next;
    }
    //头指针以及尾指针也要置空
    head = NULL;
    last = NULL;


}

template<class E>
void LinkedList<E>::linkBefore(Node<E> *cur, E e) {
    Node<E> *prev = cur->prev;
    Node<E> *new_node = new Node<E>(e, prev, cur);

    //当前的上一个节点指向新增的节点
    cur->prev = new_node;
    if (prev) {
        //上一个节点的next指向新增的节点
        prev->next = new_node;
    } else {
        head = new_node;
    }
}

template<class E>
E LinkedList<E>::unlink(Node<E> *cur) {
    //左右两个节点
    Node<E> *prev = cur->prev;
    Node<E> *next = cur->next;

    E value = cur->value;
    //考虑左右两边为空的情况，严谨，思维灵活
    if (prev) {
        prev->next = next;
    } else {
        head = next;
    }
    if (next) {
        next->prev = prev;
    } else {
        last = prev;
    }
    delete cur;
    len--;
    return value;
}


#endif //NDK34_LINKEDLIST_HPP
