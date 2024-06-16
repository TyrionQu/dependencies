#include "c_StepProfilerInterface_client.h"
#include "erpc_client_setup.h"
#include "erpc_port.h"
#include <iostream>
int32_t precnt = 1;
int32_t postcnt = 7;
int32_t i = 0;
FILE* pf;


int main()
{

    erpc_transport_t transport = erpc_transport_tcp_init("localhost", 12345, 0);
    erpc_mbf_t erpc_mbf_dynamic = erpc_mbf_dynamic_init();
    erpc_client_t client = erpc_client_init(transport, erpc_mbf_dynamic);
    initStepProfiler_client(client);
    initStylusProfiler_client(client);
    /**********client func*********/

    Z_Home();
    Y_Home();
    int32_t a= getLVDTStatus();
    printf("a=%d\n",a);
    /*****************************/

    a =  GetMotorRunSetStatus(0);
    printf("a=%d\n",a);

    a = GetMotorStopSetStatus(0);
    printf("a=%d\n",a);

    a = GetMotorZeroStatus(0);
    printf("a=%d\n",a);





    // if (data)
    // {
    //     erpc_free(data->frequency);

    //     erpc_free(data->mag);

    //     erpc_free(data->phase);
    //     erpc_free(data->dc);
    // }
    // erpc_free(data);
    deinitStepProfiler_client();
    deinitStylusProfiler_client();
    erpc_client_deinit(client);
    erpc_mbf_dynamic_deinit(erpc_mbf_dynamic);
    erpc_transport_tcp_close(transport);
    //等待1s
    // _sleep(1);
    return 0;
}