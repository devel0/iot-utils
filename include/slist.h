#ifndef _SEARCHATHING_IOT_UTILS_SLIST_H
#define _SEARCHATHING_IOT_UTILS_SLIST_H

#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef __MBED__
#include <mbed.h>
#endif

/**
 * @brief Templated simple linked-list node element.
 * 
 * Store templated element `T' into a node object that allow to
 * follow using a `next' pointer to the next one in the list.
 * The given template `T' must support default constructor for
 * internal purpose.
 * 
 * @tparam T template of data
 */
template <class T>
class SListNode
{
public:
    /**
     * @brief Constructor stores a copy of given element into internal data.
     * 
     * @param _data data to store
     */
    SListNode<T>(const T &_data) { data = _data; }

    /**
     * @brief Element data.     
     */
    T data;

    /**
     * @brief Pointer to the next node in simple linked list.     
     */
    SListNode<T> *next = NULL;
};

/**
 * @brief Templated simple linked-list.
 * 
 * Store templated element `T' into a simple linked list.
 * The given template `T' must support default constructor for
 * internal purpose.
 * 
 * @tparam T template of data
 */
template <class T>
class SList
{
    uint16_t size = 0;
    SListNode<T> *first = NULL;
    SListNode<T> *last = NULL;

public:
    /**
     * @brief Default constructor.     
     */
    SList()
    {
    }

    /**
     * @brief Copy constructor.
     * 
     * @param other list to copy data from
     */
    SList(const SList &other)
    {
        *this = other;
    }

    /**
     * @brief Assign operator.
     * 
     * Creates a copy of the given `other' list.
     * 
     * @param other other list to copy data from
     * @return SList& new list with data copied from given other
     */
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

    /**
     * @brief Destructor.
     * 
     * Deallocates memory used for nodes and thus calls destructor of stored templated objects.     
     */
    ~SList()
    {
        Clear();
    }

    /**
     * @brief Current list size.
     * 
     * @return uint16_t 
     */
    uint16_t Size() const { return size; }

    /**
     * @brief Adds given templated object `data' to the list.
     * 
     * If DEBUG enabled a report about out-of-memory will be reported if unable to allocate more nodes.
     * 
     * @param data item data to add
     * @return T& reference to item data
     */
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

    /**
     * @brief Clear the list destroying each nodes thus calling the destructor of contained templated data objects.     
     */
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

    /**
     * @brief Remove the node by idx ( 0 is the first ).
     * 
     * It does nothing if invalid index out of bounds.
     * 
     * @param idx index of item to remove (0 is the first)
     */
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

    /**
     * @brief Retrieve a reference of the template object at the given `idx' in the node list.
     * 
     * Note: don't use `auto' pointer of the returned object will be copied instead of referenced.
     * 
     * @param idx index of element to retrieve (0 is the first)
     * @return T& template data of i-th item
     */
    T &Get(int idx) const
    {
        return GetNode(idx)->data;
    }

    /**
     * @brief Retrieve a pointer to the node at the given `idx' ( 0 is start ).
     * 
     * If an invalid index was given returns NULL.
     * 
     * @param idx index of element node to retrieve (0 is the first)
     * @return SListNode<T>* pointer to i-th item in the list ( NULL if invalid index )
     */
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