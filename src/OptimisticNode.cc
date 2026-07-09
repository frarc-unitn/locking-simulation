#include "OptimisticNode.h"
#include "Optimistic_m.h"

Define_Module(OptimisticNode);

void OptimisticNode::initialize() {
  scheduleStart();
}

cMessage* OptimisticNode::createStartMessage() {
  return new ReadRequest("Node: Read Request", MessageKind::READREQUEST);
}

void OptimisticNode::handleMessage(cMessage* msg) {
  switch (msg->getKind()) {
    case MessageKind::READREPLY:
      handleReadReply((ReadReply*) msg);
      delete msg;
      break;
    case MessageKind::CASSUCCESS:
      handleCompareAndSwapSuccess((CompareAndSwapSuccess*) msg);
      delete msg;
      break;
    case MessageKind::CASFAILED:
      handleCompareAndSwapFailed((CompareAndSwapFailed*) msg);
      delete msg;
      break;
    default:
      throw cRuntimeError("OptimisticNode: Unrecognized Message Kind");
      break;
  }
}

void OptimisticNode::handleReadReply(ReadReply* msg){
  const int old_data = msg->getData();
  prepareCompareAndSwap(old_data);
}

void OptimisticNode::handleCompareAndSwapSuccess(CompareAndSwapSuccess* msg){
  scheduleStart();
}

void OptimisticNode::handleCompareAndSwapFailed(CompareAndSwapFailed* msg){
  const int old_data = msg->getData();
  prepareCompareAndSwap(old_data);
}

void OptimisticNode::prepareCompareAndSwap(int old_data){
  const int data = doWork(old_data);
  CompareAndSwap* message = new CompareAndSwap("Node: Compare and Swap Request", MessageKind::CAS);
  message->setOld_data(old_data);
  message->setData(data);
  sendWorkMessage(message);
}
