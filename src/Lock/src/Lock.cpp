#include "Lock.hpp"

Lock::Lock(mutex *pm)
{
    pm->lock();
    this->pMutex.reset(pm, unlock);

    cout << "Lock" << endl;
}

void unlock(mutex *pm)
{
    pm->unlock();

    cout << "Unlock" << endl;
}