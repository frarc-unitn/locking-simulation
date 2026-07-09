#include "Node.h"

void Node::scheduleStart() {
  const double delay = par("requestInterval").doubleValueInUnit("ms");
  cMessage* msg = createStartMessage();
  sendDelayed(msg, delay, "link");
}

