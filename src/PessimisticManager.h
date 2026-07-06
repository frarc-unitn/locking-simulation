#include "Manager.h"
#include "Pessimistic_m.h"
#pragma once

class PessimisticManager: public Manager {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
    // virtual void finish() override;
  private:
    void handleLockRequest(LockRequest* msg);
    void handleLockRelease(LockRelease* msg);
};
