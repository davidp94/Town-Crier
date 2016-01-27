#include "App.h"

#include "sgx_urts.h"
#include "sgx_uae_service.h"
#include "App.h"
#include "Enclave_u.h"

/* Global EID shared by multiple threads */
sgx_enclave_id_t global_eid = 0;

#define RPC_TEST

int main()
{

#ifdef RPC_TEST
    test_rpc();
#endif

#if defined(_MSC_VER)
    if (query_sgx_status() < 0) {
        printf("Enter a character before exit ...\n");
        getchar();
        return -1; 
    }
#endif 
    if(initialize_enclave() < 0){
        printf("Enter a character before exit ...\n");
        getchar();
        return -1; 
    }
 
    // test_self_test();
    int ret;
    test_yahoo_finance(global_eid, &ret);
    if (ret != 0) {
        printf("test_yahoo_finance returned %d\n", ret);
    }

    printf("Info: SampleEnclave successfully returned.\n");
    printf("Enter a character before exit ...\n");
    getchar();
    return 0;
}
