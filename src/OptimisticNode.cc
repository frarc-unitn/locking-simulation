#include "OptimisticNode.h"
#include "Optimistic_m.h"

Define_Module(OptimisticNode);

void OptimisticNode::initialize() {
  // Schedule Read Request
}

void OptimisticNode::handleMessage(cMessage* msg) {
  switch (msg->getKind()) {
    case MessageKind::READREPLY:
      handleReadReply((ReadReply*) msg);
      break;
    case MessageKind::CASSUCCESS:
      handleCompareAndSwapSuccess((CompareAndSwapSuccess*) msg);
      break;
    case MessageKind::CASFAILED:
      handleCompareAndSwapFailed((CompareAndSwapFailed*) msg);
      break;
    default:
      throw cRuntimeError("OptimisticNode: Unrecognized Message Kind");
      break;
  }
}
