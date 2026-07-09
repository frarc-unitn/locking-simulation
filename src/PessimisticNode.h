#include "Node.h"
#include "Pessimistic_m.h"
#pragma once

class PessimisticNode: public Node {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
    // virtual void finish() override;

  private:
    virtual cMessage* createStartMessage() override;

    void handleLockGranted(LockGranted* msg);
};
