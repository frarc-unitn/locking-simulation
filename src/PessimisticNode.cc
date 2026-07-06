#include "PessimisticNode.h"
#include "Pessimistic_m.h"

Define_Module(PessimisticNode);

void PessimisticNode::initialize() {
  // Schedule Lock Request
}

void PessimisticNode::handleMessage(cMessage* msg) {
  switch(msg->getKind()) {
    case MessageKind::LOCKGRANTED:
      handleLockGranted((LockGranted*) msg);
      break;
    default:
      throw cRuntimeError("PessimisticNode: Unrecognized Message Kind");
      break;
  }
}
