static unsigned int Allocate_Counter  = 0;
static unsigned int Deallocate_Counter  = 0;

void *Memory_Allocate (size_t size) {
    void *pvHandle = NULL;
    pvHandle = malloc(size);
    if (NULL != pvHandle) {
        ++Allocate_Counter;
    } else {
        //Log error
    }
    return (pvHandle);
}
void Memory_Deallocate (void *pvHandle) {
    if(pvHandle != NULL) {
        free(pvHandle);
        ++Deallocate_Counter;
    }
}

int Check_Memory_Leak(void) {
    int iRet = 0;
    if (Allocate_Counter != Deallocate_Counter) {
        //Log error
        iRet = Memory_Leak_Exception;
    } else {
        iRet = OK;
    }
    return iRet;
}
