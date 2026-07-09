#include "PessimisticNode.h"
#include "Pessimistic_m.h"

Define_Module(PessimisticNode);

void PessimisticNode::initialize() {
  scheduleStart();
}

cMessage* PessimisticNode::createStartMessage() {
  return new LockRequest("Node: Lock Request", MessageKind::LOCKREQUEST);
}

void PessimisticNode::handleMessage(cMessage* msg) {
  switch(msg->getKind()) {
    case MessageKind::LOCKGRANTED:
      handleLockGranted((LockGranted*) msg);
      delete msg;
      break;
    default:
      throw cRuntimeError("PessimisticNode: Unrecognized Message Kind");
      break;
  }
}

void PessimisticNode::handleLockGranted(LockGranted* msg){
  int data = doWork(msg->getData());
  LockRelease* reply = new LockRelease("Node: Lock Release", MessageKind::LOCKRELEASE);
  reply->setData(data);
  sendWorkMessage(reply);
}
