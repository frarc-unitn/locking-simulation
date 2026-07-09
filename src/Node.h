#include <omnetpp.h>
#pragma once

using namespace omnetpp;

class Node : public cSimpleModule {
  protected:
    virtual void initialize() override;
    virtual void finish() override;

    void scheduleStart();
    int doWork(int data);
    void sendWorkMessage(cMessage* msg); 
    void commitWorkToVector(); 
    cOutVector time_to_complete;

  private:
    virtual cMessage* createStartMessage() = 0;
    simtime_t work_start;
};
