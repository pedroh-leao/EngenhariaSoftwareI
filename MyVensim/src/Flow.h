#ifndef FLOW_H
#define FLOW_H

#include "System.h"

class Flow{
protected:
    System *source, *target;

public:
    Flow();
    Flow(System*, System*);
    Flow(const Flow&); //constructor for copy
    virtual ~Flow();

    void setSource(System*);
    System* getSource() const;

    void setTarget(System*);
    System* getTarget() const;

    virtual double executeEquation() = 0;

    Flow& operator=(const Flow&);
};


#endif