---
title: include/slist.h


---

# include/slist.h








## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[SListNode](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list_node.md)** <br>Templated simple linked-list node element.  |
| class | **[SList](https://github.com/devel0/iot-utils/tree/main/data/api/Classes/class_s_list.md)** <br>Templated simple linked-list.  |
















## Source code

```cpp
#ifndef _SEARCHATHING_IOT_UTILS_SLIST_H
#define _SEARCHATHING_IOT_UTILS_SLIST_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

template <class T>
class SListNode
{
public:
    SListNode<T>(const T &_data) { data = _data; }

    T data;

    SListNode<T> *next = NULL;
};

template <class T>
class SList
{
    uint16_t size = 0;
    SListNode<T> *first = NULL;
    SListNode<T> *last = NULL;

public:
    SList()
    {
    }

    SList(const SList &other)
    {
        *this = other;
    }

    SList &operator=(const SList &other)
    {
        Clear();

        auto node = other.first;

        while (node)
        {
            Add(node->data);
            node = node->next;
        }

        return *this;
    }

    ~SList()
    {
        Clear();
    }

    uint16_t Size() const { return size; }

    T &Add(const T &data)
    {
        auto node = new SListNode<T>(data);
        if (node == NULL)
        {
#if defined DEBUG
            printf("* Fatal: SList alloc of node out of memory\n");
#endif
        }
        if (first == NULL)
            first = last = node;
        else
        {
            last->next = node;
            last = node;
        }
        ++size;

        return node->data;
    }

    void Clear()
    {
        if (first == NULL)
            return;

        SListNode<T> *node = first;
        while (node != NULL)
        {
            SListNode<T> *tmp = node->next;
            delete node;
            node = tmp;
            --size;
        }
        first = last = NULL;
    }

    void Remove(uint16_t idx)
    {
        if (idx >= size)
            return; // arg exception

        if (idx == 0) // delete first
        {
            SListNode<T> *tmp = first->next;
            delete first;
            first = tmp;
        }
        else
        {
            SListNode<T> *before = GetNode(idx - 1);
            if (idx == size - 1) // delete last
            {
                delete last;
                before->next = NULL;
                last = before;
            }
            else
            {
                SListNode<T> *after = before->next->next;
                delete before->next;
                before->next = after;
            }
        }

        --size;
    }

    T &Get(int idx) const
    {
        return GetNode(idx)->data;
    }

    SListNode<T> *GetNode(int idx) const
    {
        if (idx == size - 1)
            return last;

        if (idx >= size)
            return NULL;

        SListNode<T> *res = first;
        while (idx--)
        {
            res = res->next;
        }

        return res;
    }
};

#endif
```


-------------------------------


