#include "Node.h"
#include "omnetpp/csimulation.h"

void Node::initialize(){
  this->time_to_complete.setName("Time to Complete");
}

void Node::scheduleStart(){
  const double delay = par("requestInterval").doubleValueInUnit("ms");
  cMessage* msg = createStartMessage();
  sendDelayed(msg, delay, "link$o");
  this->work_start = simTime() + delay;
}

int Node::doWork(int data){
  return data+1;
}

void Node::sendWorkMessage(cMessage* msg){
  const double delay = par("workDelay").doubleValueInUnit("ms");
  sendDelayed(msg, delay, "link$o");
}

void Node::commitWorkToVector() {
  this->time_to_complete.record(simTime() - this->work_start);
  this->work_start = 0;
}

void Node::finish() {
  this->time_to_complete.registerVector();
}

