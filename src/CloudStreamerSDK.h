
#ifndef __CLOUDSTREAMERSDK_H__
#define __CLOUDSTREAMERSDK_H__

#include "utils/utils.h"
#include "utils/_cunk.h"
#include "utils/MLog.h"
#include "Interfaces/ICloudStreamerCallback.h"
#include "Objects/CloudShareConnection.h"
#include "cloud/core/CameraManager/CameraManagerConfig.h"
#include "cloud/core/CameraManager/CameraManager.h"
#include "cloud/core/CameraManager/ICameraManagerCallback.h"

class CloudStreamerSDK : public CUnk,
						public ICameraManagerCallback
{
	const char *TAG = "CloudStreamerSDK";
	const int LOG_LEVEL = 2; //Log.VERBOSE;
	MLog Log;

	ICloudStreamerCallback *mCallback;
	long m_RefConnected;

	CloudShareConnection mConnection;

	//camera info
	std::string mToken;
	long long mCamid;
	std::string mSvcpUrl;

	//streamer CM
	CameraManagerConfig mCameraManagerConfig;
	CameraManager mCameraManager;
	int prepareCM();
	int closeCM();

public:
    CloudStreamerSDK(ICloudStreamerCallback *callback);
    virtual ~CloudStreamerSDK();

	int setSource(std::string &channel);

    int Start();
	int Stop();

	//=>ICameraManagerCallback
	void onPrepared();
	void onClosed(int error, std::string reason);
	void onUpdateConfig(CameraManagerConfig &config);
	void onStreamStart();
	void onStreamStop();
	void onCommand(std::string cmd);
	void onUpdatePreview();
	//<=ICameraManagerCallback
};

#endif //__CLOUDSTREAMERSDK_H__
