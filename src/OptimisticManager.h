#include "Manager.h"
#include "Optimistic_m.h"
#pragma once

class OptimisticManager: public Manager {
  protected:
    // virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
    // virtual void finish() override;

  private:
    void handleReadRequest(ReadRequest* msg);
    void handleCompareAndSwap(CompareAndSwap* msg);
};
