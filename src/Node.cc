#include "Node.h"

void Node::scheduleStart() {
  const double delay = par("requestInterval").doubleValueInUnit("ms");
  cMessage* msg = createStartMessage();
  sendDelayed(msg, delay, "link");
}

int Node::doWork(int data) {
  return data+1;
}

void Node::sendWorkMessage(cMessage* msg){
  const double delay = par("workDelay").doubleValueInUnit("ms");
  sendDelayed(msg, delay, "link");
}

