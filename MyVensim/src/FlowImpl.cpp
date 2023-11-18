#include "FlowImpl.h"

FlowImpl :: FlowImpl() {}

FlowImpl :: FlowImpl(System* source, System* target){
    this->source = source;
    this->target = target;
}

FlowImpl :: FlowImpl(const FlowImpl& f){
    this->source = f.source;
    this->target = f.target;
}

FlowImpl :: ~FlowImpl() {}

void FlowImpl :: setSource(System* s){
    source = s;
}

System* FlowImpl :: getSource() const{
    return source;
}

void FlowImpl :: setTarget(System* s){
    target = s;
}

System* FlowImpl :: getTarget() const{
    return target;
}

Flow& FlowImpl :: operator=(const Flow& f){
    if(this == &f) return *this;

    this->source = f.getSource();
    this->target = f.getTarget();

    return *this;
}