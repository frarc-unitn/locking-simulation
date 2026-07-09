#include <omnetpp.h>
#pragma once

using namespace omnetpp;

class Node : public cSimpleModule {
  protected:
    virtual void scheduleStart();
    // virtual void finish() override;

  private:
    virtual cMessage* createStartMessage() = 0;
};
