// A generic implementation of a doubly linked list using templates

#ifndef __DLL__
#define __DLL__

#include <iostream>
using namespace std;

const int FORWARD = 1;
const int REVERSE = -1;

template <class T>
class Node
{
  public:
    inline Node();
    inline ~Node();
    T* mData;
    Node<T>* mPrev;
    Node<T>* mNext;
};

template <class T>
Node::Node()
:mData(NULL)
,mPrev(NULL)
,mNext(NULL)
{
}

template <class T>
Node::~Node()
{
    mPrev = NULL;
    mNext = NULL;
    delete(mData);
}

template <class T>
class DLL
{
  public:
    DLL();
    DLL(int sizeParm, T fillParm);
    ~DLL();
    void print();
    void push_back(const T* dataParm);
    void push_back(Node<T>* nodeParm);
    void pop_back();
    void push_front(const T* dataParm);
    void push_front(Node<T>* nodeParm);
    void pop_front();
    T* front();
    T* back();
    bool isEmpty();
    int size();
    void clear();
    T* at(int indexParm);
    T& operator[](int indexParm);

    void addNode(const T* dataParm, int indexParm);
    // Just removes the node entry from the DLL. Heap memory of the node is not deallocated.
    Node<T>* removeNodeSoft(int indexParm);
    // Removes the node entry from the DLL and also deallocates the heap memory
    void removeNodeHard(int indexParm);

    void resize(int sizeParm,
                T* fillParm,
                const int directionParm = REVERSE);

  private:
    int      mSize;
    Node<T>* mHead;
    Node<T>* mTail;
};

template <class T>
DLL<T>::DLL()
:mSize(0)
,mHead(NULL)
,mTail(NULL)
{
    cout << "DLL Created" << endl;
}

template <class T>
DLL<T>::DLL(int sizeParm, T* fillParm)
:mSize(sizeParm)
{
    // create the first node
    mHead = new Node<T>();
    mHead->mData = fillParm;
    mTail = mHead;

    // create the remaining nodes
    for (int i=1; i<sizeParm; i++)
    {
        Node<T>* sNode = new Node<T>();
        sNode->mData = fillParm;
        mTail->mNext = sNode;
        sNode->mPrev = mTail;
        mTail = sNode;
    }
    mSize = sizeParm;
    cout << "DLL Created with " << mSize << " elements" << endl;
}

template <class T>
DLL<T>::~DLL()
{
    this->clear();
}

template <class T>
void DLL<T>::resize(int sizeParm,
                    T* fillParm,
                    const int directionParm)
{
    if (mSize < sizeParm)
    {
        int sCount = sizeParm - mSize;
        if (directionParm == FORWARD)
        {
            // add nodes at front
            for (int i=0; i<sCount; i++)
            {
                this->push_front(fillParm);
            }
        }
        else
        {
            // add nodes at back - default
            for (int i=0; i<sCount; i++)
            {
                this->push_back(fillParm);
            }
        }
    }
    else if (mSize > sizeParm)
    {
        int sCount = mSize - sizeParm;
        if (directionParm == FORWARD)
        {
            // delete from front
            for (int i=0; i<sCount; i++)
            {
                this->pop_front();
            }
        }
        else
        {
            // delete from back - default
            for (int i=0; i<sCount; i++)
            {
                this->pop_back();
            }
        }
    }
}

template <class T>
void push_back(Node<T>* nodeParm)
{
    if (nodeParm != NULL)
    {
        if (mSize == 0)
        {
            mHead = sNode;
            mTail = sNode;
        }
        else
        {
            mTail->mNext = sNode;
            sNode->mPrev = mTail;
            mTail = sNode;
        }
        mSize++;
    }
}

template <class T>
void DLL<T>::push_back(const T* dataParm)
{
    if (dataParm != NULL)
    {
        Node<T>* sNode = new Node<T>();
        sNode->mData = dataParm;
        push_back(sNode);
    }
}

template <class T>
void DLL<T>::pop_back()
{
    if (mSize > 0)
    {
        Node<T>* sNode = mTail;
        mTail = mTail->mPrev;
        mTail->mNext = NULL;
        delete(sNode);
        mSize--;
    }
}

template <class T>
void push_front(Node<T>* nodeParm)
{
    if (nodeParm != NULL)
    {
        if (mSize == 0)
        {
            mHead = sNode;
            mTail = sNode;
        }
        else
        {
            mHead->mPrev = sNode;
            sNode->mNext = mHead;
            mHead = sNode;
        }
        mSize++;
    }
}

template <class T>
void DLL<T>::push_front(const T* dataParm)
{
    Node<T>* sNode = new Node<T>();
    sNode->mData = dataParm;
    push_front(sNode);
}

template <class T>
void DLL<T>::pop_front()
{
    if (mSize > 0)
    {
        Node<T>* sNode = mHead;
        mHead = mHead->mNext;
        mHead->mPrev = NULL;
        delete(sNode);
        mSize--;
    }
}

