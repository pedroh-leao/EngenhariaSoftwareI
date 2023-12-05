#include "FlowImpl.h"

FlowBody :: FlowBody() {
    source = NULL;
    target = NULL;
}

FlowBody :: FlowBody(System* source, System* target){
    this->source = source;
    this->target = target;
}

FlowBody :: FlowBody(const Flow& f){
    this->source = f.getSource();
    this->target = f.getTarget();
}

FlowBody :: ~FlowBody() {}

void FlowBody :: setSource(System* s){
    source = s;
}

System* FlowBody :: getSource() const{
    return source;
}

void FlowBody :: setTarget(System* s){
    target = s;
}

System* FlowBody :: getTarget() const{
    return target;
}