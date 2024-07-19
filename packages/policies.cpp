#include <iostream>

#include "policies.h" 
#include "../utilities/index.h"

using namespace std;

Policy getPolicy(string policyName){
    
    toLowerCase(policyName);
    Policy policy;

    if(policyName == "lru"){
        policy = Policy::LRU ;
    }else if(policyName == "lifo"){
        policy = Policy::LIFO;
    }else if(policyName == "fifo"){
        policy = Policy::FIFO;
    }

    return policy;
}
