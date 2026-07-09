#include <omnetpp.h>
#pragma once

using namespace omnetpp;

class Manager : public cSimpleModule {
  protected:
    int data = 0;

    // virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override = 0;
    // virtual void finish() override;
};
