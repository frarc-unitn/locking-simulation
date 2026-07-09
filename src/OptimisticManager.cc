#include "OptimisticManager.h"
#include "Optimistic_m.h"
#include <omnetpp.h>

Define_Module(OptimisticManager);

void OptimisticManager::handleMessage(cMessage* msg) {
  switch(msg->getKind()) {
    case MessageKind::READREQUEST:
      handleReadRequest((ReadRequest*) msg);
      delete msg;
      break;
    case MessageKind::CAS:
      handleCompareAndSwap((CompareAndSwap*) msg);
      delete msg;
      break;
    default:
      throw cRuntimeError("OptimisticManager: Unrecognized Message Kind");
      break;
  }
}

void OptimisticManager::handleReadRequest(ReadRequest* msg) {
  ReadReply* reply = new ReadReply("Manager: Read Reply", MessageKind::READREPLY);
  reply->setData(this->data);
  send(reply, "nodes$o", msg->getArrivalGate()->getIndex());
}

void OptimisticManager::handleCompareAndSwap(CompareAndSwap* msg) {
  cMessage* reply;
  if(msg->getOld_data() == this->data) {
    this->data = msg->getData();
    reply = new CompareAndSwapSuccess("Manager: CAS Success", MessageKind::CASSUCCESS);
  } else {
    reply = new CompareAndSwapFailed("Manager: CAS Failed", MessageKind::CASFAILED);
    ((CompareAndSwapFailed*) reply)->setData(this->data);
  }

  send(reply, "nodes$o", msg->getArrivalGate()->getIndex());
}
