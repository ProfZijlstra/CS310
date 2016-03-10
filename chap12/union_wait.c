union wait {
    unsigned short w_status;
    struct {
        unsigned short w_Termsig:7; // termination signal
        unsigned short w_Coredump:1;// core dump indicator
        unsigned short w_Retcode:8; // exit code if w_termsig==0
    } w_T;                          // interrrupted process status
    struct {
        unsigned short w_Stopval:8; // == W_STOPPED if stopped
        unsigned short w_Stopsig:8; // signal causing suspension
    } w_S;                          // suspended process status
};

