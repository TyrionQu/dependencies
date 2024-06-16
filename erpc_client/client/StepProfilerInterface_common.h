/*
 * Generated by erpcgen 1.12.0 on Sat Jun  8 13:47:25 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_StepProfilerInterface_common_h_)
#define _StepProfilerInterface_common_h_


#if defined(__cplusplus)
extern "C"
{
#endif
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "erpc_version.h"

#if 11200 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif


#if !defined(ERPC_TYPE_DEFINITIONS_STEPPROFILERINTERFACE)
#define ERPC_TYPE_DEFINITIONS_STEPPROFILERINTERFACE

// Aliases data types declarations
typedef struct lvdtFreqData lvdtFreqData;

// Structures/unions data types declarations
struct lvdtFreqData
{
    uint32_t lengthNum;
    uint32_t folat_lengthNum;
    int32_t * frequency;
    int16_t * sin;
    int16_t * dc;
    float * mag;
    float * phase;
};


#endif // ERPC_TYPE_DEFINITIONS_STEPPROFILERINTERFACE

#if defined(__cplusplus)
}
#endif

#endif // _StepProfilerInterface_common_h_
