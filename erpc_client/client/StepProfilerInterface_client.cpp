/*
 * Generated by erpcgen 1.12.0 on Wed Sep  4 13:11:29 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include "erpc_port.h"
#endif
#include "erpc_codec.hpp"
#include "StepProfilerInterface_client.hpp"
#include "erpc_manually_constructed.hpp"

#if 11200 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;
using namespace erpcShim;

//! @brief Function to read struct lvdtFreqData
static void read_lvdtFreqData_struct(erpc::Codec * codec, lvdtFreqData * data);

//! @brief Function to read struct sysStatus
static void read_sysStatus_struct(erpc::Codec * codec, sysStatus * data);


// Read struct lvdtFreqData function implementation
static void read_lvdtFreqData_struct(erpc::Codec * codec, lvdtFreqData * data)
{
    if(NULL == data)
    {
        return;
    }

    codec->read(data->folat_lengthNum);

    uint32_t lengthTemp_0;
    codec->startReadList(lengthTemp_0);
    data->lengthNum = lengthTemp_0;
    data->frequency = (int32_t *) erpc_malloc(lengthTemp_0 * sizeof(int32_t));
    for (uint32_t listCount0 = 0U; listCount0 < lengthTemp_0; ++listCount0)
    {
        codec->read(data->frequency[listCount0]);
    }

    uint32_t lengthTemp_1;
    codec->startReadList(lengthTemp_1);
    data->lengthNum = lengthTemp_1;
    data->sin = (int16_t *) erpc_malloc(lengthTemp_1 * sizeof(int16_t));
    for (uint32_t listCount1 = 0U; listCount1 < lengthTemp_1; ++listCount1)
    {
        codec->read(data->sin[listCount1]);
    }

    uint32_t lengthTemp_2;
    codec->startReadList(lengthTemp_2);
    data->lengthNum = lengthTemp_2;
    data->dc = (int16_t *) erpc_malloc(lengthTemp_2 * sizeof(int16_t));
    for (uint32_t listCount2 = 0U; listCount2 < lengthTemp_2; ++listCount2)
    {
        codec->read(data->dc[listCount2]);
    }

    uint32_t lengthTemp_3;
    codec->startReadList(lengthTemp_3);
    data->lengthNum = lengthTemp_3;
    data->mag = (float *) erpc_malloc(lengthTemp_3 * sizeof(float));
    for (uint32_t listCount3 = 0U; listCount3 < lengthTemp_3; ++listCount3)
    {
        codec->read(data->mag[listCount3]);
    }

    uint32_t lengthTemp_4;
    codec->startReadList(lengthTemp_4);
    data->lengthNum = lengthTemp_4;
    data->phase = (float *) erpc_malloc(lengthTemp_4 * sizeof(float));
    for (uint32_t listCount4 = 0U; listCount4 < lengthTemp_4; ++listCount4)
    {
        codec->read(data->phase[listCount4]);
    }
}

// Read struct sysStatus function implementation
static void read_sysStatus_struct(erpc::Codec * codec, sysStatus * data)
{
    if(NULL == data)
    {
        return;
    }

    codec->read(data->pwrOn);

    codec->read(data->pwrOff);

    codec->read(data->towerDown);

    codec->read(data->singleAcquisition);

    codec->read(data->towerUp);

    codec->read(data->towerHome);

    codec->read(data->unloadSample);

    codec->read(data->loadSample);

    codec->read(data->Err);
}




StepProfiler_client::StepProfiler_client(ClientManager *manager)
:m_clientManager(manager)
{
}

StepProfiler_client::~StepProfiler_client()
{
}

// StepProfiler interface Z_Home function client shim.
void StepProfiler_client::Z_Home(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_Z_HomeId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_Z_HomeId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StepProfiler interface Y_Home function client shim.
void StepProfiler_client::Y_Home(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_Y_HomeId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_Y_HomeId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StepProfiler interface Z_Run function client shim.
void StepProfiler_client::Z_Run(int32_t dir)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_Z_RunId, request.getSequence());

    codec->write(dir);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_Z_RunId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StepProfiler interface Y_Run function client shim.
void StepProfiler_client::Y_Run(int32_t dir)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_Y_RunId, request.getSequence());

    codec->write(dir);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_Y_RunId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StepProfiler interface setForce function client shim.
void StepProfiler_client::setForce(int32_t force)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_setForceId, request.getSequence());

    codec->write(force);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_setForceId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StepProfiler interface getLVDTStatus function client shim.
int32_t StepProfiler_client::getLVDTStatus(void)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_getLVDTStatusId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    codec->read(result);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_getLVDTStatusId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = -1;
    }

    return result;
}

// StepProfiler interface getLVDTFreq function client shim.
void StepProfiler_client::getLVDTFreq(lvdtFreqData * data, int32_t preCount, int32_t postCount)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_getLVDTFreqId, request.getSequence());

    codec->write(preCount);

    codec->write(postCount);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    read_lvdtFreqData_struct(codec, data);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_getLVDTFreqId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

StylusProfiler_client::StylusProfiler_client(ClientManager *manager)
:m_clientManager(manager)
{
}

StylusProfiler_client::~StylusProfiler_client()
{
}

// StylusProfiler interface MotorRun function client shim.
void StylusProfiler_client::MotorRun(uint8_t _motorId, uint8_t _runType, uint8_t _runDir)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_MotorRunId, request.getSequence());

    codec->write(_motorId);

    codec->write(_runType);

    codec->write(_runDir);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_MotorRunId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface MotorStop function client shim.
void StylusProfiler_client::MotorStop(uint8_t _motorId)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_MotorStopId, request.getSequence());

    codec->write(_motorId);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_MotorStopId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface GetMotorRunSetStatus function client shim.
uint8_t StylusProfiler_client::GetMotorRunSetStatus(uint8_t _motorId)
{
    erpc_status_t err = kErpcStatus_Success;

    uint8_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_GetMotorRunSetStatusId, request.getSequence());

    codec->write(_motorId);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    codec->read(result);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_GetMotorRunSetStatusId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = 0xFFU;
    }

    return result;
}

// StylusProfiler interface GetMotorStopSetStatus function client shim.
uint8_t StylusProfiler_client::GetMotorStopSetStatus(uint8_t _motorId)
{
    erpc_status_t err = kErpcStatus_Success;

    uint8_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_GetMotorStopSetStatusId, request.getSequence());

    codec->write(_motorId);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    codec->read(result);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_GetMotorStopSetStatusId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = 0xFFU;
    }

    return result;
}

// StylusProfiler interface MotorZero function client shim.
void StylusProfiler_client::MotorZero(uint8_t _motorId)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_MotorZeroId, request.getSequence());

    codec->write(_motorId);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_MotorZeroId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface GetMotorZeroStatus function client shim.
uint8_t StylusProfiler_client::GetMotorZeroStatus(uint8_t _motorId)
{
    erpc_status_t err = kErpcStatus_Success;

    uint8_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_GetMotorZeroStatusId, request.getSequence());

    codec->write(_motorId);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    codec->read(result);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_GetMotorZeroStatusId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = 0xFFU;
    }

    return result;
}

// StylusProfiler interface LineCtrl function client shim.
void StylusProfiler_client::LineCtrl(uint16_t _value)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_LineCtrlId, request.getSequence());

    codec->write(_value);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_LineCtrlId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface AmplifierTypeSwitch function client shim.
void StylusProfiler_client::AmplifierTypeSwitch(uint8_t _type)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_AmplifierTypeSwitchId, request.getSequence());

    codec->write(_type);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_AmplifierTypeSwitchId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface SingalCheckSwitch function client shim.
void StylusProfiler_client::SingalCheckSwitch(uint8_t _ctrl)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_SingalCheckSwitchId, request.getSequence());

    codec->write(_ctrl);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_SingalCheckSwitchId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface DataTx2PcSwitch function client shim.
void StylusProfiler_client::DataTx2PcSwitch(uint8_t _ctrl)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_DataTx2PcSwitchId, request.getSequence());

    codec->write(_ctrl);

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_DataTx2PcSwitchId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface PwrOn function client shim.
void StylusProfiler_client::PwrOn(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_PwrOnId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_PwrOnId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface PwrOff function client shim.
void StylusProfiler_client::PwrOff(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_PwrOffId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_PwrOffId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface TowerDown function client shim.
void StylusProfiler_client::TowerDown(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_TowerDownId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_TowerDownId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface TowerUp function client shim.
void StylusProfiler_client::TowerUp(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_TowerUpId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_TowerUpId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface TowerHome function client shim.
void StylusProfiler_client::TowerHome(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_TowerHomeId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_TowerHomeId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface UnloadSample function client shim.
void StylusProfiler_client::UnloadSample(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_UnloadSampleId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_UnloadSampleId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface LoadSample function client shim.
void StylusProfiler_client::LoadSample(void)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_LoadSampleId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_LoadSampleId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface GetSysStatus function client shim.
void StylusProfiler_client::GetSysStatus(sysStatus * data)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_GetSysStatusId, request.getSequence());

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    read_sysStatus_struct(codec, data);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_GetSysStatusId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface SAStop function client shim.
void StylusProfiler_client::SAStop(sAStopType _flag)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_SAStopId, request.getSequence());

    codec->write(static_cast<int32_t>(_flag));

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_SAStopId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}

// StylusProfiler interface SingleAcquisition function client shim.
void StylusProfiler_client::SingleAcquisition(float _sample, float _speed, float _length, float _duration, float _resolution, sAStartType _flag)
{
    erpc_status_t err = kErpcStatus_Success;


#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(true);

    // Encode the request.
    Codec * codec = request.getCodec();

    codec->startWriteMessage(message_type_t::kOnewayMessage, m_serviceId, m_SingleAcquisitionId, request.getSequence());

    codec->write(_sample);

    codec->write(_speed);

    codec->write(_length);

    codec->write(_duration);

    codec->write(_resolution);

    codec->write(static_cast<int32_t>(_flag));

    // Send message to server
    // Codec status is checked inside this function.
    m_clientManager->performRequest(request);

    err = codec->getStatus();

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_SingleAcquisitionId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    return;
}
