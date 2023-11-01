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
    this->source = s;
}

System* Flow :: getSource() const{
    return this->source;
}

void Flow :: setTarget(System *s){
    this->target = s;
}

System* Flow :: getTarget() const{
    return this->target;
}

Flow& Flow :: operator=(const Flow& f){
    if(this == &f) return *this;

    this->source = f.source;
    this->target = f.target;

    return *this;
}