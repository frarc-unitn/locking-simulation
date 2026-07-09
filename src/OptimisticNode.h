#include "Node.h"
#include "Optimistic_m.h"
#pragma once

class OptimisticNode: public Node {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
    // virtual void finish() override;

  private:
    virtual cMessage* createStartMessage() override;

    void handleReadReply(ReadReply* msg);
    void handleCompareAndSwapSuccess(CompareAndSwapSuccess* msg);
    void handleCompareAndSwapFailed(CompareAndSwapFailed* msg);
};
