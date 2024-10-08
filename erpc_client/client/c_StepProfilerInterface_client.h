/*
 * Generated by erpcgen 1.12.0 on Wed Sep  4 13:11:29 2024.
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
    kStylusProfiler_PwrOn_id = 11,
    kStylusProfiler_PwrOff_id = 12,
    kStylusProfiler_TowerDown_id = 13,
    kStylusProfiler_TowerUp_id = 14,
    kStylusProfiler_TowerHome_id = 15,
    kStylusProfiler_UnloadSample_id = 16,
    kStylusProfiler_LoadSample_id = 17,
    kStylusProfiler_GetSysStatus_id = 18,
    kStylusProfiler_SAStop_id = 19,
    kStylusProfiler_SingleAcquisition_id = 20,
};

//! @name StepProfiler
//@{
int32_t InitInstance(const char * host, uint16_t port);
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

void PwrOn(void);

void PwrOff(void);

void TowerDown(void);

void TowerUp(void);

void TowerHome(void);

void UnloadSample(void);

void LoadSample(void);

void GetSysStatus(sysStatus * data);

void SAStop(sAStopType _flag);

void SingleAcquisition(float _sample, float _speed, float _length, float _duration, float _resolution, sAStartType _flag);
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
