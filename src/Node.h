#include <omnetpp.h>
#pragma once

using namespace omnetpp;

class Node : public cSimpleModule {
  protected:
    void scheduleStart();
    // virtual void finish() override;
    int doWork(int data);
    void sendWorkMessage(cMessage* msg); 

  private:
    virtual cMessage* createStartMessage() = 0;
};
