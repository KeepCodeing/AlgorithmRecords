#include<windows.h>

template<typename T>
class SuperThread
{
public:
    SuperThread(T* t,void (T::*f)());
    void StartThread();
    void PauseThread();
    void RestartThread();
    void DestroyThread();
    void WaitForThread();
    static DWORD WINAPI StartRun(void* param);
    T* t;
    void (T::*f)();
    static bool isOk;
private:
//    pthread_t mThread;
    HANDLE handle;
    

};
template<typename T>
bool SuperThread<T>::isOk=false;
template<typename T>
SuperThread<T>::SuperThread(T* t,void (T::*f)())
{
    this->t=t;
    this->f=f;
}
template<typename T>
void SuperThread<T>::StartThread()
{
//    pthread_create(&mThread,NULL,&StartRun,this);
    handle=CreateThread(NULL,0,StartRun,this,0,0);
    while(!this->isOk)
    {
        Sleep(50);
    }
    this->isOk=false;
//    WaitForSingleObject(hMutex,INFINITE);


}
template<typename T>
void SuperThread<T>::PauseThread()
{
}
template<typename T>
void SuperThread<T>::RestartThread()
{
}
template<typename T>
void SuperThread<T>::DestroyThread()
{

}
template<typename T>
void SuperThread<T>::WaitForThread()
{
    //pthread_join(mThread,NULL);
    WaitForSingleObject(handle,INFINITE);
}
template<typename T>
DWORD WINAPI SuperThread<T>::StartRun(void* param)
{
    SuperThread<T>* mt=(SuperThread<T>*) param;
    T *t1=mt->t;
    void (T::*f1)();
    f1=mt->f;
    SuperThread<T>::isOk=true;
    (t1->*f1)();
    return 0;
}
