#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "cocos2d.h"
USING_NS_CC;

template<class ItemType>  
class Iterator  
{  
public:  
    virtual void first()=0;  
    virtual void next()=0;  
    virtual ItemType* currentItem()=0;  
    virtual bool isDone()=0;  
    virtual ~Iterator(){}  
};  
  
template<class ItemType>  
class ConcreteIterator : public Iterator <ItemType>  
{  
public:  
    ConcreteIterator(ConcreteAggregate<ItemType>*a): aggr(a),CurrentIndex(0){}  
    virtual void first()  
    {  
        CurrentIndex = 0;  
    }  
    virtual void next()  
    {  
        if( CurrentIndex < aggr->getLen() )  
            CurrentIndex++;  
    }  
    virtual ItemType currentItem()  
    {  
        if( CurrentIndex < aggr->getLen() )  
            //return &(*aggr)[ CurrentIndex ];  
        else  
            return NULL;  
    }  
    virtual bool isDone()  
    {  
        return ( CurrentIndex >= aggr->getLen() );  
    }  
private:
    ConcreteAggregate<ItemType> * aggr;  
    int CurrentIndex; 
};  

#endif