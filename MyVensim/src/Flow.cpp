#include "Flow.h"

Flow :: Flow() {}

Flow :: Flow(System* source, System* target){
    this->source = source;
    this->target = target;
}

Flow :: Flow(const Flow& f){
    this->source = f.source;
    this->target = f.target;
}

Flow :: ~Flow() {}

void Flow :: setSource(System *s){
    source = s;
}

System* Flow :: getSource() const{
    return source;
}

void Flow :: setTarget(System *s){
    target = s;
}

System* Flow :: getTarget() const{
    return target;
}

Flow& Flow :: operator=(const Flow& f){
    if(this == &f) return *this;

    this->source = f.source;
    this->target = f.target;

    return *this;
}