template <class T>
void DLL<T>::addNode(const T* dataParm, int indexParm)
{
    if (indexParm > mSize || indexParm < -(mSize+1))
    {
        cout << "[ERROR] Node Index out of DLL range : [" << indexParm << "]"
             << " | DLL size : [" << mSize << "]" << endl;
        return;
    }

    Node<T>* sNewNode = new Node<T>();
    sNode->mData = dataParm;

    if (0 == indexParm || -(mSize+1) == indexParm)
    {
        push_front(dataParm);
    }
    else if (mSize == indexParm || -1 == indexParm)
    {
        push_back(dataParm);
    }
    else
    {
        // now iterate till indexParm
        Node<T>* sNode = NULL;
        if (indexParm > 0)
        {
            sNode = mHead;
            for (int i=0; i<indexParm; i++)
            {
                sNode = sNode->mNext;
            }
        }
        else // indexParm < 0 (reverse order iteration)
        {
            sNode = mTail;
            for (int i=-1; i>indexParm; i--)
            {
                sNode = sNode->mPrev;
            }
            sNode = sNode->mNext; // adjusting to insert in reverse order
        }
        sNewNode->mNext = sNode;
        sNewNode->mPrev = sNode->mPrev;
        sNode->mPrev->mNext = sNewNode;
        sNode->mPrev = sNewNode;
        mSize++;
    }
}

template <class T>
Node<T>* DLL<T>::removeNodeSoft(int indexParm)
{
    Node<T>* sNode = NULL;
    if (mSize == 0)
    {
        cout << "DLL is Empty. Invalid Operation !" << endl;
    }
    else if (mSize < 0)
    {
        cout << "DLL size can't be negative. Invalid Operation !" << endl;
    }
    else if (indexParm >= mSize || indexParm < -mSize)
    {
        cout << "Index out of range. Invalid Operation!. Index:" << indexParm << " | DLL size:" << mSize << endl;
    }
    else
    {
        if (0 == indexParm || -(mSize) == indexParm)
        {
            // remove the first node
            sNode = mHead;
            mHead = mHead->mNext;
            mHead->mPrev = NULL;
        }
        else if (mSize-1 == indexParm || -1 == indexParm)
        {
            // remove the last node
            sNode = mTail;
            mTail = mTail->mPrev;
            mTail->mNext = NULL;
        }
        else
        {
            // now iterate till indexParm
            sNode = NULL;
            if (indexParm > 0)
            {
                sNode = mHead;
                for (int i=0; i<indexParm; i++)
                {
                    sNode = sNode->mNext;
                }
            }
            else // indexParm < 0 (reverse order iteration)
            {
                sNode = mTail;
                for (int i=-1; i>indexParm; i--)
                {
                    sNode = sNode->mPrev;
                }
            }
            sNode->mPrev->mNext = sNode->mNext;
            sNode->mNext->mPrev = sNode->mPrev;
        }
        mSize--;
    }
    return sNode;
}

template <class T>
void DLL<T>::removeNodeHard(int indexParm)
{
    Node<T>* sNode = removeNodeSoft(indexParm);
    if (sNode != NULL)
    {
        delete(sNode);
    }
}

template <class T>
void DLL<T>::print()
{
    Node<T>* sNode = mHead;
    while(sNode != NULL)
    {
        cout << sNode->mData << " ";
        sNode = sNode->mNext;
    }
    cout << endl;
}

template <class T>
void DLL<T>::clear()
{
    Node<T>* sNode = NULL;
    while(mHead != NULL)
    {
        sNode = mHead;
        mHead = mHead->mNext;
        delete(sNode);
    }
    mSize = 0;
    cout << "DLL Cleared" << endl;
}

template <class T>
T* DLL<T>::front()
{
    return mHead->mData;
}

template <class T>
T* DLL<T>::back()
{
    return mTail->mData;
}

template <class T>
T* DLL<T>::at(int indexParm)
{
    T* sDataPtr = NULL;
    if (mSize == 0)
    {
        cout << "DLL is Empty. Invalid Operation !" << endl;
    }
    else if (indexParm >= mSize || indexParm < -mSize)
    {
        cout << "Index out of range. Invalid Operation !" << endl;
    }
    else
    {
        if (indexParm >=0)
        {
            Node<T>* sNode = mHead;
            for (int i=0; i<indexParm; i++)
            {
                sNode = sNode->mNext;
            }
            sDataPtr = sNode->mData;
        }
        else
        {
            Node<T>* sNode = mTail;
            for (int i=-1; i>indexParm; i--)
            {
                sNode = sNode->mPrev;
            }
            sDataPtr = sNode->mData;
        }
    }
    return sDataPtr;
}

template <class T>
T& DLL<T>::operator[](int indexParm)
{
    T* sDataPtr = this->at(indexParm);
    return (*sDataPtr);
}

template <class T>
bool DLL<T>::isEmpty()
{
    bool sIsEmpty = (mSize == 0) ? true : false;
    return sIsEmpty;
}

template <class T>
int DLL<T>::size()
{
    return mSize;
}


#endif  // __DLL_H__
