#include "OptimisticManager.h"
#include "Optimistic_m.h"
#include "omnetpp/cexception.h"
#include <omnetpp.h>

Define_Module(OptimisticManager);

void OptimisticManager::handleMessage(cMessage* msg) {
  switch(msg->getKind()) {
    case MessageKind::READREQUEST:
      handleReadRequest((ReadRequest*) msg);
      break;
    case MessageKind::CAS:
      handleCompareAndSwap((CompareAndSwap*) msg);
      break;
    default:
      throw cRuntimeError("OptimisticManager: Unrecognized Message Kind");
      break;
  }
}
