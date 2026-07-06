#include <omnetpp.h>
#pragma once

using namespace omnetpp;

class Node : public cSimpleModule {
  protected:
    virtual void initialize() override = 0;
    virtual void handleMessage(cMessage* msg) override = 0;
    // virtual void finish() override;
};
