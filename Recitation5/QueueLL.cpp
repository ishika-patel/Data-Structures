#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    /*if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;*/
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    // TODO Complete this function, handle the case when you're enqueuing in an empty queue

    if (isEmpty())
    {
        queueEnd = nn;
        queueFront = nn;

        // nn->next = queueFront;
        // queueFront = nn;

        // QueueEnd->next = nn;
        // QueueEnd = nn;

    }
    else
    {
        //  Node* temp = queueEnd;
        //  temp->next = nn;
        //  queueEnd = nn;

         queueEnd->next = nn;
         queueEnd = nn;
    }
    

}

//TODO
void QueueLL::dequeue()
{
    //Node *nn = new Node;
    //nn->key = key;
    //nn->next = nullptr;
    
    if(!isEmpty())
    {
            // TODO Complete this function, handle the case when your queue becomes empty after dequeuing
            Node* temp = queueFront;
            queueFront = queueFront->next;
            delete temp;
    }
    else{
        cout<<"queue is empty. can not deque"<<endl;
    }
}

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
