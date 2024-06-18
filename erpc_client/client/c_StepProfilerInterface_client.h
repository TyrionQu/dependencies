/*
 * Generated by erpcgen 1.12.0 on Sat Jun  8 13:47:25 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_c_StepProfilerInterface_client_h_)
#define _c_StepProfilerInterface_client_h_

#include "StepProfilerInterface_common.h"
#include "erpc_client_manager.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#if !defined(ERPC_FUNCTIONS_DEFINITIONS)
#define ERPC_FUNCTIONS_DEFINITIONS


/*! @brief StepProfiler identifiers */
enum _StepProfiler_ids
{
    kStepProfiler_service_id = 1,
    kStepProfiler_Z_Home_id = 1,
    kStepProfiler_Y_Home_id = 2,
    kStepProfiler_Z_Run_id = 3,
    kStepProfiler_Y_Run_id = 4,
    kStepProfiler_setForce_id = 5,
    kStepProfiler_getLVDTStatus_id = 6,
    kStepProfiler_getLVDTFreq_id = 7,
};


/*! @brief StylusProfiler identifiers */
enum _StylusProfiler_ids
{
    kStylusProfiler_service_id = 2,
    kStylusProfiler_MotorRun_id = 1,
    kStylusProfiler_MotorStop_id = 2,
    kStylusProfiler_GetMotorRunSetStatus_id = 3,
    kStylusProfiler_GetMotorStopSetStatus_id = 4,
    kStylusProfiler_MotorZero_id = 5,
    kStylusProfiler_GetMotorZeroStatus_id = 6,
    kStylusProfiler_LineCtrl_id = 7,
    kStylusProfiler_AmplifierTypeSwitch_id = 8,
    kStylusProfiler_SingalCheckSwitch_id = 9,
    kStylusProfiler_DataTx2PcSwitch_id = 10,
};

//! @name StepProfiler
//@{
int32_t InitInstance();
int32_t ExitInstance();

void Z_Home(void);

void Y_Home(void);

void Z_Run(int32_t dir);

void Y_Run(int32_t dir);

void setForce(int32_t force);

int32_t getLVDTStatus(void);

void getLVDTFreq(lvdtFreqData * data, int32_t preCount, int32_t postCount);
//@}

//! @name StylusProfiler
//@{
void MotorRun(uint8_t _motorId, uint8_t _runType, uint8_t _runDir);

void MotorStop(uint8_t _motorId);

uint8_t GetMotorRunSetStatus(uint8_t _motorId);

uint8_t GetMotorStopSetStatus(uint8_t _motorId);

void MotorZero(uint8_t _motorId);

uint8_t GetMotorZeroStatus(uint8_t _motorId);

void LineCtrl(uint16_t _value);

void AmplifierTypeSwitch(uint8_t _type);

void SingalCheckSwitch(uint8_t _ctrl);

void DataTx2PcSwitch(uint8_t _ctrl);
//@}

#endif // ERPC_FUNCTIONS_DEFINITIONS

void initStepProfiler_client(erpc_client_t client);

void deinitStepProfiler_client(void);

void initStylusProfiler_client(erpc_client_t client);

void deinitStylusProfiler_client(void);

#if defined(__cplusplus)
}
#endif

#endif // _c_StepProfilerInterface_client_h_
